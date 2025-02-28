#ifndef	_ADXT_H_INCLUDED
#define	_ADXT_H_INCLUDED
/****************************************************************************/
/*																			*/
/*			$title$ �`�c�w�f�[�^�Đ� ���C�u����								*/
/*					ADXT (ADX TALK) Library									*/
/*																			*/
/*				1997.2.25		written M.Oshimi							*/
/*																			*/
/****************************************************************************/

/*	Version number of ADXT library 		*/
#define	ADXT_VER	"5.67"

/*	�X�g���[���W���C���g				*/
/*	Stream Joint						*/
#ifndef SJ_DEFINED
#define SJ_DEFINED
typedef void *SJ;
#endif


/*	�X�g���[���R���g���[��				*/
/*	Stream Controller					*/
#ifndef ADXSTM_DEFINED
#define ADXSTM_DEFINED
typedef	void	*ADXSTM;
#endif

/*	�X�g���[���W���C���g�f�R�[�_		*/
/*	Stream Joint decoder				*/
#ifndef ADXSJD_DEFINED
#define ADXSJD_DEFINED
typedef void	*ADXSJD;
#endif

/*	�I�[�f�B�I�����_��					*/
/*	Audio Renderer						*/
#ifndef ADXRNA_DEFINED
#define ADXRNA_DEFINED
typedef void	*ADXRNA;
#endif

#ifndef TRUE
#define TRUE	1
#endif
#ifndef FALSE
#define FALSE	0
#endif

/****************************************************************************/
/*		�萔�}�N��															*/
/*		MACRO CONSTANT														*/
/****************************************************************************/

/*	�ő哯��������						*/
/*	Maximum number of ADXT handle		*/
#define	ADXT_MAX_OBJ		(8)

/*	�ő�f�[�^�T�C�Y					*/
/*	Maximum data size					*/
#define	ADXT_MAX_DATASIZE	(0x40000000)

/*	���̓o�b�t�@�̃G�L�X�g���̈�̑傫��	*/
/*	Size of Extra area in input buffer		*/
#define ADXT_IBUF_XLEN (36)

/*	ADX Talk �̏o�̓o�b�t�@�̑傫���@�i�T���v���P�ʁj	*/
/*	Output buffer size of ADX Talk (unit:sample)		*/
#define	ADXT_OBUF_SIZE	(0x2000)
#define	ADXT_OBUF_DIST	(0x2020)

/*	�ő�T���v�����O���g��				*/
/*	Maximum sampling frequency			*/
#define	ADXT_MAX_SFREQ	(44100)

/*	ADX Talk�̍Đ�����	(ADXT_CALC_WORK�}�N���Ŏg�p)		*/
/*	Play method of ADX Talk (used 'ADXT_CALC_WORK' macro)	*/
#define ADXT_PLY_MEM	(0)			/*	����������̍Đ�					*/
									/*	Play memory data					*/
#define ADXT_PLY_STM	(1)			/*	CD����̃X�g���[���Đ�				*/
									/*	Stream play from CD-ROM				*/

#define ADXT_CALC_IBUFSIZE0(nch, sfreq)	(25000*(nch)*((sfreq)/1000)/44)

#define ADXT_CALC_IBUFSIZE(nch, nstm, sfreq)	\
	((ADXT_CALC_IBUFSIZE0(nch, sfreq)*((nstm)+1)+2048)/2048*2048+ADXT_IBUF_XLEN)
#define ADXT_CALC_OBUFSIZE(nch)	\
	( ADXT_OBUF_DIST*(nch)*sizeof(short))
#define ADXT_CALC_WORK(nch, stmflg, nstm, sfreq)	\
	(ADXT_CALC_IBUFSIZE(nch, nstm, sfreq)*(stmflg) + ADXT_CALC_OBUFSIZE(nch) + 32)

/*	���̓o�b�t�@�ւ̓ǂݍ��ݗ�						*/
/*	Number of sectors to read into the input buffer	*/
#define ADXT_MAX_CDBSCT		(75)
#define ADXT_MIN_CDBSCT		(65)
#define ADXT_PREP_RDSCT		(25)

/*	$define$ ADX Talk�̓�����(ADXT_STAT_�`)	*/
/*	Status of ADX Talk							*/
#define	ADXT_STAT_STOP		(0)		/*	��~�� 								*/
									/*	During standstill					*/
#define ADXT_STAT_DECINFO	(1)		/*	�`�c�w �̃w�b�_���擾��			*/
									/*	Getting header information			*/
#define ADXT_STAT_PREP		(2)		/*	�Đ������� 							*/
									/*	During play preparation				*/
#define ADXT_STAT_PLAYING	(3)		/*	�f�R�[�h���Đ��� 					*/
									/*	During decode and play				*/
#define ADXT_STAT_DECEND	(4)		/*	�f�R�[�h�I�� 						*/
									/*	Decode end							*/
#define ADXT_STAT_PLAYEND	(5)		/*	�Đ��I�� 							*/
									/*	Play end							*/

/*	$define$ ADX Talk�̃G���[�R�[�h�@(ADXT_ERR_�`)	*/
/*	Error code of ADX Talk							*/
#define	ADXT_ERR_OK			(0)		/*	���� 								*/
									/*	Normality							*/
#define ADXT_ERR_SHRTBUF	(-1)	/*	���̓o�b�t�@�G���v�e�B				*/
									/*	The input buffer is empty			*/
#define ADXT_ERR_SNDBLK		(-2)	/*	�T�E���h�u���b�N�G���[				*/
									/*	Error of sound block				*/

/*	$define$ �t�B���^���[�h	(ADXT_FLTMODE_�`)		*/
/*	Filter mode										*/
#define	ADXT_FLTMODE_CPU	(0)		/*	�b�o�t�ɂ��W�J���[�h				*/
									/*	by CPU								*/
