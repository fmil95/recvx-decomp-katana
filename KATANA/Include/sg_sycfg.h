/********************************************************************
 *  Shinobi Library
 *  Copyright (c) 1998-1999 SEGA
 *
 *  Library : High layer Configuration Library
 *  Module  : Library Interface Header
 *  File    : sg_sycfg.h
 *  Date    : 1999-03-31
 *  Version : 1.14
 *
 ********************************************************************/

#ifndef _SG_SYCFG_H_
#define _SG_SYCFG_H_

/********************************************************************/
/*  �C���N���[�h�t�@�C��                                            */
/*  include files                                                   */
/********************************************************************/
#include    <sg_xpt.h>                      /*                      */
#include    <shinobi.h>                     /*                      */
/********************************************************************/
/*  �萔��`                                                        */
/*  constants                                                       */
/********************************************************************/
#define SYD_CFG_STEREO  (0x00)              /* �X�e���I�ݒ�         */
#define SYD_CFG_MONO    (0x01)              /* ���m�����ݒ�         */
#define SYD_CFG_OK      (0)                 /* ����I��             *//* Ver1.10 */
#define SYD_CFG_NG      (-1)                /* �ُ�I��             *//* Ver1.10 */

                                            /* Ver1.10              */
/*** �J���g���[�R�[�h ***/
/*** country code     ***/
#define SYD_CFG_JAPAN    (0x30)             /* ���{                 */
#define SYD_CFG_AMERICA  (0x31)             /* �A�����J�E�u���W��...*/
#define SYD_CFG_EUROPE   (0x32)             /* ���B                 */

/*** ����ݒ� ***/
/*** language ***/
#define SYD_CFG_JAPANESE   (0x0)            /* ���{��               */
#define SYD_CFG_ENGLISH    (0x1)            /* �p��                 */
#define SYD_CFG_GERMAN     (0x2)            /* �h�C�c��             */
#define SYD_CFG_FRENCH     (0x3)            /* �t�����X��           */
#define SYD_CFG_SPANISH    (0x4)            /* �X�y�C����           */
#define SYD_CFG_ITALIAN    (0x5)            /* �C�^���A��           */

#define SYD_CFG_D_JAPANESE (0x30)           /* ���{��               */
#define SYD_CFG_D_ENGLISH  (0x31)           /* �p��                 */
#define SYD_CFG_D_GERMAN   (0x32)           /* �h�C�c��             */
#define SYD_CFG_D_FRENCH   (0x33)           /* �t�����X��           */
#define SYD_CFG_D_SPANISH  (0x34)           /* �X�y�C����           */
#define SYD_CFG_D_ITALIAN  (0x35)           /* �C�^���A��           */

/*** �����`�� ***/
/*** bloadcast type ***/
#define SYD_CFG_NTSC     (0x30)             /* NTSC                 */
#define SYD_CFG_PAL      (0x31)             /* PAL                  */
#define SYD_CFG_PAL_M    (0x32)             /* PAL-M                */
#define SYD_CFG_PAL_N    (0x33)             /* PAL-N                */


/*** �̎��ʔԍ� ***/
/*** individual id ***/
#define SYD_CFG_IID_SIZE (6)				/* �̎��ʎq�f�[�^��   */
											/* individual id data size */

#define SYD_CFG_IID_OK		(1)				/* IID�擾OK            *//* Ver1.11 */
#define SYD_CFG_IID_CHKERR	(2)				/* �`�F�b�N�T���G���[   *//* Ver1.11 */
#define SYD_CFG_IID_NG  	(0)				/* IID�擾NG            *//* Ver1.11 */

/********************************************************************/
/*  �^��`                                                          */
/*  structure/union/enum                                            */
/********************************************************************/

/********************************************************************/
/*  �L��ϐ���`                                                    */
/*  global valiables                                                */
/********************************************************************/

/********************************************************************/
/*  �֐���`                                                        */
/*  functions                                                       */
/********************************************************************/
#ifdef __cplusplus
extern "C"{                                 /* for C++ Interface    */
#endif  /* __cplusplus */

Sint32 syCfgInit( Void* ) ;                 /* ���C�u�������������� */
Sint32 syCfgExit( Void  ) ;                 /* ���C�u�����I������   */
Sint32 syCfgSetSoundMode( Sint32  ) ;       /* �����ݒ�̍X�V       */
Sint32 syCfgGetSoundMode( Sint32* ) ;       /* �����ݒ�̎Q��       */
                                            /* Ver1.02              */
Sint32 syCfgGetCountryCode  ( Sint32* ) ;   /* �J���g���[�R�[�h�擾 */
Sint32 syCfgGetLanguage     ( Sint32* ) ;   /* ����ݒ�擾         */
Sint32 syCfgGetDefaultLanguage( Sint32* ) ; /* �f�t�H���g����ݒ�擾*//* Ver1.14*/
Sint32 syCfgGetBroadcastType( Sint32* ) ;   /* �����`���擾         */

Sint32 syCfgGetIndividualID( Sint8* ) ;     /* �ő̎��ʔԍ�         */

#ifdef __cplusplus
}                                           /* for C++ Interface    */
#endif /* __cplusplus  */
#endif /* _SG_SYCFG_H_ */
/****************************************** End of sg_sycfg.h *******/
