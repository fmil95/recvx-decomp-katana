/********************************************************************
 *  Shinobi Library
 *  Copyright (c) 1998-1999 SEGA
 *
 *  Library : Dreamcast Demo System Library
 *  Module  : Library Interface Header
 *  File    : sg_syDds.h
 *  Date    : 1999-03-17
 *  Version : 1.00
 *
 ********************************************************************/

#ifndef _SG_SYDDS_H_
#define _SG_SYDDS_H_

/********************************************************************/
/*  �C���N���[�h�t�@�C��                                            */
/*   inlcude files                                                  */
/********************************************************************/
#include    <sg_xpt.h>                      /*                      */

/********************************************************************/
/*  �萔��`                                                        */
/*  constants                                                       */
/********************************************************************/
#define SYD_DDS_OK                (0)          /*                    */
#define SYD_DDS_ERR               (-1)         /*                    */
/********************************************************************/
/*  �֐���`                                                        */
/*  functions                                                       */
/********************************************************************/
#ifdef __cplusplus
extern "C"{                                 /* for C++ Interface    */
#endif  /* __cplusplus */

Sint32 syDdsSetAppDir( Sint8 *AppDir );
Sint32 syDdsSetAppTno( Sint8 AppTno );
Void syDdsExit( void );

#ifdef __cplusplus
}                                           /* for C++ Interface    */
#endif /* __cplusplus  */
#endif /* _SG_SYDDS_H_ */
/****************************************** End of sg_syDds.h *******/
