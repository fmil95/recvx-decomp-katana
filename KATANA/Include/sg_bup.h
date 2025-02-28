/*
 *  Shinobi Library
 *  Copyright (c) 1998 SEGA
 *
 *       Backup
 *
 *  Module  : Library Header File
 *  File    : sg_bup.h
 *  Create  : 1998-07-03
 *  Modify  : 1999-03-01
 *  Version : 1.44
 *  Note    :
 */

#ifndef _SG_BUP_H_
#define _SG_BUP_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * C VIRTUAL TYPES DEFINITIONS
 */

#include <sg_xpt.h>


/*
 *  TYPEDEFS
 */

/******** �^�C���X�^���v�\���� *********************************************/
/******** Time stamp structure *********************************************/
typedef struct {
	Uint16 year;                /* �N(1998�`)                              */
	                            /* year(1998-)                             */
	Uint8 month;                /* ��(1�`12)                               */
	                            /* month(1-12)                             */
	Uint8 day;                  /* ��(1�`31)                               */
	                            /* day(1-31)                               */
	Uint8 hour;                 /* ��(0�`23)                               */
	                            /* hour(0-23)                              */
	Uint8 minute;               /* ��(0�`59)                               */
	                            /* minute(0-59)                            */
	Uint8 second;               /* �b(0�`59)                               */
	                            /* second(0-59)                            */
	Uint8 dayofweek;            /* �j��(�� = 0,�� = 1, ... �y = 6)         */
	                            /* day of week(sun=0, mon=1, ... sat=6)    */
} BUS_TIME;


/******** �f�B�X�N���\���� ***********************************************/
/******** Disk information structure ***************************************/
typedef struct {
	Uint8 volume[32];           /* �{�����[���f�[�^                        */
	                            /* Volume data                             */
	Uint16 total_blocks;        /* �S�u���b�N��                            */
	                            /* Number of all blocks                    */
	Uint16 total_user_blocks;   /* �S���[�U�[�u���b�N��(�ő�t�@�C����)    */
	                            /* Number of all user blocks(Max files)    */
	Uint16 free_blocks;         /* �󂫃u���b�N��                          */
	                            /* Number of free blocks                   */
	Uint16 free_user_blocks;    /* �󂫃��[�U�[�u���b�N��                  */
	                            /* Number of free user blocks              */
	Uint16 total_exe_blocks;    /* �S���s�t�@�C���p�u���b�N��              */
	                            /* Number of blocks for executable file    */
	Uint16 free_exe_blocks;     /* �󂫎��s�t�@�C���p�u���b�N��            */
	                            /* Number of free blocks for executable    */
	Uint16 block_size;          /* �u���b�N�T�C�Y(512�Œ�)                 */
	                            /* Size of block (Always 512 bytes)        */
	Uint16 icon_no;             /* �A�C�R���ԍ�(0�`255)                    */
	                            /* Icon number(0-255)                      */
	BUS_TIME time;              /* �t�H�[�}�b�g���ꂽ����                  */
	                            /* Time when disk was formatted            */
} BUS_DISKINFO;

/******** �t�@�C�����\���� ***********************************************/
/******** File information structure ***************************************/
typedef struct {
	Uint32 filesize;            /* �t�@�C���T�C�Y(�o�C�g��)                */
	                            /* File size (in bytes)                    */
	Uint16 blocks;              /* �g�p�u���b�N��                          */
	                            /* File size (in blocks)                   */
	Uint8 type;                 /* �t�@�C���^�C�v(�ʏ�/���s�\)           */
	                            /* File type (normal / executable)         */
	Uint8 copyflag;             /* �R�s�[�t���O(ff=�R�s�[�s��)             */
	                            /* Copy flag(ff=cannot copy)               */
	Uint16 headerofs;           /* �w�b�_�I�t�Z�b�g                        */
	                            /* Header offset                           */
	BUS_TIME time;              /* �^�C���X�^���v                          */
	                            /* Time stamp                              */
} BUS_FILEINFO;

