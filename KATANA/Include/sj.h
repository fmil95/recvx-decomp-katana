#ifndef _SJ_H_INCLUDED
#define _SJ_H_INCLUDED
/****************************************************************************/
/*																			*/
/*				�X�g���[���W���C���g���C�u�����w�b�_�@						*/
/*																			*/
/*				 1998.4.14			written by M.Oshimi						*/
/*																			*/
/****************************************************************************/

#define	SJ_VER	"5.51"

#ifdef _MSC_VER
#pragma comment(lib, "sj.lib")
#endif

/***********************************************************************
 *      �����}�N��
 ***********************************************************************/

/* �����A�h���X�̃|�C���^�^�ւ̕ϊ� */
#define SJ_VOID_PTR(adr)	((void *)(adr))

/* ����n�r�b�g���[���ɂ���
 * �@1,2,8,16�r�b�g�̏ꍇ�ASH�́A�ړI�̃��W�X�^�����g�p����2���߂ŏ���
 * �ł���̂ŁA�V�t�g�����ɂ���B
 * �@3�`7�r�b�g�̏ꍇ�ASH�́A-128�܂ł͖��߃R�[�h�ɃC�~�f�B�G�C�g�f�[�^
 * ���i�[�ł���̂ŁA�}�X�N�����ɂ���B1���߂܂���2���߁B
 * �@���̑��̏ꍇ�A�󋵂ɉ����čœK�Ƃ͌���Ȃ����A�V�t�g�����ɂ��Ă����B
 */
#define SJ_OFF_LSB(val, n)	((((unsigned long)(val)) >> (n)) << (n))
#define SJ_OFF_LSB1(val)	((((unsigned long)(val)) >> (1)) << (1))
#define SJ_OFF_LSB2(val)	((((unsigned long)(val)) >> (2)) << (2))
#define SJ_OFF_LSB3(val)	(((unsigned long)(val)) & (0xfffffff8))
#define SJ_OFF_LSB4(val)	(((unsigned long)(val)) & (0xfffffff0))
#define SJ_OFF_LSB5(val)	(((unsigned long)(val)) & (0xffffffe0))
#define SJ_OFF_LSB6(val)	(((unsigned long)(val)) & (0xffffffc0))
#define SJ_OFF_LSB7(val)	(((unsigned long)(val)) & (0xffffff80))
#define SJ_OFF_LSB8(val)	((((unsigned long)(val)) >> (8)) << (8))
#define SJ_OFF_LSB16(val)	((((unsigned long)(val)) >> (16)) << (16))

/* �|�C���^��2,4,8,16,32byte���E�܂Ŗ߂��i���ӁF���ʂ�(void*)�^�j */
#define SJ_BACK_BND2(ptr)	SJ_VOID_PTR(SJ_OFF_LSB1(ptr))
#define SJ_BACK_BND4(ptr)	SJ_VOID_PTR(SJ_OFF_LSB2(ptr))
#define SJ_BACK_BND8(ptr)	SJ_VOID_PTR(SJ_OFF_LSB3(ptr))
#define SJ_BACK_BND16(ptr)	SJ_VOID_PTR(SJ_OFF_LSB4(ptr))
#define SJ_BACK_BND32(ptr)	SJ_VOID_PTR(SJ_OFF_LSB5(ptr))

/* �|�C���^��2,4,8,16,32byte���E�܂Ői�߂�i���ӁF���ʂ�(void*)�^�j */
#define SJ_FORE_BND2(ptr)	SJ_BACK_BND2( ((unsigned long)(ptr)) +  1)
#define SJ_FORE_BND4(ptr)	SJ_BACK_BND4( ((unsigned long)(ptr)) +  3)
#define SJ_FORE_BND8(ptr)	SJ_BACK_BND8( ((unsigned long)(ptr)) +  7)
#define SJ_FORE_BND16(ptr)	SJ_BACK_BND16(((unsigned long)(ptr)) + 15)
#define SJ_FORE_BND32(ptr)	SJ_BACK_BND32(((unsigned long)(ptr)) + 31)

/* 32byte���E�̗̈�m�ۂ̂��߂ɁA�̈�T�C�Y�𐅑������� */
#define SJ_SIZ_BND32(siz)	((siz) + 32)

/* SJ�o�b�t�@�A�h���X��32�o�C�g���E�̎擾 */
#define	SJ_ADR_BND32(adr)	SJ_FORE_BND32(adr)

