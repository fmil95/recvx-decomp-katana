/*
 *  Middleware Library
 *  Copyright (c) 1998 CRI,SEGA
 *  
 *      Video Render
 *
 *  Module  : Library Header File
 *  File    : sg_mwrnv.h
 *  Create  : 1999-04-01
 *  Modify  : 1998-04-01
 *  Note    : M.O
 */

#ifndef _SG_MWRNV_H_
#define _SG_MWRNV_H_

/*	Version No.	*/
#define	MWD_RNV_VER		"2.10"

/***** �C���N���[�h *****/
#include	<sg_xpt.h>
#include	"sj.h"
#include	"sg_mwmvf.h"

/***** �萔�}�N�� *****/

/*	�e�N�X�`���t���[���̃T�C�Y	*/
#define	MWD_RNV2_SIZE_OF_TXFRM	(16)	/*	sizeof(MWS_RNV_TXFRM)		*/

/*	�e�N�X�`���t�H�[�}�b�g	*/
#define	MWD_RNV2_TFMT_YUV420		(0)
#define	MWD_RNV2_TFMT_YUV422		(1)
#define	MWD_RNV2_TFMT_PLT8			(2)

/*	�������[�h	*/
#define MWD_RNV2_COMPO_OPEQ			(0)	/*	�s����							*/
#define MWD_RNV2_COMPO_ADD			(1)	/*	���Z����						*/
#define MWD_RNV2_COMPO_ALPH			(2)	/*	�A���t�@����					*/
#define MWD_RNV2_COMPO_INVALPH		(3)	/*	�C���o�[�X�A���t�@����			*/
#define MWD_RNV2_COMPO_DSTALPH		(4)	/*	���葤�̃A���t�@����			*/
#define MWD_RNV2_COMPO_INVDSTALPH	(5)	/*	���葤�̃C���o�[�X�A���t�@����	*/

#define	MWD_RNV_DTYPE_AUTO		(0)			/*	��������		*/
#define	MWD_RNV_DTYPE_FULL		(1)			/*	�t���X�N���[��	*/

/*	�s�N�`���`��R�[���o�b�N�̕Ԃ�l	*/
#define MWD_RNV_DRAWCB_OK			(0)
#define MWD_RNV_DRAWCB_WAIT		(1)
#define MWD_RNV_DRAWCB_SKIP		(2)

#define	MWD_DSPPNT_NOMAL		(0)
#define	MWD_DSPPNT_ENDOFSTRIP	(1)

/*	������	*/
/*	�n���h���̏��	*/
/*	�n���h���̏��		*/
/*	Status of Handle	*/
#ifndef MWE_RNV2_STAT_DEFINED
#define MWE_RNV2_STAT_DEFINED
typedef enum {
	MWE_RNV2_STAT_STOP = 0x00,		/*	STOP							*/
	MWE_RNV2_STAT_MN_WAIT = 0x01,	/*	WAIT(manual mode)				*/
	MWE_RNV2_STAT_MN_FLSH = 0x02,	/*	FLUSH(manual mode)				*/
	MWE_RNV2_STAT_MN_EXEC = 0x03,	/*	EXECUTING(manual mode)			*/
	MWE_RNV2_STAT_PEND = 0x04,		/*	PLAY END						*/
	MWE_RNV2_STAT_WAIT = 0x05,		/*	WAIT							*/
	MWE_RNV2_STAT_FLSH = 0x06,		/*	FLUSH							*/
	MWE_RNV2_STAT_EXEC = 0x07		/*	EXECUTING						*/
} MWE_RNV2_STAT;
#endif

/***** �f�[�^�^�̒�` *****/

/* �r�f�I�����_���n���h�� */
#ifndef MWRNV2_DEFINED
#define MWRNV2_DEFINED
typedef void *MWRNV2;
#endif

/*	�\���X�N���[���|�C���g	*/
#ifndef MWS_RNV_DSPPNT_DEFINED
#define MWS_RNV_DSPPNT_DEFINED
typedef struct _mws_rnv_dsppnt {
	Uint32	ctrl;					/*	�X�g���b�v����f�[�^				*/
	float	plx;					/*	�\���t���[���o�b�t�@ X ���W			*/
	float	ply;					/*	�\���t���[���o�b�t�@ Y ���W			*/
	float	plz;					/*	�\���t���[���o�b�t�@ Z ���W			*/
	float	tlx;					/*	�e�N�X�`�� U ���W					*/
	float	tly;					/*	�e�N�X�`�� V ���W					*/
	Uint32 rgb_base;				/*	ARGB��l							*/
	Uint32 rgb_ofst;				/*	ARGB�I�t�Z�b�g						*/
} MWS_RNV_DSPPNT;
#endif

