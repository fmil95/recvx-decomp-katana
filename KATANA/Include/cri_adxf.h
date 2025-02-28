#ifndef	_CRI_ADXF_H_INCLUDED
#define	_CRI_ADXF_H_INCLUDED
/****************************************************************************/
/*																			*/
/*			$title$ �`�c�w�t�@�C���V�X�e�� ���C�u����						*/
/*				ADXF (ADX File System) Library								*/
/*																			*/
/*			Copyright (c) 1998 CSK Research Institute						*/
/*				1998.7.3		written by S.Hosaka							*/
/*																			*/
/****************************************************************************/

/****************************************************************************/
/*      �C���N���[�h�t�@�C��												*/
/*      Include file														*/
/****************************************************************************/

/****************************************************************************/
/*		�萔�}�N��															*/
/*		MACRO CONSTANT														*/
/****************************************************************************/

/*	Version number of ADX File System	*/
#define	ADXF_VER				"5.53"


/*	�ő�p�[�e�B�V������				*/
/*	Maximum number of partition			*/
#define	ADXF_PART_MAX			(256)

/*	�ő�t�@�C����						*/
/*	Maximum number of file				*/
#define	ADXF_FILE_MAX			(65536)

/*	ADXF�n���h���I�u�W�F�N�g�̌�		*/
/*	Maximum number of ADXF handle		*/
#define	ADXF_OBJ_MAX			(16)

/*	�n���h���̏��						*/
/*	Status of handle					*/
#define	ADXF_STAT_STOP			(1)			/*	��~��						*/
											/*	During standstill			*/
#define ADXF_STAT_READING		(2)			/*	�f�[�^�ǂݍ��ݒ�			*/
											/*	During data read-in			*/
#define ADXF_STAT_READEND		(3)			/*	�f�[�^�ǂݍ��ݏI��			*/
											/*	Data read-in end			*/
#define ADXF_STAT_ERROR			(4)			/*	�ǂݍ��݃G���[����			*/
											/*	Read-in error outbreak state*/

/*	�V�[�N�^�C�v						*/
/*	Type of seek						*/
#define	ADXF_SEEK_SET			(0)			/*	�t�@�C���̐擪				*/
											/*	The beginning of file		*/
#define ADXF_SEEK_CUR			(1)			/*	���݂̈ʒu					*/
											/*	The current position		*/
#define ADXF_SEEK_END			(2)			/*	�t�@�C���̏I�[				*/
											/*	The end of file				*/

/*	�G���[�R�[�h						*/
/*	Error code							*/
#define	ADXF_ERR_OK				(0)			/*	����I��					*/
											/*	Successful					*/
#define	ADXF_ERR_FATAL			(-1)		/*	�O���̃G���[				*/
											/*	Fatal error					*/
#define	ADXF_ERR_INTERNAL		(-2)		/*	�����̃G���[				*/
											/*	Internal error				*/
#define	ADXF_ERR_PRM			(-3)		/*	�s���ȃp�����[�^			*/
											/*	Illegal parameter			*/
#define	ADXF_ERR_AFS_FILE		(-4)		/*	�s����AFS�t�@�C��			*/
											/*	Illegal AFS file			*/

/*	����l								*/
/*	Default value						*/
#define	ADXF_DEF_SCT_SIZE		(2048)		/*	CD-ROM�̃Z�N�^�T�C�Y		*/
											/*	Sector size in CD-ROM		*/
#define	ADXF_DEF_DMA_ALIGN		(32)		/*	DMA�̃A���C�����g			*/
											/*	Alignment of DMA transfer	*/

#define	ADXF_CMD_HSTRY_MAX		(256)		/*	�R�}���h�����̌�			*/
											/*	Number of command history	*/

#define	ADXF_CMD_OPEN			(1)			/*	ADXF_Open					*/
#define	ADXF_CMD_OPEN_AFS		(2)			/*	ADXF_OpenAfs				*/
#define	ADXF_CMD_CLOSE			(3)			/*	ADXF_Close					*/
#define	ADXF_CMD_READ_NW32		(4)			/*	ADXF_ReadNw32				*/
#define	ADXF_CMD_STOP			(5)			/*	ADXF_Stop					*/
#define	ADXF_CMD_SEEK			(6)			/*	ADXF_Seek					*/

