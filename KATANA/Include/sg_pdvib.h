/*
 *  Shinobi Library
 *  Copyright (c) 1998 SEGA
 *
 *       PERIPHERAL VIBRATOR
 *
 *  Module  : Library Header File
 *  File    : sg_pdvib.h
 *  Create  : 1999-1-18
 *  Modify  :
 *  Version : 1.00
 *  Note    :
 */

#ifndef _SG_PDVIB_H_
#define _SG_PDVIB_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <sg_xpt.h>

/*
 *  DEFINES / MACROS
 */

/******** �G���[�R�[�h *****************************************************/
/******** Error code *******************************************************/
#define PDD_VIBERR_OK           0        /* �G���[�Ȃ�                     */
                                         /* No error                       */
#define PDD_VIBERR_BUSY        (-1)      /* �R�}���h������                 */
                                         /* Busy                           */
#define PDD_VIBERR_NO_VIBRATOR (-2)      /* �U���f�o�C�X���ڑ�����Ă��Ȃ� */
                                         /* No vibrator is connected       */
#define PDD_VIBERR_INVALID     (-3)      /* �w�肳�ꂽ�p�����[�^�͖���     */
                                         /* Invalid parameter              */

/******** �f�o�C�X�̌��� ***************************************************/
/******** Direction of device **********************************************/
#define PDD_VIB_DIRECTION_NORMAL   0     /* �ʏ�                           */
                                         /* Normal                         */
#define PDD_VIB_DIRECTION_FLIP     1     /* 180�x��](�t����)              */
                                         /*                                */
#define PDD_VIB_DIRECTION_LEFT     2     /* ��90�x��]                     */
                                         /*                                */
#define PDD_VIB_DIRECTION_RIGHT    3     /* �E90�x��]                     */
                                         /*                                */

/******** �U���t���O *******************************************************/
/******** flags ************************************************************/
#define PDD_VIB_FLAG_CONTINUOUS  (1 << 0)    /* �A���U��                   */
                                             /* Continuous vibration       */
#define PDD_VIB_FLAG_EXHALATION  (1 << 3)    /* ���U�w��                   */
                                             /* Exhalation vibration       */
#define PDD_VIB_FLAG_CONVERGENCE (1 << 7)    /* �����w��                   */
                                             /* Convergence vibration      */

/******** �U�����j�b�g�ʒu *************************************************/
/******** Vibrator unit position *******************************************/
#define PDD_VIB_POS_FRONT 0              /* �f�o�C�X�O��                   */
                                         /* Front of the device            */
#define PDD_VIB_POS_BACK  1              /* �f�o�C�X�㕔                   */
                                         /* Back of the device             */
#define PDD_VIB_POS_LEFT  2              /* �f�o�C�X����                   */
                                         /* Left of the device             */
#define PDD_VIB_POS_RIGHT 3              /* �f�o�C�X�E��                   */
                                         /* Right of the device            */

/******** �U���� ***********************************************************/
/******** Vibration axis ***************************************************/
#define PDD_VIB_AXIS_NONE 0              /* ���Ȃ�                         */
                                         /* No axis                        */
#define PDD_VIB_AXIS_X    1              /* X��                            */
                                         /* X axis                         */
#define PDD_VIB_AXIS_Y    2              /* Y��                            */
                                         /* Y Axis                         */
#define PDD_VIB_AXIS_Z    3              /* Z��                            */
                                         /* Z Axis                         */

/******** �R�[���o�b�N�֐����^�[���l ***************************************/
#define PDD_VIBRET_OK     0              /* �p��                           */
                                         /* Continue enumeration           */


/*
 *  TYPEDEFS
 */

/******** �U���p�����[�^�\���� *********************************************/
/******** Vibration parameter structure ************************************/
typedef struct {
	Uint8 unit;                          /* ���j�b�g�ԍ�                   */
	                                     /* Unit number                    */
	Uint8 flag;                          /* �U���t���O                     */
	                                     /* Vibration flag                 */
	Sint8 power;                         /* ����                           */
	                                     /* Power                          */
	Uint8 freq;                          /* �U�����g��                     */
	                                     /* Frequency                      */
	Uint8 inc;                           /* �U�����z����                   */
	                                     /*                                */
	Uint8 reserved[3];                   /* �\��                           */
	                                     /* Reserved                       */
} PDS_VIBPARAM;

/******** �U���f�o�C�X���\���� *******************************************/
/******** Vibration device information structure ***************************/
typedef struct {
	Uint8 units;                         /* ���j�b�g��                     */
	                                     /* Number of units                */
	Uint8 se_units;                      /* �����U���ݒ�\���j�b�g��     */
	                                     /* Number of ...                  */
} PDS_VIBINFO;

/******** �U�����j�b�g���\���� *******************************************/
/******** Vibration unit information structure *****************************/
typedef struct {
	Uint8 position;                      /* �U�����j�b�g�ʒu               */
	                                     /* Vibration unit position        */
	Uint8 axis;                          /* �U����                         */
	                                     /* Vibration axis                 */
	Uint8 pow_enable;                    /* �U�����x�σt���O             */
	                                     /* Is power variable ?            */
	Uint8 cont_enable;                   /* �A���U���t���O                 */
	                                     /* Is continuous ?                */
	Uint8 dir_enable;                    /* �����w��t���O                 */
	                                     /* ...                            */
	Uint8 wave_enable;                   /* �C�ӐU���g�`�t���O             */
	                                     /* ...                            */
	Uint8 min_freq;                      /* �ŏ��U�����g��                 */
	                                     /* Minimum frequency              */
	Uint8 max_freq;                      /* �ő�U�����g��                 */
	                                     /* Maximum frequency              */
} PDS_VIBUNITINFO;

/******** �R�[���o�b�N�֐��^ ***********************************************/
/******** Callback function type *******************************************/
typedef Sint32 (*PD_VIBCALLBACK)(Sint32 stat, Uint32 param);
typedef Sint32 (*PD_VIBENUMUNITCALLBACK)(Uint32 unit, Sint32 stat,
									PDS_VIBUNITINFO* info, Uint32 param);


/*
 *  PROTOTYPES
 */

/******** maxi��p����y�֐� ***********************************************/
/******** Easy vibration functions for Puru-puru pack **********************/
Sint32 pdVibMxIsReady(Uint32 port);
Sint32 pdVibMxSetStopTime(Uint32 port, Uint32 time);
Sint32 pdVibMxStart(Uint32 port, const PDS_VIBPARAM* param);
Sint32 pdVibMxStop(Uint32 port);


/******** �ėp�U���֐� *****************************************************/
/******** Vibration functions **********************************************/
Sint32 pdVibIsReady(Uint32 port);
Sint32 pdVibGetDirection(Uint32 port);
Sint32 pdVibSetStopTime(Uint32 port, Uint8* unit, Uint8* time, Uint32 num);
Sint32 pdVibStart(Uint32 port, const PDS_VIBPARAM* param, Uint32 numunits);
Sint32 pdVibSetWave(Uint32 port, Uint32 unit, const void* wave, Uint32 num);
Sint32 pdVibGetInfo(Uint32 port, PDS_VIBINFO* info);
Sint32 pdVibEnumerateUnit(Uint32 port, PD_VIBENUMUNITCALLBACK func,
																Uint32 param);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SG_PDVIB_H_ */

