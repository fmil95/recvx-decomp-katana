/*
 *  Middleware Library
 *  Copyright (c) 1998,1999 SEGA
 *  
 *		MPEG Sofdec
 *
 *  Module  : Library Header File
 *  File    : SFD_MW.H
 *  Create  : 1998-07-25
 *  Modify  : 1999-03-12
 *  Note    :
 */

#ifndef	_SFD_MW_H_
#define	_SFD_MW_H_

/*	Version No.	*/
#define	MWD_SFD_VER	"2.19"

/***************************************************************************
 *      MACRO CONSTANT
 ***************************************************************************/

/*	Sofdec Error						*/
#define	MWD_PLY_ERR_SFD_INIT	(-301)
#define	MWD_PLY_ERR_SFD_NOTYPE	(-302)
#define	MWD_PLY_ERR_SFD_ERRFN	(-303)
#define	MWD_PLY_ERR_SFD_FINISH	(-304)
#define	MWD_PLY_ERR_SFD_CREATE	(-305)
#define	MWD_PLY_ERR_SFD_DSTRY	(-306)
#define	MWD_PLY_ERR_SFD_START	(-307)
#define	MWD_PLY_ERR_SFD_STOP	(-308)
#define	MWD_PLY_ERR_SFD_GETTIME	(-309)
#define	MWD_PLY_ERR_SFD_PAUSE	(-310)
#define	MWD_PLY_ERR_SFD_STANDBY	(-311)

/*	�t�@�C���^�C�v						*/
/*	File type							*/
#define	MWD_PLY_FTYPE_NON		(0)
#define	MWD_PLY_FTYPE_SFD		(1)
#define	MWD_PLY_FTYPE_MPV		(2)

/*	�f�R�[�_�^�C�v						*/
/*	Decode type							*/
#define	MWD_DECTYP_NON			(0)
#define	MWD_DECTYP_SOFDEC		(1)

/*	�\�����C�e���V						*/
/*	Display latency						*/
#define	MWD_LATENCY_2V			(2)
#define	MWD_LATENCY_3V			(3)

/*	GSC�n���h���ő吔					*/
/*	Maximum number of GSC handle		*/
#define	MWD_GSCHN_MAX			(1)

/*	����̕\���^�C�v					*/
/*	Display type of animation			*/
#define MWD_PLY_DTYPE_AUTO	(0)
#define MWD_PLY_DTYPE_FULL	(1)
#define MWD_PLY_DTYPE_WND	(2)
#define MWD_PLY_DTYPE_SRF	(3)

/*	�P�x�̃f�t�H���g�l					*/
/*	Default value of brightness			*/
#if 0
#define MWD_DFL_BRIGHT		(0xea)		/* mwSfd Ver1.11 */
#define MWD_DFL_BRIGHT		(0xff)
#endif
#define MWD_DFL_BRIGHT		(0xe0)		/*	Ver.1.20	*/

/*	�P�x�I�t�Z�b�g�̃f�t�H���g�l		*/
/*	Default value of brightness offset	*/
/*
#define MWD_DFL_BRIGHT_OFST	(0)
*/
#define MWD_DFL_BRIGHT_OFST	(6)			/*	Ver.1.20	*/

/*	�\���X�N���[���̉��s���̃f�t�H���g�l		*/
/*	Default value of z coordinay	*/
#define MWD_DFL_DLZ			(65536.0f)

/*	�������[�h			*/
/*	Composition Mode	*/
#define MWD_PLY_COMPO_OPEQ			(0x0000)	/*	�s����					*/
#define MWD_PLY_COMPO_TRNSP			(0x0001)	/*	���� (���_���̂�)		*/
#define MWD_PLY_COMPO_ADD			(0x0002)	/*	���Z����				*/
#define MWD_PLY_COMPO_LUMI			(0x0004)	/*	���~�l�b�Z���X����		*/
#define MWD_PLY_COMPO_ALPH3			(0x0005)	/*	3�l�A���t�@����			*/
#define MWD_PLY_COMPO_ALPH5			(0x0006)	/*	5�l�A���t�@����			*/
#define MWD_PLY_COMPO_ALPH256		(0x0007)	/*	�t���A���t�@����		*/
#define MWD_PLY_COMPO_SANDWICH		(0x0008)	/*	�T���h�E�B�b�`����		*/
#define MWD_PLY_COMPO_MAT			(0x0009)	/*	�}�b�g����				*/
#define MWD_PLY_COMPO_MIX			MWD_PLY_COMPO_LUMI