#define	ADXF_CMD_NUM_MAX		(16)

/****************************************************************************/
/*		�񋓒萔															*/
/*		Enumarate Constants													*/
/****************************************************************************/

/****************************************************************************/
/*		�����}�N��															*/
/*		Process MACRO														*/
/****************************************************************************/

/*	�p�[�e�B�V�������ɕK�v�ȗ̈�̌v�Z						*/
/*	Calculation of necessary area for partition information		*/

#define	ADXF_PTIF_CMN_SZ			(5*sizeof(long))

#define	ADXF_CALC_PTINFO_REAL_SIZE(n)	\
								(ADXF_PTIF_CMN_SZ+(((n)+1)*sizeof(short)))

#define	ADXF_CALC_PTINFO_SIZE(n)	\
					((ADXF_CALC_PTINFO_REAL_SIZE(n)+sizeof(short))/4*4)

#define	ADXF_CALC_ADD_PTINFO_SIZE(n)	\
					(ADXF_PTIF_CMN_SZ+((n)*(2*sizeof(short)+sizeof(long))))

/****************************************************************************/
/*		�f�[�^�^															*/
/*      Data type declaration												*/
/****************************************************************************/

#ifndef ADXSTM_DEFINED
#define ADXSTM_DEFINED
typedef void *ADXSTM;
#endif

#ifndef SJ_DEFINED
#define SJ_DEFINED
typedef void *SJ;
#endif

/*	ADXF�n���h��		*/
/*	ADXF handle			*/
#ifndef ADXF_DEFINED
#define	ADXF_DEFINED
typedef	struct _adx_fs {
	char	used;					/*	�g�p�����ۂ�						*/
	char	stat;					/*	�n���h���̏��						*/
	char	sjflag;					/*	�O������ݒ肳�ꂽSJ���ۂ�			*/
	char	rev;					/*	�\��̈�							*/
	ADXSTM	stm;					/*	ADXSTM�n���h��						*/
	SJ		sj;						/*	�X�g���[���W���C���g				*/
	long	fad;					/*	�t�@�C���A�h���X					*/
	long	fnsct;					/*	�t�@�C���T�C�Y(�Z�N�^)				*/
	long	fsize;					/*	�t�@�C���T�C�Y(�o�C�g)				*/
	long	skpos;					/*	�A�N�Z�X�|�C���^�̈ʒu				*/
	long	rdstpos;				/*	�ǂݍ��݊J�n�ʒu					*/
	long	rqsct;					/*	�ǂݍ��ݗv���f�[�^��(�Z�N�^)		*/
	long	rdsct;					/*	�ǂݍ��񂾃f�[�^��(�Z�N�^)			*/
	char	*buf;					/*	�o�b�t�@�̃A�h���X(�o�C�g)			*/
	long	bsize;					/*	�o�b�t�@�̃T�C�Y(�o�C�g)			*/
} ADX_FS;
typedef	ADX_FS	*ADXF;
#endif

/*	�p�[�e�B�V�������		*/
/*	Partition information	*/
#ifndef ADXF_PTINFO_DEFINED
#define ADXF_PTINFO_DEFINED
typedef struct _adxf_ptinfo {
	struct _adxf_ptinfo	*next;		/*	���̃p�[�e�B�V����(NULL:�I���W�i��)	*/
	long				size;		/*	�p�[�e�B�V�������̈�T�C�Y		*/
	long				fad;		/*	�p�[�e�B�V�����̐擪FAD				*/
	long				nfile;		/*	�p�[�e�B�V�������̃t�@�C����		*/
	unsigned short		nentry;		/*	�p�[�e�B�V�������̓o�^�t�@�C����	*/
	char				type;		/*	�I���W�i�����ǋL���̃t���O			*/
	char				rev;		/*	�\��̈�							*/
	long				top;		/*	�t�@�C�����̐擪					*/
} ADXF_PTINFO;
#endif

