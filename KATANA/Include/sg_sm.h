#ifndef _SG_SM_H_INCLUDED
#define _SG_SM_H_INCLUDED
/***********************************************************************
 *
 *				V-Sync�J�E���^���C�u�����w�b�_
 *				�i�E���C�u�����T���v���j
 *
 *      Copyright(c) SEGA ENTERPRISES, LTD., 1998
 *      Ver.1.00	(1998-2-15) 	Written by mOshimi
 *----------------------------------------------------------------------
 *		Note:
 ************************************************************************/

/*
	�� V-Sync�J�E���^���C�u����
	�@�{���C�u�����́A�E���C�u�����̂��߂̂ЂȌ^�ł��B����ɏ������邱�Ƃɂ��
	�I�[�o���C�ɑΉ����邱�Ƃ��ł��܂��B
	V-sync�J�E���^���C�u�����́AV-Sync�̋N�����񐔂��擾���邽�߂̃��C�u����
	�ł��B�n���h�������ɃJ�E���^�ϐ��������AV-Sync���荞�݂̋N�����񐔂�
	�J�E���g���܂��B���������ɁAV-Sync���荞�݃��[�`����VCNT_ExecServer�֐���
	�o�^���܂��BVCNT_ExecServer�֐��́A���荞�݂ɂ���ČĂяo����A�X�e�[�^�X
	�����s���̏ꍇ�̓J�E���^�ϐ����P�C���N�������g���܂��B
	�܂��AVCNT_Start�֐��ɂ���ăJ�E���g���X�^�[�g���AVCNT_Stop�֐��Œ�~
	���܂��B�X�e�[�^�X�́AVCNT_GetStat�֐��Ŏ擾�ł��܂��B

	���C���^�t�F�[�X�֐����@�O���[�o���֐��Ăяo�����߂̊֐�
	void smVcntInit(void);
	void smVcntFinish(void);
	void smVcntExecServer(void);
	SmVcnt smVcntCreate(Sint32 cntmax);
	���O���[�o���֐����@�O���[�o���ϐ��E�X�^�e�B�b�N�ϐ����A�N�Z�X����֐�
	void smVcntInitG(void);
	void smVcntFinishG(void);
	void smVcntExecServerG(void);
	SmVcnt smVcntCreateG(Sint32 cntmax);
	���n���h���֐����@�@�n���h�������̕ϐ��̂݃A�N�Z�X����֐�
	SmVcnt smVcntDestroy(SmVcnt vcnt);
	Sint32 smVcntGetStat(SmVcnt vcnt);
	void smVcntStart(SmVcnt vcnt);
	void smVcntStop(SmVcnt vcnt);
	Sint32 smVcntGetCnt(SmVcnt vcnt);
	void smVcntSetCnt(SmVcnt vcnt, Sint32 cnt);
*/

#ifdef __cplusplus
    #define EXTERN_C    extern "C"
#else
    #define EXTERN_C    extern
#endif

#ifdef _NON_NINJA_
#include	<sg_xpt.h>
#endif
#include	<sg_ov.h>

/*	���C�u����ID�̒�`												*/
#define SmVcntD_LID { \
	0x211b2800, 0xa6a9, 0x11d1, 0x8f, 0x3f, 0x00, 0x60, 0x08, 0x94, 0x48, 0xbc\
}\

EXTERN_C const UUID SmVcntLID;


/*  ���C�u�����̃o�[�W����													*/
#define	SmVcntD_VERSION_NO	(0x01)		/*  �o�[�W�����ԍ�					*/
#define	SmVcntD_REVISION_NO	(0x00)		/*  ���r�W�����ԍ�					*/

/*	V-Sync�J�E���^�n���h���̍ő吔											*/
#define SmVcntD_MAX	(16)

/*	V-Sync�J�E���^�n���h���̓�����										*/
enum {
	SmVcntE_STAT_STOP=0,				/*	�J�E���g��~��					*/
	SmVcntE_STAT_EXEC					/*	�J�E���g���s��					*/
};

/*	V-Sync �J�E���^�p�N���e�B�J���Z�N�V�����ϐ�								*/
/*	�i���ۂ́A���荞�݃}�X�N���x��)											*/
typedef Sint32 SmVcntCs;

/*	V-Sync�J�E���^�n���h��	*/
typedef struct {
	Uint8	used;						/*	�g�p�����ۂ�					*/
	Uint8	stat;						/*	������						*/
	Sint16	rsv2;						/*	�\��̈�						*/
	Sint32	max;						/*	�J�E���^�̏���l				*/
	Sint32	cnt;						/*	V �J�E���^						*/
} SmVcntObj;
typedef SmVcntObj *SmVcnt;

/*	�e���C�u�������K���쐬���郉�C�u�����C���^�t�F�[�X�֐�  				*/
typedef struct {
	void	(*QueryInterface)();		/*	for COM compatibility			*/
	void	(*AddRef)();				/*	for COM compatibility			*/
	void	(*Release)();				/*	for COM compatibility			*/
	void	(*Init)(OvLib ovl);			/*	������							*/
	void	(*Finish)(OvLib ovl);		/*	�I������						*/
	void	(*Exec)(void);				/*	���s(�T�[�o�֐�)				*/
	SmVcnt	(*Create)(Sint32 cntmax);	/*	V-Sync�n���h���̐���			*/
} SmVcntLif;
typedef SmVcntLif *SmVcntI;

/*	���C�u�����n���h��	*/
extern SmVcntLif SmVcntG_lif;

/***
*		���[�U�֐��v���g�^�C�v
***/

/*	���C�u�����̏�����	*/
void smVcntInit(void);
/*	���C�u�����̏I��	*/
void smVcntFinish(void);
/*	V�J�E���^�n���h���̐���	*/
SmVcnt smVcntCreate(Sint32 cntmax);
/*	V�J�E���^�n���h���̏���	*/
void smVcntDestroy(SmVcnt vcnt);
/*	�����Ԃ̎擾	*/
Sint32 smVcntGetStat(SmVcnt vcnt);
/*	�J�E���g�̊J�n	*/
void smVcntStart(SmVcnt vcnt);
/*	�J�E���g�̒�~	*/
void smVcntStop(SmVcnt vcnt);
/*	�J�E���g�l�̎擾	*/
Sint32 smVcntGetCnt(SmVcnt vcnt);
/*	�J�E���g�l�̐ݒ�	*/
void smVcntSetCnt(SmVcnt vcnt, Sint32 cnt);
/*	�T�[�o�֐��i�ʏ�̓��[�U�͎g�p���Ȃ��j	*/
void smVcntExecServer(void);

/***
*		�����֐�
***/

/*	�N���e�B�J���Z�N�V�����ւ̐i��	*/
void smVcntLockCs(SmVcntCs *cs);
/*	�N���e�B�J���Z�N�V��������̒E�o	*/
void SmVcntUnlockCs(SmVcntCs *cs);

/*	���C�u�����̏�����	(�O���[�o���֐�)	*/
void smVcntInitG(OvLib ovl);
/*	���C�u�����̏I��	(�O���[�o���֐�)	*/
void smVcntFinishG(OvLib ovl);
/*	V �J�E���^�n���h���̐���	(�O���[�o���֐�)	*/
SmVcnt smVcntCreateG(Sint32 cntmax);
/*	�T�[�o�֐�	(�O���[�o���֐�)	*/
void smVcntExecServerG(void);

#endif		/*	#ifndef _SM_H_INCLUDED		*/
