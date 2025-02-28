#ifndef	_CRI_SAN_H_INCLUDED
#define	_CRI_SAN_H_INCLUDED
/****************************************************************************/
/*																			*/
/*			$title$ �ȈՃA�j���[�V���� ���C�u����							*/
/*				SAN (Simple Animation) Library								*/
/*																			*/
/*			Copyright (c) 1999 CSK Research Institute						*/
/*				1998.7.28		written by S.Hosaka							*/
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

/*	Version No.					*/
#define	SAN_VER					"1.09"

/*	�n���h���̌�				*/
/*	Maximum number of handle	*/
#define	SAN_OBJ_MAX				(4)

/*	�������[�h					*/
/*	Composite mode				*/
#define SAN_COMPO_OPEQ			(0x0000)	/*	�s����						*/
											/*	Opaque						*/
#define SAN_COMPO_TRNSP			(0x0001)	/*	���� (���_���̂�)			*/
											/*	Translucent					*/
#define SAN_COMPO_ADD			(0x0002)	/*	���Z����					*/
											/*	Add							*/
#define SAN_COMPO_LUMI			(0x0004)	/*	���~�l�b�Z���X����			*/
											/*	Luminous					*/
#define SAN_COMPO_ALPH3			(0x0005)	/*	3�l�A���t�@����				*/
											/*	3 step alpha				*/
#define SAN_COMPO_ALPH5			(0x0006)	/*	5�l�A���t�@����				*/
											/*	5 step alpha				*/
#define SAN_COMPO_ALPH256		(0x0007)	/*	�t���A���t�@����			*/
											/*	256 step alpha				*/
#define SAN_COMPO_MIX			SAN_COMPO_LUMI
											/*	Mixing composite mode		*/

/*	�P�x						*/
/*	Brightness					*/
#define	SAN_BRIGHT_MAX			(255)
#define	SAN_BRIGHT_MIN			(0)
#define	SAN_BRIGHT_SRF_MAX		(1.0f)
#define	SAN_BRIGHT_SRF_MIN		(0.0f)

/*	�P�x�̃f�t�H���g�l									*/
/*	Sofdec�̃f�t�H���g�l(sfdfx_mw.h�Œ�`)				*/
/*	Default value of brightness							*/
/*	It is same with Sofdec(definition in sfdfx_mw.h)	*/
#ifndef MWD_DFL_BRIGHT
#define MWD_DFL_BRIGHT			(0xe0)
#endif

/*	�P�x�I�t�Z�b�g�̃f�t�H���g�l						*/
/*	Sofdec�̃f�t�H���g�l(sfdfx_mw.h�Œ�`)				*/
/*	Default value of brightness offset					*/
/*	It is same with Sofdec(definition in sfdfx_mw.h)	*/
#ifndef MWD_DFL_BRIGHT_OFST
#define MWD_DFL_BRIGHT_OFST		(6)
#endif

/*	�\���X�N���[���̉��s��	*/
/*	Depth of screen			*/
#define	SAN_DLZ_MAX				(65536.0f)	/*	��							*/
											/*	inmost						*/
#define	SAN_DLZ_MIN				(1.0f)		/*	��O						*/
											/*	this side					*/

/*	�\���X�N���[���̉��s���̃f�t�H���g�l		*/
/*	Default value of screen depth				*/
#define SAN_DEF_DLZ				(65536.0f)

/****************************************************************************/
/*		�񋓒萔															*/
/*		Enumarate Constants													*/
/****************************************************************************/

/****************************************************************************/
/*		�����}�N��															*/
/*		Process MACRO														*/
/****************************************************************************/

/****************************************************************************/
/*		�f�[�^�^															*/
/*      Data type declaration												*/
/****************************************************************************/