/******** �o�b�N�A�b�v�t�@�C���w�b�_ ***************************************/
/******** Backup file header structure *************************************/
typedef struct {
	char vms_comment[18];       /* VMS�p�R�����g                           */
	                            /* Comment string for VMS                  */
	char btr_comment[34];       /* BOOT ROM�p�R�����g                      */
	                            /* Comment string for BOOT ROM             */
	Uint8 game_name[16];        /* �Q�[����                                */
	                            /* Game name (Sort key)                    */
	void* icon_palette;         /* �A�C�R���p���b�g�A�h���X                */
	                            /* Icon palette address                    */
	void* icon_data;            /* �A�C�R���f�[�^�A�h���X                  */
	                            /* Icon pixel address                      */
	Uint16 icon_num;            /* �A�C�R����                              */
	                            /* Number of icons                         */
	Uint16 icon_speed;          /* �A�C�R���A�j���[�V�����X�s�[�h          */
	                            /* Icon animation speed                    */
	void* visual_data;          /* �r�W���A���f�[�^�A�h���X                */
	                            /* Visual data address                     */
	Uint16 visual_type;         /* �r�W���A���^�C�v                        */
	                            /* Visual type                             */
	Uint16 reserved;            /* �\��                                    */
	                            /* Reserved                                */
	void* save_data;            /* �A�v���P�[�V�����Z�[�u�f�[�^�A�h���X    */
	                            /* Application save data address           */
	Uint32 save_size;           /* �A�v���P�[�V�����Z�[�u�f�[�^�T�C�Y      */
	                            /* Application save data size (in bytes)   */
} BUS_BACKUPFILEHEADER;

/******** �{�����[���A�C�R���t�@�C�� ***************************************/
/******** Volume icon file structure ***************************************/
typedef struct {
	char vms_comment[16];              /* VMS�p�R�����g                    */
	                                   /* Comment string for VMS           */
	Uint8 mono_icon[128];              /* ���m�N���A�C�R���f�[�^           */
	                                   /* Monochrome icon data             */
	Uint16 color_icon_palette[16];     /* �J���[�A�C�R���p���b�g           */
	                                   /* Color icon palette               */
	Uint8 color_icon[512];             /* �J���[�A�C�R���f�[�^             */
	                                   /* Color icon pixel data            */
	Uint8 reserved[1024-16-128-544-4]; /* �\��                             */
	                                   /* reserved                         */
	Uint32 aligndata;                  /* 4�o�C�g�A���C���̂��߂̃f�[�^    */
	                                   /* Data for 4-bytes align           */
} BUS_VOLUMEICONFILE;


/******** �R�[���o�b�N�֐��^ ***********************************************/
/******** Callback function types ******************************************/
typedef void (*BU_INITCALLBACK)(void);
typedef Sint32 (*BU_COMPLETECALLBACK)(Sint32 drive, Sint32 op,
												Sint32 status, Uint32 param);
typedef Sint32 (*BU_PROGRESSCALLBACK)(Sint32 drive, Sint32 op,
												Sint32 count, Sint32 max);


/*
 *  PROTOTYPES
 */


/*-------- �ʏ�A�v���Ŏg�p����֐� ---------------------------------------*/
/*-------- Functions for normal applications ------------------------------*/
Sint32 buInit(Sint32 capacity, Sint32 drives, void* work,
													BU_INITCALLBACK func);
Sint32 buExit(void);
Sint32 buSaveFile(Sint32 drive, const char* fname, const void* buf,
									Uint32 nblock, BUS_TIME* time, Uint32 flag);
Sint32 buSaveExecFile(Sint32 drive, const char* fname, const void* buf,
									Uint32 nblock, BUS_TIME* time, Uint32 flag);
Sint32 buLoadFile(Sint32 drive, const char* fname, void* buf, Uint32 nblock);

Sint32 buDeleteFile(Sint32 drive, const char* fname);
Sint32 buDeleteFileEx(Sint32 drive, const char** fname, Sint32 nfiles);

void buSetCompleteCallback(BU_COMPLETECALLBACK func);
void buSetProgressCallback(BU_PROGRESSCALLBACK func);
Sint32 buIsReady(Sint32 drive);
Sint32 buIsFormat(Sint32 drive);
Sint32 buGetDiskFree(Sint32 drive, Sint32 type);
Sint32 buGetFileInfo(Sint32 drive, const char* fname, BUS_FILEINFO* finfo);
Sint32 buGetFileSize(Sint32 drive, const char* fname);
Sint32 buIsExistFile(Sint32 drive, const char* fname);
Sint32 buStat(Sint32 drive);
Sint32 buGetLastError(Sint32 drive);
Sint32 buMountDisk(Sint32 drive, void* addr, Sint32 size);
Sint32 buUnmountDisk(Sint32 drive);
Sint32 buRewriteExecFile(Sint32 drive, const char* fname, const void* buf,
												Uint32 start, Uint32 nblock);
