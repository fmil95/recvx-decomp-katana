/* 
 * File: sg_Cp.h
 * Desc: system library (memory copy)
 * Auth: Jiro Terakwa(SYSTEM R&D)
 * Create: 1998/04/07 Jiro Terakawa: Ver. 0.1
 * Change:
 *
 * Func: syCpInit:       �R�s�[���C�u�����̏�����
 *       syCpFinish:     �R�s�[���C�u�����̏I��
 *       syCpCreate:     �R�s�[�n���h���̐���
 *       syCpCopy:       �R�s�[�̎��s
 *       syCpGetStat:    �R�s�[�󋵂̎擾
 *                       
 * Note:
 *
 */
#ifndef _SG_CP_H_
#define _SG_CP_H_

#define  SYD_CP_MODE_ANY   0 /* �f�o�C�X�w��Ȃ� */
#define  SYD_CP_MODE_DMA1  1 /* DMA1 ���g�p���ē]�� */
#define  SYD_CP_MODE_DMA3  3 /* DMA3 ���g�p���ē]�� */
#define  SYD_CP_MODE_CPU   4 /* CPU �œ]�� */
typedef Uint32 SY_CP_MODE;

#define SYD_CP_WIDTH_1BYTE     1  /* CHCR?.TS012 */
#define SYD_CP_WIDTH_2BYTE     2  /* CHCR?.TS012 */
#define SYD_CP_WIDTH_4BYTE     4  /* CHCR?.TS012 */
#define SYD_CP_WIDTH_8BYTE     8  /* CHCR?.TS012 */
#define SYD_CP_WIDTH_32BYTE    32  /* CHCR?.TS012 */
typedef Uint32 SY_CP_WIDTH;

#define  SYD_CP_STAT_DONE  0   /* �R�s�[�͐���I������ */
#define  SYD_CP_STAT_ERR   1   /* �R�s�[�̓G���[�ɂ��I������ */
#define  SYD_CP_STAT_ABORT 2   /* �R�s�[�̓��[�U����̎w���Œ��f���� */
#define  SYD_CP_STAT_PEND  3   /* �R�s�[�͑҂��s��ɓ����Ă��� */
#define  SYD_CP_STAT_PROG  4   /* �R�s�[�͎��s���ł��� */
#define  SYD_CP_STAT_OPEN  5   /* �R�s�[�́A���[�U�̃R���t�B�O���[�V�������ł��� */
typedef Uint32 SY_CP_STAT;

struct SYS_CP{
  Void *src;           /* �]�����A�h���X   */
  Void *dst;           /* �]����A�h���X   */
  Uint32 size;         /* �]���T�C�Y       */
  Void (*callback)(Void *);      /* �R�[���o�b�N�֐� */
  Void *arg;           /* �R�[���o�b�N�֐��ďo�����̈��� */
  SY_CP_MODE mode; /* �R�s�[���[�h     */
  SY_CP_STAT stat; /* ���             */
  SY_CP_WIDTH width;   /* �]���P�� 1, 2, 4, 8, 32 BYTE */
};

/* �n���h�� */
typedef struct SYS_CP * SYCP;

EXTERN Void syCpInit(Void);

EXTERN SYCP syCpCreate(Void *src, Void *dst, Void (*callback)(Void *), SY_CP_MODE syCpMode);

/* Void syCpSetSrc(SYCP syCp); */
#define syCpSetSrc(_syCp, _src) \
  ((_syCp)->src = (_src))
/* Void syCpSetDst(SYCP syCp); */
#define syCpSetDst(_syCp, _dst) \
  ((_syCp)->dst = (_dst))
/* Void syCpSetCallback(SYCP syCp); */
#define syCpSetCallback(_syCp, _callback) \
  ((_syCp)->callback = (_callback))
/* Void syCpSetArg(SYCP syCp); */
#define syCpSetArg(_syCp, _arg) \
  ((_syCp)->arg = (_arg))
/* Void syCpSetMode(SYCP syCp); */
#define syCpSetMode(_syCp, _mode) \
  ((_syCp)->mode = (_mode))
/* Void syCpSetSize(SYCP syCp); */
#define syCpSetSize(_syCp, _size) \
  ((_syCp)->size = (_size))

EXTERN Void syCpCopy(SYCP syCp);

EXTERN Void syCpAbort(SYCP syCp);

/* SY_CP_STAT syCpGetStat(SYCP syCp);*/
#define syCpGetStat(_syCp) \
  ((_syCp)->syCpStat)

EXTERN Void syCpDestroy(SYCP syCp);

EXTERN Void syCpFinish(Void);

#endif /* _SG_CP_H_ */