#define	ADXT_FLTMODE_SCSP	(1)		/*	AICA-DSP�ɂ��W�J���[�h			*/
									/*	by AICA-DSP							*/

/*	$define$ �Đ����[�h	(ADXT_PMODE_�`)				*/
/*	Play mode										*/
#define	ADXT_PMODE_FNAME	(0)		/*	�t�@�C�����܂��� FID �ɂ��w��		*/
									/*	Play specified file name or file ID	*/
#define	ADXT_PMODE_AFS		(1)		/*	AFS �ɂ��w��						*/
									/*	Play specified AFS file				*/
#define	ADXT_PMODE_MEM		(2)		/*	�������Đ�							*/
									/*	Play data from memory				*/
#define	ADXT_PMODE_SJ		(3)		/*	�X�g���[���W���C���g�Đ�			*/
									/*	Play data from StreamJoint			*/

/*	$define$ �G���[���J�o�[���[�h	(ADXT_RMODE_�`)	*/
/*	Mode of error recovery							*/
#define	ADXT_RMODE_NOACT	(0)		/*	���J�o�[�������Ȃ�					*/
									/*	Do not recover						*/
#define	ADXT_RMODE_STOP		(1)		/*	������~							*/
									/*	Automatic stop						*/
#define	ADXT_RMODE_REPLAY	(2)		/*	�����ăv���C						*/
									/*	Automatic replay					*/

/*	�p���|�b�g�̐ݒ�l		*/
/*	Panpot parameter		*/
#define	ADXT_PAN_LEFT		(-15)
#define	ADXT_PAN_CENTER		(0)
#define	ADXT_PAN_RIGHT		(15)
#define	ADXT_PAN_AUTO		(-128)	/*	MONO/STE �ɂ���Ď����I�ɐ؂�ւ���	*/
									/*	Changes automatically by data		*/

/*	�X�e���I�Đ����̃`�����l���ԍ�		*/
/*	Channel number playing stereo data	*/
/*	ADXT_CH_L:left, ADXT_CH_R:right		*/
#define	ADXT_CH_L			(0)
#define	ADXT_CH_R			(1)

/*	�ő�Đ��`�����l����				*/
/*	Maximum number of play channel		*/
#define	ADXT_MAX_NCH		(2)

/*	�T�[�o�֐��̌Ăяo�����p�x�̋K��l�@60�i��/�b�j				*/
/*	Default value of frequency called server function(times/sec)	*/
#define ADXT_DEF_SVRFREQ	(60)

/*	Default value of output volume(dB)	*/
#define	ADXT_DEF_OUTVOL		(0)

/*	���̓o�b�t�@�̉����l (�G���[�����p�A�P�ʃo�C�g�j				*/
/*	Minimum data in the input buffer(byte) (for coping with error)	*/
#define	ADXT_MIN_BUFDATA	(64)

/*	�G���[���ʎ��ԁ@�i�P��:�b)			*/
/*	Error distinction time(sec)			*/
#define	ADXT_EWAIT_PLY		(5)
#define	ADXT_EWAIT_NOTPLY	(20)

/*	�C���f�b�N�X�̍ő吔				*/
/*	Maximum number of index				*/
#define	ADXT_MAX_IDX		(0xFFFF)

/****************************************************************************/
/*		�f�[�^�^															*/
/*      Data type declaration												*/
/****************************************************************************/

/*	ADX Talk �I�u�W�F�N�g�\����		*/
/*	Structure of ADX Talk object	*/
typedef	struct _adx_talk {
	char	used;						/*	�g�p�����ۂ�					*/
	char	stat;						/*	������						*/
	char	pmode;						/*	�Đ����[�h						*/
	char	maxnch;						/*	�ő�Đ��`�����l����			*/
	ADXSJD	sjd;						/*	ADX�X�g���[���W���C���g�f�R�[�_	*/
	ADXSTM	stm;						/*	���̓X�g���[���R���g���[��		*/
	ADXRNA	rna;						/*	�I�[�f�B�I�����_��				*/
	SJ		sjf;						/*	�t�@�C�����̓X�g���[���W���C���g*/
	SJ		sji;						/*	���̓X�g���[���W���C���g		*/
	SJ		sjo[ADXT_MAX_NCH];			/*	�o�̓X�g���[���W���C���g		*/
	char	*ibuf;						/*	���̓o�b�t�@					*/
	long	ibuflen;					/*	���̓o�b�t�@�T�C�Y�i�o�C�g�P��)	*/
	long	ibufxlen;					/*	���̓o�b�t�@�G�N�X�g���T�C�Y	*/
	short	*obuf;						/*	�o�̓o�b�t�@					*/
	long	obufsize;					/*	�o�̓o�b�t�@�T�C�Y�i�T���v���j	*/
	long	obufdist;					/*	�o�̓o�b�t�@�Ԋu�i�T���v���j	*/
	long	svrfreq;					/*	�T�[�o�֐��Ăяo���p�x			*/
	short	maxsct;						/*	���̓o�b�t�@���̍ō��Z�N�^��	*/
	short	minsct;						/*	���̓o�b�t�@���̍Œ�Z�N�^��	*/
	short	outvol;						/*	�o�̓{�����[��					*/
	short	outpan[ADXT_MAX_NCH];		/*	�o�̓p���|�b�g�̐ݒ�l			*/
	long	maxdecsmpl;					/*	�ő�f�R�[�h�T���v����			*/
	long	lpcnt;						/*	���[�v�J�E���^					*/
	long	lp_skiplen;					/*	���[�v�X�L�b�v�o�C�g��			*/
	long	trp;						/*	�g�����X�|�[�Y�� (�Z���g)		*/
	long	wpos;						/*	���f�B�A��̏������݈ʒu		*/
	long	mofst;						/*	���f�B�A��̃I�t�Z�b�g			*/
	short	ercode;						/*	�G���[�R�[�h					*/
	long	edecpos;					/*	�G���[���o�p�f�R�[�h�ʒu		*/
	short	edeccnt;					/*	�f�R�[�h�ʒu�J�E���^			*/
	short	eshrtcnt;					/*	�����ޯ̧����è�����			*/
	char	lpflg;						/*	���[�v���邩�ۂ�				*/
	char	autorcvr;					/*	�����I�ɃG���[���A���邩�ۂ�	*/
	char	fltmode;					/*	�t�B���^���[�h					*/
	char	execflag;					/*	�T�[�o�����s���邩�ۂ�			*/
	char	pstwait_flag;				/*	�����o�͊J�n�҂��t���O			*/
	char	pstready_flag;				/*	�����o�͏��������t���O			*/
	char	pause_flag;					/*	�ꎞ��~�t���O					*/
	void	*amp;						/*	�U�����o��						*/
	SJ		ampsji[ADXT_MAX_NCH];		/*	�U�����o�p����SJ				*/
	SJ		ampsjo[ADXT_MAX_NCH];		/*	�U�����o�p�o��SJ				*/
	long	time_ofst;					/*	�����̃I�t�Z�b�g				*/
} ADX_TALK;
typedef	ADX_TALK	*ADXT;