Sint32 buMakeBackupFileImage(void* buf, const BUS_BACKUPFILEHEADER* hdr);
Sint32 buCalcBackupFileSize(Uint32 inum, Uint32 vtype, Uint32 size);
Sint32 buAnalyzeBackupFileImage(BUS_BACKUPFILEHEADER* hdr, const void* buf);

/*-------- ��Ƀt�@�C�����[�e�B���e�B���Ŏg�p����֐� ---------------------*/
/*-------- Functions for file utility -------------------------------------*/
void buSetCallbackParam(Uint32 param);
Sint32 buMount(Sint32 drive);
Sint32 buRemount(Sint32 drive);
Sint32 buUnmount(Sint32 drive);
Sint32 buGetDiskInfo(Sint32 drive, BUS_DISKINFO* info);
Sint32 buFindFirstFile(Sint32 drive, char* fname);
Sint32 buFindNextFile(Sint32 drive, char* fname);
Sint32 buFindFirstFileEx(Sint32 drive, char* fname, BUS_FILEINFO* finfo);
Sint32 buFindNextFileEx(Sint32 drive, char* fname, BUS_FILEINFO* finfo);
Sint32 buFindExecFile(Sint32 drive, char* fname);
Sint32 buSetFileAttr(Sint32 drive, const char* fname, Uint16 hdrofs,
															Uint8 copyflag);
Sint32 buFormatDisk(Sint32 drive, const Uint8* volume, Sint32 icon,
											const BUS_TIME* time, Uint32 flag);
Sint32 buRenameFile(Sint32 drive, const char* from, const char* to);
Sint32 buDefragDisk(Sint32 drive, void* work);
Sint32 buLoadFileEx(Sint32 drive, const char* fname, void* buf,
												Uint32 start, Uint32 nblock);

/*-------- ���̑��̊֐� ---------------------------------------------------*/
/*-------- Other functions ------------------------------------------------*/
void buExecServer(void);
Uint32 buGetVersion(void);
void buSetPrintFunc(void (*func)(const char* str));
void buSetRetryCount(Sint32 count);
Sint32 buGetRetryCount(void);
Uint16 buCalcCRC(const void* buf, Uint32 size);



/******** ���[�N�e�� *******************************************************/
/******** Work *************************************************************/
#define BUD_WORK_GAP 32

#define BUM_WORK_SIZE(_cap_, _max_) \
	(((_cap_ * _max_) * 512) + (BUD_WORK_GAP * _max_))

/******** �Z�[�u���̃t���O�w�� *********************************************/
/******** Save flags *******************************************************/
#define BUD_FLAG_VERIFY       0x80000000    /* �x���t�@�C�w��              */
                                            /* Verify on                   */
#define BUD_FLAG_COPY(n)      (n & 0xff)    /* �R�s�[�t���O                */
                                            /* Copy flag                   */
#define BUD_FLAG_COPYDISABLE  0x000000ff    /* �R�s�[�֎~�t���O��t����    */
                                            /* Set copy prohibition flag   */

/******** �Ή��ő�e�� *****************************************************/
/******** Capacity *********************************************************/
#define BUD_CAPACITY_128KB   (1 + 1 +  13)  /* �e��128KB�̂�               */
                                            /* 128KB only                  */
#define BUD_CAPACITY_256KB   (1 + 2 +  30)  /* �e��256KB�܂�               */
                                            /* 128KB,256KB                 */
#define BUD_CAPACITY_512KB   (1 + 4 +  60)  /* �e��512KB�܂�               */
                                            /* 128KB,256KB,512KB           */
#define BUD_CAPACITY_1MB     (1 + 8 + 113)  /* �e��1MB�܂�                 */
                                            /* 128KB,256KB,512KB,1MB       */

/******** �Ή��h���C�u *****************************************************/
/******** Drives ***********************************************************/
#define BUD_USE_DRIVE_A1    (1 << 0)        /* �|�[�gA�̊g���X���b�g1      */
                                            /* Expansion slot 1 of port A  */
#define BUD_USE_DRIVE_A2    (1 << 1)        /* �|�[�gA�̊g���X���b�g2      */
                                            /* Expansion slot 2 of port A  */
#define BUD_USE_DRIVE_B1    (1 << 2)        /* �|�[�gB�̊g���X���b�g1      */
                                            /* Expansion slot 1 of port B  */
#define BUD_USE_DRIVE_B2    (1 << 3)        /* �|�[�gB�̊g���X���b�g2      */
                                            /* Expansion slot 2 of port B  */
