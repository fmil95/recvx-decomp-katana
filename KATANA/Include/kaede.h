/*
 *  Shinobi Library
 *  Copyright (c) 1998 SEGA
 *
 *       Maple Driver
 *
 *  Module  : Library Header File
 *  File    : kaede.h
 *  Create  : 1998-03-25
 *  Modify  : 1999-01-19
 *  Version : 1.43
 *  Note    :
 */


#ifndef _KAEDE_H_
#define _KAEDE_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * C VIRTUAL TYPES DEFINITIONS
 */

#include <sg_xpt.h>


/*
 * GLOBAL DEFINES/MACROS DEFINES
 */

/******** �f�o�C�X�ő吔 ***************************************************/
#define KDD_DEV_MAX 24


/******** �f�o�C�X�ԍ���` *************************************************/
#define KDD_DEV_0      0                      /* �f�o�C�X  0               */
#define KDD_DEV_1      1                      /* �f�o�C�X  1               */
#define KDD_DEV_2      2                      /* �f�o�C�X  2               */
#define KDD_DEV_3      3                      /* �f�o�C�X  3               */
#define KDD_DEV_4      4                      /* �f�o�C�X  4               */
#define KDD_DEV_5      5                      /* �f�o�C�X  5               */
#define KDD_DEV_6      6                      /* �f�o�C�X  6               */
#define KDD_DEV_7      7                      /* �f�o�C�X  7               */
#define KDD_DEV_8      8                      /* �f�o�C�X  8               */
#define KDD_DEV_9      9                      /* �f�o�C�X  9               */
#define KDD_DEV_10    10                      /* �f�o�C�X  10              */
#define KDD_DEV_11    11                      /* �f�o�C�X  11              */
#define KDD_DEV_12    12                      /* �f�o�C�X  12              */
#define KDD_DEV_13    13                      /* �f�o�C�X  13              */
#define KDD_DEV_14    14                      /* �f�o�C�X  14              */
#define KDD_DEV_15    15                      /* �f�o�C�X  15              */
#define KDD_DEV_16    16                      /* �f�o�C�X  16              */
#define KDD_DEV_17    17                      /* �f�o�C�X  17              */
#define KDD_DEV_18    18                      /* �f�o�C�X  18              */
#define KDD_DEV_19    19                      /* �f�o�C�X  19              */
#define KDD_DEV_20    20                      /* �f�o�C�X  20              */
#define KDD_DEV_21    21                      /* �f�o�C�X  21              */
#define KDD_DEV_22    22                      /* �f�o�C�X  22              */
#define KDD_DEV_23    23                      /* �f�o�C�X  23              */

#define KDD_DEV_A0     0                      /* �f�o�C�X  0               */
#define KDD_DEV_A1     1                      /* �f�o�C�X  1               */
#define KDD_DEV_A2     2                      /* �f�o�C�X  2               */
#define KDD_DEV_A3     3                      /* �f�o�C�X  3               */
#define KDD_DEV_A4     4                      /* �f�o�C�X  4               */
#define KDD_DEV_A5     5                      /* �f�o�C�X  5               */
#define KDD_DEV_B0     6                      /* �f�o�C�X  6               */
#define KDD_DEV_B1     7                      /* �f�o�C�X  7               */
#define KDD_DEV_B2     8                      /* �f�o�C�X  8               */
#define KDD_DEV_B3     9                      /* �f�o�C�X  9               */
#define KDD_DEV_B4    10                      /* �f�o�C�X  10              */
#define KDD_DEV_B5    11                      /* �f�o�C�X  11              */
#define KDD_DEV_C0    12                      /* �f�o�C�X  12              */
#define KDD_DEV_C1    13                      /* �f�o�C�X  13              */
#define KDD_DEV_C2    14                      /* �f�o�C�X  14              */
#define KDD_DEV_C3    15                      /* �f�o�C�X  15              */
#define KDD_DEV_C4    16                      /* �f�o�C�X  16              */
#define KDD_DEV_C5    17                      /* �f�o�C�X  17              */
#define KDD_DEV_D0    18                      /* �f�o�C�X  18              */
#define KDD_DEV_D1    19                      /* �f�o�C�X  19              */
#define KDD_DEV_D2    20                      /* �f�o�C�X  20              */
#define KDD_DEV_D3    21                      /* �f�o�C�X  21              */
#define KDD_DEV_D4    22                      /* �f�o�C�X  22              */
#define KDD_DEV_D5    23                      /* �f�o�C�X  23              */