/*	�n���h�������̃p�����[�^�\����			*/
/*	Parameter structure to create handle	*/
#ifndef MWS_RNV2_CPRM_DEFINED
#define MWS_RNV2_CPRM_DEFINED
typedef struct {
	Sint32	tfmt;			/*	�e�N�X�`���t�H�[�}�b�g					*/
	Sint32	isx;			/*	���s�N�Z����							*/
							/*	The number of sideways pixels		 	*/
	Sint32	isy;			/*	�c�s�N�Z����							*/
							/*	The number of lengthways pixels			*/
	Sint32	tex_nfrm;		/*	�e�N�X�`���t���[����(V-RAM)				*/
							/*	The number of texture frames			*/
	Sint32	work_nfrm;		/*	���[�N�t���[����						*/
							/*	The number of macro block frames		*/
	Sint32	wksize;			/*	��Ɨ̈�̑傫��						*/
							/*	Size of work area						*/
	Uint8	*wk;			/*	��Ɨ̈�								*/
							/*	Pointer to work area					*/
} MWS_RNV2_CPRM;
#endif

/***** �֐��錾 *****/

/*=========================================================================*
 *		���C�u�����̏������ƏI������
 *		Initialize and Finalize of Library
 *=========================================================================*/

/*	���C�u�����̏�����	*/
void mwRnv2Init(void);

/*	���C�u�����̏I������	*/
void mwRnv2Finish(void);

/*	Vertex�o�b�t�@�̐ݒ�	*/
void mwRnv2SetVertexBuffer(void *vtxbuf);

/*	���C�e���V�[�̐ݒ�	(nvsync:2|3)	*/
void mwRnv2SetLatency(Sint32 nvsync);

/*=========================================================================*
 *		��{����̐���
 *		Basic Control
 *=========================================================================*/

/*	���[�r�[�t���[���̍�Ɨ̈�T�C�Y�̌v�Z	*/
Sint32 mwRnv2CalcMvfWork(Sint32 tfmt, Sint32 sx, Sint32 sy, Sint32 nfrm);

/*	���[�r�[�t���[���̍�Ɨ̈�T�C�Y�̌v�Z	*/
Sint32 mwRnv2CalcWork(MWS_RNV2_CPRM *cprm);

/*	�n���h���̍쐬	*/
MWRNV2 mwRnv2Create(SJ sj, MWS_RNV2_CPRM *cprm);

/*	�n���h���̏���	*/
void mwRnv2Destroy(MWRNV2 rnv);

/*	�����_�����O�J�n	*/
void mwRnv2Start(MWRNV2 rnv);

/*	�����_�����O��~	*/
void mwRnv2Stop(MWRNV2 rnv);

/*	�T�[�o�֐�	*/
void mwRnv2ExecServer(void);

/*	�n���h����Ԃ̎擾	*/
MWE_RNV2_STAT mwRnv2GetStat(MWRNV2 rnv);

/*	�s�N�`���`��R�[���o�b�N�֐��̓o�^	*/
/*	���R�[���o�b�N�֐��̖߂�l�ɂ�肻�̃t���[����`�悷�邩�ۂ������߂�	*/
/*	  MWD_RNV_DRAWCB_OK   :	�`��											*/
/*	  MWD_RNV_DRAWCB_WAIT :	���O�̃s�N�`����\��							*/
/*	  MWD_RNV_DRAWCB_SKIP :	�X�L�b�v�B���̃s�N�`������΂����ɃR�[���o�b�N	*/
void mwRnv2EntryDrawCallbackFn(MWRNV2 rnv,
  Sint32 (*fn)(void *obj, Sint32 time, Sint32 tunit, Sint32 dfno), void *obj);

/*	�\���R�[���o�b�N�֐��̓o�^	*/
void mwRnv2EntryDispCallbackFn(MWRNV2 rnv,
 void (*fn)(void *obj, Sint32 time, Sint32 tunit, Sint32 dfno), void *obj);

/*	�e�N�X�`���t���[���̏�Ԏ擾	*/
void mwRnv2GetNumTxfrm(MWRNV2 rnv, Sint32 *ndsp, Sint32 *nren);

/*	���[�h�\�ȃe�L�X�`�����̎擾	*/
Sint32 mwRnv2GetNumRoomTex(MWRNV2 rnv);

/*	�������[�h�̐ݒ�	*/
void mwRnv2SetCompoMode(MWRNV2 rnv, Sint32 mode);

/*	�e�N�X�`�����[�h�̎��s	*/
void mwRnv2Load(MWRNV2 rnv, Sint8 *src, Sint32 time, Sint32 tunit);

