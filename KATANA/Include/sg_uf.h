/*============================================================
 * Name  : sg_flash.h
 *
 * Desc  : �����t���b�V���������A�N�Z�X���C�u����
 	* Desc  : Internal Flash Memory Access Library
 *
 * prefix: uf / UFD / UFS
 *
 * $Id: sg_flash.h 1.2 1998/12/25 02:34:07 horita Exp horita $
 *
 * $Log: sg_flash.h $
 * Revision 1.2  1998/12/25 02:34:07  horita
 * �G���[�ԍ��̒ǉ�
 * UFD_ERR_PERIINITFAIL,	�y���t�F�����̏��������I����Ă��Ȃ�
 * UFD_ERR_REFRESHFAIL,		���t���b�V���Ɏ��s
 	* Adding Error Code
 	* UFD_ERR_PERIINITFAIL,	Peripheral Initialize not completed
 	* UFD_ERR_REFRESHFAIL, Fault in Flash Memory Refresh	
 *
 * Revision 1.1  1998/12/25 02:33:43  horita
 * Initial revision
 *
 * Revision 1.3  1998/12/14 05:05:34  horita
 * �I���֐�(ufExitSystem)�̒ǉ�
 	* Adding Exit function (ufExitSystem) 
 *
 * Revision 1.2  1998/11/17 01:16:35  horita
 * �\���̂̃^�O���ɐ����������B
 	* Adding explanation to structure tag names. 
 *
 * Revision 1.1  1998/11/16 02:26:31  horita
 * Initial revision
 *
 *============================================================*/

#ifndef __SG_FLASH_H__
#define __SG_FLASH_H__
/*============================================================
  Include
  ============================================================*/
#include <sg_xpt.h>

/*============================================================
  Define
  ============================================================*/
/* PlayTime�֐��̃��[�h */
	/* Mode of PlayTime function */
enum {
	UFD_SAVE, UFD_LOAD, UFD_PLAY
};

/* ChangeAutoSave�̃t���O�l */
	/* Value of the falg, ChangeAutoSave */
enum {
	UFD_OFF,
	UFD_ON,
	UFD_UNK = 255
};


/* uf_Errno �̃G���[�ԍ� */
	/* Error code of uf_Errno */
typedef enum {
	UFD_ERR_USERFLAG_PARITY_ERROR = 1,				/* ���ʃt���O�Ƀp���e�B�G���[�������� */
										/* Parity error in common flag */
	UFD_ERR_BANKNUMBER_ERROR,					/* �o���N�ԍ����s�� */
										/* Bunk number incorrect */
	UFD_ERR_PROTECT_COMMON_FLAG,					/* ���ʃt���O���A�N�Z�X�֎~�ɂȂ��Ă��� */
										/* Common flag access prohibited */
	UFD_ERR_PROTECT_FLAG,						/* �^�C�g���̓A�N�Z�X�֎~�ɂȂ��Ă��� */
										/* Title access prohibited */
	UFD_ERR_NO_INIT,						/* ���������I�����Ă��Ȃ� */
										/* Initialize not completed */
	UFD_ERR_INIT_FAIL,						/* �������Ɏ��s���� */
										/* Initialize faulted */
	UFD_ERR_READ_FAIL,						/* �ǂݍ��݂Ɏ��s���� */
										/* Read faulted */
	UFD_ERR_WRITE_FAIL,						/* �������݂Ɏ��s���� */
										/* Write faulted  */
	UFD_ERR_NOT_FOUND,						/* �w�肵�����i�ԍ��͌�����Ȃ����� */
										/* Requested Product number not found */
	UFD_ERR_NO_PACKET_LEFT,						/* �ǋL�p�P�b�g�̎c�肪���� */
										/* No writing packet available */
	UFD_ERR_MEMORY_FAIL,						/* �����ɕK�v�ȃ����������� */
										/* Not enough memory available*/
	UFD_ERR_PERIINITFAIL,						/* �y���t�F�����̏��������I����Ă��Ȃ� */	
										/* Peripheral Initialize not completed */	
	UFD_ERR_REFRESHFAIL,						/* ���t���b�V���Ɏ��s */
										/* Refresh falted */
	UFD_ERR_MAX
} UFS_ERROR;