/******** �|�[�g�ԍ���` ***************************************************/
#define KDD_PORT_A    0                       /* �|�[�gA                   */
#define KDD_PORT_B    1                       /* �|�[�gB                   */
#define KDD_PORT_C    2                       /* �|�[�gC                   */
#define KDD_PORT_D    3                       /* �|�[�gD                   */

/******** �t�@���N�V������` ***********************************************/
#define KDD_FUNC_CONTROLLER     0x00000001  /* �W���R���g���[��            */
#define KDD_FUNC_STORAGE        0x00000002  /* �X�g���[�W                  */
#define KDD_FUNC_LCD            0x00000004  /* LCD                         */
#define KDD_FUNC_TIMER          0x00000008  /* �^�C�}                      */
#define KDD_FUNC_SOUNDINPUT     0x00000010  /* ��������                    */
#define KDD_FUNC_ARGUN          0x00000020  /* AR-Gun                      */
#define KDD_FUNC_KEYBOARD       0x00000040  /* �L�[�{�[�h                  */
#define KDD_FUNC_LIGHTGUN       0x00000080  /* Light-Gun                   */
#define KDD_FUNC_VIBRATION      0x00000100  /* �U��                        */

/******** ���X�|���X�R�[�h *************************************************/
#define KDD_RES_DEVICESTATUS       0x05   /* Device Status                 */
#define KDD_RES_DEVICEALLSTATUS    0x06   /* Device All Status             */
#define KDD_RES_DEVICEREPLY        0x07   /* Device Reply                  */
#define KDD_RES_DATATRANSFER       0x08   /* Data Transfer                 */
#define KDD_RES_NORESPONSE         0xff   /* �����Ȃ�                      */
#define KDD_RES_FUNCTIONUNKNOWN    0xfe   /* Function Type Unknown         */
#define KDD_RES_COMMANDUNKNOWN     0xfd   /* Command Unknown               */
#define KDD_RES_TRANSMITAGAIN      0xfc   /* Transmit Again                */
#define KDD_RES_FILEERROR          0xfb   /* File Error                    */
#define KDD_RES_LCDERROR           0xfa   /* LCD Error                     */
#define KDD_RES_ARERROR            0xf9   /* AR Error                      */

/******** �t�@���N�V�����G���[�R�[�h ***************************************/
#define KDD_ERR_OK            0           /* �G���[�Ȃ�                    */
#define KDD_ERR_PARTITION     (1 << 0)    /* �p�[�e�B�V�����G���[          */
#define KDD_ERR_PHASE         (1 << 1)    /* �t�F�C�Y�G���[                */
#define KDD_ERR_BLOCK         (1 << 2)    /* �u���b�N�G���[                */
#define KDD_ERR_WRITE         (1 << 3)    /* ���C�g�G���[                  */
#define KDD_ERR_LENGTH        (1 << 4)    /* �f�[�^���G���[                */
#define KDD_ERR_CRC           (1 << 5)    /* CRC�G���[                     */

/******** �G���A�R�[�h *****************************************************/
#define KDD_AREA_USA          (1 << 0)    /* �k�A�����J�n��                */
#define KDD_AREA_JAPAN        (1 << 1)    /* ���{�n��                      */
#define KDD_AREA_ASIA         (1 << 2)    /* �A�W�A�n��                    */
#define KDD_AREA_EUROPE       (1 << 3)    /* ���[���b�p�n��                */
#define KDD_AREA_RESERVED1    (1 << 4)    /* �\��n��1                     */
#define KDD_AREA_RESERVED2    (1 << 5)    /* �\��n��2                     */
#define KDD_AREA_RESERVED3    (1 << 6)    /* �\��n��3                     */
#define KDD_AREA_RESERVED4    (1 << 7)    /* �\��n��4                     */

/******** �R�l�N�^�ڑ����� *************************************************/
#define KDD_CONDIR_TOPSIDE      0         /* ��                            */
#define KDD_CONDIR_BOTTOMSIDE   1         /* ��                            */
#define KDD_CONDIR_LEFTSIDE     2         /* ��                            */
#define KDD_CONDIR_RIGHTSIDE    3         /* �E                            */