/***************************************************************************
 *      Process MACRO
 ***************************************************************************/

/*	�I�[�f�B�I�o�̓o�b�t�@�̃T�C�Y			*/
/*	Calculation of audio output buffer size	*/
#define	MWD_SFD_CALC_WORK_AUDIO_OUT(nch)	(0x2020*sizeof(short)*(nch)+32)

/*	�I�[�f�B�I�o�̓o�b�t�@�T�C�Y(�f�t�H���g�l)	*/
/*	Default size of audio output buffer			*/
#define	MWD_SFD_CALC_WORK_AUDIO_OUT0	MWD_SFD_CALC_WORK_AUDIO_OUT(2)

/*	�I�[�f�B�I���̓o�b�t�@�T�C�Y			*/
/*	Default size of audio input buffer size	*/
#define	MWD_SFD_CALC_WORK_AUDIO_IN			(36*2048+32)

/*	�I�[�f�B�I�p�o�b�t�@�T�C�Y				*/
/*	Buffer size for the audio system		*/
#define	MWD_SFD_SIZE_WORK_AUDIO(nch)	( \
				MWD_SFD_CALC_WORK_AUDIO_OUT0 + \
				MWD_SFD_CALC_WORK_AUDIO_IN \
			)

/*	�Q�Ɨp�t���[���o�b�t�@�T�C�Y					*/
/*	Calculation of frame buffer size for reference	*/
#define	MWD_SFD_CALC_WORK_RFB(wc, hc, wy, hy)	\
								SFD_RFB_BUF_SIZ((wc), (hc), (wy), (hy))

/*	�Q�Ɨp�t���[���o�b�t�@�T�C�Y(�f�t�H���g�l)		*/
/*	Default value of frame buffer size for reference*/
#define	MWD_SFD_CALC_WORK_RFB0 \
				MWD_SFD_CALC_WORK_RFB(	SFD_RFB_WIDTH_C, \
										SFD_RFB_HEIGHT_C, \
										SFD_RFB_WIDTH_Y, \
										SFD_RFB_HEIGHT_Y )

/*	�o�͗p�t���[���o�b�t�@�T�C�Y					*/
/*	Calculation of frame buffer size for output		*/
#define	MWD_SFD_CALC_WORK_TAB(wy, hy, nfrm)	\
								SFD_TA_BUF_SIZ((wy), (hy), (nfrm))

/*	�o�͗p�t���[���o�b�t�@�T�C�Y(�f�t�H���g�l)		*/
/*	Default value of frame buffer size for output	*/
#define MWD_SFD_CALC_WORK_TAB0	\
				MWD_SFD_CALC_WORK_TAB(SFD_RFB_WIDTH_Y, SFD_RFB_HEIGHT_Y, 4)

#define	MWD_SFD_CALC_WORK(sx, sy, nch)	\
		MWD_SFD_CALC_WORK_AUDIO(2) +	\
		
/*	��Ɨ̈�̃T�C�Y									*/
/*	Size of working area								*/
#define	MWD_SFD_SIZE_WORK		(0x00300000)

/*
 *  �\�����C�e���V
 *  ���_�o�^�p�o�b�t�@�T�C�Y���画�f�ł���B
 *  1���}�C�i�X�ɂ����2V���[�e���V���[�h�B
 *	Display latency
 *	It is possible to judge from vertex buffer size.
 *	It become 2V latency mode when you turn one argument into 
 *	negative number.
 */
#define	MWD_PLY_LATENCY(op, om, tp, tm, pt) ( \
			((op) < 0) ? MWD_LATENCY_2V : \
			((om) < 0) ? MWD_LATENCY_2V : \
			((tp) < 0) ? MWD_LATENCY_2V : \
			((tm) < 0) ? MWD_LATENCY_2V : \
			((pt) < 0) ? MWD_LATENCY_2V : MWD_LATENCY_3V)