#define BUD_USE_DRIVE_C1    (1 << 4)        /* �|�[�gC�̊g���X���b�g1      */
                                            /* Expansion slot 1 of port C  */
#define BUD_USE_DRIVE_C2    (1 << 5)        /* �|�[�gC�̊g���X���b�g2      */
                                            /* Expansion slot 2 of port C  */
#define BUD_USE_DRIVE_D1    (1 << 6)        /* �|�[�gD�̊g���X���b�g1      */
                                            /* Expansion slot 1 of port D  */
#define BUD_USE_DRIVE_D2    (1 << 7)        /* �|�[�gD�̊g���X���b�g2      */
                                            /* Expansion slot 2 of port D  */
#define BUD_USE_DRIVE_ALL   0xff            /* �S��                        */
                                            /* All slots of all ports      */

/******** �h���C�u�ԍ� *****************************************************/
/******** Drive number *****************************************************/
#define BUD_DRIVE_A1   0                    /* �|�[�gA�̊g���X���b�g1      */
                                            /* Expansion slot 1 of port A  */
#define BUD_DRIVE_A2   1                    /* �|�[�gA�̊g���X���b�g2      */
                                            /* Expansion slot 2 of port A  */
#define BUD_DRIVE_B1   2                    /* �|�[�gB�̊g���X���b�g1      */
                                            /* Expansion slot 1 of port B  */
#define BUD_DRIVE_B2   3                    /* �|�[�gB�̊g���X���b�g2      */
                                            /* Expansion slot 2 of port B  */
#define BUD_DRIVE_C1   4                    /* �|�[�gC�̊g���X���b�g1      */
                                            /* Expansion slot 1 of port C  */
#define BUD_DRIVE_C2   5                    /* �|�[�gC�̊g���X���b�g2      */
                                            /* Expansion slot 2 of port C  */
#define BUD_DRIVE_D1   6                    /* �|�[�gD�̊g���X���b�g1      */
                                            /* Expansion slot 1 of port D  */
#define BUD_DRIVE_D2   7                    /* �|�[�gD�̊g���X���b�g2      */
                                            /* Expansion slot 2 of port D  */

/******** �t�@�C���^�C�v ***************************************************/
/******* File types ********************************************************/
#define BUD_FILETYPE_NORMAL       0         /* �ʏ�t�@�C��                */
                                            /* Normal file                 */
#define BUD_FILETYPE_EXECUTABLE   1         /* ���s�t�@�C��                */
                                            /* Executable file             */

/******** �X�e�[�^�X *******************************************************/
/******** Status ***********************************************************/
#define BUD_STAT_READY       0x00000000     /* �R�}���h���s�\            */
                                            /* Can execute command         */
#define BUD_STAT_BUSY        0xffffffff     /* �R�}���h���s��              */
                                            /* Busy                        */

/******** �R�[���o�b�N�I�y���[�V�����p�����[�^ *****************************/
/******** Callback operation parameters ************************************/
#define BUD_OP_NOP             0x00000000   /* nop                         */
#define BUD_OP_MOUNT           0x00000001   /* buRemount()/connect         */
#define BUD_OP_UNMOUNT         0x00000002   /* remove                      */
#define BUD_OP_FORMATDISK      0x00000003   /* buFormatDisk()              */
#define BUD_OP_CLOSEFILE       0x00000004   /* buCloseFile()               */
#define BUD_OP_READFILE        0x00000005   /* buReadFile()                */
#define BUD_OP_WRITEFILE       0x00000006   /* buWriteFile()               */
#define BUD_OP_DELETEFILE      0x00000007   /* buDeleteFile()              */
#define BUD_OP_RENAMEFILE      0x00000008   /* buRenameFile()              */
#define BUD_OP_DEFRAGDISK      0x00000009   /* buDefragDisk()              */
#define BUD_OP_SETFILEATTR     0x0000000a   /* buSetFileAttr()             */
#define BUD_OP_LOADFILE        0x0000000b   /* buLoadFile()                */
#define BUD_OP_SAVEFILE        0x0000000c   /* buSaveFile()                */
#define BUD_OP_SAVEEXECFILE    0x0000000d   /* buSaveExecFile()            */
#define BUD_OP_LOADFILEEX      0x0000000e   /* buLoadFileEx()              */
#define BUD_OP_READIMAGE       0x0000000f   /* buReadDiskImage()           */
#define BUD_OP_WRITEIMAGE      0x00000010   /* buWriteDiskImage()          */
#define BUD_OP_DELETEFILEEX    0x00000011   /* buDeleteFileEx()            */
#define BUD_OP_CONNECT         0x00000012   /* connect(before mount)       */
#define BUD_OP_REMOVE          0x00000013   /* remove                      */
#define BUD_OP_REWRITEEXECFILE 0x00000014   /* buRewriteExecFile()         */