/*	�ǋL�t�@�C���̏��				*/
/*	Information of postscript file	*/
#ifndef ADXF_ADD_DEFINED
#define ADXF_ADD_DEFINED
typedef struct _adxf_add_info {
	unsigned short	flid;			/*	�t�@�C��ID							*/
	unsigned short	fnsct;			/*	�t�@�C���T�C�Y						*/
	long			ofst;			/*	�I�t�Z�b�g							*/
} ADXF_ADD_INFO;
#endif

#ifndef ADXF_CMD_HSTRY_DEFINED
#define ADXF_CMD_HSTRY_DEFINED
typedef struct _adxf_cmd_hstry {
	unsigned char	cmdid;			/*	�R�}���h(�֐�)ID					*/
	unsigned char	fg;				/*	�֐��̓�������o�����������t���O	*/
	unsigned short	ncall;			/*	�R�}���h�̌Ăяo����				*/
	long	prm[3];					/*	�R�}���h�p�����[�^					*/
} ADXF_CMD_HSTRY;
#endif

/****************************************************************************/
/*		�ϐ��錾															*/
/*		Variable Declaration												*/
/****************************************************************************/

/****************************************************************************/
/*		�֐��̐錾															*/
/*      Function Declaration												*/
/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*==========================================================================
		���C�u�����̏������ƏI������
 		Initialize and Finalize of Library
  ==========================================================================*/

/*  ���C�u�����̏�����
 * [���@��] void ADXF_Init( void );
 * [���@��] �Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ���C�u����������������B
 *  Initialization of library
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Initializes library.
 */
void ADXF_Init(void);

/* ���C�u�����̏I������
 * [���@��] void ADXF_Finish(void);
 * [���@��] �Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ���C�u�����̏I������������B
 *  Termination of library
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Finalizes library.
 */
void ADXF_Finish(void);

/*  �p�[�e�B�V�����̃��[�h
 * [���@��] long ADXF_LoadPartition(long ptid, char *fname, 
 *													void *ptinfo, long nfile);
 * [���@��] ptid	:�p�[�e�B�V����ID
 *			fname	:AFS�t�@�C���̖��O
 *			ptinfo	:�p�[�e�B�V�������ǂݍ��ݗ̈�
 *			nfile	:�t�@�C����
 * [�o�@��] �Ȃ�
 * [�֐��l] �G���[�R�[�h
 * [�@�@�\] AFS�t�@�C������ǂݍ���ŁA�p�[�e�B�V����ID�ɐݒ肷��B
 *  Load of the partition
 * [Inputs  ] ptid   :Partition ID
 *			  fname  :Name of AFS file
 *            ptinfo :Area of partition information
 *            nfile  :The number of files
 * [Outputs ] None
 * [Return  ] Error code
 * [Function] Loads AFS file and sets partition ID.
 */
long ADXF_LoadPartition(long ptid, char *fname, void *ptinfo, long nfile);

/*  �p�[�e�B�V�����̒ǉ�
 * [���@��] long ADXF_AddPartition(long ptid, char *fname, 
 *													void *ptinfo, long nfile);
 * [���@��] ptid	:�p�[�e�B�V����ID
 *			fname	:AFS�t�@�C���̖��O
 *			ptinfo	:�p�[�e�B�V�������ǂݍ��ݗ̈�
 *			nfile	:�t�@�C����
 * [�o�@��] �Ȃ�
 * [�֐��l] �G���[�R�[�h
 * [�@�@�\] �w�肳�ꂽ�p�[�e�B�V����ID��AFS�t�@�C����ǉ�����B
 *  Additon of the partition
 * [Inputs  ] ptid   :Partition ID
 *			  fname  :Name of AFS file
 *            ptinfo :Area of partition information
 *            nfile  :The number of files
 * [Outputs ] None
 * [Return  ] Error code
 * [Function] Adds AFS file to the partition ID.
 */
long ADXF_AddPartition(long ptid, char *fname, void *ptinfo, long nfile);

