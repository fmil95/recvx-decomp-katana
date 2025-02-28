/********************************************************************
 *  Shinobi Library
 *  Copyright (c) 1998-1999 SEGA
 *
 *  Library : fiber library (very simple thread library)
 *  Module  : Library Interface Header
 *  File    : sg_syfbr.h
 *  Date    : 1999-01-21
 *  Version : 1.11
 *  History : 98/02/06 r0.00
 *            98/05/04 r0.04 ���ʎq�̖��̓���                       
 *            98/05/04 r0.05 �t�@�C�o�e�[�u�������[�U����擾����   
 *            98/11/20 r1.10 syFbrPreInit/syFbrExit/syFbrSetIntStack�̒�`
 ******************************************************************/

#ifndef _SG_SYFBR_H_
#define _SG_SYFBR_H_

/********************************************************************/
/*  �C���N���[�h�t�@�C��                                            */
/*  include files                                                   */
/********************************************************************/
#include    <sg_xpt.h>                      /*                      */
#include    <sg_ov.h>                       /*                      */

/********************************************************************/
/*  �萔��`                                                        */
/*  constants                                                       */
/********************************************************************/
#ifdef SYD_FBR_FIXEDTBL                       							/* not used */                        
#define SYD_FBR_MAXFIBER    	(32)         /* �t�@�C�o�̏���l    */  /* not used */
#endif                                                                  /* not used */

#define SYD_FBR_MINFIBER    	(2)          /* �t�@�C�o�̉����l    */

#define SYD_FBR_NULL        	(NULL)       /* �t�@�C�o�n���h���G���[�l*/
#define SYD_FBR_OK          	(0)          /* �t�@�C�o�֐��߂�l  */
#define SYD_FBR_NG          	(-1)         /* �t�@�C�o�֐��߂�l  */

#define SYD_FBR_NOTSETED        (-1)
#define SYD_FBR_THREADTOCREATE  (-1)									/* not used */
#define SYD_FBR_NOTEXISTFIBER   (-1)         /* �t�@�C�o������       */
                                             /* ��t�@�C�o�n���h���l */
#define SYD_FBR_SYSSTACKSIZE (292)           /* �V�X�e�����K�v�Ƃ���X�^�b�N */
											 /* system data size in stack */
#define SYD_FBR_LID {   \
    0x77b9fee0,         \
    0xe397,0x11d1,      \
    0x9a,0xb0,0x00,0xa0,\
    0x24,0xd8,0x60,0x79 \
} ;

/********************************************************************/
/*  �^��`                                                          */
/*  structure/union/enum                                            */
/********************************************************************/
typedef struct SyFbrS_INFO_tag{             /* �t�@�C�o���         */
    void*       sp ;                        /* �t�@�C�o�̃X�^�b�N�|�C���^(fiber's stack pointer) */
    void*       data ;                      /* �t�@�C�o�̃f�[�^          (fiber's data)          */
} SYS_FBR_INFO; 
typedef SYS_FBR_INFO*    SYFBR ;            /* �t�@�C�o�n���h��     */
                                            /* fiber handle type    */
typedef void (*SyFbrYfunc)(void*) ;         /* �t�@�C�o�֐��^       */
                                            /* fiber function type  */
#define SYD_FBR_FBRSIZE (sizeof(SYS_FBR_INFO))

/********************************************************************/
/*  �L��ϐ���`                                                    */
/*  global valiables                                                */
/********************************************************************/
#ifdef  SYD_FBR_FIXEDTBL                    /*                      */ /* not used */
extern SYS_FBR_INFO sygFbrTbl[] ;           /* �t�@�C�o�e�[�u��     */ /* not used */
#else                                       /*                      */ /* not used */
extern SYS_FBR_INFO* sygFbrTblPtr ;         /* �t�@�C�o�e�[�u���|�C���^*/
                                            /* pointer to fiber table  */
#endif                                      /*                      */
extern Sint32      sygFbrMaxFiber ;         /* �ő�t�@�C�o��       */
                                            /* max number of fiber  */
extern SYFBR       sygFbrCurrent ;          /* ���݂̃t�@�C�o       */
                                            /* current fiber handle */
extern const UUID sygFbrLID ;               /* ���C�u�����h�c       */ /* not used */

/********************************************************************/
/*  �֐���`                                                        */
/*  functions                                                       */
/********************************************************************/

#ifdef __cplusplus
extern "C"{                                 /* for C++ Interface    */
#endif  /* __cplusplus */

#ifdef SYD_FBR_FIXEDTBL                                              
extern  Sint32  syFbrInit( void ) ;
#else                                                                
extern  Sint32  syFbrInit( void*, Sint32) ;                          
#endif                                                               

extern  Sint32  syFbrPreInit( Sint32*, int );                        /* r1.10 */
extern  Sint32  syFbrExit( Void ) ;                                  /* r1.10 */
extern  Sint32  syFbrSetIntStack( void* ) ;                          /* r1.10 */

extern  SYFBR   syFbrCreateFiber( void*,Uint32,SyFbrYfunc,void* ) ;
extern  SYFBR   syFbrConvertThreadToFiber( void* ) ;
extern  Sint32  syFbrDeleteFiber    ( SYFBR ) ;
extern  SYFBR   syFbrGetCurrentFiber( void ) ;
extern  void*   syFbrGetFiberData   ( void ) ;

extern  void*   syFbrCreateFiberMain(void*,long,SyFbrYfunc,void* ) ;
extern  void    syFbrSwitchToFiber        ( SYFBR ) ;
extern  void    syFbrSwitchToFiber2       ( SYFBR ) ;
extern  void    syFbrDelayedSwitchToFiber ( SYFBR ) ;
extern  void    syFbrDelayedSwitchToFiber2( SYFBR ) ;

extern  void*   syFbrGetSp  (SYFBR) ;
extern  void*   syFbrGetData(SYFBR) ;
extern  void    syFbrSetSp  (SYFBR,void*) ;
extern  void    syFbrSetData(SYFBR,void*) ;

extern  SYS_FBR_INFO*   syFbrGetTblPtr( int n ) ;                    
extern  Sint32  syFbrGetMaxFiber( void ) ;                           
extern  void*   syFbrGet_fib_sp ( int i) ;

#if 0
extern  void*   get_fib_data(int i) ;
extern  void    set_fib_sp  (int i, void* sp) ;
extern  void    set_fib_data(int i, void* data) ;
#endif

extern  void    syFbrDumpTable( void ) ;

#ifdef __cplusplus
}                                           /* for C++ Interface    */
#endif /* __cpulspuls  */
#endif /* __SG_FB_H__ */
/********************************************* End of fiber.h *******/