/*	�C���f�b�N�X�f�[�^	*/
/*	Index data			*/
typedef struct _adxt_idx {
	unsigned short nidx;
	unsigned short top;
} ADXT_IDX;

/****************************************************************************/
/*		�֐��̐錾															*/
/*      Function Declaration												*/
/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/* $func$ ADX Talk �̏�����
 * [���@��] void ADXT_Init(void);
 * [���@��] �Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ADX Talk ������������B
 *			�ϐ��̈�̏��������s���B
 *  Initialization of ADX Talk
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Initializes ADX Talk. Initializes variable.
 */
void ADXT_Init(void);

/* $func$ ADX ���C�u�����̍ď�����
 * [���@��] void ADXT_ResetLibrary(void);
 * [���@��] �Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ADX Talk ���ď���������B
 *			�ϐ��̈�̏��������s���B
 *  Reset ADX Talk
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Resets ADX Talk. Initializes variable.
 */
void ADXT_ResetLibrary(void);

/* $func$ ADX Talk�̏I��
 * [���@��] void ADXT_Finish(void);
 * [���@��] �Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ADX Talk �̏I������������B
 *  Termination of ADX Talk
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Finalizes ADX Talk.
 */
void ADXT_Finish(void);

/*	$func$ ADXT�n���h�� �̐���
 * [���@��] ADXT ADXT_Create(long maxnch, void *work, long worksize);
 * [���@��] maxnch	: �ő�Đ��`�����l�����i���m�����݂̂P�F�X�e���I�Q�j
 *			work	: ���[�N�̈�
 *			worksize: �������Đ��t���O�i�������Đ��̂�:1)
 * [�o�@��] �Ȃ�
 * [�֐��l] ADXT�n���h��
 * [�@�@�\] ADXT�n���h���𐶐�����B
 *			work�̈�̃T�C�Y�́AADXT_CALC_WORK�}�N���ɂ���ċ��߂�B
 *  Creation of ADXT handle
 * [Inputs  ] maxnch  : Number of maximum channels(monoral:1, stereo:2)
 *			  work    : Working area
 *			  worksize: Size of working area(byte)
 * [Outputs ] None
 * [Return  ] ADXT handle
 * [Function] Creates ADXT handle.
 * [Remarks ] You calculate size of working area used 'ADXT_CALC_WORK' macro. 
 */
ADXT ADXT_Create(long maxnch, void *work, long worksize);

/* $func$ ADXT�n���h�� �̏���
 * [���@��] void ADXT_Destroy(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �w�肳�ꂽ ADXT�n���h������������B
 *  Destroy of ADXT handle
 * [Inputs  ] adxt   : ADXT handle
 * [Outputs ] None
 * [Return  ] None
 * [Function] Destroys specified ADXT handle.
 */
void ADXT_Destroy(ADXT adxt);

/* $func$ FID �w��ɂ��Đ��̊J�n
 * [���@��] void ADXT_StartAfs(ADXT adxt, long patid, long fid);
 * [���@��] adxt	: ADXT�n���h��
 *			patid	: �p�[�e�B�V�������ʎq
 *			fid		: �t�@�C�����ʎq
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �p�[�e�B�V�������ʎq�ƃt�@�C�����ʎq�Ŏw�肳�ꂽ�`�c�w�t�@�C����
 *			�Đ����J�n����B
 *  Play start of ADX data by specified file ID
 * [Inputs  ] adxt	: ADXT handl
 *			  patid	: Partition ID
 *			  fid	: File ID
 * [Outputs ] None
 * [Return  ] None
 * [Function] Starts to play ADX file when you specify partition ID and file ID.
 */
void ADXT_StartAfs(ADXT adxt, long patid, long fid);

/* $func$ �t�@�C�����w��ɂ��Đ��̊J�n
 * [���@��] void ADXT_StartFname(ADXT adxt, char *fname);
 * [���@��] adxt	: ADXT�n���h��
 *			fname	: �t�@�C����
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] fname �Ŏw�肳�ꂽ�`�c�w�t�@�C���̍Đ����J�n����B
 *  Play start of ADX data specified file name
 * [Inputs  ] adxt	: ADXT handle
 *			  fname	: File name
 * [Outputs ] None
 * [Return  ] None
 * [Function] Starts to play ADX file when you specify file name.
 */
void ADXT_StartFname(ADXT adxt, char *fname);

/* $func$ �X�g���[���W���C���g�ɂ��Đ��̊J�n
 * [���@��] void ADXT_StartSj(ADXT adxt, SJ sj);
 * [���@��] adxt	: ADXT�n���h��
 *			sj		: �X�g���[���W���C���g
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �X�g���[���W���C���g���瓾����f�[�^���Đ�����B
 *  Play start of ADX data from Stream Joint
 * [Inputs  ] adxt	: ADXT handle
 *			  sj	: Stream Joint
 * [Outputs ] None
 * [Return  ] None
 * [Function] Starts to play ADX file when you specify Stream Joint.
 */