/*  �p�[�e�B�V�������T�C�Y�̎擾
 * [���@��] long ADXF_GetPtinfoSize(long ptid);
 * [���@��] ptid	:�p�[�e�B�V����ID
 * [�o�@��] �Ȃ�
 * [�֐��l] �p�[�e�B�V�������T�C�Y(�P�ʁF�o�C�g)
 * [�@�@�\] �p�[�e�B�V�������̈�̃T�C�Y���擾����B
 *  Get size of partition information
 * [Inputs  ] ptid   :Partition ID
 * [Outputs ] None
 * [Return  ] Size of the partition information(byte)
 * [Function] Gets size of the partition information.
 */
long ADXF_GetPtinfoSize(long ptid);

/*==========================================================================
		�t�@�C���̓ǂݍ���
		Read file
  ==========================================================================*/

/*	�t�@�C���̃I�[�v��(ISO9660�̃t�@�C��)
 * [���@��] ADXF ADXF_Open(char *fname, void *atr);
 * [���@��] fname	: �t�@�C����
 *			atr		: �t�@�C���̑���
 * [�o�@��] �Ȃ�
 * [�֐��l] ADXF�n���h���A�G���[�̏ꍇNULL
 * [�@�@�\] �w��̃t�@�C�����I�[�v�����AADXF�n���h����Ԃ��B
 *  Open file(ISO9660 format)
 * [Inputs  ] fname  : File name
 *			  atr    : File attribute
 * [Outputs ] None
 * [Return  ] ADXF handle
 *			  (If the operation was unsuccessful, this function returns NULL.)
 * [Function] Opens a file of ISO9660 format.
 */
ADXF ADXF_Open(char *fname, void *atr);

/*	�t�@�C���̃I�[�v��(AFS�t�H�[�}�b�g)
 * [���@��] ADXF ADXF_OpenAfs(long ptid, long flid);
 * [���@��] ptid	: �p�[�e�B�V����ID
 *			flid	: �t�@�C��ID
 * [�o�@��] �Ȃ�
 * [�֐��l] ADXF�n���h���A�G���[�̏ꍇNULL
 * [�@�@�\] �p�[�e�B�V����ID�ƃt�@�C��ID�Ŏw�肳�ꂽAFS�t�@�C�����I�[�v�����A
 *			ADXF�n���h����Ԃ��B
 *  Open file(AFS format)
 * [Inputs  ] ptid   : Partition ID
 *			  flid   : File ID
 * [Outputs ] None
 * [Return  ] ADXF handle
 *			  (If the operation was unsuccessful, this function returns NULL.)
 * [Function] Opens a file of AFS format.
 */
ADXF ADXF_OpenAfs(long ptid, long flid);

/* �t�@�C���̃N���[�Y
 * [���@��] void ADXF_Close(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �w�肳�ꂽADXF�n���h���̃t�@�C�����N���[�Y����B
 *  Close file
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] None
 * [Function] Closes a file of specific ADXF handle.
 */
void ADXF_Close(ADXF adxf);

/*  SJ�ւ̃f�[�^�ǂݍ��݊J�n
 * [���@��] void ADXF_ReadSj32(ADXF adxf, long nsct, SJ sj);
 * [���@��] adxf	: ADXF�n���h��
 *			nsct	: �ǂݍ��݃f�[�^�̗�(�P�ʁF�Z�N�^)
 *			SJ		: �X�g���[���W���C���g
 * [�o�@��] �Ȃ�
 * [�֐��l] �ǂݍ��݃f�[�^��(�P�ʁF�Z�N�^)
 * [�@�@�\] �X�g���[���W���C���g�Ƀf�[�^�ǂݍ��݂̃��N�G�X�g�𔭍s����B
 *			�X�g���[���W���C���g�̃o�b�t�@�T�C�Y�́A�Z�N�^�̐����{�łȂ����
 *			�Ȃ�Ȃ��B
 *			�X�g���[���W���C���g���烆�[�U���f�[�^��ǂݏo���ƁA�����I�ɃX�g���[ *			���W���C���g�Ƀf�[�^���ǂݍ��܂��B
 *			���N�G�X�g�����A�N�Z�X���삪��������ƁA�A�N�Z�X�|�C���^��
 *			nsct�Z�N�^�i�ށB
 *  Read-in start to Stream Joint
 * [Inputs  ] adxf   : ADXF handle
 *			  nsct   : Number of read-in sectors to request
 *			  SJ     : Stream Joint
 * [Outputs ] None
 * [Return  ] Number of sectors to read
 * [Function] Requests data read-in to Stream Joint.
 *			  Buffer size of Stream Joint must be multiples of integer.
 *			  If you read data from Stream Joint, data are read into Stream 
 *			  Joint automatically.
 *			  The access pointer moves 'nsct' sector minute when the request 
 *			  was completed.
 */