/***************************************************************************
 *      Data type declaration
 ***************************************************************************/

/*	Sofdec�̏������p�����[�^�\����							*/
/*	Parameter structure of Sofdec initialization function	*/
typedef struct {
	/*	Ninja�Ŏ��ۂɐݒ肵���\�����[�h�Ɠ����l��ݒ肵�ĉ����� 			*/
	/*	Please set the value same as mode that you set in Ninja				*/
	Sint32		mode;			/*	��ʃ��[�h								*/
								/*	Picture mode							*/
	Sint32		frame;			/*	�t���[���o�b�t�@�̃J���[���[�h 			*/
								/*	Color mode of the frame buffer			*/
	Sint32		count;			/*	�t���[���J�E���g��						*/
								/*	Number of frame count					*/
	Sint32		latency;		/*	�\�����C�e���V (2or3)					*/
								/*	Display latency(2 or 3)					*/
	Sint32		rsv[4];			/*	�\�� (�S��0��ݒ肵�ĉ�����) 			*/
								/*	Reserved(Please set 0 in all of area)	*/
} MWS_PLY_INIT_SFD;

/*	�n���h�������p�����[�^�\����			*/
/*	Parameter structure of handle creation	*/
typedef struct {
	Sint32	ftype;				/*	�Đ�����X�g���[���̎�� 				*/
								/*	File type								*/
	Sint32	max_bps;			/*	�ő�̃r�b�g�X�g���[���ʁ@(bit/sec)		*/
								/*	Maximum number of bit per second		*/
	Sint32	max_width;			/*	�Đ��摜�T�C�Y�̍ő啝					*/
								/*	Maximum width of video stream			*/
	Sint32	max_height;			/*	�Đ��摜�T�C�Y�̍ő卂��				*/
								/*	Maximum height of video stream			*/
	Sint32	nfrm_pool_wk;		/*	�V�X�e���̈�̃t���[���v�[�����i�ʏ�3)	*/
								/*	�t���[�����������������ꍇ�́A���̒l��	*/
								/*	���₵�Ă��������B						*/
								/*	Number of frame pools in system memory.	*/
								/*	Normaly this number is 3. If frame is 	*/
								/*	droped,you have to increase this number.*/
	Sint8	*work;				/*	���[�N�̈�								*/
								/*	Address of working area					*/
	Sint32	wksize;				/*	���[�N�̈�T�C�Y						*/
								/*	Size of working area					*/
	Sint32  dtype;				/*	�\���^�C�v								*/
								/*	Display type							*/
	Sint32  compo_mode;			/*	�������[�h								*/
								/*	Composition mode						*/
} MWS_PLY_CPRM_SFD;

/* �f���T�[�t�F�X���\���� */
typedef struct {
	void *srf;		/* �T�[�t�F�X   	        */
	Sint32 width;	/* �L���T�[�t�F�X�T�C�Y ��   */
	Sint32 height;	/* �L���T�[�t�F�X�T�C�Y ���� */
} MWS_PLY_MVFRM;

/***************************************************************************
 *      Function Declaration
 ***************************************************************************/

/*	�V�X�e���̏�����(sbInitSystem�̑O�ɌĂԊ֐�)					*/
/*	Initialization of system										*/
/*	(Call this function before 'sbInitSystem' function)				*/
void mwPlyPreInitSofdec(void);

/*	Initialization of Sofdec library for Kamui or Kamui2	*/
void mwPlyInitSfdFx(MWS_PLY_INIT_SFD *iprm);

/*	Termination of Sofdec library for Kamui or Kamui2 */
void mwPlyFinishSfdcFx(void);

/*	Initialization of Sofdec library for Ninja	*/
void mwPlyInitSofdec(MWS_PLY_INIT_SFD *iprm);

/*	Termination of Sofdec library for Ninja */
void mwPlyFinishSofdec(void);

/*	Initialization of Sofdec library for Ninja2	*/
void mwPlyInitSfdNj2(MWS_PLY_INIT_SFD *iprm);