/******** ���[�h�^�C�v�萔 *************************************************/
#define KDD_MODE_OPTIMIZE    0            /* �œK�����[�h                  */
#define KDD_MODE_NOPCOUNT    1            /* NOP�}����                   */
#define KDD_MODE_TIMEOUT     2            /* �^�C���A�E�g�܂ł̎���        */
#define KDD_MODE_SPEED       3            /* �ʐM���x                      */
#define KDD_MODE_DREQCOUNT   4            /* �g���f�o�C�X�ւ�Dev.Req.��  */
#define KDD_MODE_DEVENDIAN   5            /* �f�o�C�X�G���f�B�A��          */
#define KDD_MODE_DEBUG       6            /* �f�o�b�O���[�h                */
#define KDD_MODE_ROOTPLAY    7            /* ROOT�f�o�C�XT.O.���e��      */
#define KDD_MODE_GUNMODE     8            /* �K�����[�h                    */
#define KDD_MODE_AUTOFLASH   9            /* �K�����[�h���̎����t���b�V��  */

/******** �œK�����[�h *****************************************************/
#define KDD_OPTIMIZE_NONE   0             /* �œK���Ȃ�                    */
#define KDD_OPTIMIZE_8MS    1             /* VBlank In��O8ms�ŊJ�n        */
#define KDD_OPTIMIZE_4MS    2             /* VBlank In��O4ms�ŊJ�n        */
#define KDD_OPTIMIZE_2MS    3             /* VBlank In��O2ms�ŊJ�n        */
#define KDD_OPTIMIZE_1MS    4             /* VBlank In��O1ms�ŊJ�n        */

/******** �ʐM���x *********************************************************/
#define KDD_SPEED_2MBPS   0x00000000      /* 2MBPS                         */
#define KDD_SPEED_1MBPS   0x00000100      /* 1MBPS                         */
#define KDD_SPEED_4MBPS   0x00000200      /* 4MBPS                         */
#define KDD_SPEED_8MBPS   0x00000300      /* 8MBPS                         */

/******** �K�����[�h *******************************************************/
#define KDD_GUNMODE_OFF   0x00000000      /* �ʏ탂�[�h                    */
#define KDD_GUNMODE_A     0x00000001      /* PORT A�K�����[�h              */
#define KDD_GUNMODE_B     0x00000002      /* PORT B�K�����[�h              */
#define KDD_GUNMODE_C     0x00000004      /* PORT C�K�����[�h              */
#define KDD_GUNMODE_D     0x00000008      /* PORT D�K�����[�h              */
#define KDD_GUNMODE_ALL   0x0000000f      /* �S�|�[�g�K�����[�h            */

/******** �f�o�C�X�G���f�B�A�� *********************************************/
#define KDD_DEVENDIAN_LITTLE   0          /* ���g���G���f�B�A��            */
#define KDD_DEVENDIAN_BIG      1          /* �r�b�O�G���f�B�A��            */

/******** �f�o�b�O *********************************************************/
#define KDD_DEBUG_OFF   0                 /* �f�o�b�OOFF                   */
#define KDD_DEBUG_ON    1                 /* �f�o�b�OON                    */

/******** �|�[�g�Ǘ��\���� *************************************************/
typedef struct {
	Uint8 lmon;                 /* �����ڑ���ԃr�b�g                      */
	Uint8 lmold;                /* �O�t���[���ł̕����ڑ���ԃr�b�g        */
	Uint8 lmcon;                /* �����ڑ���� OFF->ON �ω��r�b�g         */
	Uint8 lmremv;               /* �����ڑ���� ON->OFF �ω��r�b�g         */
	Uint32 playcount;           /* �\��                                    */
} KDS_PORT;