long ADXF_ReadSj32(ADXF adxf, long nsct, SJ sj);

/* �f�[�^�̓ǂݍ��݊J�n
 * [���@��] void ADXF_ReadNw32(ADXF adxf, long nsct, void *buf);
 * [���@��] adxf	: ADXF�n���h��
 *			nsct	: �ǂݍ��݃f�[�^�̗�(�P�ʁF�Z�N�^)
 *			buf		: �ǂݍ��ݗ̈�
 * [�o�@��] �Ȃ�
 * [�֐��l] �ǂݍ��݃f�[�^��(�P�ʁF�Z�N�^)
 * [�@�@�\] �f�[�^�ǂݍ��݂̃��N�G�X�g�𔭍s����B
 *			���N�G�X�g�����A�N�Z�X���삪��������ƁA�A�N�Z�X�|�C���^��
 *			nsct�Z�N�^�i�ށB
 *  Read-in start
 * [Inputs  ] adxf   : ADXF handle
 *			  nsct   : Number of read-in sectors to request
 *			  buf    : Pointer to buffer into which the data is read
 * [Outputs ] None
 * [Return  ] Number of sectors to read
 * [Function] Requests data read-in to Stream Joint.
 *			  The access pointer moves 'nsct' sector minute when the request 
 *			  was completed.
 */
long ADXF_ReadNw32(ADXF adxf, long nsct, void *buf);

/* �f�[�^�̓ǂݍ��ݒ��~
 * [���@��] long ADXF_Stop(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] ���~�������_�ł̃A�N�Z�X�|�C���^�̈ʒu
 * [�@�@�\] �f�[�^�̓ǂݍ��݂𒆎~����B
 *  Read-in stop
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] The location of access pointer when you stop to read
 * [Function] Stops to read data.
 */
long ADXF_Stop(ADXF adxf);

/* �T�[�o�֐�
 * [���@��] void ADXF_ExecServer(void);
 * [���@��] �Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ������Ԃ��X�V����B
 *  Server function
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Update the inside status of library.
 */
void ADXF_ExecServer(void);

/*==========================================================================
		�A�N�Z�X�|�C���^�̐���
		Control access pointer
  ==========================================================================*/

/*  �A�N�Z�X�|�C���^�̈ړ�
 * [���@��] long ADXF_Seek(ADXF adxf, long pos, long type);
 * [���@��] adxf	: ADXF�n���h��
 *			pos		: �A�N�Z�X�|�C���^�̈ړ���(�P�ʁF�Z�N�^)
 *			type	: �ړ��(�V�[�N�^�C�v�FADXF_SEEK_�`)
 * [�o�@��] �Ȃ�
 * [�֐��l] �A�N�Z�X�|�C���^�̈ʒu�A���̒l�̓G���[�R�[�h
 * [�@�@�\] �A�N�Z�X�|�C���^��type����pos�Z�N�^���ꂽ�ʒu�Ɉړ�������B
 *  Move access pointer
 * [Inputs  ] adxf   : ADXF handle
 *			  pos    : Offset relative to 'type'
 *			  type   : Specified the origin for the offset
 * [Outputs ] None
 * [Return  ] Location containing new seek pointer
 * [Function] Changes the seek pointer to a new location relative to the 
 *			  beginning of the file, to the end of the file, or to the current 
 *			  seek pointer.
 */
long ADXF_Seek(ADXF adxf, long pos, long type);

/*  �A�N�Z�X�|�C���^�̎擾
 * [���@��] long ADXF_Tell(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �A�N�Z�X�|�C���^�̈ʒu
 * [�@�@�\] �A�N�Z�X�|�C���^�̈ʒu���擾����B
 *  Get the access pointer
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] Access pointer
 * [Function] Gets the access pointer.
 */