/*	Termination of Sofdec library for Ninja2 */
void mwPlyFinishNj2(void);

/*	Set vertex buffer to draw movie's image */
void mwPlySetVertexBuffer(void *vbuf);

/*	Server Function to load texture */
void mwPlyExecTexSvr(void);

/*	Server Function to draw movie image */
void mwPlyExecDrawSvr(void);

/*	Create MWPLY handle for Sofdec		*/
MWPLY mwPlyCreateSofdec(MWS_PLY_CPRM_SFD *cprm);

/*	��Ɨ̈�T�C�Y�̌v�Z				*/
/*	Calculation of working area size	*/
Sint32 mwPlyCalcWorkSofdec(
	Sint32 ftype, Sint32 max_bps, Sint32 max_sx, Sint32 max_sy, Sint32 nfb);

/*	��Ɨ̈�T�C�Y�̌v�Z	*/
/*	Calculation of working area size from create parameter	*/
Sint32 mwPlyCalcWorkCprmSfd(MWS_PLY_CPRM_SFD *cprm);

/*	�\�����[�h�̐ݒ�
 *	[����]
 *		mode		:��ʃ��[�h
 *		frame		:�t���[���o�b�t�@�̃J���[���[�h
 *		count		:�t���[���J�E���g��
 *		latency		:�\�����C�e���V (2V���C�e���V�𐄏�)
 *	[����]
 *	 Ninja�Ŏ��ۂɐݒ肵���\�����[�h�Ɠ����l��ݒ肵�ĉ������B
 *	 ���������� MWS_PLY_INIT_SFD �Őݒ肵���ꍇ�A���̊֐��͕K�v����܂���B
 *	 �\�����[�h��ύX�����ꍇ�́A���̊֐��ōĐݒ肷��K�v������܂��B
 *	[���l]
 *	 �t���[���J�E���g���ɂ���
 *	�E�C���^���[�X�̏ꍇ�A�\���X�VVSYNC�� = 2*count �ƂȂ�܂��B
 *	  �Ⴆ�΁A�C���^���[�X�Ńt���[���J�E���g��2�Ȃ�A4V�\���ƂȂ�܂��B
 *	�E1V�\���́A24fps�ȂǁA�C�ӂ̃t���[�����[�g�̓�����X���[�Y�ɕ\�����܂��B
 *	�E2V�\���́A��葽����CPU���Ԃ�Sofdec�ɗ^���A�R�}�����̊댯���y�����܂����A
 *	  �X���[�Y�ɍĐ��ł���t���[�����[�g�����肳��܂��B
 *	  (NTSC,VGA:29.97fps 30fps,  PAL:25fps)
 *	�E3V�ȏ�̕\���́A����Đ��ɂ͐������܂���B
 *	Set display mode
 *	[Inputs]
 *		mode		:Picture mode
 *		frame		:Color mode of frame buffer
 *		count		:Number of frame count
 *		latency		:Display latency(We recommend 2V latency.)
 *	[Notes]
 *	 Please set the value same as mode that you set in Ninja.
 *	 This function is not necessary when you set MWS_PLY_INIT_SFD in 
 *	 initialize function.
 *	 You need to set if by this function again when changed display mode.
 *	[Remarks]
 *	 About number of frame count
 *	 1)V-sync number of update display is twice 'count' in case of interlace.
 *	   For example, display is 4V when the number of frame count is 2 in case
 *	   of interlace.
 *	 2)1V-display displays animation of arbitrary frame rate smoothly.
 *	   For example 24fps.
 *	 3)2V-display gives CPU time to Sofdec and reduce danger of frame drops, 
 *	   but the frame rate that can be played smoothly is limited.
 *	   (NTSC,VGA:29.97fps 30fps, PAL:25fps)
 *	 4)We do not recommend display of more than 3V in animation play.
 */
void mwPlySetDispMode(Sint32 mode, Sint32 frame, Sint32 count, Sint32 latency);

/*	�����n�[���y�������̐ݒ�	*/
/*	Set high-speed Half Pel		*/
void mwPlySetFastHalfpel(MWPLY mwply, Sint32 sw);