/* ���E���̐�[�ƌ�����I�[�����߂� */
#define SJ_GET_ENDPOS(bgn, num)		((bgn) + (num) - 1)

/* ���E���̌��i���E�l�Fbgn <= end�j */
#define SJ_INNER_NUM(bgn, end)		((end) - (bgn) + 1)

/* ���E���̔���i���E�l�Fbgn <= x <= end�j */
#define SJ_IS_INNER(x, bgn, end) ( ((x) >= (bgn)) && ((x) <= (end)) )

/***********************************************************************
 *      �f�[�^�^�̐錾
 ***********************************************************************/

/*	�f�[�^���C���̒�`	*/
#define	SJ_LIN_FREE	(0)			/*	�f�[�^�`�����N���C��				*/
#define	SJ_LIN_DATA	(1)			/*	�t���[�`�����N���C��				*/

#define SJ_ERR_FATAL		(-1)
#define SJ_ERR_INTERNAL		(-2)
#define SJ_ERR_PRM			(-3)

#ifndef UUID_DEFINED
#define UUID_DEFINED
typedef struct _UUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} UUID;
#define uuid_t UUID
#endif

/*	�f�[�^�`�����N	*/
#ifndef SJCK_DEFINED
#define SJCK_DEFINED
typedef struct {
	char *data;					/*	�J�n�A�h���X						*/
	long len;					/*	�o�C�g��							*/
} SJCK;
#endif

/*	���C�u�����n���h��	*/
typedef struct {
	struct _sj_vtbl *vtbl;		/*	�C���^�t�F�[�X						*/
} SJ_OBJ;
#ifndef SJ_DEFINED
#define SJ_DEFINED
typedef SJ_OBJ *SJ;
#endif

/*	�C���^�t�F�[�X�֐�  				*/
typedef struct _sj_vtbl {
	void (*QueryInterface)();		/*		for COM compatibility			*/
	void (*AddRef)();				/*		for COM compatibility			*/
	void (*Release)();				/*		for COM compatibility			*/
	void (*Destroy)(SJ sj);		/*		�n���h���̏���					*/
	UUID *(*GetUuid)(SJ sj);		/*		UUID�̎擾						*/
	void (*Reset)(SJ sj);			/*		���Z�b�g						*/
	/*	�`�����N�̎擾	(FIFO�̐擪����擾)								*/
	void (*GetChunk)(SJ sj, long id, long nbyte, SJCK *ck);
	/*	�`�����N��߂��@(FIFO�̐擪�ɑ}��)									*/
	void (*UngetChunk)(SJ sj, long id, SJCK *ck);
	/*	�`�����N��}��	(FIFO�̍Ō�ɑ}��)									*/
	void (*PutChunk)(SJ sj, long id, SJCK *ck);
	/*	�擾�ł���f�[�^�̃o�C�g���̎擾									*/
	long (*GetNumData)(SJ sj, long id);
	/* �`�����N�̎擾�\�̔��� */
	long (*IsGetChunk)(SJ sj, long id, long nbyte, long *rbyte);
	/*	�G���[�������ɋN������֐��̓o�^									*/
	void (*EntryErrFunc)(SJ sj,
					void (*func)(void *obj, long ecode), void *obj);
} SJ_IF;
typedef SJ_IF *SJIF;

/*	�X�g���[���W���C���g�̏���												*/
#define SJ_Destroy(sj) \
		(*(sj)->vtbl->Destroy)(sj)
/*	�X�g���[���W���C���g�̃��Z�b�g											*/
#define SJ_Reset(sj) \
		(*(sj)->vtbl->Reset)(sj)
/*	�`�����N�̎擾															*/
#define SJ_GetChunk(sj, id, nbyte, ck) \
		(*(sj)->vtbl->GetChunk)(sj, id, nbyte, ck)
/*	�`�����N��߂�															*/
#define SJ_UngetChunk(sj, id, ck) \
		(*(sj)->vtbl->UngetChunk)(sj, id, ck)
/*	�`�����N��n��															*/
#define SJ_PutChunk(sj, id, ck) \
		(*(sj)->vtbl->PutChunk)(sj, id, ck)
/*	�擾�\�ȃf�[�^�̃o�C�g�������߂�										*/
#define SJ_GetNumData(sj, id) \
		(*(sj)->vtbl->GetNumData)(sj, id)