/* �p�P�b�g0�̒�` */
/* Packet 0 definition */
#define UFD_PLAYHIST_PACKET0  \
	Uint8	version; 						/* ���C�u�����̃o�[�W���� */ \
										/* Library version */ \
	Uint8	AutoSave; 						/* �����ۑ��t���O */ \
										/* Auto Save Flag */ \
	Uint8	ProdNum[10]; 						/* ���i�ԍ� */ \
										/* Product number */ \
	Uint8	ProdName[48];						/* ���i���i�p��j */
										/* Product name (English) */

/* �p�P�b�g1�̒�` */
/* Packet 1 definition */

#define UFD_PLAYHIST_PACKET1  \
	Uint8	ProdName2[44];						/* ���i�����{�� */ \
										/* Product name (Japanese) */ \
	Uint32	Kind;							/* �Q�[����� */ \
										/* Game genre */ \
	Uint32	FirstStartTime;						/* ����N������ */ \
										/* First boot date & time */ \
	Uint16	CRC;							/* ���i�ԍ����珤�i���܂ł�CRC */ \
										/* CRC for from product number to product name */ \
	Uint8	PeriIdx[6];						/* �y���t�F������� */
										/* Peripheral information */


/* �p�P�b�g2�̒�` */
/* Packet 2 definition */
#define UFD_PLAYHIST_PACKET2  \
	Uint32	PrevStartTime;						/* �O��N������ */ \
										/* Previous boot day & time */ \
	Uint16	StartCount;						/* �N���� */ \
										/* Number of boots */ \
	Uint16	PlayTime[24];						/* �v���C���ԗ��� */ \
										/* Play time history */ \
	Uint16	LoadCount;						/* ���[�h�� */ \
										/* Number of loads */ \
	Uint32	Reserve_2;						/* ���U�[�u */
										/* Sega reserved */

/* �p�P�b�g3�̒�` */
/* Packet 3 definition */
#define UFD_PLAYHIST_PACKET3  \
	Uint16	SaveCount;						/* �Z�[�u�� */ \
										/* Number of saves */ \
	Uint8	GameEst;						/* �v���C�]�� */ \
										/* Play Evaluation */ \
	Uint8	GameCarry;						/* �U���� */ \
										/* Play progress */ \
	Uint32	FirstNetPlay;						/* ����l�b�g���[�N�v���C���� */ \
										/* First network play day & time */ \
	Uint32	PrevNetPlay;						/* �O��l�b�g���[�N�v���C���� */ \
										/* Previous network play day & time */ \
	Uint16	NetPlayCount;						/* �l�b�g���[�N�v���C�� */ \
										/* Number of network play */ \
	Uint16	NetPlayTotalTime;					/* �S�l�b�g���[�N�v���C����(��) */ \
										/* Total network play time(min.) */ \
	Uint8	FreeArea[32];						/* ���[�U�[�J���̈� */ \
										/* User area */ \
	Uint8	Reserved2[10];						/* ���U�[�u */ \
										/* Sega reserved */ \
	Uint16	SaveOccur;						/* �t���b�V���ւ̃Z�[�u�� */
										/* Number of Flash Memory saves */

/* ���[�N�T�C�Y�̒�` -- �o�C�g�P�� */
/* Definition of work size -- bytes */
#define	UFD_WORK1_SIZ	65536						/* 64K -- �K���K�v�ȃo�b�t�@�̃T�C�Y */
										/* 64K -- Minimum required buffer size */
#define	UFD_WORK2_SIZ	60						/*  60 -- �K���K�v�ȓǂݍ��ݗp�o�b�t�@�̃T�C�Y */
										/*  60 -- Minimum required reading buffer size */
#define UFD_WORK3_SIZ	65536						/* 64K -- �Z�[�t���t���b�V�����ɕK�v�ȃo�b�t�@�̃T�C�Y1 */
										/* 64K -- Required buffer size for safe refresh */
#define UFD_WORK4_SIZ	32768						/* 32K -- �Z�[�t���t���b�V�����ɕK�v�ȃo�b�t�@�̃T�C�Y2 */
										/* 32K -- Required buffer size for safe refresh */
#define	UFD_REQUIRED_REST_PACKET	2				/* �Œ�K�v�ȒǋL�\�p�P�b�g�� */
										/* Minimum required number of writing packet */
#define UFD_WORK_NOCHANGE	((void *)-1)				/* ufChangeWorkBuffer���Ƀ��[�N��ύX���Ȃ����̒萔 */
										/* Constant for not-changing work while ufChangeWorkBuffer */