void ADXT_StartSj(ADXT adxt, SJ sj);

/* $func$ �������w��ɂ��Đ��̊J�n
 * [���@��] void ADXT_StartMem(ADXT adxt, void *adxdat);
 * [���@��] adxt	: ADXT�n���h��
 *			adxdat	: �`�c�w�f�[�^�̃A�h���X
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] adxdat�Ŏw�肳�ꂽ�`�c�w�f�[�^���Đ�����B
 *  Play start of ADX data on memory
 * [Inputs  ] adxt	: ADXT handle
 *			  adxdat: Address of ADX data
 * [Outputs ] None
 * [Return  ] None
 * [Function] Starts to play ADX data on memory when you specify address.
 */
void ADXT_StartMem(ADXT adxt, void *adxdat);

/* $func$ �������w��ɂ��Đ��̊J�n
 * [���@��] void ADXT_StartMem2(ADXT adxt, void *adxdat, long datlen);
 * [���@��] adxt	: ADXT�n���h��
 *			adxdat	: �`�c�w�f�[�^�̃A�h���X
 *			datlen	: �`�c�w�f�[�^�̑傫��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] adxdata �Ŏw�肳�ꂽ�`�c�w�f�[�^���Đ�����B
 *  Play start of ADX data on memory (TYPE 2)
 * [Inputs  ] adxt	: ADXT handle
 *			  adxdat: Address of ADX data
 *			  datlen: Length of playing ADX data
 * [Outputs ] None
 * [Return  ] None
 * [Function] Starts to play ADX data on memory. Plays to specified length.
 */
void ADXT_StartMem2(ADXT adxt, void *adxdat, long datlen);

/* $func$ �������w��ɂ��Đ��̊J�n
 * [���@��] void ADXT_StartMemIdx(ADXT adxt, void *acx, long no);
 * [���@��] adxt	: ADXT�n���h��
 *			acx		: �`�b�w�f�[�^�̃A�h���X
 *			no		: �C���f�b�N�X�ԍ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] acx �Ŏw�肳�ꂽ�`�b�w�f�[�^��no�Ԗڂ̃f�[�^���Đ�����B
 *  Play start of ACX data
 * [Inputs  ] adxt	: ADXT handle
 *			  acx	: Address of ACX data
 *			  no	: Index number
 * [Outputs ] None
 * [Return  ] None
 * [Function] Starts to play a part of ACX data when you specify index number.
 */
void ADXT_StartMemIdx(ADXT adxt, void *acx, long no);

/* $func$ �Đ��̒�~
 * [���@��] void ADXT_Stop(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �`�c�w�̍Đ����~����B
 *  Play stop
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] None
 * [Function] Stops to play ADX data.
 */
void ADXT_Stop(ADXT adxt);

/* $func$ ��Ԃ̎擾
 * [���@��] long ADXT_GetStat( ADXT adxt );
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] ���݂� ADXT�n���h���̏�Ԃ�\���萔
 * 				ADXT_STAT_STOP	 :	��~��
 *				ADXT_STAT_DECINFO:	�`�c�w �̃w�b�_���擾��
 *				ADXT_STAT_PREP	 :	�Đ�������
 *				ADXT_STAT_PLAYING:	�f�R�[�h���Đ���
 *				ADXT_STAT_DECEND :	�f�R�[�h�I��
 *				ADXT_STAT_PLAYEND:	�Đ��I��
 * [�@�@�\] ���݂�ADXT�n���h���̏�Ԃ��擾����B
 *  Get status
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] Status of ADXT handle
 * [Function] Obtains status of ADXT handle.
 */
long ADXT_GetStat(ADXT adxt);

/* $func$ �T���v���P�ʂł̍Đ������̎擾
 * [���@��] void ADXT_GetTime( ADXT adxt, long *ncount, long *tscale );
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] ncount	: �Đ��T���v����
 *			tscale	: �T���v�����O���g�� [ Hz ]
 * [�֐��l] �Ȃ�
 * [�@�@�\] �T���v���P�ʂōĐ��������擾����B
 *  Get play time by sample unit
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] ncount: Number of play sample
 *			  tscale: Sampling frequency(Hz)
 * [Return  ] None
 * [Function] Obtains play time by sample unit.
 */
void ADXT_GetTime(ADXT adxt, long *ncount, long *tscale);

/* $func$ �����Ԃł̍Đ������̎擾
 * [���@��] long ADXT_GetTimeReal(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Đ����� [ 1/100sec ]
 * [�@�@�\] �����ԂōĐ��������擾����B
 *  Get play time in real time
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] Play time(1/100sec)
 * [Function] Obtains play time in real time.
 */
long ADXT_GetTimeReal(ADXT adxt);

/* $func$ �����f�[�^�̑��T���v�����̎擾
 * [���@��] long ADXT_GetNumSmpl( ADXT adxt );
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �����f�[�^�̑��T���v����
 * [�@�@�\] �Đ����� �`�c�w �f�[�^�̑��T���v�������擾����B
 * [���@�l] ��Ԃ��A�Đ�������(ADXT_STAT_PREP)����Đ��I��(ADXT_STAT_PLAYEND)
 *			�܂ł̎��Ɏ擾�\�B
 *  Get a general sample number of sound data
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] General sample number of sound data
 * [Function] Obtains a general sample number of sound data.
 * [Remarks ] You can obtain a time between status of preparation
 *			  (ADXT_STAT_PREP) and status of play end(ADXT_STAT_PLAYEND).
 */
long ADXT_GetNumSmpl(ADXT adxt);