/*	�P�x�␳(-16)�X�C�b�`�̐ݒ�	*/
/*	Set adjust luminosity switch (if sw==1 then y = y-16)	*/
void mwPlySetAdjustY16(MWPLY mwply, Sint32 sw);

/*	�����o�̓X�C�b�`�̐ݒ�			*/
/*	Set audio output switch			*/
void mwPlySetAudioSw(MWPLY mwply, Sint32 sw);

/*	�\���ʒu�̐ݒ�				*/
/*	Set location of the display	*/
void mwPlySetDispPos(MWPLY mwply, float lx, float ly);

/*	�\���T�C�Y�̐ݒ�			*/
/*	Set size of the display		*/
void mwPlySetDispSize(MWPLY mwply, float sx, float sy);

/*	�P�x�̐ݒ�(val= 0�`255)		*/
/*	Set brightness(value=0-255)	*/
void mwPlySetBright(MWPLY mwply, Sint32 val);

/*	�P�x�̃I�t�Z�b�g�ݒ�(val= 0�`255)	*/
/*	Set brightness offset(value=0-255)	*/
void mwPlySetBrightOfst(MWPLY mwply, Sint32 val);

/*	�P�x�̎擾					*/
/*	Get brightness				*/
Sint32 mwPlyGetBright(MWPLY mwply);

/*	�P�x�I�t�Z�b�g�̎擾		*/
/*	Get brightness offset		*/
Sint32 mwPlyGetBrightOfst(MWPLY mwply);

/*	�\���X�N���[���̉��s���l�̎擾	(z:1.0->65536.0)	*/
/*	Get Z coordinary of screen	(z:1.0->65536.0)		*/
float mwPlyGetDispZ(MWPLY mwply);

/*	�\���X�N���[���̉��s���l�̐ݒ�	(z:1.0->65536.0)	*/
/*	Get Z coordinary of screen	(z:1.0->65536.0)		*/
void mwPlySetDispZ(MWPLY mwply, float z);

/*	�f���\���X�C�b�`�̐ݒ�									*/
/*	Set video output switch (if sw == 1 then output video)	*/
void mwPlySetVideoSw(MWPLY ply, Sint32 sw);

/*	�f���\���X�C�b�`�̎擾									*/
/*	Get video output switch									*/
Sint32 mwPlyGetVideoSw(MWPLY ply);

/*	�R�}���������t���[�����̎擾											*/
/*	�r�f�I���[�h���C���^���[�X���[�h��29.97, 30fps�̃��[�r�[�̎��̂ݗL��	*/
/*	Get number of droped frame												*/
/*	If video mode is interlace and movie is 29.97 or 30 fps,				*/
/*	you can use this function.												*/
Sint32 mwPlyGetNumDropFrm(MWPLY ply);

/*	�P�x->���ϊ��e�[�u���̐ݒ�	*/
void mwPlySetAlphTbl(MWPLY ply, long bno, float alph[256]);

/*	�������[�h�̐ݒ�	*/
void mwPlySetCompoMode(MWPLY ply, Sint32 mode);

/*	�}�b�g�f�[�^�̐ݒ�	*/
void mwPlySetMat(MWPLY mwply, Uint8 *mat);

/*	���[�r�[�t���[���̎擾	*/
Sint32 mwPlyGetMvFrm(MWPLY ply, MWS_PLY_MVFRM *frm);

/*	�}�X�N�t���[���̎擾	*/
Sint32 mwPlyGetMskFrm(MWPLY ply, MWS_PLY_MVFRM *frm);

/*	�������[�h�̐ݒ�	*/
void mwPlySetAsync(MWPLY ply, Sint32 sw);

/*	���̓X�g���[���W���C���g�̎擾	*/
SJ mwPlyGetInputSj(MWPLY ply);

/*	�G�t�F�N�g�R�[���o�b�N�֐��̓o�^	*/
void mwPlyEntryFxCb(MWPLY ply,
void (*fn)(void *obj, Sint32 fno, Sint32 time, Sint32 tunit), void *obj);

