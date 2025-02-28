/*
 *  Shinobi Library
 *  Copyright (c) 1998 SEGA
 *  
 *       SH4 Timer 
 *
 *  Module  : Library Header File
 *  File    : sg_tmr.h
 *  Create  : 1998-03-03
 *  Modify  : 1998-06-05
 *  Version : 1.00
 *  Note    :
 */


#ifndef _SG_TMU_H_
#define _SG_TMU_H_


#include <sg_sytmr.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/******* �G���[�R�[�h ******************************************************/
#define SYD_TMR_ERR_OK          (0)         /* �G���[�Ȃ�                  */
#define SYD_TMR_ERR_EXIST       (-1)        /* ���ɓo�^����Ă���          */

/******* �֐��v���g�^�C�v **************************************************/
/*------- �t���[�����^�C�}�֐� -------*/
void syTmrSetClock(SY_TMR_CLOCK);

/*------- �^�C�}1�֐� for Core library (or Scaduler Library) -------*/
Sint32 syTmrInt1Set(Uint32, void(*)(void *), void *);
void syTmrInt1Cancel(void);
Sint32 syTmrInt1SetEx(Uint32, void(*)(void *), void *, SY_TMR_CLOCK);

/*------- �^�C�}2�֐� -------*/
Sint32 syTmrInt2Set(Uint32, void(*)(void *), void *);
void syTmrInt2Cancel(void);
Sint32 syTmrInt2SetEx(Uint32, void(*)(void *), void *, SY_TMR_CLOCK);

#ifdef __cplusplus
	   }
#endif /* __cplusplus */

#endif /* _SG_TMU_H_ */

/******************************* end of file *******************************/