/*	�ȈՃA�j���[�V�����t�@�C���w�b�_	*/
/*	SAN file header						*/
typedef struct {
	char id_hdr[4];						/*	�w�b�_�`�����NID("SAN ")		*/
										/*	Header chunk ID ("SAN ")		*/
	long len_hdr;						/*	�w�b�_�`�����N�T�C�Y			*/
										/*	Header chunk size				*/
	char id_fmt[4];						/*	�t�H�[�}�b�gID					*/
										/*	Format ID						*/
	long npic;							/*	�s�N�`����						*/
										/*	Number of picture				*/
	long sx;							/*	�������̃T�C�Y					*/
										/*	Width of video					*/
	long sy;							/*	�c�����̃T�C�Y					*/
										/*	Height of video					*/
	long psize;							/*	�P�s�N�`���̃o�C�g��			*/
										/*	Byte per picture				*/
	long vsize;							/*	�f���f�[�^�̃o�C�g��			*/
										/*	Video size (byte)				*/
	long msize;							/*	�}�X�N�f�[�^�̃o�C�g��			*/
										/*	Mask size (byte)				*/
	char mskflg;						/*	�}�X�N�f�[�^�����邩�ۂ�		*/
										/*	Mask data flag					*/
	char valph;							/*	�f���f�[�^���̃��l(0 or 3 or 5)	*/
										/*	Alpha value in video data(0/3/5)*/
	short compo_mode;					/*	�������[�h						*/
										/*	Composite mode					*/
	long rsv2[4];						/*	�\��̈� 2						*/
										/*	Reserved						*/
	char id_dat[4];						/*	�f�[�^�`�����NID				*/
										/*	Data chunk ID					*/
	long len_dat;						/*	�f�[�^�`�����N�T�C�Y			*/
										/*	Data chunk size (byte)			*/
	long data;							/*	�f�[�^�{��						*/
										/*	Data							*/
} SAN_HDR;
typedef	SAN_HDR	*SANHDR;

/*	�ȈՃA�j���[�V�����n���h��			*/
/*	SAN handle							*/
#ifndef SAN_DEFINED
#define SAN_DEFINED
typedef void *SAN;
#endif

/*	�T�[�t�F�X���\����				*/
/*	Surface information					*/
typedef struct {
	void	*srf;						/*	�T�[�t�F�X						*/
										/*	Surface							*/
	long	width;						/*	�L���T�[�t�F�X�T�C�Y ��			*/
										/*	Width of valid surface			*/
	long	height;						/*	�L���T�[�t�F�X�T�C�Y ����		*/
										/*	Height of valid surface			*/
} SAN_PIC;

/*	�G���[�o�^�֐�						*/
/*	Error entry function				*/
typedef void (*SAN_ERRFN)(void *obj, char *msg);

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

/*==========================================================================*/
/*	�������ƏI������														*/
/*	Initialize and Finalize of Library										*/
/*==========================================================================*/

/*	���C�u�����̏�����						*/
/*  Initialization of library				*/
void SAN_Init(void);

/*	���C�u�����̏I������					*/
/*  Termination of library					*/
void SAN_Finish(void);

/*	���C�u�����̏�����(for Kamui)			*/
/*  Initialization of library(for Kaumi)	*/
void SAN_InitKm(void);

/*	���C�u�����̏I������(for Kamui)			*/
/*  Termination of library(for Kaumi)		*/
void SAN_FinishKm(void);

/*	���_�o�b�t�@�̐ݒ�	*/
/*	Set vertex buffer	*/
void SAN_SetVertexBuffer(void *vbuf);

/*==========================================================================*/
/*	��{����																*/
/*	Basic Control															*/
/*==========================================================================*/

/*	��Ɨ̈�T�C�Y�̌v�Z					*/
/*	Calculation of working area size		*/
long SAN_CalcWorkSize(long ntex);

/*	��Ɨ̈�T�C�Y�̌v�Z(for alpha)				*/
/*	Calculation of working area size(for alpha)	*/
long SAN_CalcWorkSizeAlph(long ntex, long alph_flg);

/*	�n���h���̐���							*/
/*	Creation of Handle						*/
SAN SAN_Create(void *sandat, long ntex, void *wk);

/*	�n���h���̏���							*/
/*	Destroy of Handle						*/
void SAN_Destroy(SAN san);

/*	YUV420�f�[�^��V-RAM�ւ̓]��				*/
/*	Transfer YUV420 data to V-RAM			*/
void SAN_LoadTex(SAN san, long sno, long dno);

/*	�e�N�X�`���̕\��						*/
/*	Draw texture							*/
void SAN_Draw(SAN san, long dno);

/*	�s�N�`�����̎擾						*/
/*	Get number of picture in SAN data		*/
long SAN_GetNumPic(SAN san);

/*==========================================================================*/
/*	�\������																*/
/*	Display Control															*/
/*==========================================================================*/

/*	�\���ʒu�̐ݒ�							*/
/*	Set location of the display				*/
void SAN_SetDispPos(SAN san, float lx, float ly);