/*	�X�g���[���̘A��	*/
void mwPlyLinkStm(MWPLY ply, Sint32 sw);

/*	�����p�o�b�t�@�T�C�Y�̌v�Z	*/
long mwPlyCalcCompoBufSize(Sint32 sx, Sint32 sy);

/*	�����p�o�b�t�@�̐ݒ�	*/
void mwPlySetCompoBuf(void *buf, Sint32 size);

/*	�f�R�[�h�ς݃t���[����	*/
Sint32 mwPlyGetNumDecPool(MWPLY ply);
/*	�f�R�[�h�����S�s�N�`����	*/
Sint32 mwPlyGetNumTotalDec(MWPLY ply);
/*	�X�L�b�v�����S�s�N�`����	*/
Sint32 mwPlyGetNumTotalSkip(MWPLY ply);
/*	���̓o�b�t�@�̋󂫗e�ʂ̎擾	*/
Sint32 mwPlyGetNumIbufRoom(MWPLY ply);
/*	�\���҂��t���[�����̎擾	*/
Sint32 mwPlyGetNumDispWait(MWPLY ply);
/*	�����_�����O���̃t���[�����̎擾	*/
Sint32 mwPlyGetNumRend(MWPLY ply);
/*	�f���p�r�f�I�����_���̎擾	*/
void *mwPlyGetRnvImg(MWPLY ply);
/*	�}�X�N�p�r�f�I�����_���̎擾	*/
void *mwPlyGetRnvMsk(MWPLY ply);
/*	�e�N�X�`���փ��[�h�����t���[����	*/
Sint32 mwPlyGetNumLoadFrm(MWPLY ply);

/**
*		�T�[�t�F�X�֐�
*		Functions of surface operation
**/

/*	�T�[�t�F�X�|�C���g�p�o�b�t�@�T�C�Y�̌v�Z							*/
/*	Calcurate size of surface point buffer 								*/
Sint32 mwPlyCalcSrfBufSize(MWPLY ply, Sint32 npnt);

/*	�T�[�t�F�X�|�C���g�p�o�b�t�@�̐ݒ�									*/
/*	Set surface point buffer											*/
void mwPlySetSrfPntBuf(MWPLY ply, Sint32 npnt, void *buf, Sint32 bsize);

/*	�\���ʒu�̐ݒ�														*/
/*	Set display position of surface point								*/
void mwPlySetSrfPos(MWPLY ply, Uint32 no, float lx, float ly, float lz);

/*	�\���ʒu�̎擾														*/
/*	Get display position of surface point								*/
void mwPlyGetSrfPos(MWPLY ply, Uint32 no, float *lx, float *ly, float *lz);

/*	�P�x�̐ݒ�															*/
/*	Set brightness of surface point										*/
void mwPlySetSrfBright(MWPLY ply, Uint32 no,
									float a, float r, float g, float b);
/*	�P�x�̎擾															*/
/*	Get brightness of surface point										*/
void mwPlyGetSrfBright(MWPLY ply, Uint32 no,
									float *a, float *r, float *g, float *b);
/*	�P�x�I�t�Z�b�g�̐ݒ�												*/
/*	Set brightness offset of surface point								*/
void mwPlySetSrfBrightOfst(MWPLY ply, Uint32 no,
									float a, float r, float g, float b);
/*	�P�x�I�t�Z�b�g�̎擾												*/
/*	Get brightness offset of surface point								*/
void mwPlyGetSrfBrightOfst(MWPLY ply, Uint32 no,
									float *a, float *r, float *g, float *b);
/*	�C���[�W�ʒu�̐ݒ�													*/
/*	Set image position of surface point									*/
void mwPlySetImgPos(MWPLY ply, Uint32 no, float lx, float ly);
/*	�C���[�W�ʒu�̎擾													*/
/*	Get image position of surface point									*/
void mwPlyGetImgPos(MWPLY ply, Uint32 no, float *lx, float *ly);
/*	�C���[�W�T�C�Y�̎擾												*/
/*	Get image size														*/
void mwPlyGetImgSize(MWPLY ply, Sint32 *isx, Sint32 *isy);

#endif	/*	_SFD_MW_H_	*/