/*============================================================
  Macro
  ============================================================*/

/*============================================================
  Structure
  ============================================================*/
/* �v���C�q�X�g���p�P�b�g 0 */
	/* Play history Packet 0 */
typedef struct tagUFS_Packet0 {
	UFD_PLAYHIST_PACKET0
} UFS_HistoryPacket0;

/* �v���C�q�X�g���p�P�b�g 1 */
	/* Play history Packet 1 */
typedef struct tag_HistoryPacket1 {
	UFD_PLAYHIST_PACKET1
} UFS_HistoryPacket1;

/* �v���C�q�X�g���p�P�b�g 2 */
	/* Play history Packet 2 */
typedef struct tagUFS_HistoryPacket2 {
	UFD_PLAYHIST_PACKET2
} UFS_HistoryPacket2;

/* �v���C�q�X�g���p�P�b�g 3 */
	/* Play history Packet 3 */
typedef struct tagUFS_HistoryPacket3 {
	UFD_PLAYHIST_PACKET3
} UFS_HistoryPacket3;

/* �v���C�q�X�g��(�p�P�b�g�P��) */
	/* Play History(par Packet) */
typedef struct tagUFS_PlayHistory {
	UFS_HistoryPacket0	packet0;
	UFS_HistoryPacket1	packet1;
	UFS_HistoryPacket2	packet2;
	UFS_HistoryPacket3	packet3;
} UFS_PlayHistory;

/* �v���C�q�X�g�� */
	/* Play History */
typedef struct tagUFS_AllPlayHistory {
	UFD_PLAYHIST_PACKET0
	UFD_PLAYHIST_PACKET1
	UFD_PLAYHIST_PACKET2
	UFD_PLAYHIST_PACKET3
} UFS_AllPlayHistory;

/*============================================================
  Global
  ============================================================*/
extern UFS_ERROR ufgErrno;							/* �G���[�ԍ� */
											/* Error code */

/*============================================================
  API
  ============================================================*/
Bool ufInitSystem(void* work1, void* work2, void* work3, void* work4);		/* �������֐� */
											/* Initialize function */
Bool ufChangeWorkBuffer(void* work1, void* work2, void* work3, void* work4); 	/* ���[�N�̕ύX */
/* Work Change */
Sint32 ufPlayTime(Uint8 mode, Uint8 est, Uint8 carry, Uint8 param[32]);		/* �v���C���Ԃ̍X�V */
											/* Updating Play time */
Bool ufSynch(void);								/* �v���C�f�[�^�̏����o�� */
											/* Writing Play data */
Bool ufAutoSynch(Uint32 count);							/* �v���C�f�[�^�X�V�Ԋu�̎w�� */
											/* Play data update interval */
Bool ufReadAllProduct(Uint8* Buffer);						/* �^�C�g�����X�g�̏��� */
											/* get Title list */ 
Bool ufReadAllHead(Uint8* ProdNum, UFS_AllPlayHistory* buff); 			/* �^�C�g���ʃv���C�����̎Q�� */
											/* Refer individual Play history */
Bool ufTitleDelete(void);							/* �^�C�g���ʃv���C�����̏��� */
											/* Erase individual Play history */
Bool ufChangeAutoSave(Uint8 Flag);						/* �����ۑ��t���O�̕ύX */
											/* Change Auto save flag */
Bool ufConnect(Uint32 time);							/* �T�[�o�ڑ����̃^�C�g���f�[�^�̍X�V */
											/* Data update for network connect */
Bool ufDisConnect(void);							/* �T�[�o�ؒf���̃^�C�g���f�[�^�̍X�V */
											/* Data update for network disconnect */
Bool ufSafeRefresh(void);							/* �t���b�V���������̃��t���b�V�� */
											/* Flash Memory refresh */
Bool ufGetControllerList(Uint32* list);						/* �R���g���[�����X�g�̏��� */
											/* get controller list */
Bool ufGetExtControllerList(Uint32* list);					/* �g���R���g���[�����X�g�̏��� */
											/* get extended controller list */
void ufExitSystem(void);							/* ���C�u�����I�� */
											/* Exit this library */										

/*============================================================*
 *------------------------------------------------------------*
 * End of File                                                *
 *------------------------------------------------------------*
 *============================================================*/
#endif 