/* $func$ �����f�[�^�̃T���v�����O���g���̎擾
 * [���@��] long ADXT_GetSfreq(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �����f�[�^�̃T���v�����O���g��
 * [�@�@�\] �Đ����� �T���v�����O���g�������߂�B
 * [���@�l] ��Ԃ��A�Đ�������(ADXT_STAT_PREP)����Đ��I��(ADXT_STAT_PLAYEND)
 *			�܂ł̎��Ɏ擾�\�B
 *  Get sampling frequecy
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] Sampling frequency
 * [Function] Obtains sampling frequency.
 * [Remarks ] You can obtain a sampling frequency between status of preparation
 *			 (ADXT_STAT_PREP) and status of play end(ADXT_STAT_PLAYEND).
 */
long ADXT_GetSfreq(ADXT adxt);

/* $func$ �����f�[�^�̃`�����l�����̎擾
 * [���@��] long ADXT_GetNumChan(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �����f�[�^�̃`�����l�����̎擾
 * [�@�@�\] �Đ����̉����̃`�����l���������߂�B
 * [���@�l] ��Ԃ��A�Đ�������(ADXT_STAT_PREP)����Đ��I��(ADXT_STAT_PLAYEND)
 *			�܂ł̎��Ɏ擾�\�B
 */
long ADXT_GetNumChan(ADXT adxt);

/*	$func$ �p���|�b�g�̐ݒ�
 * [���@��] void ADXT_SetOutPan(ADXT adxt, long ch, long pan);
 * [���@��] adxt	: ADXT�n���h��
 *			ch		: �`���l���ԍ� (0, 1)
 *						ADXT_CH_L=0, ADXT_CH_R=1
 *			pan		: �p���ݒ�l (-15�`+15, -128)
 *						ADXT_PAN_LEFT=-15, ADXT_PAN_CENTER=0
 *						ADXT_PAN_RIGHT=15, ADXT_PAN_AUTO=-128
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �o�̓p���|�b�g��ݒ肷��B
 *			AUTO �̏ꍇ�́AADX �f�[�^�����m�������X�e���I���ɂ���Ď����I��
 *			�p�����ݒ肳���B
 *  Set panpot
 * [Inputs  ] adxt	: ADXT handle
 *			  ch	: Channel number(ADXT_CH_L:0, ADXT_CH_R:1)
 *			  pan	: Panpot(from -15 to +15, -128)
 *						ADXT_PAN_LEFT=-15, ADXT_PAN_CENTER=0
 *						ADXT_PAN_RIGHT=15, ADXT_PAN_AUTO=-128
 * [Outputs ] None
 * [Return  ] None
 * [Function] Sets panpot of specified channel number.
 *			 Sets automatically panpot by data, monoral or stereo, when you 
 *			 specified 'ADXT_PAN_AUTO'.
 */
void ADXT_SetOutPan(ADXT adxt, long ch, long pan);

/*	$func$ �p���|�b�g�̎擾
 * [���@��] void ADXT_GetOutPan(ADXT adxt, long ch);
 * [���@��] adxt	: ADXT�n���h��
 *			ch		: �`���l���ԍ� (0, 1)
 *						ADXT_CH_L=0, ADXT_CH_R=1
 * [�o�@��] �Ȃ�
 * [�֐��l] �p���|�b�g�̐ݒ�l
 * [�@�@�\] �o�̓p���|�b�g���擾����B
 *  Get panpot
 * [Inputs  ] adxt	: ADXT handle
 *			  ch	: Channel number(ADXT_CH_L:0, ADXT_CH_R:1)
 * [Outputs ] None
 * [Return  ] Panpot
 * [Function] Obtains panpot of specified channel number.
 */
long ADXT_GetOutPan(ADXT adxt, long ch);

/*	$func$ �o�̓{�����[���̐ݒ�
 * [���@��] void ADXT_SetOutVol(ADXT adxt, long vol);
 * [���@��] adxt	: ADXT�n���h��
 *			vol		: �������x���@(0:-0dB, -960:-96dB)
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �o�̓{�����[����ݒ肷��B
 *			vol�̐ݒ�l	0    :  -0dB  �����Ȃ�
 *						-30  :  -3dB  ��70%
 *						-60  :  -6dB  ��50%
 *						-960 : -96dB  �ő�̌�����
 *  Set volume
 * [Inputs  ] adxt	: ADXT handle
 *			  vol	: Volume (0:-dB, -960:-96dB)
 * [Outputs ] None
 * [Return  ] None
 * [Function] Sets the volume of a ADXT handle.
 *			 'vol'value	0    :  -0dB  No attenuation
 *						-30  :  -3dB  about 70%
 *						-60  :  -6dB  about 50%
 *						-960 : -96dB  Maximum attenuation
 */
void ADXT_SetOutVol(ADXT adxt, long vol);

/*	$func$ �o�̓{�����[���̎擾
 * [���@��] void ADXT_GetOutVol(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �o�̓{�����[���̐ݒ�l�@(0:-0dB �` -960:-96dB)
 * [�@�@�\] �o�̓{�����[�����擾����B
 *  Get volume
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] Volume (0:-0dB, -960:-96dB)
 * [Function] Obtains the volume for a ADXT handle.
 */
long ADXT_GetOutVol(ADXT adxt);

/*	$func$ �T�[�o�֐��̌Ăяo���p�x�̐ݒ�	(�P�b������̌Ăяo����)
 * [���@��] void ADXT_SetSvrFreq(ADXT adxt, long freq);
 * [���@��] adxt	: ADXT�n���h��
 *			freq	: �T�[�o�֐��̌Ăяo���p�x (�P�b������̌Ăяo����)
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �T�[�o�֐�(ADXT_ExecServer�֐�)�̌Ăяo���p�x�̐ݒ肷��B
 *			�f�t�H���g�ł́A60���ݒ肳��Ă���B
 *			�ʏ�A�ݒ肷��K�v�͂Ȃ��B
 *  Set the frequency called server function(times/sec)
 * [Inputs  ] adxt	: ADXT handle
 *			  freq	: Frequency called server function(times/sec)
 * [Outputs ] None
 * [Return  ] None
 * [Function] Sets the frequency called server function(ADXT_ExecServer).
 *			 You do not need to set it usually. Default value is 60.
 */