/******** �R�[���o�b�N�֐��̖߂�l *****************************************/
/******** Return value of callback function ********************************/
#define BUD_CBRET_OK   0x00000000           /* �����p��                    */
                                            /* Continue operation          */

/******** �G���[�R�[�h *****************************************************/
/******** Error code *******************************************************/
#define BUD_ERR_OK              0x00000000  /* �G���[�Ȃ�                  */
                                            /* No error                    */
#define BUD_ERR_BUSY            0xffffffff  /* �R�}���h���s��              */
                                            /* Busy                        */
#define BUD_ERR_INVALID_PARAM   0xffffff00  /* �֐��p�����[�^���ُ�        */
                                            /* Invalid function parameter  */
#define BUD_ERR_ILLEGAL_DISK    0xffffff81  /* �ŏI�u���b�N�s��            */
                                            /* Illegal disk                */
#define BUD_ERR_UNKNOWN_DISK    0xffffff83  /* �Ή����Ă��Ȃ��f�B�X�N      */
                                            /* Not supported disk          */
#define BUD_ERR_NO_DISK         0xffffff01  /* �f�B�X�N�������Ă��Ȃ�      */
                                            /* Disk is not connected       */
#define BUD_ERR_UNFORMAT        0xffffff03  /* ���t�H�[�}�b�g              */
                                            /* Disk is not formatted       */
#define BUD_ERR_DISK_FULL       0xffffff04  /* �f�B�X�N�t��                */
                                            /* Disk full                   */
#define BUD_ERR_FILE_NOT_FOUND  0xffffff05  /* �t�@�C����������Ȃ�      */
                                            /* File not found              */
#define BUD_ERR_FILE_EXIST      0xffffff06  /* �������O�̃t�@�C��������    */
                                            /* File already exists         */
#define BUD_ERR_CANNOT_OPEN     0xffffff07  /* �t�@�C�����J���Ȃ�          */
                                            /* Cannot open file            */
#define BUD_ERR_CANNOT_CREATE   0xffffff08  /* ���s�t�@�C�����쐬�ł��Ȃ�  */
                                            /* Cannot create executable    */
#define BUD_ERR_EXECFILE_EXIST  0xffffff09  /* ���s�t�@�C�������݂���      */
                                            /* Executable file exists      */
#define BUD_ERR_CANNOT_DELETE   0xffffff0a  /* �t�@�C���������Ȃ�����      */
                                            /* Cannot delete file          */
#define BUD_ERR_ACCESS_DENIED   0xffffff0b  /* �t�@�C���A�N�Z�X����        */
                                            /* Access is refused           */
#define BUD_ERR_VERIFY          0xffffff10  /* �x���t�@�C�G���[            */
                                            /* Verify error                */
#define BUD_ERR_WRITE_ERROR     0xffffff40  /* ���C�g�G���[                */
                                            /* Write error                 */
#define BUD_ERR_FILE_BROKEN     0xffffff41  /* �t�@�C�������Ă���        */
                                            /* File is broken              */
#define BUD_ERR_BUPFILE_CRC     0xffffff20  /* �o�b�N�A�b�v�`��CRC�G���[   */
                                            /* CRC Error                   */
#define BUD_ERR_BUPFILE_ILLEGAL 0xffffff21  /* �o�b�N�A�b�v�`���ł͂Ȃ�    */
                                            /* File is not backup file     */
#define BUD_ERR_GENERIC         0xffff0000  /* ����`�G���[                */
                                            /* Unknown error               */

/******** �o�b�N�A�b�v�t�@�C���̃r�W���A���f�[�^�^�C�v *********************/
/******** Visual type of backup file ***************************************/
#define BUD_VISUALTYPE_NONE   0             /* �r�W���A���f�[�^�Ȃ�        */
                                            /* No visual data              */
#define BUD_VISUALTYPE_A      1             /* �^�C�vA                     */
                                            /* Type A                      */
#define BUD_VISUALTYPE_B      2             /* �^�C�vB                     */
                                            /* Type B                      */
#define BUD_VISUALTYPE_C      3             /* �^�C�vC                     */
                                            /* Type C                      */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SG_BUP_H_ */

