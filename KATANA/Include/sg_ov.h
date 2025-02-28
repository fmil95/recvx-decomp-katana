/*
 *  Overlay Library
 *  Copyright (c) 1998 SEGA
 *
 *      Overlay
 *
 *  Module  : Library Header File
 *  File    : sg_ov.h
 *  Create  : 1998-02-20
 *  Modify  : 1998-05-12
 *  Version : 0.41
 *  Note    :
 */
#ifndef _SG_OV_H_
#define _SG_OV_H_

#include	<sg_xpt.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*	Universally Unique Identifier	*/
#ifndef UUID_DEFINED
#define UUID_DEFINED
typedef struct _UUID
{
    Uint32	Data1;
    Uint16	Data2;
    Uint16	Data3;
    Uint8	Data4[8];
} UUID;
typedef UUID Uuid;
#endif

/*	���C�u����ID�̒�`		*/
#define OVD_LID { \
	0xba7e0a00, 0xbda9, 0x11d1, 0x8a, 0xeb, 0x00, 0x60, 0x08, 0x95, 0x62, 0x5f\
}\

/*  ���C�u�����̃o�[�W����(Ver.0.41)		*/
#define	OVD_VERSION_NO			(0x00)		/*  �o�[�W�����ԍ�				*/
#define	OVD_REVISION_NO			(0x41)		/*  ���r�W�����ԍ�				*/

/*	�G���[�R�[�h	*/
typedef enum {
	OVE_ERR_OK				= 0,		/*  ����I��					*/
	OVE_ERR_INVALID_FORMAT	= -1,		/*  �s���ȃt�H�[�}�b�g			*/
	OVE_ERR_INVALID_LIB_ID	= -2,		/*  �s���ȃ��C�u����ID			*/
	OVE_ERR_INVALID_LIB_HDL	= -3		/*  �s���ȃ��C�u�����n���h��	*/
} OVE_ERR;


/*	���C�u�����n���h��	*/
typedef struct {
	struct _ov_lif	*lif;			/*	���C�u�����C���^�t�F�[�X			*/
	Uint8			ver;			/*	�o�[�W�����ԍ�						*/
	Uint8			revi;			/*	���r�W�����ԍ�						*/
	Sint16			rsv1;			/*	�\�� 1								*/
	Sint32			rsv2;			/*	�\�� 2								*/
	Sint32			rsv3;			/*	�\�� 3								*/
	UUID    		lid;			/*	���C�u����ID						*/
} OVS_LIB_OBJ;
typedef OVS_LIB_OBJ *OVLIB;

/*	�e���C�u�������K���쐬���郉�C�u�����C���^�t�F�[�X�֐�  				*/
typedef struct _ov_lif {
	void (*QueryInterface)();		/*		for COM compatibility			*/
	void (*AddRef)();				/*		for COM compatibility			*/
	void (*Release)();				/*		for COM compatibility			*/
	void (*Init)(OVLIB ovl);		/*		������							*/
	void (*Finish)(OVLIB ovl);		/*		�I������						*/
	void (*Exec)(OVLIB ovl);		/*		���s							*/
} OVS_LIB_IF;
typedef OVS_LIB_IF *OVLIB_IF;

/***
*		���s���W���[���̂��߂̊֐�
***/

/*	���s���W���[���n���h��	*/
typedef struct {
	Sint32	rsv[8];
	OVS_LIB_OBJ libobj[1];
} OVS_MDL_OBJ;
typedef OVS_MDL_OBJ *OVMDL;

/***
*			���C�u���������̂��߂̒�`
***/

/*	�N���e�B�J���Z�N�V����	*/
typedef Sint32 OV_CS;

/*	���C�u�����Ǘ��e�[�u���ւ̃|�C���^�̃A�h���X	*/
#define	OVD_LIBTBL_ADR_PTR	(0x8C00FFF0)
/*	���C�u�����Ǘ��e�[�u���̍ő�o�^���ւ̃A�h���X	*/
#define	OVD_LIBTBL_ADR_MAX	(0x8C00FFF4)
/*	���C�u�����Ǘ��e�[�u���̃A�h���X	*/
#define	OVD_DEF_LIBTBL_ADR	(0x8C00FC00)

/*	���C�u�����Ǘ��e�[�u���̍ő�o�^��	*/
#define	OVD_DEF_LIBTBL_MAX	(120)

/*	���C�u�����Ǘ��e�[�u��	*/
typedef struct {
	Sint32	nlib;				/* �o�^����Ă��郉�C�u������				*/
	Sint32	rsv1;				/* �\��P									*/
	struct {
		OVLIB	lib;			/* ���C�u�����n���h��						*/
		Sint32	ref;			/* �Q�ƃJ�E���^								*/
	} entry[1];
} OVS_LIBTBL;

/***
*		�֐��錾
***/

/*	���C�u�����n���h���̎擾												*/
OVLIB ovLibOpen(UUID *lid);
/*	���C�u�����n���h���̊J��												*/
void ovLibClose(UUID *lid);
/*	���W���[���t�@�C���̓ǂݍ���											*/
OVE_ERR ovMdlEntryTbl(OVMDL ovmdl);
/*	���W���[���t�@�C���̊J��												*/
OVE_ERR ovMdlDeleteTbl(OVMDL ovmdl);
/*  ���s���W���[���̎��s													*/
Sint32 ovMdlExec(OVMDL ovmdl);

/*  ���C�u�����C���^�t�F�[�X�̎擾											*/
OVLIB_IF ovLibGetLibIf(OVLIB lib);
/*  ���C�u�����̃o�[�W�����̎擾											*/
void ovLibGetVersion(OVLIB lib, Uint8 *ver, Uint8 *revi);
/*  ���C�u����ID�̎擾														*/
UUID *ovLibGetUuid(OVLIB lib);

/*  ���C�u�����Ǘ����C�u�����̏����� (�ʏ�g�p���Ȃ��j						*/
void ovInit(void *ovltbl, Sint32 nlib);
/*  ���C�u�����Ǘ����C�u�����̏I������ (�ʏ�g�p���Ȃ��j					*/
void ovFinish(void);
/*	���C�u�����n���h���̓o�^												*/
OVE_ERR ovLibEntryTbl(OVLIB lib);
/*	���C�u�����n���h���̍폜												*/
OVE_ERR ovLibDeleteTbl(OVLIB lib);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif     /*  _SG_OV_H_	*/
