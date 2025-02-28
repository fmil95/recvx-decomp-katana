/*
 *  Shinobi Library
 *  Copyright (c) 1998 SEGA
 *
 *       PERIPHERAL TIMER
 *
 *  Module  : Library Header File
 *  File    : sg_pdtmr.h
 *  Create  : 1998-07-03
 *  Modify  :
 *  Version : 1.00
 *  Note    :
 */

#ifndef _SG_PDTMR_H_
#define _SG_PDTMR_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <sg_xpt.h>

/*
 *  DEFINES / MACROS
 */

/******** �G���[�R�[�h *****************************************************/
#define PDD_TMRERR_OK          0           /* �G���[�Ȃ�                   */
                                           /* No error                     */
#define PDD_TMRERR_BUSY       (-1)         /* �R�}���h������               */
                                           /* Timer is busy                */
#define PDD_TMRERR_NO_TIMER   (-2)         /* �^�C�}���ڑ�����Ă��Ȃ�     */
                                           /* Timer is not connected       */
#define PDD_TMRERR_INVALID    (-3)         /* �w�肳�ꂽ�����͖���         */
                                           /* Time is invalid              */


/*
 *  TYPEDEFS
 */

/******** �����\���� *******************************************************/
typedef struct {
	Uint16 year;                /* �N year                                 */
	Uint8 month;                /* �� month                                */
	Uint8 day;                  /* �� day                                  */
	Uint8 hour;                 /* �� hour                                 */
	Uint8 minute;               /* �� minute                               */
	Uint8 second;               /* �b second                               */
	Uint8 dayofweek;            /* �j��(�� = 0,�� = 1, ... �y = 6)         */
	                            /* �ݒ莞�͗L���A�擾���͖���              */
	                            /* day of week(Sun = 0, Mon=1, ... Sat =6) */
	                            /* ...                                     */
} PDS_TIME;


/******** �R�[���o�b�N�֐� *************************************************/
/******** Callback function ************************************************/
typedef void (*PD_TIMERCALLBACK)(Sint32 stat, Uint32 param);


/*
 *  PROTOTYPES
 */

Sint32 pdTmrIsReady(Uint32 port);
Sint32 pdTmrSetTime(Uint32 port, const PDS_TIME* time,
							PD_TIMERCALLBACK func, Uint32 param);
Sint32 pdTmrGetTime(Uint32 port, PDS_TIME*,
							PD_TIMERCALLBACK func, Uint32 param);
Sint32 pdTmrAlarm(Uint32 port, Uint8* data);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SG_PDTMR_H_ */