void ADXT_SetSvrFreq(ADXT adxt, long freq);

/*	$func$ �ēǂݍ��݊J�n�Z�N�^���̐ݒ�
 * [���@��] void ADXT_SetReloadSct(ADXT adxt, long minsct);
 * [���@��] adxt	: ADXT�n���h��
 *			minsct	: �ēǂݍ��݊J�n�Z�N�^��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ���̓o�b�t�@�ւ̍ēǂݍ��݊J�n�Z�N�^����ݒ肷��B
 *			���̓o�b�t�@���̃f�[�^�ʂ� minsct �Z�N�^��菭�Ȃ��Ȃ�Ƃb�c����
 *			�f�[�^��ǂݍ��ށB
 *  Set the number of start sector to reload
 * [Inputs  ] adxt	: ADXT handle
 *			  minsct: start sector number
 * [Outputs ] None
 * [Return  ] None
 * [Function] Sets of the number of start sector to reload into input buffer.
 *			 Reads data from CD-ROM when a quantity of data in the input 
 *			 buffer becomes less than 'minsct' [sector].
 */
void ADXT_SetReloadSct(ADXT adxt, long minsct);

/*	$func$ ���̓o�b�t�@���̃Z�N�^���̎擾
 * [���@��] long ADXT_GetNumSctIbuf(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Z�N�^��
 * [�@�@�\] ���̓o�b�t�@�ɓǂݍ��܂�Ă���Z�N�^�����擾����B
 *  Get the amount of data stored in input buffer(sector)
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] Number of sector
 * [Function] Obtains the amount of data that is stored in input buffer.
 */
long ADXT_GetNumSctIbuf(ADXT adxt);

/*	$func$ ���̓o�b�t�@�ɏ\���ȃf�[�^�����邩�ۂ��̌���
 * [���@��] long ADXT_IsIbufSafety(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] TRUE(1):�\���ȃf�[�^������AFALSE(0):�f�[�^�s��
 * [�@�@�\] ���̓o�b�t�@�ɏ\���ȃf�[�^�����邩�ۂ�����������B
 *			ADXT_SetReloadSct�֐��ɂ���Ďw�肳�ꂽ�ēǂݍ��݊J�n�Z�N�^���ȏ��
 *			�f�[�^�����̓o�b�t�@���ɑ��݂���ꍇ�ATRUE���Ԃ����B
 *  Check whether the input buffer is having enough data or not
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] TRUE(1):Has enough data, FALSE(0):Data are insufficient
 * [Function] Checks whether the input buffer is having enough data or not.
 *			  Returns 'TRUE' when data more than the number of sector appointed
 *			  exist in the input buffer.
 */
long ADXT_IsIbufSafety(ADXT adxt);

/*	$func$ �G���[���J�o���[���[�h�̎w��
 * [���@��] void ADXT_SetAutoRcvr(ADXT adxt, long rmode);
 * [���@��] adxt	: ADXT�n���h��
 *			rmode	: �G���[���J�o���[�̕��@
 *					  ADXT_RMODE_NOACT, ADXT_RMODE_STOP, ADXT_RMODE_REPLAY
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �G���[���J�o���[�̕��@��ݒ肷��B
 *			ADXT_RMODE_NOACT : �G���[���J�o���[���Ȃ�
 *			ADXT_RMODE_STOP  : �����I�ɒ�~���A�����Ԃ�ADXT_STAT_STOP�ɂȂ�B
 *			ADXT_RMODE_REPLAY: CD����̃f�[�^�̋������r�؂ꂽ�Ƃ��ɁA�����I��
 *							   �t�@�C���̐擪����Đ�����B
 *							   ���̑��̏ꍇ�́A�����I�ɒ�~������B
 *  Set a mode of error recovery
 * [Inputs  ] adxt	: ADXT handle
 *			  rmode	: Method of error recovery
 *					  ADXT_RMODE_NOACT, ADXT_RMODE_STOP, ADXT_RMODE_REPLAY
 * [Outputs ] None
 * [Return  ] None
 * [Function] Sets the method that recover from error.
 *			 ADXT_RMODE_NOACT : Does not recover
 *			 ADXT_RMODE_STOP  : Stops automatically
 *			 ADXT_RMODE_REPLAY: Replay from the top of a file automatically 
 *							    when data supply from CD-ROM broke off.
 *							    Other cases stop automatically.
 */
void ADXT_SetAutoRcvr(ADXT adxt, long rmode);

/*	$func$ �Đ����I���������ۂ��̌���
 * [���@��] long ADXT_IsCompleted(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] TRUE(1):�Đ��I���AFALSE(0):�Đ���
 * [�@�@�\] �Đ����I���������ۂ��𒲂ׂ�B
 *  Check whether the play finished or not
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] TRUE(1):Finished, FALSE(0):Playing
 * [Function] Checks whether the play finished or not.
 */
long ADXT_IsCompleted(ADXT adxt);

/*	$func$ �e�n���h���̃T�[�o�֐��@�i������Ԃ̍X�V)
 * [���@��] long ADXT_ExecHndl(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �e�n���h���̓�����Ԃ��X�V����B
 *			ADXT_ExecServer������Ăяo�����B
 *  Server function of each handle
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] None
 * [Function] Update the inside status.
 *			  This function is called from 'ADXT_ExecServer' function.
 */
void ADXT_ExecHndl(ADXT adxt);

/*	$func$ �T�[�o�֐��@�i������Ԃ̍X�V)
 * [���@��] long ADXT_ExecServer(void);
 * [���@��] �Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ���C�u�����̓�����Ԃ��X�V����B
 *			V-Sync ���ɌĂяo���Ȃ���΂Ȃ�Ȃ��B
 *  Server function
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] None
 * [Function] Update the inside status of library.
 */