/*	�X�g���[���W���C���gUUID�̎擾 (UUID�ւ̃A�h���X)						*/
#define SJ_GetUuid(sj) \
		(*(sj)->vtbl->GetUuid)(sj)
/*	�G���[�������ɋN������R�[���o�b�N�֐��̓o�^							*/
#define SJ_EntryErrFunc(sj, id, f, o) \
		(*(sj)->vtbl->EntryErrFunc)(sj, id, f, o)
/* �`�����N�̎擾�\�̔��� */
#define SJ_IsGetChunk(sj, id, nbyte, rbyte) \
			(*(sj)->vtbl->IsGetChunk)(sj, id, nbyte, rbyte)

/***
*			�֐���`
***/

#ifdef		__cplusplus
extern	"C" {
#endif

/*	$func$ �`�����N�̕���
 * [���@��] void SJ_SplitChunk(SJCK *ck, long nbyte,
 *													SJCK *ck1, SJCK *ck2);
 * [���@��] ck		: ����ΏۂƂȂ�`�����N
 *			nbyte	: ck1 �̃o�C�g��
 * [�o�@��] ck1		: �������ꂽ�O���̃`�����N
 *			ck2		: �������ꂽ�㔼�̃`�����N
 * [�֐��l] ck2	�`�����N�̃o�C�g��
 * [�@�@�\] ck�`�����N��ck1�`�����N��ck2�`�����N�ɕ�������B
 *			ck1�`�����N�́Anbyte �̒����ɂȂ�B
 *			ck1�`�����N�̑傫�����Anbyte �ɖ����Ȃ��ꍇ�́A�������ꂸ�A
 *			ck2�`�����N�̒����́A0�ƂȂ�B
 *			ck1��ck�́A�������̂��w�肵�Ă��ǂ��B
 *			�P�ɕ�������ꍇ�́A�ȉ��̂悤�ɋL�q����B
 *				SJCK_SplitChunk(&ck, 100, &ck, &ck2);
 */
void SJ_SplitChunk(SJCK *ck, long nbyte, SJCK *ck1, SJCK *ck2);

/***
*		�����O�o�b�t�@�^�C�v�̃X�g���[���W���C���g
***/

/*	������																	*/
void SJRBF_Init(void);
/*	�I������	*/
void SJRBF_Finish(void);
/*	�����O�o�b�t�@�̐���													*/
SJ SJRBF_Create(char *buf, long bsize, long xsize);

/***
*		�������^�C�v�̃X�g���[���W���C���g
***/

/*	������																	*/
void SJMEM_Init(void);
/*	�I������	*/
void SJMEM_Finish(void);
/*	�������X�g���[���̐���													*/
SJ SJMEM_Create(char *data, long bsize);

/***
*		�ėp�X�g���[���W���C���g
***/

/*	�`�����N�̌������[�h	*/
#define	SJUNI_MODE_SEPA			(0)
#define	SJUNI_MODE_JOIN			(1)

#define	SJUNI_CALC_WORK(nck)	((nck)*16)

/*	������	*/
void SJUNI_Init(void);
/*	�I������	*/
void SJUNI_Finish(void);
/*	�ėp�X�g���[���W���C���g�̐���	*/
SJ SJUNI_Create(long mode, char *work, long wksize);
/*	�`�����N���̎擾	*/
long SJUNI_GetNumChunk(SJ sj, long id);
/*	�`�F�C���v�[�����̎擾	*/
long SJUNI_GetNumChainPool(SJ sj);

#if 0
/*	GetChunk�֐����Ă΂ꂽ�Ƃ��̃R�[���o�b�N�֐��̓o�^						*/
void SJUNI_EntryGetFunc(SJ sj, long id, void (*f)(void *o, SJCK *ck), void *o);
/*	PutChunk�֐����Ă΂ꂽ�Ƃ��̃R�[���o�b�N�֐��̓o�^						*/
void SJUNI_EntryPutFunc(SJ sj, long id, void (*f)(void *o, SJCK *ck), void *o);
/*	UngetChunk�֐����Ă΂ꂽ�Ƃ��̃R�[���o�b�N�֐��̓o�^					*/
void SJUNI_EntryUngetFunc(SJ sj, long id, void (*f)(void *o, SJCK *ck), void *o);
#endif

#ifdef		__cplusplus
}
#endif


#endif     /*  #ifndef _SJ_H_INCLUDED	*/