/*	�e�N�X�`���̕`��	*/
void mwRnv2Draw(MWRNV2 rnv);

/*	�\���X�C�b�`�̐ݒ�	*/
void mwRnv2SetDispSw(MWRNV2 rnv, Sint32 sw);

/*	�\���X�C�b�`�̎擾	*/
Sint32 mwRnv2GetDispSw(MWRNV2 rnv);

/*	�\���T�[�t�F�X�̎擾	*/
void *mwRnv2GetCurSrf(MWRNV2 rnv);

/***
*			�\���E�B���h�E�̐���
***/

/*	�\���ʒu��T�C�Y�̃f�t�H���g�l�̐ݒ�	*/
/*	INPUT :ssx, ssy, isx, isy, tw, th				*/
/*	OUTPUT:plx, ply, plz, psx, psy, tw, th				*/
void mwRnv2SetWndDefConf(MWRNV2 rnv, long dtype);
/*	�\���ʒu�̐ݒ�	*/
void mwRnv2SetWndPos(MWRNV2 rnv, float lx, float ly);
/*	�\���T�C�Y�̐ݒ�	*/
void mwRnv2SetWndSize(MWRNV2 rnv, float sx, float sy);
/*	�\���ʒu�̉��s��	*/
void mwRnv2SetWndZ(MWRNV2 rnv, float lz);
/*	�P�x�̐ݒ�	*/
void mwRnv2SetWndBright(MWRNV2 rnv, Uint32 val);
/*	�P�x�̎擾	*/
Uint32 mwRnv2GetWndBright(MWRNV2 rnv);
/*	�P�x�I�t�Z�b�g�̐ݒ�	*/
void mwRnv2SetWndBrightOfst(MWRNV2 rnv, Uint32 val);
/*	�P�x�I�t�Z�b�g�̎擾	*/
Uint32 mwRnv2GetWndBrightOfst(MWRNV2 rnv);

/***
*			�\���T�[�t�F�X�̐ݒ�
***/

/*	�R���g���[���R�[�h�̐ݒ�	*/
void mwRnv2SetSrfCtrl(MWRNV2 rnv, Uint32 no, Uint32 ctrl);
/*	�R���g���[���R�[�h�̎擾	*/
Uint32 mwRnv2GetSrfCtrl(MWRNV2 rnv, Uint32 no);
/*	�T�[�t�F�X�|�C���g�p�o�b�t�@�T�C�Y�̌v�Z	*/
Sint32 mwRnv2CalcSrfBufSize(MWRNV2 rnv, Sint32 npnt);
/*	�T�[�t�F�X�|�C���g�p�o�b�t�@�̐ݒ�	*/
void mwRnv2SetSrfPntBuf(MWRNV2 rnv, Sint32 npnt, void *buf, Sint32 bsize);
/*	�\���ʒu�̐ݒ�	*/
void mwRnv2SetSrfPos(MWRNV2 rnv, Uint32 no, float lx, float ly, float lz);
/*	�\���ʒu�̎擾	*/
void mwRnv2GetSrfPos(MWRNV2 rnv, Uint32 no, float *lx, float *ly, float *lz);
/*	�P�x�̐ݒ�	*/
void mwRnv2SetSrfBright(MWRNV2 rnv, Uint32 no,
									float a, float r, float g, float b);
/*	�P�x�̎擾	*/
void mwRnv2GetSrfBright(MWRNV2 rnv, Uint32 no,
									float *a, float *r, float *g, float *b);
/*	�P�x�I�t�Z�b�g�̐ݒ�	*/
void mwRnv2SetSrfBrightOfst(MWRNV2 rnv, Uint32 no,
									float a, float r, float g, float b);
/*	�P�x�I�t�Z�b�g�̎擾	*/
void mwRnv2GetSrfBrightOfst(MWRNV2 rnv, Uint32 no,
									float *a, float *r, float *g, float *b);
/*	�C���[�W�ʒu�̐ݒ�	*/
void mwRnv2SetImgPos(MWRNV2 rnv, Uint32 no, float lx, float ly);

/*	�C���[�W�ʒu�̎擾	*/
void mwRnv2GetImgPos(MWRNV2 rnv, Uint32 no, float *lx, float *ly);

/*	�C���[�W�T�C�Y�̐ݒ�	*/
void mwRnv2SetImgSize(MWRNV2 rnv, Sint32 isx, Sint32 isy);

/*	�C���[�W�T�C�Y�̎擾	*/
void mwRnv2GetImgSize(MWRNV2 rnv, Sint32 *isx, Sint32 *isy);
#endif /*	_SG_MWRNV_H_	*/