/******** �f�o�C�X�Ǘ��\���� ***********************************************/
typedef struct {
	Uint8 on;                   /* �_���ڑ���ԃt���O                      */
	Uint8 old;                  /* �O�t���[���ł̘_���ڑ����              */
	Uint8 connect;              /* �_���ڑ���� OFF->ON�ω��t���O          */
	Uint8 remove;               /* �_���ڑ���� ON->OFF�ω��t���O          */
	Uint8 response;             /* ���X�|���X�R�[�h                        */
	Uint8 dst_ap;               /* �]����AP                                */
	Uint8 src_ap;               /* �]����AP                                */
	Uint8 datasize;             /* �f�[�^�T�C�Y(�����O���[�h��)            */
	void* recvdata;             /* ��M�f�[�^�̃A�h���X                    */
	Sint32 errcode;             /* �t�@���N�V�����G���[�R�[�h              */
	Uint32 reserved[2];         /* �\��                                    */
} KDS_DEVICE;

/******** �f�o�C�X���\���� ***********************************************/
typedef struct {
	Uint32 function;            /* �t�@���N�V����                          */
	Uint8 fd[3][4];             /* �t�@���N�V������`�u���b�N�f�[�^        */
	Uint8 is_root;              /* ���[�g�f�o�C�X���ǂ�����\��            */
	Uint8 area_code;            /* �G���A�R�[�h                            */
	Uint8 connector_dir[2];     /* �g���R�l�N�^����                        */
	char product_name[32];      /* ���i��                                  */
	char license[64];           /* ���C�Z���X                              */
	Uint16 stdby_pow;           /* �X�^���o�C����d��                      */
	Uint16 max_pow;             /* �ő����d��                            */
} KDS_DEVICEINFO;

/******** �R���g���[�����\���� *******************************************/
typedef struct {
	Uint32 button;              /* �����Ă���{�^��                        */
} KDS_CONTROLLERINFO;

/******** LCD���\���� ****************************************************/
#define KDD_LCD_NORMALLYWHITE 0 /* Normally White                          */
#define KDD_LCD_NORMALLYBLACK 1 /* Normally Black                          */
#define KDD_LCD_HV_00         0 /* �f�[�^���т̓^�C�v'00'                  */
#define KDD_LCD_HV_01         1 /* �f�[�^���т̓^�C�v'01'                  */
#define KDD_LCD_HV_10         2 /* �f�[�^���т̓^�C�v'10'                  */
#define KDD_LCD_HV_11         3 /* �f�[�^���т̓^�C�v'11'                  */

typedef struct {
	Uint16 partition;           /* �p�[�e�B�V������                        */
	Uint16 blocksize;           /* 1�u���b�N�̃o�C�g��                     */
	Uint16 writecount;          /* 1�u���b�N���C�g��                     */
	Uint8  direction;           /* �s�N�Z���̕���H/V                       */
	Uint8  normally;            /* Normally Black/White                    */
} KDS_LCDINFO;

/******** �X�g���[�W���\���� *********************************************/
#define KDD_STORAGE_REMOVABLE 1 /* �����[�o�u�����f�B�A�ł���              */

typedef struct {
	Uint16 partition;           /* �p�[�e�B�V������                        */
	Uint16 blocksize;           /* 1�u���b�N�̃o�C�g��                     */
	Uint16 writecount;          /* 1�u���b�N���C�g��                     */
	Uint16 readcount;           /* 1�u���b�N���[�h��                     */
	Uint16 removable;           /* �����[�o�u�����f�B�A���ǂ���            */
	Uint16 reserved;            /* �\��                                    */
} KDS_STORAGEINFO;

/******** �^�C�}���\���� *************************************************/
typedef struct {
	Uint8 write_timer;          /* �������݉\�^�C�}                      */
	Uint8 read_timer;           /* �ǂݍ��݉\�^�C�}                      */
	Uint8 button;               /* �����Ă���{�^��                        */
	Uint8 alarm;                /* �����Ă���A���[��                      */
} KDS_TIMERINFO;

/******** SIP���\���� ****************************************************/
#define KDD_SIP_GETSAMPLINGDATA 1 /* Get Sampling Data�T�u�R�}���h������   */
#define KDD_SIP_BASICCONTROL    2 /* Basic Control�T�u�R�}���h������       */
#define KDD_SIP_AMPCONTROL      4 /* AMP Control�T�u�R�}���h������         */
#define KDD_SIP_TESTMODE        8 /* Test Mode�T�u�R�}���h������           */

typedef struct {
	Uint32 function;            /* �����Ă���@�\                          */
} KDS_SIPINFO;