long ADXF_Tell(ADXF adxf);

/*==========================================================================
		���̎擾
		Get information
  ==========================================================================*/

/*  �t�@�C���T�C�Y�̎擾
 * [���@��] long ADXF_GetFsizeSct(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �t�@�C���T�C�Y(�P�ʁF�Z�N�^)
 * [�@�@�\] �w�肳�ꂽ�t�@�C���̃T�C�Y���Z�N�^�P�ʂŎ擾����B
 *  Get file size
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] File size(sector)
 * [Function] Obtains the size of the specified file.
 */
long ADXF_GetFsizeSct(ADXF adxf);

/*  �t�@�C���T�C�Y�̎擾
 * [���@��] long ADXF_GetFsizeByte(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �t�@�C���T�C�Y(�P�ʁF�o�C�g)
 * [�@�@�\] �w�肳�ꂽ�t�@�C���̃T�C�Y���o�C�g�P�ʂŎ擾����B
 *  Get file size
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] File size(byte)
 * [Function] Obtains the size of the specified file.
 */
long ADXF_GetFsizeByte(ADXF adxf);

/*  �ǂݍ��ݗv�����̎擾
 * [���@��] long ADXF_GetNumReqSct(ADXF adxf, long *seekpos);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] seekpos	: �ǂݍ��݈ʒu
 * [�֐��l] �v�������ǂݍ��݃f�[�^��(�P�ʁF�Z�N�^)
 * [�@�@�\] �v�������ǂݍ��݈ʒu�ƃf�[�^�ʂ��擾����B
 *  Get request information
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] seekpos: location of start to read
 * [Return  ] Request data size(sector)
 * [Function] Obtains read-in start position and the read-in size that 
 *			  demanded.
 */
long ADXF_GetNumReqSct(ADXF adxf, long *seekpos);

/*  ���ۂɓǂݍ��񂾃Z�N�^���̎擾
 * [���@��] long ADXF_GetNumReadSct(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �ǂݍ��񂾃f�[�^��(�P�ʁF�Z�N�^)
 * [�@�@�\] ���ۂɓǂݍ��񂾃f�[�^�ʂ��擾����B
 *  Get the number of sectors read
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] Size of read data(sector)
 * [Function] Obtains the size of data that read actually.
 */
long ADXF_GetNumReadSct(ADXF adxf);

/*  �n���h���̏�Ԃ̎擾
 * [���@��] long ADXF_GetStat(ADXF adxf);
 * [���@��] adxf	: ADXF�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] ADXF�n���h���̓������(��ԁFADXF_STAT_�`)
 * [�@�@�\] ADXF�n���h���̓�����Ԃ��擾����B
 *  Get status of handle
 * [Inputs  ] adxf   : ADXF handle
 * [Outputs ] None
 * [Return  ] Status of handle
 * [Function] Gets status of handle.
 */
long ADXF_GetStat(ADXF adxf);

/*  FAD�ƃt�@�C���T�C�Y�̎擾
 * [���@��] long ADXF_GetAfsRange(long ptid, long flid, 
 *													long *fad, long *fnsct);
 * [���@��] ptid	: �p�[�e�B�V����ID
 *			flid	: �t�@�C��ID
 * [�o�@��] fad		: �t�@�C���A�h���X
 *			nsct	: �t�@�C���T�C�Y(�P��:�Z�N�^)
 * [�֐��l] �G���[�R�[�h
 * [�@�@�\] �p�[�e�B�V�������̃t�@�C���̃t�@�C���A�h���X�ƃT�C�Y���擾����B
 *  Get FAD and file size
 * [Inputs  ] ptid   : Partition ID
 *			  flid   : File ID
 * [Outputs ] fad    : File address
 *			  nsct   : File size(sector)
 * [Return  ] Error code
 * [Function] Obtains address and size of file in the partition.
 */
long ADXF_GetFileRange(long ptid, long flid, long *fad, long *fnsct);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif	/* _CRI_ADXF_H_INCLUDED */