void ADXT_ExecServer(void);

/*	$func$ �G���[�R�[�h�̎擾
 * [���@��] long ADXT_GetErrCode(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �G���[�R�[�h���擾����B
 *  Get error code
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] None
 * [Function] Obtains the error code.
 */
long ADXT_GetErrCode(ADXT adxt);

/*	$func$ �G���[�R�[�h�̃N���A
 * [���@��] void ADXT_ClearErrCode(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �G���[�R�[�h���N���A����B
 *  Clear error code
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] None
 * [Function] Clears the error code.
 */
void ADXT_ClearErrCode(ADXT adxt);

/*	$func$ ���[�v�����񐔂̎擾
 * [���@��] long ADXT_GetLpCnt(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] ���[�v������
 * [�@�@�\] ���[�v�����񐔂��擾����B
 *  Get the number of times played a loop
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] Number of times played a loop
 * [Function] Obtains the number of times that played a loop.
 */
long ADXT_GetLpCnt(ADXT adxt);

/*	$func$ ���[�v�t���O�̐ݒ�
 * [���@��] void ADXT_SetLpFlg(ADXT adxt, long flg);
 * [���@��] adxt	: ADXT�n���h��
 *			flg		: 1=���[�v����A0=���[�v���Ȃ�
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ���[�v���邩�ۂ���ݒ肷��B
 *  Set the loop flag
 * [Inputs  ] adxt	: ADXT handle
 *			  flg	: 1=loop, 0=not loop
 * [Outputs ] None
 * [Return  ] None
 * [Function] Sets whether play a loop or not.
 */
void ADXT_SetLpFlg(ADXT adxt, long flg);

/*	$func$ ���̓X�g���[���W���C���g�̎擾
 * [���@��] SJ ADXT_GetInputSj(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �X�g���[���W���C���g�n���h��
 * [�@�@�\] ���͗p�X�g���[���W���C���g���擾����B
 *  Get input Stream Joint
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] Stream Joint
 * [Function] Obtains Stream Joint for the input.
 */
SJ ADXT_GetInputSj(ADXT adxt);

/*	$func$ �����o�͊J�n�҂��̐ݒ�
 * [���@��] void ADXT_SetWaitPlayStart(ADXT adxt, long flg);
 * [���@��] adxt	: ADXT�n���h��
 *			flg		: 1=�E�F�C�g����A0=�����o�͂𑦍��ɊJ�n����
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �����̏o�͂̊J�n�҂���ݒ肷��B
 *  Set waiting for starting to output the sound
 * [Inputs  ] adxt	: ADXT handle
 *			  flg	: 1=waits, 0=starts to output sound
 * [Outputs ] None
 * [Return  ] None
 * [Function] Sets waiting for starting to output the sound.
 */
void ADXT_SetWaitPlayStart(ADXT adxt, long flg);

/*	$func$ �����o�͊J�n�����������ۂ��̔���
 * [���@��] void ADXT_IsReadyPlayStart(ADXT adxt);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �����o�͊J�n�̏������������ۂ��𔻒肷��B
 *  Check whether preparations completion
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] None
 * [Return  ] None
 * [Function] Checks whether ADXT handle was preparations completion.
 */
long ADXT_IsReadyPlayStart(ADXT adxt);

/*	$func$ �ꎞ��~�̐ݒ�
 * [���@��] void ADXT_Pause(ADXT adxt, long sw);
 * [���@��] adxt	: ADXT�n���h��
 *			sw		: 1=�ꎞ��~�A0=�ĊJ
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �ꎞ��~���邩�ۂ���ݒ肷��B
 *  Pause/Continue
 * [Inputs  ] adxt	: ADXT handle
 *			  sw	: 1=pause, 0=continue
 * [Outputs ] None
 * [Return  ] None
 * [Function] Stops temporarily by a specified switch and release temporary 
 *			  standstill.
 */
void ADXT_Pause(ADXT adxt, long sw);

/*	$func$ �G�t�F�N�^�̐ݒ�
 * [���@��] void ADXT_SetFx(ADXT adxt, long fxch, long fxlvl);
 * [���@��] adxt	: ADXT�n���h��
 *			fxch	: �G�t�F�N�^�̓��̓`�����l���ԍ� (0�`15)
 *			fxlvl	: �G�t�F�N�^�̓��̓��x���@(0�`15)
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �G�t�F�N�^�ւ̏o�͂�ݒ肷��B
 *  Set the effect
 * [Inputs  ] adxt	: ADXT handle
 *			  fxch	: Input channel number to Effector (0-15)
 *			  fxlvl	: Input level to Effector(from 0 to -45[dB])
 * [Outputs ] None
 * [Return  ] None
 * [Function] Sets output to the effect.
 */
void ADXT_SetFx(ADXT adxt, long fxch, long fxlvl);

/*	$func$ �G�t�F�N�^�ݒ�l�̎擾
 * [���@��] void ADXT_GetFx(ADXT adxt, long *fxch, long *fxlvl);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] fxch	: �G�t�F�N�^�ւ̓��̓`�����l���ԍ� (0�`15)
 *			fxlvl	: �G�t�F�N�^�ւ̓��̓��x���@(0�`15)
 * [�֐��l] �Ȃ�
 * [�@�@�\] �G�t�F�N�^�̐ݒ�l���擾����B
 *  Get the effect value
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] fxch	: Input channel number to Effector(0-15)
 *			  fxlvl	: Input level to Effector(from 0 to -45[dB])
 * [Return  ] None
 * [Function] Obtains the effect value.
 */
void ADXT_GetFx(ADXT adxt, long *fxch, long *fxlvl);