/******** GUN���\���� ****************************************************/
typedef struct {
	Uint32 button;              /* �����Ă���{�^��                        */
} KDS_GUNINFO;

/******** �U�����\���� ***************************************************/
typedef struct {
	Uint32 vn;                  /* �U�����j�b�g�̌�                      */
	Uint32 se;                  /* �����ݒ�\�ȃ��j�b�g�̌�            */
} KDS_VIBRATIONINFO;

/******** �ʐM�󋵍\���� ***************************************************/
typedef struct {
	Uint32 send_count;          /* ���v���M��                            */
	Uint32 recv_count;          /* ���v��M��                            */
	Uint32 vbin_count;          /* VBlank���荞�݃n���h�����Ă΂ꂽ��    */
	Uint32 dmaend_count;        /* MPDMAE���荞�݃n���h�����Ă΂ꂽ��    */
	Uint32 cannot_send_count;   /* ���M�֐����G���[��Ԃ�����            */
	Uint32 blocked_count;       /* VBlank���荞�݃n���h�����u���b�N������*/
	Uint32 total_vover_count;   /* ���vVBlank�I�[�o�[��                  */
	Uint32 error_count[4];      /* ���v�G���[��(IA, OR, FIFO, COM)       */
	Uint16 send_line[2];        /* �ŐV�̑��M�X�^�[�gH���C��               */
	Uint16 recv_line[2];        /* �ŐV�̎�M���荞��H���C��               */
	Uint16 vover_count[2];      /* �ŐV�̑���M��VBlank�I�[�o�[��        */
} KDS_SYSTEMINFO;

/******** �K�����[�h�󋵍\���� *********************************************/
typedef struct {
	Uint32 enable;              /* �K�����[�h���ǂ���                      */
	Uint32 port;                /* �K�����[�h�ɐݒ肳��Ă���|�[�g        */
	Uint32 current_port;        /* �ŐV�̑���M�Ńf�[�^���X�V���ꂽ�|�[�g  */
	Uint32 last_port;           /* �O��̃|�[�g                            */
} KDS_GUNMODEINFO;



/******** �v���g�^�C�v *****************************************************/

/*------- �V�X�e���֐� ----------------------------------------------------*/
Sint32 kdInitSystem(void* recvbuf, void* sendbuf);
void kdExitSystem(void);
const KDS_SYSTEMINFO* kdGetSystemInfo(void);
Sint32 kdInitSystemEx(Sint32* devmap, void** recvbuf, void* sendbuf,
																Sint32 num);

/*------- �t���[���֐� ----------------------------------------------------*/
Sint32 kdMakeFrame(void);
Sint32 kdSendFrame(void);
Sint32 kdRecvFrame(void);

/*------- ���[�h�ݒ�֐� --------------------------------------------------*/
Sint32 kdSetDriverMode(Sint32 type, Sint32 mode);
Sint32 kdGetDriverMode(Sint32 type);

/*------- �f�o�C�X�Ǘ��֐� ------------------------------------------------*/
const KDS_DEVICE* kdGetDevice(Sint32 device);
const KDS_DEVICEINFO* kdGetDeviceInfo(Sint32 device);
const KDS_PORT* kdGetPortStatus(Sint32 port);
Sint32 kdGetStatus(Sint32 device, Sint32 seq);
Sint32 kdIsChanged(Sint32 device);
void kdRecognizeChanged(Sint32 device);

/*------- �R�}���h���s�֐� ------------------------------------------------*/
Sint32 kdSetDeviceRequest(Sint32 device);
Sint32 kdSetAllStatusRequest(Sint32 device);
Sint32 kdSetDeviceReset(Sint32 device);
Sint32 kdSetDeviceKill(Sint32 device);
Sint32 kdSetGetCondition(Sint32 device, Sint32 func);
Sint32 kdSetGetMediaInfo(Sint32 device, Sint32 func, Sint32 pt);
Sint32 kdSetBlockRead(Sint32 device, Sint32 func, Sint32 pt,
											Sint32 phase, Sint32 block);
Sint32 kdSetBlockWrite(Sint32 device, Sint32 func, Sint32 pt,
					Sint32 phase, Sint32 block, const void* src, Sint32 size);
Sint32 kdSetGetLastError(Sint32 device, Sint32 func, Sint32 pt,
											Sint32 phase, Sint32 block);
