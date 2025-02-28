/********************************************************************/
/*                                                                  */
/*  Shinobi Scheduler Library Header(scheduler.h)                   */
/*                                                                  */
/*  98/02/13 r0.00                                                  */
/*  98/03/06 r0.01:update all                                       */
/*  98/05/07 r0.02:(1)�V�R�[�f�B���O��ɑΉ�                      */
/********************************************************************/

#ifndef _SG_SYSCD_H_
#define _SG_SYSCD_H_

/********************************************************************/
/*  �C���N���[�h�t�@�C��                                            */
/********************************************************************/
#include <machine.h>                        /*                      */
#include <sg_xpt.h>                         /* ���ʃw�b�_           */
#include <sg_int.h>                         /*                      */
#include "sg_syfbr.h"                       /* �t�@�C�o�w�b�_       */

/********************************************************************/
/*  �萔��`                                                        */
/********************************************************************/
#define SYD_SCD_CPUMAX (0xFFFFFFFF)      /* CPU���蓖�Ď��ԍő�l */

#define SYD_SCD_PROC_NONE (0)            /* null     */
#define SYD_SCD_PROC_EXEC (1)            /* ���s�\ */
#define SYD_SCD_PROC_EXIT (2)            /* exit     */

#define SYD_SCD_SLEEPFOREVER   ((Uint32)-1) /* �N�������܂ŃX���[�v*/

#define SYD_SCD_OK   (0)
#define SYD_SCD_NG   (-1)
#define SYD_SCD_NULL (NULL)
#define SYD_SCD_MINFIBER (1)

/********************************************************************/
/*  �^��`                                                          */
/********************************************************************/
/* �֐��o�^���         */
typedef struct SyScdS_FuncAttr_tag{
    Uint32 lOrder  ;                        /* �o�^����  0:�Ō�ɒǉ� / 1�`:�w�肵���ʒu�ɒǉ� */
    void*  lParam   ;                       /* �t�@�C�o�N�����ɓn���p�����[�^  */
    void*  pStack   ;                       /* �t�@�C�o���g�p����X�^�b�N�G���A*/
    Uint32 lStackSize;                      /* �t�@�C�o�̃X�^�b�N�T�C�Y        */
    Uint32 lTime    ;                       /* CPU�ő劄�蓖�Ď���             */
}SYS_SCD_FUNCATTR ;                           /* 0  :������:����CPU��������܂�  */
                                            /* 1�`SyScdYCPUTIME_MAX:100u�b�P�� */
/* �t�@�C�o���         */
typedef struct SyScdS_FiberObj_tag{
    SYFBR   hFiber ;                        /* �X�P�W���[�����O����t�@�C�o�̃n���h�� */
    Uint32  lTime  ;                        /* CPU�ő劄�蓖�Ď���             */
    Uint32  lStat  ;                        /* �t�@�C�o�̏��(���s��,���s�\,...)*/
    Uint32  lExec  ;                        /* �X���[�v�J�E���g�i���Ɖ���҂��j*/
}SYS_SCD_FIBEROBJ;

/* �X�P�W���[���e�[�u�� */
typedef struct SyScdTblObj_tag{
/*  Bool    bUsed     ;                   */ /* �g�p���t���O(0:���g�p 1:�g�p��)  */
    Sint32  sFiberMax ;                     /* �t�@�C�o�o�^�ő吔               */
    Sint32  sFiberNum ;                     /* �t�@�C�o�o�^��                   */
    Sint32  sCurrent  ;                     /* ���s���̃t�@�C�o�ԍ�             */
    SYFBR   hFiberMain ;                    /* �X�P�W���[���̃t�@�C�o           */
    SYS_SCD_FIBEROBJ fibers[1];             /* �o�^���ꂽ�t�@�C�o��� */
} SYS_SCD_TBLOBJ;

/* �n���h���̒�`       */
typedef SYS_SCD_TBLOBJ* SYSCD ;                /* �X�P�W���[���n���h�� */

/********************************************************************/
/*  �֐��}�N��  �@�@                                                */
/********************************************************************/
                                    /* x�̃t�@�C�o�𓮍삳���邽�߂̃o�b�t�@��*/
#define SYD_SCD_BUFSIZE(x)   (sizeof(SYS_SCD_TBLOBJ)+ \
                              ((x)-1) * sizeof(SYS_SCD_FIBEROBJ))


/********************************************************************/
/*  �֐���`                                                        */
/********************************************************************/
#ifdef __cplusplus
extern "C"{                                 /* for C++ Interface    */
#endif  /* __cplusplus */

extern  Sint32      syScdInit   ( void ) ;
extern  void        syScdFinish ( void ) ;
extern  SYSCD       syScdCreate ( void*, Sint32 ) ;
extern  Sint32      syScdDelete ( SYSCD ) ; 

extern  Sint32      syScdAddFunc( SYSCD, void (*func)(void*),SYS_SCD_FUNCATTR*, SYFBR* ) ;
extern  Sint32      syScdSleep  ( SYSCD, Uint32) ; 
extern  Sint32      syScdWakeupFiber( SYSCD, SYFBR) ; 
extern  Sint32      syScdExit   ( SYSCD ) ;
extern  Sint32      syScdExecyte( SYSCD ) ;
extern  void        syScdTerminateFiber( SYSCD ) ;

extern  void        syScdSaveContext( void ) ;
extern  void        syScdJumpContext( void ) ;

#ifdef __cplusplus
}                                           /* for C++ Interface    */
#endif /* __cpulspuls  */

#endif /* __SG_SYSCD_H__ */
/********************************************* End of sg_syscd.h *******/