/*	$func$ �t�B���^�̐ݒ�
 * [���@��] void ADXT_SetFilter(ADXT adxt, long coff, long q);
 * [���@��] adxt	: ADXT�n���h��
 *			coff	: �J�b�g�I�t���g��
 *			q		: ��s�x
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �t�B���^�ւ̏o�͂�ݒ肷��B
 *  Set the filter
 * [Inputs  ] adxt	: ADXT handle
 *			  coff	: Cut off frequency
 *			  q		: 
 * [Outputs ] None
 * [Return  ] None
 * [Function] Sets the filter.
 */
void ADXT_SetFilter(ADXT adxt, long coff, long q);

/*	$func$ �t�B���^�ݒ�l�̎擾
 * [���@��] void ADXT_GetFilter(ADXT adxt, long *coff, long *q);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] coff	: �J�b�g�I�t���g��
 *			q		: ��s�x
 * [�֐��l] �Ȃ�
 * [�@�@�\] �t�B���^�ւ̏o�͒l���擾����B
 *  Get the filter value
 * [Inputs  ] adxt	: ADXT handle
 * [Outputs ] coff	: Cut off frequency
 *			  q		: 
 * [Return  ] None
 * [Function] Obtains the filter value.
 */
void ADXT_GetFilter(ADXT adxt, long *coff, long *q);

/*	$func$ �g�����X�|�[�Y�̐ݒ�
 * [���@��] void ADXT_SetTranspose(ADXT adxt, long transps, long detune);
 * [���@��] adxt	: ADXT�n���h��
 *			transps	: �g�����X�|�[�Y��
 *			detune	: �f�`���[����
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �g�����X�|�[�Y��ݒ肷��B
 *  Set transpose
 * [Inputs  ] adxt		: ADXT handle
 *			  transps	: Amount of transpose
 *			  detune	: Amount of detune
 * [Outputs ] None
 * [Return  ] None
 * [Function] Sets the transpose.
 */
void ADXT_SetTranspose(ADXT adxt, long transps, long detune);

/*	$func$ �g�����X�|�[�Y�̎擾
 * [���@��] void ADXT_GetTranspose(ADXT adxt, long *transps, long *detune);
 * [���@��] adxt	: ADXT�n���h��
 * [�o�@��] transps	: �g�����X�|�[�Y��
 *			detune	: �f�`���[����
 * [�֐��l] �Ȃ�
 * [�@�@�\] �g�����X�|�[�Y�ʂ��擾����B
 *  Get tanspose
 * [Inputs  ] adxt		: ADXT handle
 * [Outputs ] transps	: Amount of transpose
 *			  detune	: Amount of detune
 * [Return  ] None
 * [Function] Obtains the amount of transpose.
 */
void ADXT_GetTranspose(ADXT adxt, long *transps, long *detune);

/*	$func$ �G���[�֐��̓o�^
 * [���@��] void ADXT_EntryErrFunc(void (*func)(void *obj, char *msg),
 *																void *obj);
 * [���@��] func	: �G���[�����֐�
 *			obj		: �G���[�����֐��̑�1����
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] �G���[�����֐���o�^����B
 *  Entry error callback function
 * [Inputs  ] func	: Error handling function
 *			  obj	: First argument of error handling function
 * [Outputs ] None
 * [Return  ] None
 * [Function] Entry error callback function.
 */
void ADXT_EntryErrFunc(void (*func)(void *obj, char *msg), void *obj);

/*	$func$ �����f�[�^�̕���
 * [���@��] long ADXT_DiscardSmpl(ADXT adxt, long nsmpl)
 * [���@��] adxt	: ADXT�n���h��
 *			nsmpl	: �T���v����
 * [�o�@��] �Ȃ�
 * [�֐��l] �̂Ă��T���v����
 * [�@�@�\] �f�R�[�h���������f�[�^���̂Ă�B
 *  Discard sound data
 * [Inputs  ] adxt	: ADXT handle
 *			  nsmpl	: Number of sample
 * [Outputs ] None
 * [Return  ] sample number discarded
 * [Function] Discards sound data decoded.
 */
long ADXT_DiscardSmpl(ADXT adxt, long nsmpl);

/***
*			�U�����o�@�\
***/

/*	�U���擾�p��Ɨ̈�̑傫���̌v�Z	*/
long ADXT_CalcAmpWork(long maxnch);
/*	�U���擾�p��Ɨ̈�̐ݒ�	*/
void ADXT_SetAmpWork(ADXT adxt, void *work, long wksize);
/*	�U���̎擾	*/
long ADXT_GetAmplitude(ADXT adxt, long ch);

/*	�w�b�_���̋����}��	*/
void ADXT_InsertHdrSfa(ADXT adxt, long nch, long sfreq, long nsmpl);
/*	�^�C���I�t�Z�b�g�̐ݒ�	*/
void ADXT_SetTimeOfst(ADXT adxt, long ofst);

/***
*			Sofdec�p�g���֐�
***/

/* ADX�w�b�_�̔��� */
long ADXT_IsHeader(char *adr, long siz, long *hdrsiz);

/* ADX�I���R�[�h�̔��� */
long ADXT_IsEndcode(char *adr, long siz, long *endsiz);
/*
	adr   �F�I������|�C���^(ADX�f�[�^��36�o�C�g���E)
	siz   �F�I������T�C�Y (����ɕK�v�ȃT�C�Y�͍��X���o�C�g
			��������܂��񂪁A�t�@�C�����[�h���āA�o�b�t�@��
			�~�ς���Ă���T�C�Y����͂��܂�)
	ndsiz�F�I���R�[�h�T�C�Y�i�t�b�^�T�C�Y�j
*/

/* �����f�[�^�̋����}�� */
long ADXT_InsertSilence(ADXT adxt, long nch, long nsmpl);
/*
	nsmpl �@�F�}���v���T���v���� [sample/1ch]
	�֐��l  �F�}�����s�T���v���� (0 �` nsmpl)
			  ADXT���͗pSJ�ɏ\���ȋ󂫂������ nsmpl �̒[����
			  �؂�̂Ă��l���Ԃ�B
*/

#ifdef __cplusplus
}
#endif

#endif