Sint32 kdSetARControl(Sint32 device, const void* buf);
Sint32 kdSetFT4Control(Sint32 device, const void* buf);
Sint32 kdSetSetCondition(Sint32 device, Sint32 func, const void* buf,
																Sint32 size);
Sint32 kdSetTransmitAgain(Sint32 device);
Sint32 kdSetResetPattern(Sint32 port);

/*------- �f�o�C�X�T�[�r�X�֐� --------------------------------------------*/
const Uint8* kdDevGetFD(const KDS_DEVICEINFO* dev, Uint32 func);
Sint32 kdDevGetControllerInfo(KDS_CONTROLLERINFO* sinfo,
											const KDS_DEVICEINFO* info);
Sint32 kdDevGetStorageInfo(KDS_STORAGEINFO* sinfo,
											const KDS_DEVICEINFO* info);
Sint32 kdDevGetSIPInfo(KDS_SIPINFO* sinfo, const KDS_DEVICEINFO* info);
Sint32 kdDevGetLCDInfo(KDS_LCDINFO* sinfo, const KDS_DEVICEINFO* info);
Sint32 kdDevGetTimerInfo(KDS_TIMERINFO* sinfo, const KDS_DEVICEINFO* info);
Sint32 kdDevGetGunInfo(KDS_GUNINFO* sinfo, const KDS_DEVICEINFO* info);
void kdGetGunPosition(Sint32* x, Sint32* y);
Sint32 kdGetGunLatchedPort(void);
void kdSetGunRapid(Uint32 port, Uint32 num);
Uint32 kdGetGunRapid(Uint32 port);
void kdSetGunTrigger(Uint32 port);
void kdSetGunCallback(Sint32 (*func)(void));

/*------- ���̑��̊֐� ----------------------------------------------------*/
void kdGetVersion(Sint32* major, Sint32* minor);
void kdSetHandler(Uint32 num, void (*func)(void));

/*------- �R�}���h���s�֐�(�R�[���o�b�N�t��) ------------------------------*/
typedef void (*KD_CALLBACK)(Sint32 device, Sint32 seqno,
								KDS_DEVICE* dev, KDS_DEVICEINFO* info);
Sint32 kdSetCallback(Sint32 device, KD_CALLBACK func, Sint32 seqno);
Sint32 kdSetDeviceRequestEx(Sint32 device, KD_CALLBACK cbfunc);
Sint32 kdSetAllStatusRequestEx(Sint32 device, KD_CALLBACK cbfunc);
Sint32 kdSetDeviceResetEx(Sint32 device, KD_CALLBACK cbfunc);
Sint32 kdSetDeviceKillEx(Sint32 device, KD_CALLBACK cbfunc);
Sint32 kdSetGetConditionEx(Sint32 device, Sint32 func, KD_CALLBACK cbfunc);
Sint32 kdSetGetMediaInfoEx(Sint32 device, Sint32 func, Sint32 pt,
														KD_CALLBACK cbfunc);
Sint32 kdSetBlockReadEx(Sint32 device, Sint32 func, Sint32 pt,
							Sint32 phase, Sint32 block, KD_CALLBACK cbfunc);
Sint32 kdSetBlockWriteEx(Sint32 device, Sint32 func, Sint32 pt, Sint32 phase,
			Sint32 block, const void* src, Sint32 size, KD_CALLBACK cbfunc);
Sint32 kdSetGetLastErrorEx(Sint32 device, Sint32 func, Sint32 pt,
							Sint32 phase, Sint32 block, KD_CALLBACK cbfunc);
Sint32 kdSetARControlEx(Sint32 device, const void* buf, KD_CALLBACK cbfunc);
Sint32 kdSetFT4ControlEx(Sint32 device, const void* buf, KD_CALLBACK cbfunc);
Sint32 kdSetSetConditionEx(Sint32 device, Sint32 func, const void* buf,
											Sint32 size, KD_CALLBACK cbfunc);
Sint32 kdSetTransmitAgainEx(Sint32 device, KD_CALLBACK cbfunc);
Sint32 kdSetResetPatternEx(Sint32 port, KD_CALLBACK cbfunc);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _KAEDE_H_ */

/******************************* end of file *******************************/