/*	�\���T�C�Y�̐ݒ�						*/
/*	Set size of the display					*/
void SAN_SetDispSize(SAN san, float sx, float sy);

/*	�\���X�N���[���̉��s���l�̐ݒ�			*/
/*	Get Z coordinary of screen				*/
void SAN_SetDispZ(SAN san, float z);

/*	�\���X�N���[���̉��s���l�̎擾	(z:1.0-65536.0)	*/
/*	Get Z coordinary of screen	(z:1.0-65536.0)		*/
float SAN_GetDispZ(SAN san);

/*	�P�x�̐ݒ� (val= 0-255)					*/
/*	Set brightness (val= 0-255)				*/
void SAN_SetDispBright(SAN san, long val);

/*	�P�x�̎擾								*/
/*	Get brightness							*/
long SAN_GetDispBright(SAN san);

/*	�P�x�̃I�t�Z�b�g�ݒ� (val= 0-255)		*/
/*	Set brightness offset (value= 0-255)	*/
void SAN_SetDispBrightOfst(SAN san, long val);

/*	�P�x�I�t�Z�b�g�̎擾					*/
/*	Get brightness offset					*/
long SAN_GetDispBrightOfst(SAN san);

/*==========================================================================*/
/*	�T�[�t�F�X����															*/
/*	Surface Control															*/
/*==========================================================================*/

/*	�T�[�t�F�X�|�C���g�p�o�b�t�@�T�C�Y�̌v�Z	*/
/*	Calcuration size of surface point buffer 	*/
long SAN_CalcSrfBufSize(SAN san, long npnt);

/*	�T�[�t�F�X�|�C���g�p�o�b�t�@�̐ݒ�			*/
/*	Set surface point buffer					*/
void SAN_SetSrfPntBuf(SAN san, long npnt, void *buf, long bsize);

/*	�\���ʒu�̐ݒ�								*/
/*	Set display position of surface point		*/
void SAN_SetSrfPos(SAN san, unsigned long no, float lx, float ly, float lz);

/*	�\���ʒu�̎擾								*/
/*	Get display position of surface point		*/
void SAN_GetSrfPos(SAN san, unsigned long no, float *lx, float *ly, float *lz);

/*	�P�x�̐ݒ�									*/
/*	Set brightness of surface point				*/
void SAN_SetSrfBright(SAN san, unsigned long no,
									float a, float r, float g, float b);

/*	�P�x�̎擾									*/
/*	Get brightness of surface point				*/
void SAN_GetSrfBright(SAN san, unsigned long no,
									float *a, float *r, float *g, float *b);

/*	�P�x�I�t�Z�b�g�̐ݒ�						*/
/*	Set brightness offset of surface point		*/
void SAN_SetSrfBrightOfst(SAN san, unsigned long no,
									float a, float r, float g, float b);

/*	�P�x�I�t�Z�b�g�̎擾						*/
/*	Get brightness offset of surface point		*/
void SAN_GetSrfBrightOfst(SAN san, unsigned long no,
									float *a, float *r, float *g, float *b);

/*	�C���[�W�ʒu�̐ݒ�							*/
/*	Set image position of surface point			*/
void SAN_SetImgPos(SAN san, unsigned long no, float lx, float ly);

/*	�C���[�W�ʒu�̎擾							*/
/*	Get image position of surface point			*/
void SAN_GetImgPos(SAN san, unsigned long no, float *lx, float *ly);

/*	�C���[�W�T�C�Y�̎擾						*/
/*	Get image size								*/
void SAN_GetImgSize(SAN san, long *isx, long *isy);

/*==========================================================================*/
/*	�e�N�X�`��																*/
/*	Texture																	*/
/*==========================================================================*/

/*	�r�f�I�s�N�`���̎擾	*/
void SAN_GetVideoPic(SAN san, long dno, SAN_PIC *pic);

/*	�}�X�N�s�N�`���̎擾	*/
void SAN_GetMskPic(SAN san, long dno, SAN_PIC *pic);

/*==========================================================================*/
/*	�G���[����																*/
/*	Error																	*/
/*==========================================================================*/

/*	�G���[�����֐��̓o�^						*/
/*	Entrying function when error happened		*/
void SAN_EntryErrFunc(SAN_ERRFN errfn, void *obj);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif	/* _CRI_SAN_H_INCLUDED */
