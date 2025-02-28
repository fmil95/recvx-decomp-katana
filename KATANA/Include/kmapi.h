/*++

  COPYRIGHT        (C) NEC        Corporation 1997 - 1998

  All rights reserved by NEC Corporation. This program must be
  used solely for the purpose for which it was furnished by NEC
  Corporation. No part of this program may be reproduced or
  disclosed to others, in any form, without the prior written
  permission of NEC Corporation.
  Use of copyright notice does not evidence publication of this
  program.

  Author	:  		T.Hirata(NEC Software Ltd.,)
  Module Name:		kmapi.h

  Abstract:
	KAMUI = Kamui is abstruction model that is ultimate interface for PowerVR.
	'kmapi.h' define prototype of kamui function.

  Environment:
	Microsoft Compiler.

  Notes:
	define Kamui's api proto-types.

  Revision History:

--*/

#if !defined(__kamui_api_h)
#define __kamui_api_h

#ifdef __cplusplus
extern "C" {
#endif 

/*++
kmInitDevice

proto type:

	KMSTATUS
	kmInitDevice (KMVIDEOMODE nVideoMode);

Description:
	�n�[�h�E�F�A�̏��������s���܂��B�r�f�I�M�����o�͂��ABLANK��ʂ�\�����܂��B

Arguments:
	IN	nVideoMode
		�r�f�I���[�h���w�肵�܂��B���L�̂����ꂩ���w��ł��܂��B

			KM_NTSC	... NTSC��(�k�āA���{�Ȃ�)
			KM_PAL	... PAL�� (���[���b�p�Ȃ�)
			KM_VGA	... VGA (ARC1)

		ARC1�ł́A�ǂ���w�肵�Ă�KM_VGA���w�肳�ꂽ���̂Ƃ݂Ȃ���܂��B



Result:

	KMSTATUS_SUCCESS				�f�o�C�X����������
	KMSTATUS_INVALID_VIDEOMODE		�s���ȃr�f�I���[�h���w�肵���B
	KMSTATUS_HARDWARE_NOT_PRESENTED	�n�[�h�E�F�A���g�p�ł��Ȃ��B

--*/
KMSTATUS KMAPI
kmInitDevice (
		IN	KMVIDEOMODE nVideoMode
	);


/*++
kmSetDisplayMode

proto type:

	KMSTATUS
	kmSetDisplayMode(
			IN	KMDISPLAYMODE	nDisplayMode,
			IN	KMBPPMODE		nBpp,
			IN	KMBOOLEAN		fDither,
			IN	KMBOOLEAN		fAntiAlias
		);

Description:
	Frame Buffer�̕\�����[�h��ݒ肵�܂��B

Arguments:
	IN	nDisplayMode
	�f�B�X�v���C���[�h���w�肵�܂��B
		KM_DSPMODE_VGA				VGA(640x480) 60Hz
		KM_DSPMODE_NTSCNI320x240	320x240 �m���C���^���[�X60Hz
		KM_DSPMODE_NTSCI320x240		320x240 �C���^���[�X 30Hz
		KM_DSPMODE_NTSCNI320x480	320x240 �^���m���C���^�[���[�X 60Hz
		KM_DSPMODE_NTSCNI320x480FF	320x240 �^���m���C���^�[���[�X 60Hz �t���b�J�[�t���[
		KM_DSPMODE_NTSCI320x480		320x240 �C���^���[�X 30Hz
		KM_DSPMODE_NTSCNI640x240	640x240 �m���C���^���[�X60Hz
		KM_DSPMODE_NTSCI640x240		640x240 �C���^���[�X30Hz
		KM_DSPMODE_NTSCNI640x480	640x480 �^���m���C���^�[���[�X 60Hz
		KM_DSPMODE_NTSCNI640x480FF	640x480 �^���m���C���^�[���[�X 60Hz �t���b�J�[�t���[
		KM_DSPMODE_NTSCI640x480		640x480 �C���^���[�X 30Hz

		KM_DSPMODE_PALNI320x240		320x240 �m���C���^���[�X50Hz
		KM_DSPMODE_PALI320x240		320x240 �C���^���[�X25Hz
		KM_DSPMODE_PALNI320x480		320x480 �^���m���C���^�[���[�X 50Hz
		KM_DSPMODE_PALNI320x480FF	320x480 �^���m���C���^�[���[�X 50Hz �t���b�J�[�t���[
		KM_DSPMODE_PALI320x480		320x480 �C���^���[�X25Hz
		KM_DSPMODE_PALNI640x240		640x240 �m���C���^���[�X50Hz
		KM_DSPMODE_PALI640x240	 	640x240 �C���^���[�X25Hz
		KM_DSPMODE_PALNI640x480		640x480 �^���m���C���^�[���[�X 50Hz
		KM_DSPMODE_PALNI640x480FF	640x480 �^���m���C���^�[���[�X 50Hz �t���b�J�[�t���[
		KM_DSPMODE_PALI640x480		640x480 �C���^���[�X25Hz

	IN	nBpp
	FrameBuffer�̃J���[���[�h���w�肵�܂��B
	�ȉ��̒�`�ςݒ萔���g�p���邱�Ƃ��ł��܂��B
		KM_DSPBPP_RGB565		RGB565 
		KM_DSPBPP_RGB555		RGB555
		KM_DSPBPP_ARGB1555		ARGB1555
		KM_DSPBPP_RGB888		RGB888
		KM_DSPBPP_ARGB8888		ARGB8888

	IN	bDither
		PowerVR �� �����_�����O���ʂ� 16bit�� Frame Buffer �ɏ������ލۂ�
		Dither �̗L�������肵�܂��B�����_�����O��� Frame Buffer �� 
		RGB888�AARGB8888 �ł���ꍇ�A���̃t���O�͖�������܂��B

			TRUE	Dither ���g�p����B
			FALSE	Dither ���g�p���Ȃ��B

	IN	bAntiAlias
		�A���`�G���A�V���O�t�B���^�̎g�p�ۂ����肵�܂��B
		�A���`�G�C���A�V���O�t�B���^��L���ɂ����ꍇ���쑬�x��
		�ቺ����ꍇ������܂��B

			TRUE 	Anti Aliasing Filter ���g�p����B
			FALSE	Anti Aliasing Filter ���g�p���Ȃ��B


Result:
	KMSTATUS_SUCCESS				����
	KMSTATUS_INVALID_DISPLAY_MODE	�s���ȃf�B�X�v���C���[�h���w�肳�ꂽ�B
									���������Ɏw�肳�ꂽ�f�B�X�v���C���[�h��
									��������f�B�X�v���C���[�h���w�肳�ꂽ�B


--*/

KMSTATUS KMAPI
kmSetDisplayMode(
		IN	KMDISPLAYMODE	nDisplayMode,
		IN	KMBPPMODE		nBpp,
		IN	KMBOOLEAN		fDither,
		IN	KMBOOLEAN		fAntiAlias
	);


/*++
kmChangeDisplayFilterMode

proto type:

	KMSTATUS 
	kmChangeDisplayFilterMode(	
			KMBOOLEAN fDither,
			KMBOOLEAN fAntiAlias
		);

Description:
	kmSetDisplayMode �Őݒ肵���f�B�U��A���`�G���A�V���O�t�B���^�� Enable / Disable ��
	��ŕύX����ׂɎg�p���܂��B

Arguments:
	IN	bDither
		PowerVR �� �����_�����O���ʂ� 16bit�� Frame Buffer �ɏ������ލۂ�
		Dither �̗L�������肵�܂��B�����_�����O��� Frame Buffer �� 
		RGB888�AARGB8888 �ł���ꍇ�A���̃t���O�͖�������܂��B

			TRUE	Dither ���g�p����B
			FALSE	Dither ���g�p���Ȃ��B

	IN	bAntiAlias
		�A���`�G���A�V���O�t�B���^�̎g�p�ۂ����肵�܂��B
		�A���`�G�C���A�V���O�t�B���^��L���ɂ����ꍇ���쑬�x��
		�ቺ����ꍇ������܂��B

			TRUE 	Anti Aliasing Filter ���g�p����B
			FALSE	Anti Aliasing Filter ���g�p���Ȃ��B

Result:
	KMSTATUS_SUCCESS				����
	KMSTATUS_INVALID_DISPLAY_MODE	�s���ȃf�B�X�v���C���[�h���w�肳�ꂽ�B
									���������Ɏw�肳�ꂽ�f�B�X�v���C���[�h��
									��������f�B�X�v���C���[�h���w�肳�ꂽ�B

--*/

KMSTATUS  KMAPI
kmChangeDisplayFilterMode(	
		IN	KMBOOLEAN fDither,
		IN	KMBOOLEAN fAntiAlias
	);

/*++
kmBlankScreen

proto type:

	KMSTATUS
	kmBlankScreen(	KMBOOLEAN bBlanking	);

Description:
	�t���[���o�b�t�@�̉�ʕ\���𒆎~���A�u�����L���O�ɂ���B
	��< 1��� V-Sync Callback ���� 1��̌Ăяo���̂ݑΉ�����B>��

Arguments:
	IN	bBlanking	��ʂ��u�����L���O���邩�ǂ����̎w��B
			TRUE 	�u�����L���O�J�n
            FALSE	�u�����L���O����

Result:
	KMSTATUS_SUCCESS		����

--*/
KMSTATUS KMAPI
kmBlankScreen(
			IN	KMBOOLEAN bBlanking
		);

/*++
kmAdjustDisplayCenter

proto type:

	KMSTATUS
	kmAdjustDisplayCenter( 	KMINT32 nXAdjust, 
							KMINT32 nYAdjust 
						);

Description:
	��ʏ�ɂ�����Frame buffer �̕\���ʒu�̒������s���܂��B

Arguments:
	IN	nXAdjust	�������̉�ʕ`��ʒu�𒲐�����l
	IN	nYAdjust	�c�����̉�ʕ`��ʒu�𒲐�����l

Result:
	KMSTATUS_SUCCESS		����
	KMSTATUS_OUT_OF_RANGE	�L���͈͊O�̒l���w�肵���B

--*/
KMSTATUS KMAPI
kmAdjustDisplayCenter( 
			IN	KMINT32 nXAdjust, 
			IN	KMINT32 nYAdjust 
		);


/*++
kmSetSystemConfiguration

proto type:
	KMSTATUS kmSetSystemConfiguration(
			PKMSYSTEMCONFIGSTRUCT pSystemConfigStruct
	)

Description:
		KMSYSTEMCONFIGSTRUCT�^�\���̂Ɏw�肵���p�����[�^�ɏ]���A�_�Ђ̊e��V�X�e���\����ݒ肵�܂��B
		Frame Buffer / Texture Buffer / Native Buffer �̊֌W

		 Texture/Frame Buffer �S�̗̂e��  -  (�w�肳�ꂽ�ő�e�N�X�`���g�p�T�C�Y + �\���pFrame Buffer)
				=	 Native Buffer

  ���ӁF�܂��A�e�N�X�`���T�[�t�F�X�̊m�ۂ́A
		�{�֐��Ăяo���ȑO�Ɍ�ŌĂяo���Ă��������B
		���̊֐��́A�]��(�_��Ver1.28�ȑO)�� �ȉ��̊֐��ɑ�����̂ł��B

				kmCreateFrameBufferSurface
				kmCreateVertexBuffer
				kmCreateTABuffer
				kmActivateFrameBuffer 

		kmSetSystemConfiguration���g�p����ꍇ�͏�L�̊֐��͌Ăяo���Ȃ��ł��������B

Arguments:
	IN	OUT	pSystemConfigStruct	KMSYSTEMCONFIGSTRUCT�^�\���̂ւ̃|�C���^���w�肵�܂��B
								�{�\���̂̃����o�͈ȉ��̗l�ɐݒ肵�܂��B

				dwSize		KMSYSTEMCONFIGSTRUCT �\���̂̃T�C�Y �������܂��B
							pSystemConfigStruct->dwSize = sizeof(KMSYSTEMCONFIGSTRUCT);

				flags		�V�X�e���̓�����w�肵�܂��B
								KM_CONFIGFLAG_ENABLE_CLEAR_FRAMEBUFFER	Frame Buffer �m�ێ��Ƀo�b�t�@�̓��e���N���A���܂��B
								KM_CONFIGFLAG_ENABLE_STRIPBUFFER		Strip Buffer ��L���ɂ��܂��B
								KM_CONFIGFLAG_ENABLE_2V_LATENCY			2V Laytency Mode �ɂ��܂��B
								KM_CONFIGFLAG_NOWAITVSYNC				V-SYNC ��҂��Ȃ����[�h�ł��B
								KM_CONFIGFLAG_USEDIRECTMODE				kmXxxxXxxxDirect �n�� �֐����g�p����B
																		���̃t���O���w�肵���ꍇ�A���_�f�[�^�o�^/�����_�����O�J�n�́A
																		�ȉ��̊֐����g�p���ă^�C���A�N�Z�����[�^�֒��ڃf�[�^��
																		�������ނ��Ƃɂ���Ď������܂��B
																			kmStartVertexStripDirect
																			kmSetVertexDirect
																			kmSetUserClippingDirect
																			kmSetEndOfListDirect
																			kmRenderDirect
								KM_CONFIGFLAG_NOWAIT_FINISH_TEXTUREDMA	Texture��DMA�]�������ꍇ�ɁADMA�̏I����҂��Ȃ��悤�ɂ��܂��B
								                                        DMA�̏I�����o��kmQueryFinishLastTextureDMA���g�p���čs���Ă��������B
								                                        �܂��ADMA����DMA�]�����������ւ̃A�N�Z�X�͕K��������悤�ɂ��Ă��������B

				ppSurfaceDescArray/	nNumOfFrameBuffer;
							KMSURFACEDESC �\���̂̃|�C���^�z��ւ̃|�C���^�ƃ|�C���^�z��̗v�f����^���܂��B
							�ȉ��̂悤�ɐݒ肵�܂��B

									KMSURFACEDESC Surface1;
									KMSURFACEDESC Surface2;
									PKMSURFACEDESC ppSurfaceArray[nNumOfFrameBuffer];
									ppSurfaceArray[0] = &Surface1;
									ppSurfaceArray[1] = &Surface2;

									pSystemConfigStruct->nNumOfFrameBuffer  = nNumOfFrameBuffer;
									pSystemConfigStruct->ppSurfaceDescArray = ppSurfaceArray;

				nWidth / nHeight / nBpp
							�m�ۂ��� Frame Buffer�̑傫��/ BPP �ł��B
							nWidth / nBpp �͏�ɖ������܂��B
							nHeight �� Strip �o�b�t�@�g�p���ȊO�ɂ́A�������܂��B

				nTextureMemorySize
							�g�p����e�N�X�`���������̃T�C�Y���w�肵�܂��B

				pBufferDesc
						KMVERTEXBUFFDESC �\���̂ւ̃|�C���^�ł��B

				pVertexBuffer
				nVertexBufferSize;
						���_�o�b�t�@�ւ̃x�[�X�A�h���X/�T�C�Y���w�肵�܂��B

				fBufferSize[5]		�^�������_�o�b�t�@���Ŋe���X�g����߂銄���� % �Ŏw�肵�܂��B
									���v�l =< 100% �ɂȂ�悤�ɐݒ肵�Ă��������B
Result:
	KMSTATUS_SUCCESS			����
	KMSTATUS_NOT_ENOUGH_MEMORY	Native Buffer/Frame Buffer �̂��߂̃������e�ʂ�����܂���

--*/

KMSTATUS KMAPI
kmSetSystemConfiguration(
		IN	OUT	PKMSYSTEMCONFIGSTRUCT pSystemConfigStruct
	);


/*++
kmCreateFrameBufferSurface

proto type:

	KMSTATUS 
	kmCreateFrameBufferSurface (
			PKMSURFACEDESC pSurfaceDesc,
			KMINT32 nWidth, 
			KMINT32 nHeight,
			KMBOOLEAN fStripBuffer,
			KMBOOLEAN fBufferClear
		);

Description:
	�\���p��Surface�� Frame Buffer ��������Ɋm�ۂ��A
	���������܂��B���̊֐����Ăяo���O��kmSetDisplayMode���s���K�v������܂��B

Arguments:
	OUT	pSurfaceDesc		KMSURFACEDESC �\���̗̂̈�������|�C���^�ł��B
							kmCreateFrameBufferSurface �ō쐬�����T�[�t�B�X�̏�񂪊i�[����܂��B
							KMSTATUS �� KMSTATUS_NOT_ENOUGH_MEMORY���Ԃ��ꂽ�ꍇ�ɂ͕s��ƂȂ�܂��B


	IN	nWidth, nHeight		�m�ۂ��� Surface�̕�/�������w�肵�܂��B0,0��ݒ肵���ꍇ�ɂ́AkmSetDisplayMode��
							�w�肵����ʃT�C�Y���g�p���܂��B
							HOLLY�� Strip Buffer���g�p���邱�Ƃ��ł��܂��BStrip Buffer���g�p����ꍇ�ɂ́A
							nHeight �� 32�̔{�����w�肷��K�v������܂��BStrip Buffer�̋@�\��ARC1�ɂ͂���܂���B
							ARC1�Ŏg�p����ꍇ�ɂ͏��0,0���w�肵�Ă��������B


	IN	bStripBuffer		Strip Buffer �̍쐬�L�����w�肵�܂��BStrip Buffer�̋@�\��ARC1�ɂ͂���܂���B
							ARC1�Ŏg�p����ꍇ�ɂ͏��FALSE���w�肵�Ă��������B
								TRUE		StripBuffer�`���� Frame Buffer �𐶐����܂��B 
								FALSE		Frame Buffer �𐶐����܂��B

	IN	bBufferClear		Frame Buffer �쐬���ɏ������̗L�����w�肵�܂��B
								TRUE	Surface���쐬�����Ƃ���0�N���A���܂��B
								FALSE	Sufrace��0�N���A���܂���B

Result:
	KMSTATUS_SUCCESS				Frame Buffer �쐬����
	KMSTATUS_NOT_ENOUGH_MEMORY		���s�A�������e�ʂ�����Ȃ�
	

--*/


KMSTATUS KMAPI
kmCreateFrameBufferSurface (
		OUT	PKMSURFACEDESC 	pSurfaceDesc,
		IN	KMINT32 		nWidth, 
		IN	KMINT32 		nHeight,
		IN	KMBOOLEAN 		fStripBuffer,
		IN	KMBOOLEAN 		fBufferClear
	);


/*++
kmCreateTextureSurface

proto type:
	KMSTATUS 
	kmCreateTextureSurface(
			PKMSURFACEDESC	pSurfaceDesc,
			KMINT32			nWidth, 
			KMINT32			nHeight, 
			KMTEXTURETYPE	nTextureType
		);

Description:
	�e�N�X�`���p��Surface���m�ۂ��܂��B

Arguments:
	OUT	pSurfaceDesc		KMSURFACEDESC �\���̗̂̈�������|�C���^�ł��B
							�m�ۂ��� Texture Surface �̏�񂪕Ԃ���܂��B
							KMSTATUS ��KMSTATUS_NOT_ENOUGH_MEMORY���Ԃ��ꂽ�ꍇ�ɂ͕s��ƂȂ�܂��B

	IN	nWidth, nHeight		�e�N�X�`���̉��T�C�Y�A�c�T�C�Y���w�肵�܂��B
								MIPMAP���g�p����ꍇ�ɂ̓g�b�v���x���̃e�N�X�`���T�C�Y���w�肵�܂��B
								Twiddled, VQ, Palettized�Ȃǂ̐����`�e�N�X�`�����g�p����ꍇ�ɂ� 
									nWidth�Ɏw�肵���l�݂̂��g�p����܂��B
								�����`�e�N�X�`�����g�p����ꍇ�ɂ́AnWidth, nHeight���ɗL���ł��B
								ARC1�AHOLLY�͐����`�e�N�X�`���T�C�Y�Ƃ��� 8x8�`1024x1024�܂ł̃e�N�X�`�����g�p�ł��܂����A
								nWidth, nHeight�Ɏw�肷��l��,8, 16, 32, 64, 128, 256, 512, 1024��
								�����ꂩ�łȂ���΂Ȃ�܂���B

	IN	nTextureType		�e�N�X�`���̌`�����w�肵�܂��B
							�ȉ��̃J�e�S���R�[�h�A�s�N�Z���t�H�[�}�b�g�R�[�h����
							����I�яo���A�_���a(or)���ė^���܂�

								-�J�e�S���R�[�h
									KM_TEXTURE_TWIDDLED			// Twiddled�t�H�[�}�b�g
									KM_TEXTURE_TWIDDLED_MM		// Twiddled�t�H�[�}�b�gMipmap����
									KM_TEXTURE_VQ				// VQ���k�`��
									KM_TEXTURE_VQ_MM			// VQ���k�`��Mipmap����
									KM_TEXTURE_PALETTIZE4		// 4bpp�p���b�g�`��
									KM_TEXTURE_PALETTIZE4_MM	// 4bpp�p���b�g�`��Mipmap����
									KM_TEXTURE_PALETTIZE8		// 8bpp�p���b�g�`��
									KM_TEXTURE_PALETTIZE8_MM	// 8bpp�p���b�g�`��Mipmap����
									KM_TEXTURE_RECTANGLE		// ��`

								- �s�N�Z���t�H�[�}�b�g�R�[�h
									KM_TEXTURE_1555
									KM_TEXTURE_565
									KM_TEXTURE_4444
									KM_TEXTURE_YUV422
									KM_TEXTURE_BUMP
									KM_TEXTURE_8888

							��)  KM_TEXTURE_8888��KM_TEXTURE_PALETTIZE4or8�Ƃ̑g�ݍ��킹�̂ݗL���ł��B

Result:
		KMSTATUS_SUCCESS					�e�N�X�`���������m�ې���
		KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��
		KMSTATUS_NOT_ENOUGH_MEMORY			�������e�ʂ�����Ȃ�
		KMSTATUS_INVALID_MIPMAPED_TEXTURE	MIPMAP�ł��Ȃ��e�N�X�`����MIPMAP���w�肵���B

--*/

KMSTATUS KMAPI
kmCreateTextureSurface(
		OUT	PKMSURFACEDESC	pSurfaceDesc,
		IN	KMINT32			nWidth, 
		IN	KMINT32			nHeight, 
		IN	KMTEXTURETYPE	nTextureType
	);

/*++
kmCreateCombinedTextureSurface

proto type:
	KMSTATUS 
	kmCreateCombinedTextureSurface(
			PKMSURFACEDESC	pSurfaceDesc1,
			PKMSURFACEDESC	pSurfaceDesc2,
			KMINT32			nWidth, 
			KMINT32			nHeight, 
			KMTEXTURETYPE	nTextureType
		);

Description:
	VQ�e�N�X�`���p��Surface�� 2�m�ۂ��܂��BnTextureType�ɂɐݒ肷��e�N�X�`���J�e�S����
	KM_TEXTURE_VQ,KM_TEXTURE_VQ_MM�̂ǂ��炩�łȂ���΂Ȃ�܂���B

Arguments:
	OUT	pSurfaceDesc1		KMSURFACEDESC �\���̗̂̈������ 1 �߂̃|�C���^�ł��B
							�m�ۂ��� Texture Surface �̏�񂪕Ԃ���܂��B
							KMSTATUS ��KMSTATUS_NOT_ENOUGH_MEMORY���Ԃ��ꂽ�ꍇ�ɂ͕s��ƂȂ�܂��B

	OUT	pSurfaceDesc2		KMSURFACEDESC �\���̗̂̈������ 2 �߂̃|�C���^�ł��B
							�m�ۂ��� Texture Surface �̏�񂪕Ԃ���܂��B
							KMSTATUS ��KMSTATUS_NOT_ENOUGH_MEMORY���Ԃ��ꂽ�ꍇ�ɂ͕s��ƂȂ�܂��B

	IN	nWidth, nHeight		�e�N�X�`���̉��T�C�Y�A�c�T�C�Y���w�肵�܂��B
							MIPMAP���g�p����ꍇ�ɂ̓g�b�v���x���̃e�N�X�`���T�C�Y���w�肵�܂��B
							ARC1�AHOLLY�͐����`�e�N�X�`���T�C�Y�Ƃ��� 8x8�`1024x1024�܂ł̃e�N�X�`�����g�p�ł��܂����A
							nWidth, nHeight�Ɏw�肷��l��,8, 16, 32, 64, 128, 256, 512, 1024��
							�����ꂩ�łȂ���΂Ȃ�܂���B

	IN	nTextureType		�e�N�X�`���̌`�����w�肵�܂��B
							�ȉ��̃J�e�S���R�[�h�A�s�N�Z���t�H�[�}�b�g�R�[�h����
							����I�яo���A�_���a(or)���ė^���܂�

								-�J�e�S���R�[�h
									KM_TEXTURE_VQ				// VQ���k�`��
									KM_TEXTURE_VQ_MM			// VQ���k�`��Mipmap����

								- �s�N�Z���t�H�[�}�b�g�R�[�h
									KM_TEXTURE_ARGB1555
									KM_TEXTURE_ARGB4444

Result:
		KMSTATUS_SUCCESS					�e�N�X�`���������m�ې���
		KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��
		KMSTATUS_NOT_ENOUGH_MEMORY			�������e�ʂ�����Ȃ�

--*/

KMSTATUS KMAPI
kmCreateCombinedTextureSurface(
		OUT	PKMSURFACEDESC	pSurfaceDesc1,
		OUT	PKMSURFACEDESC	pSurfaceDesc2,
		IN	KMINT32			nWidth, 
		IN	KMINT32			nHeight, 
		IN	KMTEXTURETYPE	nTextureType
	);


/*++
kmSetAlphaThreshold

proto type:

	KMSTATUS 
	kmSetAlphaThreshold(	
			KMINT32 nThreshold	
		);

Description:
	1555�T�[�t�F�X�������_�����O�pSurface�Ƃ����ꍇ�Ƀ���1bit�����肷�邽�߂̃X���b�V�����h�l�ł��B
	�����_�����O���ʂ��A�����ŃZ�b�g�����l�ȏ�ƂȂ����ꍇ�A���r�b�g��1�ɂ��܂��B
	���r�b�g��RAMDAC�ȂǂŃN���}�L�[����������ꍇ�Ɏg�p����܂��B

Arguments:
	IN	nThreshold		0�`255�̒l�̃X���b�V�����h�l�B
						0�ȉ��܂���255�ȏ���w�肳�ꂽ�ꍇ�́A���ꂼ��0�A255 �ɃN�����v����܂��B


Result:
	KMSTATUS_SUCCESS		�ݒ萬��
--*/

KMSTATUS KMAPI
kmSetAlphaThreshold(	
		IN	KMINT32 nThreshold	
	);

/*++
kmActivateFrameBuffer

proto type:

	KMSTATUS 
	kmActivateFrameBuffer(
			PKMSURFACEDESC	pPrimarySurfaceDesc,
			PKMSURFACEDESC	pBackBufferSufaceDesc, 
			KMBOOLEAN 		fStripBuffer,
			KMBOOLEAN 		fWaitVSync
		);

Description:
	 Frame Buffer �̕\�����J�n���܂��B
Arguments:

	IN	pPrimarySurfaceDesc		�\���Ɏg�p����Surface��Surface�\���̂ł��B 
								kmCreateFrameBufferSurface ��Surface���m�ۂ������_�œ���ꂽ
								Surface�\���̂�ݒ肵�Ă��������B

	IN	pBackBufferSurfaceDesc	�����_�����O�Ώ�Surface��Surface�\���̂ł��B

	IN	bStripBuffer			StripBuffer���g�p����ꍇTRUE���w�肵�܂��B
	IN	bWaitVSync				Surface�̕\����Vsync�܂�Wait���邩�ǂ������w�肵�܂��B
								TRUE�̏ꍇ�{�֐���Vsync�^�C�~���O�܂ŃE�F�C�g���A
								�\�����J�n���܂��B


Result:
	KMSTATUS_SUCCESS			�\���؂�ւ�����

--*/

KMSTATUS KMAPI
kmActivateFrameBuffer(
		IN	PKMSURFACEDESC	pPrimarySurfaceDesc,
		IN	PKMSURFACEDESC	pBackBufferSufaceDesc, 
		IN	KMBOOLEAN		fStripBuffer,
		IN	KMBOOLEAN		fWaitVSync
	);

/*++
kmFlipFrameBuffer

proto type:

	KMSTATUS
	kmFlipFrameBuffer( KMVOID );

Description:
	 Frame Buffer ���_�u���o�b�t�@�����O�����ꍇ�ɁA�\���p��PrimarySurface�� 
	�����_�����O�^�[�Q�b�g�� BackBuffer �����ւ��܂��B

	Flip�R�}���h�̓L���[�C���O����܂��B
	BackBuffer �ւ̃����_�����O���I�����Ă���ꍇ�A
	kmFlipFrameBuffer() �����s����
	����Vsync�^�C�~���O�� Flip�����s����܂��B

	�Ȃ��AStripBuffer�g�p���ɂ́A�\�t�g�E�F�A�ɂ��Flip�͕K�v����܂���B

Arguments:
		none

Result:
		KMSTATUS_SUCCESS			Flip�R�}���h���s����
		KMSTATUS_CANT_FLIP_SURFACE 	Flip�R�}���h���s���s

--*/
KMSTATUS KMAPI
kmFlipFrameBuffer( KMVOID );

/*++
kmSetWaitVsyncCount

proto type:

	KMSTATUS
	kmSetWaitVsyncCount( KMINT32 nCount );

Description:
		�t���[�����[�g��藦�ɂ��邽�߂ɁA�O��� Flip��A
		����Flip �\�ɂȂ�܂ł�V-Sync�����w�肵�܂��B

Arguments:
		IN	nCount		V-Sync ��҂񐔂��w�肵�܂��B�O��� Flip��A
						����Flip �\�ɂȂ�܂ł�V-Sync�����w�肵�܂��B

Result:
		KMSTATUS_SUCCESS			����
--*/
KMSTATUS KMAPI
kmSetWaitVsyncCount(
		IN	KMINT32 nCount 
		);


/*++
kmSetCullingRegister

proto type:

	KMSTATUS
	kmSetCullingRegister(
			KMFLOAT fCullVal
		);

Description:
	������ Polygon �ɑ΂���J�����O�̃X���b�V�����h�l��ݒ肵�܂��B

Arguments:
		IN	fCullVal	���ʃp�����[�^�̃f�^�~�i���g�l��ݒ肵�܂��B

Result:
		KMSTATUS_SUCCESS			Flip�R�}���h���s����
		KMSTATUS_CANT_FLIP_SURFACE 	Flip�R�}���h���s���s

--*/

KMSTATUS KMAPI
kmSetCullingRegister(
		IN	KMFLOAT fCullVal
	);


/*++
kmSetColorClampValue

proto type:

	KMSTATUS
	kmSetColorClampValue(
			KMPACKEDARGB MaxVal,
			KMPACKEDARGB MinVal 
		);

Description:
	�J���[�̃N�����v�l���w�肵�܂��B�J���[�N�����v�̓t�H�O�̑O�i�Ŋ|�����܂��B
	�����_�����O���ɃN�����v�F��ύX����Ƃ��ɂ́A
	�K�������_�����O�I���̃R�[���o�b�N�֐����ȂǂŕύX���s���Ă��������B
	����ȊO�̃^�C�~���O�ŕύX���s�����ꍇ�A��ʃC���[�W���s���ƂȂ�ꍇ���L��܂��B

Arguments:
	IN	MaxVal			Packed�� ARGB 32bit�J���[�ŁA�N�����v�̍ő�l���w�肵�܂��B
						�P�x128��RGB�F���w�肷��ꍇ��0x00808080�̂悤�Ɏw�肵�܂��B

	IN	MinVal			Packed�� ARGB 32bit�J���[�ŁA�N�����v�̍ő�l���w�肵�܂��B
						�P�x20��RGB�F���w�肷��ꍇ��0x00141414�̂悤�Ɏw�肵�܂��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/

KMSTATUS KMAPI
kmSetColorClampValue(
		IN	KMPACKEDARGB MaxVal,
		IN	KMPACKEDARGB MinVal 
	);

/*++
kmSetFogTableColor

proto type:

	KMSTATUS
	kmSetFogTableColor(
			IN	KMPACKEDARGB FogTableColor
		);

Description:
	�t�H�O�J���[���w�肵�܂��BHOLLY�ł�FogVertex�AFogTable�ɕʁX�̃t�H�O�J���[���w��ł��܂����A
	ARC1�ł͓���̂���FogVertex�AFogTable�ɕʁX�̒l��ݒ肵�Ă��A�ォ��ݒ肳�ꂽ�l���L���ƂȂ�܂��B
	�����_�����O���Ƀt�H�O�J���[��ύX����Ƃ��ɂ́A�K�������_�����O�I���̃R�[���o�b�N�֐����ȂǂŕύX��
	�s���Ă��������B����ȊO�̃^�C�~���O�ŕύX���s�����ꍇ�A��ʃC���[�W���s���ƂȂ�ꍇ������܂��B

Arguments:
	IN	FogTableColor		FogTable �Ɏg�p����Packed��32bit�J���[�ł��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/

KMSTATUS KMAPI
kmSetFogTableColor(
		IN	KMPACKEDARGB FogTableColor
	);

/*++
kmSetFogVertexColor

proto type:

	KMSTATUS 
	kmSetFogVertexColor(
			KMPACKEDARGB FogVertexColor
		);

Description:
	�t�H�O�J���[���w�肵�܂��BHOLLY�ł�FogVertex�AFogTable�ɕʁX�̃t�H�O�J���[���w��ł��܂����A
	ARC1�ł͓���̂���FogVertex�AFogTable�ɕʁX�̒l��ݒ肵�Ă��A�ォ��ݒ肳�ꂽ�l���L���ƂȂ�܂��B
	�����_�����O���Ƀt�H�O�J���[��ύX����Ƃ��ɂ́A�K�������_�����O�I���̃R�[���o�b�N�֐����ȂǂŕύX��
	�s���Ă��������B����ȊO�̃^�C�~���O�ŕύX���s�����ꍇ�A��ʃC���[�W���s���ƂȂ�ꍇ������܂��B

Arguments:
	IN	FogVertexColor		FogVertex�Ɏg�p����Packed��32bit�J���[�ł��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/

KMSTATUS  KMAPI
kmSetFogVertexColor(
		IN	KMPACKEDARGB FogVertexColor
	);

/*++
kmSetFogTable

proto type:

	KMSTATUS
	kmSetFogTable(
			PKMFLOAT pfFogTable
		);

Description:
	FogTable��o�^���܂��B256�i�K��float�l�̊i�[���ꂽ�z��ւ̃|�C���^�������Ƃ��ēn���܂��B
	

Arguments:
	IN	pfFogTable	�t�H�O�e�[�u���l�z��ւ̃|�C���^�B256�i�K�̃p�����[�^���w�肵�܂��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/

KMSTATUS KMAPI
kmSetFogTable(
		IN	PKMFLOAT pfFogTable
	);

/*++
kmSetFogDensity

proto type:

	KMSTATUS
	kmSetFogDensity(KMDWORD fogDensity)

Description:
	TSP Fog �̌W����^����B

Arguments:
	IN	fogDensity			TSP Fog �̌W��

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/
KMSTATUS	KMAPI
kmSetFogDensity(
		IN	KMDWORD fogDensity
	);

/*++
kmSetPaletteMode

proto type:

	KMSTATUS 
	kmSetPaletteMode(	
			KMPALETTEMODE Palettemode
		);

Description:
	�I���`�b�v�p���b�g�̃��[�h�w������܂��B

Arguments:
	IN	PaletteMode		�p���b�g�� BPP ���[�h
						KM_PALETTE_16BPP	16BPP���[�h 565, 555, 1555, 4444���g�p���܂��B
						KM_PALETTE_32BPP 	32BPP���[�h 8888���g�p���܂��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/
KMSTATUS  KMAPI
kmSetPaletteMode(	
		IN	KMPALETTEMODE Palettemode
	);

/*++
kmSetPaletteData

proto type:
	KMSTATUS
	kmSetPaletteData(
			PKMPALETTEDATA pPaletteTable
		);

Description:
	�I���`�b�v�p���b�g�̐ݒ���s���܂��B

Arguments:
	IN	pPaletteTable	Palette�ݒ�p�z��̃|�C���^���w�肵�܂��B
						Palette�ݒ�p�z��̓��e�͈ȉ��̂悤�ɂȂ�܂��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/

KMSTATUS KMAPI
kmSetPaletteData(
		IN	PKMPALETTEDATA pPaletteTable
	);


/*++
kmSetPaletteBankData

proto type:
	KMSTATUS 
	kmSetPaletteBankData(
			IN KMINT32		PaletteEntry,
			IN KMINT32		DataSize,
			IN PKMPALETTEDATA	pPaletteTable
		);

Description:
	Palettize�e�N�X�`���Ŏg�p����� On Chip Palette �́A
	�ꕔ�����w�肵���p���b�g�f�[�^�ŏ��������܂��B
	�p���b�g�̍\���ɂ��Ă�kmSetPaletteData���Q�Ɗ肢�܂��B
	�p���b�g���[�h��4bpp/8bpp�Ɋւ�炸 PaletteEntry�Ɏw��\�Ȓl�́A0����1023�̂����ꂩ�ł��B
	�o���N�̋��E�Ɋ֌W�Ȃ��A�C�ӂ̃G���g������f�[�^���������ނ��Ƃ��ł��܂��B
	�p���b�g��PaletteEntry�Ԗڂ̃G���g������APaletteEntry�@�{�@DataSize�Ԗڂ̃G���g���܂łɁA
	pPaletteTable�Ŏw�����̈�̐擪�̃f�[�^���珇�ɃZ�b�g���Ă����܂��B
	�p���b�g�ԍ� 1023 ���傫���p���b�g�ԍ��ɑΉ�����f�[�^�͖�������܂��B
	���Ȃ킿�ݒ肪 PaletteEntry�@�{�@DataSize�@���@1024�@�̏ꍇ�́A�p���b�g�ԍ�1023�܂łŒ�~���܂��B

Arguments:
	IN PaletteEntry
		�f�[�^���������ރp���b�g�̐擪�G���g���ԍ����w�肵�܂��B
		 0 ���� 1023 �̒��̂����ꂩ���w�肵�܂��B
		�w�肳�ꂽ�G���g���ԍ�����̃p���b�g�̓��e�����������܂��B

	IN DataSize
		�������ރf�[�^�̃T�C�Y(�G���g����)���w�肵�܂��B
		1 ����ő�1024 ���w��ł��܂��B

	IN pPaletteTable
		Palette�ݒ�p�z��̃|�C���^���w�肵�܂��B
		Palette�ݒ�p�z��̓��e�͈ȉ��̂悤�ɂȂ�܂��B

		KMPALETTEDATA		PaletteTable;

		���̃p���b�g�f�[�^�̗v�f����DataSize�ȏ�Ȃ���΂Ȃ�܂���B
		���ꂪDataSize�ȏ�Ȃ������ꍇ�̓���͕ۏ؂��܂���B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/
KMSTATUS 
kmSetPaletteBankData(
		IN KMINT32			PaletteEntry,
		IN KMINT32			DataSize,
		IN PKMPALETTEDATA	pPaletteTable
	);

/*++
kmSetBorderColor

proto type:
	KMSTATUS
	kmSetBorderColor(
			KMPACKEDARGB BorderColor
		);

Description:
	�{�[�_�[(�\����ʊO�̕���)�J���[�̐ݒ���s���܂��B

Arguments:
	IN	BorderColor		Packed��ARGB�J���[�ł��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/

KMSTATUS KMAPI
kmSetBorderColor(
		IN	KMPACKEDARGB BorderColor
	);

/*++
kmSetBackGroundRenderState

proto type:
	KMSTATUS
	kmSetBackGroundRenderState(
			PKMVERTEXCONTEXT	pVertexContext
		);

Description:
	kmProcessVertexRenderState �Őݒ肵�� KMVERTEXCONTEXT�\���̂̈ȉ��̃����o��
	Background Plane �̃����_�����O�p�����[�^�Ƃ��ăV�X�e���ɓo�^����B
	�{�֐��Ăяo���ȍ~�� kmSetBackGroundPlane() �Ŏw�肷�� �a�f�ʂ̐ݒ�́A
	�����ApVertexContext �Őݒ肵�� KMVERTEXCONTEXT �̒l���L���ɂȂ�B

	�Q�Ƃ��郁���o�F
				pVertexContext->GLOBALPARAMBUFFER
				pVertexContext->ISPPARAMBUFFER
				pVertexContext->TSPPARAMBUFFER
				pVertexContext->TexturePARAMBUFFER


Arguments:
	IN	pVertexContext
						Vertex Context �ւ̃|�C���^��^����B

Result:
	KMSTATUS_SUCCESS	�ݒ萬��

--*/

KMSTATUS KMAPI
kmSetBackGroundRenderState(
		IN	PKMVERTEXCONTEXT	pVertexContext
	);

/*++
kmSetBackGroundPlane

proto type:
	KMSTATUS
	kmSetBackGroundPlane(
				PVOID			pVertex[3],
				KMVERTEXTYPE	VertexType,
				KMINT32			StructSize
			);

Description:
	�o�b�N�O���E���h���ʂ̐ݒ���s���܂��B
	���̑O�ɁAkmSetBackGroundRenderState ���Ăяo���K�v������܂��B

Arguments:
	IN	pVertex[3]		�o�b�N�O���E���h�v���[����̍��W���������_�f�[�^�\���̂ւ̃|�C���^
						�ڍׂ́A kmSetVertex �Q��

	IN	VertexType		���_�f�[�^�̃f�[�^�^�C�v�������B
						�ڍׂ� kmSetVertex �Q��
	IN	StructSize		���_�f�[�^�̃f�[�^�^�C�v�������B
						�ڍׂ� kmSetVertex �Q��

Result:
	KMSTATUS_SUCCESS			�ݒ萬��

--*/

KMSTATUS KMAPI
kmSetBackGroundPlane(
			IN	PVOID			pVertex[3],
			IN	KMVERTEXTYPE	VertexType,
			IN	KMINT32			StructSize
		);

/*++
kmSetAutoSortMode

proto type:
	KMSTATUS
	kmSetAutoSortMode(
			KMBOOLEAN fEnable
		);

Description:
	�������ʂ̃I�[�g�\�[�g���[�h��ON/OFF�𐧌䂵�܂��B

Arguments:
	IN	bEnable		Auto Sort mode �̗L�����t���O
				TRUE	�������ʂ̃\�[�g�ɃI�[�g�\�[�g���[�h��ݒ肵�܂��B
				FALSE	�]���^�Ɠ����\�t�g�E�F�A�ɂ��\�[�e�B���O���G�~�����[�V�������܂��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/

KMSTATUS KMAPI
kmSetAutoSortMode(
		IN	KMBOOLEAN fEnable
	);

/*++
kmSetPixelClipping

proto type:
	KMSTATUS
	kmSetPixelClipping(
				KMINT32	Xmin,
				KMINT32	Ymin,
				KMINT32	Xmax,
				KMINT32	Ymax
			);

Description:
	 Frame Buffer �ւ̃����_�����O�̏o�͂ɑ΂���A�s�N�Z���P�ʂ̃N���b�s���O��ݒ肵�܂��B

Arguments:
	IN	Xmin, Ymin, Xmax, Ymax
				�s�N�Z���P�ʂ̃N���b�s���O�̈�̍���A�E�����W���w�肵�܂��B
				(Xmin,Ymin)-(Xmax,Ymax)�́A��ʃT�C�Y��菬�����Ȃ���΂����܂���B
				�܂��A��ʃ��[�h��24bpp�̎��́A�N���b�s���O�̈�̍��W�͋����łȂ���΂����܂���
				(���Ȃ킿 2�s�N�Z���P�ʂł����N���b�s���O�̈��ݒ�ł��܂���)�B
				�����łȂ������ꍇ�ɂ́A(Xmin,Ymin)�ɑ΂��Ă͎w���� 1 �傫���l�A
										(Xmax,Ymax)�ɑ΂��Ă͎w���� 1 �������l���ݒ肳��܂��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��
	KMSTATUS_INVALID_PARAMETER	�p�����[�^���s��

--*/

KMSTATUS KMAPI
kmSetPixelClipping(
		IN	KMINT32	Xmin,
		IN	KMINT32	Ymin,
		IN	KMINT32	Xmax,
		IN	KMINT32	Ymax
	);

/*++
kmSetPixelClipping

proto type:
	KMSTATUS
	kmSetStrideWidth(
			KMINT32 nWidth
		);

Description:
	�X�g���C�h�e�N�X�`���̃X�g���C�h�T�C�Y���w�肵�܂��B�X�g���C�h�T�C�Y�́A
	32 �̔{���łȂ���΂Ȃ�Ȃ��B

Arguments:
	IN	nWidth		�X�g���C�h�T�C�Y����͂���B
					�X�g���C�h�T�C�Y�� 32�̔{���łȂ���΂Ȃ�Ȃ��B

Result:
	KMSTATUS_SUCCESS			�ݒ萬��
	KMSTATUS_INVALID_PARAMETER	�p�����[�^���s��

--*/

KMSTATUS KMAPI
kmSetStrideWidth(
		KMINT32 nWidth
	);

/*++
kmSetForwardClipping

proto type:

	KMSTATUS
	kmSetForwardClipping(
			IN	KMFLOAT fDepth
		);

Description:
	�O�ʃN���b�s���O��ݒ肵�܂��B fDepth �̒l�����̏ꍇ�ɂ́A
	�l�͖�������A�N���b�s���O�͍s���Ȃ��B�܂��A1/w �� IEEE 754
	�̐��x���E�𒴂���̈�ł̃N���b�s���O�͍s���܂���B
	�{�ݒ�̓j�A�N���b�v���s�����̂ł͂���܂���̂ŁA���_�� 1/w ��
	���W�l�����ɑ傫���Ƃ���̃j�A�N���b�v�́A�A�v���P�[�V������
	�s���K�v������B

Arguments:
	IN	fDepth
		�O�ʃN���b�s���O�� Depth�l��ݒ肵�܂��B

Result:

	KMSTATUS_SUCCESS				����

--*/
KMSTATUS KMAPI
kmSetForwardClipping(
		IN	KMFLOAT fDepth
		);

/*++
kmResetRenderer

proto type:

	KMSTATUS
	kmResetRenderer( VOID );

Description:
	�����_�����O�p�C�v���C���̃\�t�g�E�F�A���Z�b�g���s���B

	�g�p����ꍇ�F
		�EStripBuffer�g�p���ɃX�g���b�v���̃f�[�^��`������Ȃ�����
		  �ꍇ�̋������Z�b�g����B

Arguments:
	NONE

Result:

	KMSTATUS_SUCCESS				����

--*/

KMSTATUS KMAPI
kmResetRenderer( VOID );

/*++
kmSetUserClipLevelAdjust

proto type:

	KMSTATUS
	kmSetUserClipLevelAdjust( KMADJUSTTYPE	Adjust,
				  PKMINT32	pLine
				 );

Description:
	���������̉�ʕ\�����[�h��ݒ肵�܂��B
	������g�p���邱�Ƃɂ��A���������̃��[�U�[�N���b�s���O�̈�̋��E���A
	��ʂ̂قڒ����ɗ���悤�ɂ��邱�Ƃ��ł��܂��B�ΐ�Q�[���Ȃǂŉ�ʂ�
	�㉺ 2 �������Ďg�p����ꍇ�ɐݒ肵�܂��B

	�_�Ђŉ�ʂ��㉺ 2 �ɕ����������ꍇ�́A���̊֐���KM_LEVEL_ADJUST_HALF���w�肵����ŁA
	���[�U�[�N���b�v�̈�̂x���W�����L�̂悤�ɐݒ肵�Ă��������B����ƁA���̃N���b�v�̈��
	���������̋��E���ɗ͉�ʂ̒����ƂȂ�悤�A�\���̈�𒲐����܂��B

		��ʂ̏c�����̉𑜓x	���[�U�[�N���b�v�̈�̂x���W
			240						0 �` 119�@�Ɓ@120 �` 239
			480						0 �` 255�@�Ɓ@256 �` 479

	�Ȃ��A���̏ꍇ�A��ʂ̏㕔�����C�����͕\�����Ȃ��Ȃ�܂��B�\������
	�Ȃ��Ȃ郉�C�����́ApLine���瓾�邱�Ƃ��ł��܂��B

Arguments:
	IN	Adjust	���������̉�ʕ\�����[�h���w�肵�܂��B
			�ȉ��̂����ꂩ���w��ł��܂��B
			KMADJUSTTYPE
			KM_LEVEL_ADJUST_NORMAL		�ʏ�\���p�̕\�����[�h�w�肵�܂��B
			KM_LEVEL_ADJUST_HALF		2�����\���p�̕\�����[�h���w�肵�܂��B


	OUT	pLine
			Adjust��KM_LEVEL_ADJUST_HALF���w�肵���ꍇ�A�_�Ђ͂����ɉ�ʂ̏㉺������
			�V�t�g�ʂ��s�N�Z�����ŕԂ��܂��B��ʂ̍ŏ㕔����A�����Ŏw�肳�ꂽ���C������
			�\������Ȃ��Ȃ�܂��B���_�o�^���ɂ͊e���_�̂x���W�l�ɁA���̒l�����Z���Ă��������B
			pLine �� NULL ���w�肵�Ă����܂��܂��񂪁A���̏ꍇ�A���[�U�͒��_�̂x���W�ɉ��Z���ׂ�
			���C�������擾���邱�Ƃ��ł��܂���B

			Adjust��KM_LEVEL_ADJUST_NORMAL���w�肵���ꍇ�́ApLine���w���̈�̓��e�͕ύX���܂���B


Result:

	KMSTATUS_SUCCESS				����

--*/
KMSTATUS KMAPI
kmSetUserClipLevelAdjust(
		IN	KMADJUSTTYPE	Adjust,
		OUT	PKMINT32	pLine
	);

/*++
kmGetGunTriggerPos

proto type:
	KMSTATUS KMAPI
	kmGetGunTriggerPos(
			PKMDWORD pHPos,
			PKMDWORD pVPos
		);

Description:
	Gun Peripheral �̃g���K�������ꂽ�ʒu��Ԃ��܂��B
	ARC1 �ł͎�������܂���B

Arguments:
	OUT	pHPos	H-Blank Out ����̐����ʒu
    OUT	pVPos	V-Blank Out ����̐����ʒu

Result:
	KMSTATUS_SUCCESS		����

--*/

KMSTATUS KMAPI
kmGetGunTriggerPos(
		OUT	PKMDWORD pHPos,
		OUT	PKMDWORD pVPos
	);

/*++
kmProcessVertexRenderState

proto type:
	KMSTATUS
	kmProcessVertexRenderState(
				PKMVERTEXCONTEXT pVertexContext
			);

Description:
	���_(�X�g���b�v)���ƂɗL���ƂȂ郌���_�����O�E�p�����[�^��ݒ肵�܂�
	(pVertexContext�̐ݒ�l���V�X�e���ɓo�^���邽�߂̑O�������s���܂�)�B

	�{�֐���pVertexContext�ɐݒ肳�ꂽ�l�����ƂɈȉ��̒l�𐶐����܂��B
			Global Parameter
			Combined ISP/TSP
			Instruction Word
			TSP Control Word
			Texture Control Bits

	�{�֐�������������L�f�[�^�́AKMVERTEXCONTEXT���̈ȉ��Ɏ��������o�ɕۑ����܂��B
			pVertexContext->GLOBALPARAMBUFFER
			pVertexContext->ISPPARAMBUFFER
			pVertexContext->TSPPARAMBUFFER
			pVertexContext->TexturePARAMBUFFER

	�{�֐��ɂ��A�O�������s���� pVertexContext �̏�L�����o�������_�����O�Ɏg�p����
	�p�����[�^�Ƃ��āA�V�X�e���ɓo�^���邽�߂ɂ́AkmSetVertexRenderState���Ăяo�����ƕK�v������܂��B

	VERTEXCONTEXT���ŏ��Ɏg�p���鎞�ɂ́AVERTEXCONTEXT�̂��ׂẴ����o�̒l���w��(������)����
	�K�v������܂��B

	���F
		pVertexContext->RenderState �ɂ��ׂẴt���O��ݒ肵�A���ׂẴp�����[�^���`���Ă��������B
		����`�̃r�b�g���������ꍇ�̓���͕ۏ؂��܂���B

Arguments:
	IN	pVertexContext		�R���e�L�X�g�ւ̃|�C���^��ݒ肵�܂��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��
	KMSTATUS_INVALIDSETTING	������Ă��Ȃ����[�h�ݒ�

--*/

KMSTATUS KMAPI
kmProcessVertexRenderState(
		IN	PKMVERTEXCONTEXT pVertexContext
	);

/*++
kmSetVertexRenderState

proto type:

	KMSTATUS
	kmSetVertexRenderState (
			PKMVERTEXCONTEXT pVertexContext
		);

Description:
	kmProcessVertexRenderState�ŏ������� pVertexContext ���̈ȉ��̃����o�y�ъ֘A����l��
	�����_�����O�Ɏg�p����p�����[�^�Ƃ��ăV�X�e���ɓo�^���܂��B

			pVertexContext->GLOBALPARAMBUFFER
			pVertexContext->ISPPARAMBUFFER
			pVertexContext->TSPPARAMBUFFER
			pVertexContext->TexturePARAMBUFFER

	�{�֐��̌Ăяo���Őݒ肵���p�����[�^�� �{�֐��̌�ŌĂяo����� kmStartVertexStrip 
	�ȍ~�̒��_(Strip)�o�^�ŗL���ƂȂ�܂��B


Arguments:
	IN	pVertexContext		KMVERTEXCONTEXT �\���̂ւ̃|�C���^��ݒ肵�܂��B

Result:
	KMSTATUS_SUCCESS		�����_�����O�p�����[�^�o�^����

--*/


KMSTATUS KMAPI
kmSetVertexRenderState (
		IN	PKMVERTEXCONTEXT pVertexContext
	);

/*++
kmSetModifierRenderState

proto type:
	KMSTATUS
	kmSetModifierRenderState(
			PKMVERTEXCONTEXT	pVertexContext
		);

Description:
	kmProcessVertexRenderState�Őݒ肵��KMVERTEXCONTEXT���̈ȉ��̃����o���A
	 Modifier Volume �̉e�����󂯂� Polygon�́A2 �Ԗڂ̃����_�����O�p�����[�^
	�Ƃ��ăV�X�e���ɓo�^���܂��B

				pVertexContext->TSPPARAMBUFFER
				pVertexContext->TexturePARAMBUFFER

	�ȍ~�� Modifier Volume �̉e�����󂯂� Polygon �̓o�^�ł́A�{�֐��Ŏw�肵��
	KMVERTEXCONTEXT�� 2 �Ԗڂ̃����_�����O�p�����[�^�Ƃ��Ďg�p���܂��B

	KMVERTEXCONTEXT�\���̂̂����ȉ��̃����o�͎Q�Ƃ��܂���(�������܂�)�B
	(kmSetVertexRenderState�ł̐ݒ�l���L���ƂȂ�܂�)
	// for Global Parameter
	KMPARAMTYPE			ParamType			// Parameter Type
	KMLISTTYPE			ListType			// List Type
	KMSTRIPLENGTH		StripLength			// Strip Length
	KMUSERCLIPMODE		UserClipMode		// UserClip Mode
	KMCOLORTYPE			ColorType			// Color Type
	KMUVFORMAT			UVFormat			// UV format

	// for ISP/TSP Instruction Word
	KMDEPTHMODE			DepthMode;			// DepthMode�w��
	KMCULLINGMODE		CullingMode;		// Culling Mode
	KMSCREENCORDINATION	ScreenCoordination;	// Screen Coordination
	KMSHADINGMODE		ShadingMode;		// Shading Mode
	KMMODIFIER			SelectModifier;		// Modifier Volume Valiant
	KMBOOLEAN			bZWriteDisable;		// Z Write Disable

	// for ModifierInstruction
	KMDWORD				ModifierInstruction;// ModifierInstruction
	KMFLOAT				fBoundingBoxXmin;	// BoundingBoxXmin(ShadowVolume)
	KMFLOAT				fBoundingBoxYmin;	// BoundingBoxYmin(ShadowVolume)
	KMFLOAT				fBoundingBoxXmax;	// BoundingBoxXmax(ShadowVolume)
	KMFLOAT				fBoundingBoxYmax;	// BoundingBoxYmax(ShadowVolume)

Arguments:
	IN	pVertexContext		�����_�����O�R���e�L�X�g�ւ̃|�C���^��ݒ肵�܂��B

Result:
	KMSTATUS_SUCCESS		�����_�����O�p�����[�^�o�^����


--*/

KMSTATUS KMAPI
kmSetModifierRenderState(
		IN	PKMVERTEXCONTEXT	pVertexContext
	);

/*++
kmSetGlobalClipping

proto type:
	KMSTATUS
	kmSetGlobalClipping(
				KMINT32 nWidth, 
				KMINT32 nHeight
			);
Description:
	�O���[�o���N���b�s���O�̈���w�肵�܂��B0,0�I���W����Width�AHeight�Ŏw�肳�ꂽ
	�̈�ȊO�̂Ƃ���ɂ̓����_�����O����܂���B

Arguments:
	IN	nWidth, nHeight				�^�C���T�C�Y�̔{�����w�肵�܂��B
									HOLLY�̏ꍇ��32x32�̃^�C���T�C�Y�̂��߁A
									���Ƃ���128x64�̗̈���w�肵�����ꍇ�ɂ� Width = 4,Height= 2�Ƃ��܂��B
									ARC1�̏ꍇ��32x8�̃^�C���T�C�Y�ł����A 
									HOLLY�ł̃p�����[�^�w���_�Г�����ARC1�ɍ��킹�ĕϊ�(Height�~4)���܂��B

Result:
	KMSTATUS_SUCCESS					�ݒ萬��
	KMSTATUS_INVALID_PARAMETER			�ݒ莸�s

--*/

KMSTATUS KMAPI
kmSetGlobalClipping(
		IN	KMINT32 nWidth, 
		IN	KMINT32 nHeight
	);

/*++
kmUseAnotherModifier

proto type:
	KMSTATUS
	kmUseAnotherModifier(
			KMLISTTYPE kmModifierListType
			);

Description:
	kmModifierListType �Ŏw�肵�� Modifier �𑼕��� 
	Modifier �Ƃ��Ă��g�p����B

Arguments:
	IN	kmModifierListType		KM_OPAQUE_MODIFIER	Opaque Modifier �� Trans Modifier  �Ƃ��Ďg�p����B
								KM_TRANS_MODIFIER	Trans Modifier  �� Opaque Modifier �Ƃ��Ďg�p����B

Result:
	KMSTATUS_SUCCESS				�ݒ萬��
	KMSTATUS_INVALID_LIST_TYPE		�ݒ莸�s

--*/

KMSTATUS KMAPI
kmUseAnotherModifier(
		IN	KMLISTTYPE kmModifier
			);

/*++
kmSetCheapShadowMode

proto type:
	KMSTATUS
	kmSetCheapShadowMode(
			KMINT32 nIntensity
			);

Description:
	�`�[�v(�Ȉ�)�V���h�E���[�h��I�����܂��BCheapShadowMode�Ƃ́A����Polygon�� Modifier Volume �ɂ������������ꍇ�A
   ���̕����̋P�x�������邱�Ƃɂ��e��\������@�\�ł��B���̊֐��Œl���ݒ肳�ꂽ��́A���ׂĂ�ModifierVolume�̐ݒ��
   �`�[�v�V���h�E���[�h�ɐݒ肳��܂��B�V�[������ 2 �p�����[�^Polygon�Ƃ̋����͂ł��܂���B
   CheapShadowMode���I��������ɂ͈����ɕ��̐������Ă��̊֐����Ăяo���Ă��������B

Arguments:
	IN	nIntensity		���f�B�t�@�C�A�{�����[�����ɓ�����Polygon�̋P�x��ݒ肵�܂��B0����255�̒l���g�p�ł��܂��B
						���ۂɂ͂����256�Ŋ������l��Polygon�̃x�[�X�J���[�ƃI�t�Z�b�g�J���[�ɏ�Z����܂��B�]���āA
						128���w�肷���128/256 = 0.5����Z����邱�ƂɂȂ�܂��B�܂��A���̒l����͂����ꍇ�A
						���̃V�[������ CheapShadowMode �̐ݒ���I�����A�ʏ�� 2 �p�����[�^Polygon���L���ƂȂ�܂��B

Result:
	KMSTATUS_SUCCESS					�ݒ萬��
	KMSTATUS_INVALID_PARAMETER			�p�����[�^���s��

--*/

KMSTATUS KMAPI
kmSetCheapShadowMode(
		IN	KMINT32 nIntensity
			);

/*++
kmSetStripLength

proto type:
	KMSTATUS
	kmSetStripLength(
		IN	KMSTRIPLENGTH	StripLength
		);

Description:
	Strip�������̊���l��ݒ肵�܂��B�^�C���A�N�Z�����[�^���A���͂��ꂽ���_�f�[�^�X�g���b�v�� Strip������������
	�ۂ̍ő�X�g���b�v�����w�肵�܂��B
	�f�t�H���g(�V�X�e�������l)�� KM_STRIP_06�ł��B
	�������AkmProcessVertexRenderState�֐��̈����Ƃ��Ďg�p����APKMVERTEXCONTEXT �\���̂� StripLength�����o��
	�L���ɂ����ꍇ�ɂ́A�{�֐��Őݒ肵���l�𖳎����AStripLength�����o�ɐݒ肵���l���g�p���܂��B

Arguments:
	IN	StripLength		Strip�������̊���l���w�肵�܂��B�ȉ��̂����ꂩ���w��ł��܂��B
						KMSTRIPLENGTH	KM_STRIP_01		= 0		// Strip��1�ɕ������܂�
										KM_STRIP_02		= 1		// Strip��2�ɕ������܂�
										KM_STRIP_04		= 2		// Strip��4�ɕ������܂�
										KM_STRIP_06		= 3		// Strip��6�ɕ������܂�

Result:
	KMSTATUS_SUCCESS	�ݒ萬��

--*/

KMSTATUS KMAPI
kmSetStripLength(
		IN	KMSTRIPLENGTH	StripLength
	);

/*++
kmSetUserClipping

proto type:
	KMSTATUS
	kmSetUserClipping(
			PKMVERTEXBUFFDESC pBufferDesc,
			KMLISTTYPE ListType,
			KMINT32	Xmin,
			KMINT32	Ymin,
			KMINT32	Xmax,
			KMINT32 Ymax 
		);

Description:
	���[�U�[�N���b�s���O�̈��ݒ肵�܂��BKMVERTEXCONTEXT �\���̂�UserClipMode�����o�ɁA
	KM_USERCLIP_INSIDE�܂���KM_USERCLIP_OUTSIDE���w�肵��Polygon�ɑ΂��ẮA
	�����Ŏw�肵�����[�U�[�N���b�s���O�̈悪�L���ƂȂ�܂��B

	���ӁF  ���_�X�g���b�v�̓o�^�̓r���ŃX�g���b�v�̈ꕔ�������N���b�v���邱�Ƃ͂ł��܂���B
			��̓I�ɂ́AkmStartVertexStrip �� �J�n�������_�X�g���b�v�̓o�^��
			kmSetVertex�� ENDOFSTRIP ��o�^����܂ł̊ԂɁAkmSetUserClipping�𔭍s���Ă͂����܂���B

Arguments:
	IN	pBufferDesc
						PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ̃|�C���^����͂��܂��B

	IN	ListType		���_�f�[�^���X�g�̎�ނ��w�肵�܂��B�ȉ��̂����ꂩ���w��ł��܂��B
						KMLISTTYPE	KM_OPAQUE_POLYGON		= 0	// �s����Polygon
									KM_OPAQUE_MODIFIER		= 1	// �s���� Modifier Volume 
									KM_TRANS_POLYGON		= 2	// ������/����Polygon
									KM_TRANS_MODIFIER		= 3	// ������/���� Modifier Volume 
									KM_PUNCHTHROUGH_POLYGON = 4	// �p���`�X���[Polygon(CLX2�̂�)

	IN	Xmin, Ymin, Xmax, Ymax
						���[�U�[�N���b�v�̈�̍���A�E�����W���w�肵�܂��B
						�����Ŏw�肷��l�̓^�C���P�ʂł��B(1 = 32pixel)
						Xmin,Xmax�́A����6bit�̂ݗL���ł��B
						Ymin,Ymax�́A����4bit�̂ݗL���ł��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/

KMSTATUS KMAPI
kmSetUserClipping(
		IN	PKMVERTEXBUFFDESC pBufferDesc,
		IN	KMLISTTYPE 		ListType,
		IN	KMINT32			Xmin,
		IN	KMINT32			Ymin,
		IN	KMINT32			Xmax,
		IN	KMINT32			Ymax
	);

/*++
kmSetUserClippingDirect

proto type:
	KMSTATUS
	kmSetUserClippingDirect(
			KMINT32	Xmin, 
			KMINT32	Ymin,
			KMINT32	Xmax, 
			KMINT32	Ymax
		);

Description:
	���[�U�[�N���b�s���O�̈��ݒ肵�܂��BVERTEXCONTEXT��UserClipMode�����o�ɁAKM_USERCLIP_INSIDE�܂���KM_USERCLIP_OUTSIDE��
	�w�肵��Polygon�ɑ΂��ẮA�����Ŏw�肵�����[�U�[�N���b�s���O�̈悪�L���ƂȂ�܂��B

���ӁF kmStartVertexStripDirect��kmSetVertexDirect�̊ԂŁA kmSetUserClippingDirect�𔭍s���Ă͂����܂���B

Arguments:

	IN	Xmin, Ymin, Xmax, Ymax
						���[�U�[�N���b�v�̈�̍���A�E�����W���w�肵�܂��B
						�����Ŏw�肷��l�̓^�C���P�ʂł��B(1 = 32pixel)
						Xmin,Xmax�́A����6bit�̂ݗL���ł��B
						Ymin,Ymax�́A����4bit�̂ݗL���ł��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/

KMSTATUS KMAPI
kmSetUserClippingDirect(
		IN	KMINT32	Xmin,
		IN	KMINT32	Ymin,
		IN	KMINT32	Xmax,
		IN	KMINT32	Ymax
	);

/*++
kmGetCurrentVertexOffset

proto type:
	KMDWORD
	kmGetCurrentVertexOffset(
			KMLISTTYPE ListType
		);

Description:
	���݁A�w��̃��X�g�^�C�v��VertexBuffer���Œ��_�f�[�^���X�g�A����Ă���32�r�b�g���[�h����Ԃ�l�Ƃ��ĕԂ��܂��B
	�{�֐��œ����l���AkmChangeVertexOffset��kmChangeVertexPCW�Ƒg�ݍ��킹�Ďg�p���邱�Ƃɂ��AVertexBuffer���̒l��
	�ύX���邱�Ƃ��ł��܂��B

Arguments:
	IN	ListType		���_�f�[�^���X�g���w�肵�܂��B�ȉ��̂����ꂩ���w��ł��܂��B
						KMLISTTYPE	KM_OPAQUE_POLYGON	= 0	// �s����Polygon
									KM_OPAQUE_MODIFIER	= 1	// �s���� Modifier Volume 
									KM_TRANS_POLYGON	= 2	// ������/����Polygon
									KM_TRANS_MODIFIER	= 3	// ������/���� Modifier Volume 

Result:
	�w�胊�X�g�^�C�v�̌��݂̏������݈ʒu��Ԃ��܂��B�l�͎w�胊�X�g�^�C�v��VertexBuffer�́A�ŏ��̃|�C���^�����
	32bit���[�h�I�t�Z�b�g�l(���݂̎w�胊�X�g�^�C�vVertexBuffer�̎g�p�e��)�ł��B
	Vertex��`��Direct�n�̊֐����g�p���Ă���ꍇ�ɂ͎g�p�ł��܂���B

--*/

KMDWORD KMAPI
kmGetCurrentVertexOffset(
		KMLISTTYPE ListType
	);

/*++
kmChangeVertexOffset

proto type:
	KMSTATUS
	kmChangeVertexOffset(
			KMLISTTYPE ListType,
			KMDWORD    VertexOffset
		);

Description:
	�w�胊�X�g�^�C�v��VertexBuffer�́A���݂̏������݈ʒu��ύX���܂��B
	Vertex��`��Direct�n�̊֐����g�p���Ă���ꍇ�ɂ͎g�p�ł��܂���B


Arguments:

	IN	ListType		���_�f�[�^���X�g���w�肵�܂��B�ȉ��̂����ꂩ���w��ł��܂��B
						KMLISTTYPE	KM_OPAQUE_POLYGON		= 0	// �s����Polygon
									KM_OPAQUE_MODIFIER		= 1	// �s���� Modifier Volume 
									KM_TRANS_POLYGON		= 2	// ������/����Polygon
									KM_TRANS_MODIFIER		= 3	// ������/���� Modifier Volume 
									KM_PUNCHTHROUGH_POLYGON = 4	// �p���`�X���[Polygon(CLX2�̂�)

	IN	VertexOffset	�w�胊�X�g�^�C�v�̏������݈ʒu���w�肵�܂��BkmGetCurrentVertexOffset�ȂǂŎ擾�����l���g�p���܂��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��
	KMSTATUS_INVALID_VALUE	�w��ł��Ȃ��l��ݒ肵��

--*/

KMSTATUS KMAPI
kmChangeVertexOffset(
		KMLISTTYPE ListType,
		KMDWORD    VertexOffset
	);

/*++
kmChangeVertexPCW

proto type:
	KMSTATUS
	kmChangeVertexPCW(
			KMLISTTYPE ListType,
			KMDWORD    VertexPCW,
			KMDWORD    IncPtr
		);

Description:
	�w��̃��X�g�^�C�vVertexBuffer�́A���݂̏������݈ʒu��VertexPCW�Ŏw�肳�ꂽ�l���������݂܂��B���̏ꍇ
	VertexBuffer�̃|�C���^��IncPtr�����A�C���N�������g����܂��B�O�p�`�̃X�g���b�v��`�I����A�r���ŃX�g���b�v��
	���f����ꍇ�ȂǂɎg�p���܂��B�{�֐���VertexBuffer���̐�������j�󂷂�\��������܂��̂Ŏg�p����ꍇ�ɂ͏\��
	���ӂ��Ă��������B�܂��AVertex��`��Direct�n�̊֐����g�p���Ă���ꍇ�ɂ͎g�p�ł��܂���B

Arguments:
	IN	ListType		���_�f�[�^���X�g���w�肵�܂��B�ȉ��̂����ꂩ���w��ł��܂��B
						KMLISTTYPE	KM_OPAQUE_POLYGON		= 0	// �s����Polygon
									KM_OPAQUE_MODIFIER		= 1	// �s���� Modifier Volume 
									KM_TRANS_POLYGON		= 2	// ������/����Polygon
									KM_TRANS_MODIFIER		= 3	// ������/���� Modifier Volume 
									KM_PUNCHTHROUGH_POLYGON = 4	// �p���`�X���[Polygon(CLX2�̂�)
	IN	VertexPCW		���_��`��ParameterControlWord���w�肵�܂��B
									KM_VERTEXPARAM_NORMAL		= 0xE0000000	// �ʏ�̒��_�f�[�^
									KM_VERTEXPARAM_ENDOFSTRIP	= 0xF0000000	// �X�g���b�v�I�[�̒��_�f�[�^

	IN	IncPtr			VertexPCW�Ŏw�肳�ꂽ�p�����[�^�������݌�ɁAVertexBuffer�̃|�C���^��������i�߂�̂����w�肵�܂��B
						�ʏ��sizeof(...)/4�̂悤�Ɏg�p���Ă���VertexType�̃T�C�Y���w�肵�܂��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��

--*/

KMSTATUS KMAPI
kmChangeVertexPCW(
		KMLISTTYPE ListType,
		KMDWORD    VertexPCW,
		KMDWORD    IncPtr
	);

/*++
kmChangeContextColorType

proto type:
	KMSTATUS
	kmChangeContextColorType(
			KMCOLORTYPE Color
		);

Description:
	���_�̃J���[�t�H�[�}�b�g��ύX���܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextColorType(
		KMCOLORTYPE Color
	);

/*++
kmChangeContextDepthMode

proto type:
	KMSTATUS 
	kmChangeContextDepthMode(
			KMDEPTHMODE DepthMode
		);

Description:
	Z�l��r���[�h��I�����܂��B

Arguments:

Result:

--*/

KMSTATUS  KMAPI
kmChangeContextDepthMode(
		KMDEPTHMODE DepthMode
	);

/*++
kmChangeContextCullingMode

proto type:
	KMSTATUS
	kmChangeContextCullingMode(
			KMCULLINGMODE CullingMode
		);

Description:
	�J�����O���[�h��I�����܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextCullingMode(
		KMCULLINGMODE CullingMode
	);

/*++
kmChangeContextZWriteDisable

proto type:
	KMSTATUS
	kmChangeContextZWriteDisable(
			KMBOOLEAN fZWriteDisable
		);

Description:
	Z�l�̍X�V���֎~/�����܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextZWriteDisable(
		IN	KMBOOLEAN fZWriteDisable
	);

/*++
kmChangeContextSRCBlendMode

proto type:
	KMSTATUS
	kmChangeContextSRCBlendMode(
			KMBLENDINGMODE SRCBlend
		);

Description:
	�\�[�X�̃u�����f�B���O���[�h��I�����܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextSRCBlendMode(
		IN	KMBLENDINGMODE SRCBlend
	);

/*++
kmChangeContextDSTBlendMode

proto type:
	KMSTATUS
	kmChangeContextDSTBlendMode(
			KMBLENDINGMODE DSTBlend
		);

Description:
	�f�B�X�e�l�[�V�����̃u�����f�B���O���[�h��I�����܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextDSTBlendMode(
		IN	KMBLENDINGMODE DSTBlend
	);

/*++
kmChangeContextFogMode

proto type:
	KMSTATUS
	kmChangeContextFogMode(
			KMFOGMODE FogMode
		);

Description:
	�t�H�O���[�h��I�����܂��B

Arguments:

Result:

--*/
KMSTATUS KMAPI
kmChangeContextFogMode(
		IN	KMFOGMODE FogMode
	);

/*++
kmChangeContextFlipUV

proto type:
	KMSTATUS
	kmChangeContextFlipUV(
			KMFLIPMODE FlipMode
		);

Description:
	�e�N�X�`����Flip��ݒ肵�܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextFlipUV(
		IN	KMFLIPMODE FlipMode
	);

/*++
kmChangeContextClampUV

proto type:
	KMSTATUS
	kmChangeContextClampUV(
			KMCLAMPMODE ClampMode
		);

Description:
	�e�N�X�`����Clamp��ݒ肵�܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextClampUV(
		IN	KMCLAMPMODE ClampMode
	);

/*++
kmChangeContextFilterMode

proto type:
	KMSTATUS
	kmChangeContextFilterMode(
			KMFILTERMODE FilterMode
		);

Description:
	�e�N�X�`���t�B���^��ݒ肵�܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextFilterMode(
		IN	KMFILTERMODE FilterMode
	);

/*++
kmChangeContextSuperSample

proto type:
	KMSTATUS
	kmChangeContextSuperSample(
			KMBOOLEAN fEnable
		);

Description:
	������TRUE�̏ꍇanisotoropic Filter���g�p���܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextSuperSample(
		IN	KMBOOLEAN fEnable
	);

/*++
kmChangeContextTextureShadingMode

proto type:
	KMSTATUS
	kmChangeContextTextureShadingMode(
			KMTEXTURESHADINGMODE TexShadingmode
		);

Description:
	�e�N�X�`���u�����f�B���O���[�h���w�肵�܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextTextureShadingMode(
		IN	KMTEXTURESHADINGMODE TexShadingmode
	);

/*++
kmChangeContextColorClamp

proto type:
	KMSTATUS
	kmChangeContextColorClamp(
			KMBOOLEAN fColorClamp
		);

Description:
	������TRUE�̏ꍇ�O���[�o�����W�X�^�̒l�ɏ]���ĐF���N�����v����܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextColorClamp(
		IN	KMBOOLEAN fColorClamp
	);

/*++
kmChangeContextPaletteBank

proto type:
	KMSTATUS
	kmChangeContextPaletteBank(
			KMDWORD Bank
		);

Description:
	���݂̃p���b�g�o���N��ύX���܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextPaletteBank(
		IN	KMDWORD Bank
	);


/*++
kmChangeContextStripLength

proto type:
	KMSTATUS
	kmChangeContextStripLength(
			KMSTRIPLENGTH		 StripLength
		);

Description:
	���͂��ꂽ���_�X�g���b�v�f�[�^���A�^�C���A�N�Z�����[�^�����ŁA��Polygon���̃X�g���b�v�ɕ������邩���w�肵�܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextStripLength(
		IN	KMSTRIPLENGTH		 StripLength
	);


/*++
kmChangeContextUserClipMode

proto type:
	KMSTATUS
	kmChangeContextUserClipMode(
			KMUSERCLIPMODE 		UserClipMode
		);

Description:
	KmSetUserClipping�Ŏw�肵���N���b�s���O�̈�ɑ΂�����ʂ��w�肵�܂��B

Arguments:

Result:

--*/

KMSTATUS KMAPI
kmChangeContextUserClipMode(
		IN	KMUSERCLIPMODE 		UserClipMode
	);


/*++
kmCreateVertexBuffer

proto type:
	KMSTATUS
	kmCreateVertexBuffer(
			PKMVERTEXBUFFDESC pBufferDesc,
			KMINT32 OpaquePolygonBuffer,
			KMINT32 OpaqueModifierBuffer,
			KMINT32 TransPolygonBuffer,
			KMINT32 TransModifierBuffer
		);

Description:
	���_�f�[�^�o�^�Ɏg�p����o�b�t�@(�ȉ� Vertex Buffer)�ƁAVertex Buffer �ɓo�^���ꂽ���_�f�[�^���A
	�^�C���A�N�Z�����[�^�������_�����O�Ɏg�p����p�����[�^�Ƃ��ēW�J���邽�߂̃o�b�t�@(�ȉ� Native Buffer)��
	�ȉ��̏ꏊ�ɂ��ꂼ��_�u���o�b�t�@�Ƃ��Ċm�ۂ��܂��B

			Vertex Buffer	...  ���C����������
			Native Buffer	...	  Frame Buffer ������

	Native Buffer �̃T�C�Y�́A�����Ŏw�肳�ꂽ�e���X�g�̃T�C�Y�����ƂɎZ�o���܂��B

	���_�f�[�^�o�^�́A kmStartVertexStrip, kmSetVertex ���g�p���čs���܂��B
	�eBuffer �� 1�V�[�����̃f�[�^�̓o�^������AkmRender �ł܂Ƃ߂Ăg�v�֑��邱�Ƃɂ���ă����_�����O���J�n���܂��B

	���F �{�֐��͌݊����̂��߂ɗp�ӂ���Ă���̂� kmSetSystemConfiguration ���g�p���Ă��������B

		�����_�����O���ɂs�`�̓W�J���s�����߂� �_�u���o�b�t�@�Ƃ��� Native Data Buffer ���m�ۂ��܂��B
		�Ȃ��ACLX2���T�|�[�g����� Punchthrough Polygon�pBuffer �̗e�ʂ��w�肷�邱�Ƃ͂ł��܂���A
		�܂��AkmCreateVertexBuffer��kmCreateTABuffer�𓯎��Ɏg�p���邱�Ƃ͂ł��܂���B

Arguments:
	I/O	pBufferDesc		PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ̃|�C���^����͂��܂��B
						Vertex Buffer Descriptor�̊e�����o�ɂ́A�����Ŋm�ۂ��ꂽ
						4 �̃o�b�t�@�̐擪�A�h���X���Ԃ���܂��B

	IN	OpaquePolygonBuffer
						�s����Polygon��ςݏグ�钸�_�f�[�^���X�g�̃T�C�Y(DWORD��)�B

	IN	OpaqueModifierBuffer
						�s���� Modifier Volume ��ςݏグ�钸�_�f�[�^���X�g�̃T�C�Y(DWORD��)�B

	IN	TransPolygonBuffer
						������/����Polygon��ςݏグ�钸�_�f�[�^���X�g�̃T�C�Y(DWORD��)�B

	IN	TransModifierBuffer
						������/���� Modifier Volume ��ςݏグ�钸�_�f�[�^���X�g�̃T�C�Y(DWORD��)�B

Result:
	KMSTATUS_SUCCESS			���_�f�[�^���X�g�m�ې���
	KMSTATUS_NOT_ENOUGH_MEMORY	�������e�ʂ�����Ȃ�

--*/

KMSTATUS KMAPI
kmCreateVertexBuffer(
		IN OUT	PKMVERTEXBUFFDESC pBufferDesc,
		IN		KMINT32 OpaquePolygonBuffer,
		IN		KMINT32 OpaqueModifierBuffer,
		IN		KMINT32 TransPolygonBuffer,
		IN		KMINT32 TransModifierBuffer
	);


/*++
kmDiscardVertexBuffer

prototype:
KMSTATUS KMAPI
kmDiscardVertexBuffer(
		PKMVERTEXBUFFDESC pBufferDesc
	);

Description:
	kmCreateVertexBuffer�ɂĊm�ۂ������_�f�[�^�o�^�p�� 4��ނ̃o�b�t�@(�_�u���o�b�t�@)���J�����܂��B
	������ Frame Buffer ��Ɋm�ۂ����^�C���A�N�Z�����[�^�o�͗p�o�b�t�@(Native Data Buffer)���J�����܂��B

Arguments:
	I/O pBufferDesc			PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ̃|�C���^����͂��܂��B

Result:
	KMSTATUS_SUCCESS		���_�f�[�^���X�g�J������

--*/
KMSTATUS KMAPI
kmDiscardVertexBuffer(
		PKMVERTEXBUFFDESC pBufferDesc
	);


/*++
kmCreateTABuffer

proto type:
	KMSTATUS
	kmCreateTABuffer(
		IN	PKMVERTEXBUFFDESC pBufferDesc,
		IN	KMINT32 TABuffer
		);

Description:
	�^�C���A�N�Z�����[�^�o�͗p�o�b�t�@(Native Data Buffer)���A Frame Buffer ��������Ɋm�ۂ��܂��B
	���_�f�[�^�o�^�́A�ȉ��̊֐����g�p���ă^�C���A�N�Z�����[�^�֒��ڃf�[�^�𑗂荞�ނ��ƂŎ������܂��B

				kmStartVertexStripDirect
				kmSetVertexDirect
				kmSetUserClippingDirect
				kmSetEndOfListDirect
				kmRenderDirect

���ӁF�ЂƂ̃A�v���P�[�V�������� kmCreateVertexBuffer �� kmCreateTABuffer �𓯎��Ɏg�p���邱�Ƃ͂ł��܂���B
      �܂��A�e�N�X�`���T�[�t�F�X�̊m�ۂ́A�{�֐��Ăяo���ȑO�Ɍ�ŌĂяo���Ă��������B
	  (CLX1/2)�ł́A�l�B�e�B�u�f�[�^�o�b�t�@�̐������@���ς�邽�߁A���̊֐��͎g�p�ł��܂���B
	  (CLX1/2)�ł́AkmSetSystemConfiguration ���g�p���Ă��������B

Arguments:

	IN	pBufferDesc		PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ̃|�C���^�ł��B

	IN	TABuffer		�^�C���A�N�Z�����[�^�o��(PowerVR�l�C�e�C�u�f�[�^)��ۑ�����o�b�t�@�̃T�C�Y(�o�C�g��)�B

Result:
	KMSTATUS_SUCCESS			���_�f�[�^���X�g�m�ې���
	KMSTATUS_NOT_ENOUGH_MEMORY	�������e�ʂ�����Ȃ�

--*/

KMSTATUS KMAPI
kmCreateTABuffer(
		IN	PKMVERTEXBUFFDESC pBufferDesc,
		IN	KMINT32 TABuffer
	);

/*++
kmFlushVertexBuffer

proto type:
	KMSTATUS
	kmFlushVertexBuffer(
		IN	KMLISTTYPE ListType
		);

Description:
	ListType �Ŏw�肵�� ���_�f�[�^���X�g�̓��e�� Tiling Accelerator �ɓ]�����܂��B

���ӁF

Arguments:
	IN	ListType		Flush ���钸�_�f�[�^���X�g���w�肵�܂��B

Result:
	KMSTATUS_SUCCESS	�]�������H

--*/

KMSTATUS KMAPI
kmFlushVertexBuffer(
		IN	KMLISTTYPE ListType
		);

/*++
kmStartVertexStrip

proto type:
	KMSTATUS
	kmStartVertexStrip( 
			PKMVERTEXBUFFDESC pBufferDesc
		);

Description:
	�_�ЂɁA���_�f�[�^�X�g���b�v�̓o�^���J�n���邱�Ƃ�ʒm���܂��B
	�ȉ��̊֐��̌Ăяo���ŃV�X�e���ɓo�^����

		kmSetVertexRenderState
		kmSetModifierRenderState

	�����_�����O�p�����[�^���A5��̒��_�f�[�^���X�g�̂����ꂩ�֏������݂܂��B
	�������ޒ��_�f�[�^���X�g�́A KMVERTEXCONTEXT��
	ListType�����o���猈�肳��܂��B

���ӁF�����ŏ������񂾃����_�����O�p�����[�^�̏��ƁA����ɑ���kmSetVertex�ő���
	  ���_�p�����[�^�̌`���̑g�ݍ��킹���������Ȃ��ꍇ�̓���͕ۏ؂���܂���B

	<�{�֐��͍�������v������邽��Inline�W�J�����}�N���Ƃ��Ē�`����܂��B>

	�}�N�����g�p����ꍇ�ɂ́A�ȉ��̂悤�ɐݒ肵�Ă��������B

		#define _KM_USE_VERTEX_MACRO_
		#include <kamui.h>
		#include <kamuix.h> 

Arguments:
	IN	pBufferDesc				PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ̃|�C���^�ł��B
								�f�[�^��o�^���钸�_�f�[�^���X�g�̏��������B

Result:
	KMSTATUS_SUCCESS			�����_�����O�p�����[�^ �������ݐ���
	KMSTATUS_NOT_ENOUGH_MEMORY	���_�f�[�^���X�g�̗e�ʂ�����Ȃ�

--*/
#if !defined(_KM_USE_VERTEX_MACRO_)
KMSTATUS KMAPI
kmStartVertexStrip( 
		IN	PKMVERTEXBUFFDESC pBufferDesc
	);
#endif

/*++
kmStartVertexStripDirect

proto type:
	KMSTATUS
	kmStartVertexStripDirect(VOID);

Description:
	���_�f�[�^�X�g���b�v�̓o�^���J�n���܂��BkmProcessVertexRenderState �ō쐬�� kmSetModifierRenderState ��
	�V�X�e���ɓo�^���������_�����O�p�����[�^���^�C���A�N�Z�����[�^�֒��ڏ������݂܂��B
	����V�[���̒��_�f�[�^���^�C���A�N�Z�����[�^�ɑ���ꍇ�A���_�̎�ޖ��ɂ܂Ƃ߂ē��͂���K�v������܂��B

	��F Opaque Polygon ��o�^��  Translucent Polygon ��o�^���A�ēxOpaque Polygon ��o�^���� ���Ƃ͂ł��܂���B

	���ӁF	�����ŏ������񂾃����_�����O�p�����[�^�̏��ƁA����ɑ���kmSetVertex�ŏ�������
			���_�p�����[�^�̌`���̑g�ݍ��킹���������Ȃ��ꍇ�̓���͕ۏ؂���܂���B

			���X�g�ւ̒��_�o�^���������A�ʂ̃��X�g�̓o�^���J�n����ꍇ�A kmSetEndOfListDirect ���g�p����
			���X�g�̊������^�C���A�N�Z�����[�^�ɒʒm����K�v������܂��B


Result:
	KMSTATUS_SUCCESS		�����_�����O�p�����[�^�������ݐ���

Arguments:
	IN	pBufferDesc		KMVERTEXBUFFDESC�^��Vertex Buffer Descriptor�ւ̃|�C���^�ł��B

Result:
	KMSTATUS_SUCCESS		�����_�����O�p�����[�^�������ݐ���

--*/

KMSTATUS KMAPI
kmStartVertexStripDirect(VOID);

/*++
kmSetVertex

proto type:
	KMSTATUS
	kmSetVertex(
			PKMVERTEXBUFFDESC pBufferDesc,
			PVOID pVertex,
			KMVERTEXTYPE VertexType,
			KMINT32 StructSize
		);

Description:
	pVertex���w�����_�f�[�^���A�V�X�e���ɓo�^�ς݂̃����_�����p�����[�^�� ListType �Ŏw�肵�����_�f�[�^���X�g�֏������݂܂��B
	�X�g���b�v�̍Ō�ƂȂ钸�_�f�[�^��Parameter Control Word ��KM_VERTEXPARAM_ENDOFSTRIP �łȂ������Ƃ��̓���͕ۏ؂��܂���B

	���ӁF	�����ŏ������ޒ��_�p�����[�^�̌`���ƁA���̑O��kmSetVertexRenderState�Őݒ肵���O���[�o���p�����[�^�̌`����
			�g�ݍ��킹���������Ȃ��ꍇ�̓���͕ۏ؂��܂���B

	<�{�֐��͍�������v������邽��Inline�W�J�����}�N���Ƃ��Ē�`����܂��B>

	�}�N�����g�p����ꍇ�ɂ́A�ȉ��̂悤�ɐݒ肵�Ă��������B

		#define _KM_USE_VERTEX_MACRO_
		#include <kamui.h>
		#include <kamuix.h> 

Arguments:
	IN	pBufferDesc		PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ̃|�C���^�ł��B
	IN	pVertex			���_�f�[�^�\���̂ւ̃|�C���^�ł��B
	IN	VertexType		���_�f�[�^�̃f�[�^�^�C�v�������܂��B���L�̂����ꂩ���w�肵�܂��B
						KM_VERTEXTYPE_00			// ���_�f�[�^ Type 0
						KM_VERTEXTYPE_01			// ���_�f�[�^ Type 1
						KM_VERTEXTYPE_02			// ���_�f�[�^ Type 2
						KM_VERTEXTYPE_03			// ���_�f�[�^ Type 3
						KM_VERTEXTYPE_04			// ���_�f�[�^ Type 4
						KM_VERTEXTYPE_05			// ���_�f�[�^ Type 5
						KM_VERTEXTYPE_06			// ���_�f�[�^ Type 6
						KM_VERTEXTYPE_07			// ���_�f�[�^ Type 7
						KM_VERTEXTYPE_08			// ���_�f�[�^ Type 8
						KM_VERTEXTYPE_09			// ���_�f�[�^ Type 9
						KM_VERTEXTYPE_10			// ���_�f�[�^ Type 10
						KM_VERTEXTYPE_11			// ���_�f�[�^ Type 11
						KM_VERTEXTYPE_12			// ���_�f�[�^ Type 12
						KM_VERTEXTYPE_13			// ���_�f�[�^ Type 13
						KM_VERTEXTYPE_14			// ���_�f�[�^ Type 14
						KM_VERTEXTYPE_15			// ���_�f�[�^ Type 15
						KM_VERTEXTYPE_16			// ���_�f�[�^ Type 16
						KM_VERTEXTYPE_17			// ���_�f�[�^ Type 17

	IN	StructSize		���_�f�[�^�̃f�[�^�^�C�v�T�C�Y�������܂��B���_�f�[�^�Ɏg�p����^�C�v�ɍ��킹�āA
						sizeof(KMVERTEX_01)�̗l�Ɏw�肵�Ă��������B

Result:
	KMSTATUS_SUCCESS			���_�f�[�^�������ݐ���
	KMSTATUS_NOT_ENOUGH_MEMORY	���_�f�[�^���X�g�̗e�ʂ�����Ȃ�

--*/
#if !defined(_KM_USE_VERTEX_MACRO_)
KMSTATUS KMAPI
kmSetVertex(
		IN	PKMVERTEXBUFFDESC pBufferDesc,
		IN	PVOID pVertex,
		IN	KMVERTEXTYPE VertexType,
		IN	KMINT32 StructSize
	);
#endif

/*++
kmSetVertexDirect

proto type:
	KMSTATUS
	kmSetVertexDirect(
			PVOID pVertex,
			KMVERTEXTYPE VertexType,
			KMINT32 StructSize
		);

Description:
	pVertex���w�����_�f�[�^���^�C���A�N�Z�����[�^�֒��ڏ������݂܂��B
	����V�[���̒��_�f�[�^���^�C���A�N�Z�����[�^�ɑΑ���ꍇ�A���_�̎�ޖ��ɂ܂Ƃ߂ē��͂���K�v������܂��B

	���ӁF	�X�g���b�v�̍Ō�ƂȂ钸�_�f�[�^�� Parameter Control Word ��KM_VERTEXPARAM_ENDOFSTRIP ��
			�Ȃ������Ƃ��̓���͕ۏ؂��܂���B
			�����ŏ������ޒ��_�f�[�^�̃f�[�^�^�C�v�ƁA���̑O��kmSetVertexRenderState�Őݒ肵��
			�O���[�o���p�����[�^�̌`���̑g�ݍ��킹���������Ȃ��ꍇ�̓���͕ۏ؂��܂���B

Arguments:
	IN	pVertex			���_�f�[�^�\���̂ւ̃|�C���^�ł��B
	IN	VertexType		���_�f�[�^�̃f�[�^�^�C�v�������܂��B���L�̂����ꂩ���w�肵�܂��B
						KM_VERTEXTYPE_00			// ���_�f�[�^ Type 0
						KM_VERTEXTYPE_01			// ���_�f�[�^ Type 1
						KM_VERTEXTYPE_02			// ���_�f�[�^ Type 2
						KM_VERTEXTYPE_03			// ���_�f�[�^ Type 3
						KM_VERTEXTYPE_04			// ���_�f�[�^ Type 4
						KM_VERTEXTYPE_05			// ���_�f�[�^ Type 5
						KM_VERTEXTYPE_06			// ���_�f�[�^ Type 6
						KM_VERTEXTYPE_07			// ���_�f�[�^ Type 7
						KM_VERTEXTYPE_08			// ���_�f�[�^ Type 8
						KM_VERTEXTYPE_09			// ���_�f�[�^ Type 9
						KM_VERTEXTYPE_10			// ���_�f�[�^ Type 10
						KM_VERTEXTYPE_11			// ���_�f�[�^ Type 11
						KM_VERTEXTYPE_12			// ���_�f�[�^ Type 12
						KM_VERTEXTYPE_13			// ���_�f�[�^ Type 13
						KM_VERTEXTYPE_14			// ���_�f�[�^ Type 14
						KM_VERTEXTYPE_15			// ���_�f�[�^ Type 15
						KM_VERTEXTYPE_16			// ���_�f�[�^ Type 16
						KM_VERTEXTYPE_17			// ���_�f�[�^ Type 17

	IN	StructSize		���_�f�[�^�̃f�[�^�^�C�v�T�C�Y�������܂��B���_�f�[�^�Ɏg�p����^�C�v�ɍ��킹�āA
						sizeof(KMVERTEX_01)�̗l�Ɏw�肵�Ă��������B
Result:
	KMSTATUS_SUCCESS		���_�f�[�^�������ݐ���

--*/

KMSTATUS KMAPI
kmSetVertexDirect(
		IN	PVOID 				pVertex,
		IN	KMVERTEXTYPE		VertexType,
		IN	KMINT32				StructSize
	);


/*++
kmSetEndOfListDirect

proto type:
	KMSTATUS
	kmSetEndOfListDirect( VOID );

Description:
	����̎�ނ̃��X�g�̏I�����A�^�C���A�N�Z�����[�^�֒��ڒʒm���܂��B

	���ݓo�^���̃��X�g�̍Ō�� kmSetEndOfListDirect() �𔭍s���āA
	���݂̃��X�g�^�C�v�̃f�[�^�̓o�^���I���������Ƃ�ʒm���܂��B

	���ӁFkmSetVertex���g�p���Ē��_�o�^���s���Ă���ꍇ�ɂ́A�{�֐����Ăяo���Ă͂����܂���B

Arguments:
	None

Result:
	KMSTATUS_SUCCESS		�ʒm����

--*/

KMSTATUS KMAPI
kmSetEndOfListDirect( VOID );


/*++
kmRender

proto type:
	KMSTATUS
	kmRender( VOID );

Description:
	�^�C���A�N�Z�����[�^�ɑ΂��āA1�V�[�����̒��_�f�[�^�̓o�^���I���������Ƃ�_�Ђɒʒm��,
	�f�[�^�W�J������ABack Buffer �ɑ΂��郌���_�����O���J�n���܂��B

Arguments:
	None

Result:
	KMSTATUS_SUCCESS		�ʒm����

--*/

KMSTATUS KMAPI
kmRender( VOID );

/*++
kmRenderDirect

proto type:
	KMSTATUS
	kmRenderDirect(VOID);

Description:
	�^�C���A�N�Z�����[�^�ɑ΂��āA1�V�[�����̒��_�f�[�^�̓o�^���I���������Ƃ�_�Ђɒʒm��,
	���_�f�[�^�W�J������ABack Buffer �ɑ΂��郌���_�����O���J�n���܂��B

Arguments:
	None

Result:
	KMSTATUS_SUCCESS		�ʒm����

--*/

KMSTATUS KMAPI
kmRenderDirect(VOID);

/*++
kmRenderTexture

proto type:
	KMSTATUS
	kmRenderTexture(	
			PKMSURFACEDESC pTextureSurface
		);

Description:
	�^�C���A�N�Z�����[�^�ɑ΂��āA1�V�[�����̒��_�f�[�^�̓o�^���I���������Ƃ�_�Ђɒʒm���܂��B
	���_�f�[�^�W�J������A����(pTextureSurface) �Ŏw�肳��ꂽ�e�N�X�`���ɑ΂��郌���_�����O���J�n���܂��B(
	�Ȃ��A�`���Ɏw�肷��e�N�X�`���́ARectangle/Stride�`���łȂ���΂Ȃ�܂���B

Arguments:
	OUT	pTextureSurface		�����_�����O���ʂ��i�[����e�N�X�`���ł��B

Result:
	KMSTATUS_SUCCESS			�ʒm����
	KMSTATUS_INVALID_TEXTURE	�����ȃe�N�X�`�����w�肵��

--*/

KMSTATUS KMAPI
kmRenderTexture(
		PKMSURFACEDESC pTextureSurface
	);

/*++
kmRenderTextureDirect

proto type:
	KMSTATUS
	kmRenderTextureDirect(
			PKMSURFACEDESC pTextureSurface
		);

Description:
	�^�C���A�N�Z�����[�^�ɑ΂��āA1�V�[�����̒��_�f�[�^�̓o�^���I���������Ƃ�_�Ђɒʒm���܂��B
	���_�f�[�^�W�J������A����(pTextureSurface) �Ŏw�肳��ꂽ�e�N�X�`���ɑ΂��郌���_�����O���J�n���܂��B(
	�Ȃ��A�`���Ɏw�肷��e�N�X�`���́ARectangle/Stride�`���łȂ���΂Ȃ�܂���B

Arguments:
	OUT	pTextureSurface		�����_�����O���ʂ��i�[����e�N�X�`���ł��B

Result:
	KMSTATUS_SUCCESS		�ʒm����
	KMSTATUS_INVALID_TEXTURE	�����ȃe�N�X�`�����w�肵��

--*/

KMSTATUS KMAPI
kmRenderTextureDirect(
		PKMSURFACEDESC pTextureSurface
	);

/*++
kmSetEORCallback

proto type:

	KMSTATUS 
	kmSetEORCallback(
			PKMCALLBACKFUNC pEORCallback,
			PVOID pCallbackArguments
		);

Description:
	�����_�����O�I�����ɌĂ΂��R�[���o�b�N�֐���o�^���܂��B
	�R�[���o�b�N�֐��́A�ȉ��̌`���ŃR�[�f�B���O���Ă��������B

		VOID EORCallbackFunc(PVOID pCallbackArguments);

	pCallbackArguments(����)�F�o�^���Ɏw�肳�ꂽ�p�����[�^�ւ̃|�C���^�ł��B

Arguments:
	IN	pEORCallback	�����_�����O�I�����ɌĂ΂��֐��̃|�C���^���w�肵�܂��B
	IN	pCallbackArguments
						callback ���Ɍďo�����֐��֓n���A�����ւ̃|�C���^���w�肵�܂��B


Result:
	KMSTATUS_SUCCESS		�o�^����

--*/

KMSTATUS  KMAPI
kmSetEORCallback(
		PKMCALLBACKFUNC pEORCallback,
		PVOID 			pCallbackArguments
	);

/*++
kmSetVSyncCallback

proto type:
	KMSTATUS
	kmSetVSyncCallback(
			PKMCALLBACKFUNC pVSyncCallback,
			PVOID pCallbackArguments
		);

Description:
	�����A�����(Vsync)�˓����ɌĂяo�����R�[���o�b�N�֐���o�^���܂��B
	�R�[���o�b�N�֐��́A�ȉ��̌`���ŃR�[�f�B���O���Ă��������B

		VOID VSyncCallbackFunc(PVOID pCallbackArguments);

	pCallbackArguments(����)�F�o�^���Ɏw�肳�ꂽ�p�����[�^�ւ̃|�C���^�ł��B

Arguments:
	IN	pVSyncCallback	Vsync�˓����ɌĂ΂��֐��̃|�C���^���w�肵�܂��B
	IN	pCallbackArguments
						callback ���Ɍďo�����֐��֓n���A�����ւ̃|�C���^���w�肵�܂��B

Result:
	KMSTATUS_SUCCESS		�o�^����

--*/

KMSTATUS KMAPI
kmSetVSyncCallback(
		PKMCALLBACKFUNC pVSyncCallback,
		PVOID 			pCallbackArguments
	);

/*++
kmSetHSyncCallback

proto type:
	KMSTATUS
	kmSetHSyncCallback(
			PKMCALLBACKFUNC pHSyncCallback,
			PVOID pCallbackArguments
		);

Description:
	�����A�����(Hsync)�˓����ɌĂяo�����R�[���o�b�N�֐���o�^���܂��B
	�R�[���o�b�N�֐��́A�ȉ��̌`���ŃR�[�f�B���O���Ă��������B

	VOID HSyncCallbackFunc(PVOID pCallbackArguments);

	pCallbackArguments(����)�F�o�^���Ɏw�肳�ꂽ�p�����[�^�ւ̃|�C���^�ł��B

Arguments:
	IN	pHSyncCallback		Hsync�˓����ɌĂ΂��֐��̃|�C���^���w�肵�܂��B

	pCallbackArguments		callback ���Ɍďo�����֐��֓n���A�����ւ̃|�C���^���w�肵�܂��B
							KmSetHSyncLine �Ŏw�肵�����C���ԍ��͓n����Ȃ��̂ŁA
							kmSetHSyncLine �Őݒ肵���l�����̃|�C���^�������̈�ɕێ����邩�A
							�܂��́AkmGetCurrentScanline()���g�p���āA���݂� Scanline �����擾���Ă��������B

Result:
	KMSTATUS_SUCCESS		�o�^����

--*/

KMSTATUS KMAPI
kmSetHSyncCallback(
		PKMCALLBACKFUNC pHSyncCallback,
		PVOID pCallbackArguments
	);

/*++
kmSetHSyncLine

proto type:
	KMSTATUS
	kmSetHSyncLine(
			KMINT32 nInterruptLine
		);

Description:
	�\�������C���ڂŊ��荞�݂��N���������w�肵�܂��B 

Arguments:
	IN	nInterruptLine	�����C���ڂŊ��荞�݂��N�������w�肵�܂��B0�`240/480�̒l��ݒ肵�Ă��������B 

Result:
	KMSTATUS_SUCCESS			�ݒ萬��
	KMSTATUS_ILLEGAL_PARAMETER	�l���s��

--*/

KMSTATUS KMAPI
kmSetHSyncLine(
		KMINT32 nInterruptLine
	);

/*++
kmGetCurrentScanline

proto type:
	KMSTATUS
	kmGetCurrentScanline(
			PKMINT32 pScanline
		);

Description:
	���݂�H-Sync���C����ǂݏo���܂��B 

Arguments:
	OUT	pScanline	���݂�H-Sync���C�����i�[����KMINT32�ւ̃|�C���^�ł��B 

Result:
	KMSTATUS_SUCCESS			�ݒ萬��

--*/

KMSTATUS KMAPI
kmGetCurrentScanline(
		PKMINT32 pScanline
	);

/*++
kmSetTexOverflowCallback

proto type:
	KMSTATUS
	kmSetTexOverflowCallback(
			PKMCALLBACKFUNC pTexOverflowCallback,
			PVOID pCallbackArguments
		);

Description:
	�e�N�X�`�����������c���Ă��Ȃ���ԂŁA�e�N�X�`����o�^���悤�Ƃ����ꍇ�ɌĂ΂��R�[���o�b�N�֐���
	�o�^���܂��B�R�[���o�b�N�֐��́A�ȉ��̌`���ŃR�[�f�B���O���Ă��������B

		VOID TexOverflowCallbackFunc(PVOID pCallbackArguments);

	pCallbackArguments(����)�F�o�^���Ɏw�肳�ꂽ�p�����[�^�ւ̃|�C���^�ł��B

Arguments:
	IN	pTexOverflowCallback	�e�N�X�`���I�[�o�[�t���[���̃R�[���o�b�N�֐��ւ̃|�C���^���w�肵�܂��B
	IN	pCallbackArguments		callback ���Ɍďo�����֐��֓n���A�����ւ̃|�C���^���w�肵�܂��B
	
Result:
	KMSTATUS_SUCCESS		�o�^����

--*/

KMSTATUS KMAPI
kmSetTexOverflowCallback(
		PKMCALLBACKFUNC pTexOverflowCallback,
		PVOID pCallbackArguments
	);

/*++
kmSetStripOverRunCallback

proto type:
	KMSTATUS
	kmSetStripOverRunCallback (
			PKMCALLBACKFUNC	pStripOverRunCallback,
			PVOID			pCallbackArguments
		);

Description:
	StripBuffer�̏c�T�C�Y�̕\�����Ԓ��Ɏ���Strip�̃����_�����O���I�����Ȃ������ꍇ�ɌĂ΂��
	�R�[���o�b�N�֐���o�^���܂��B�R�[���o�b�N�֐��́A�ȉ��̌`���ŃR�[�f�B���O���Ă��������B

			VOID StripOverRunCallbackFunc(PVOID pCallbackArguments);

	pCallbackArguments(����)�F�o�^���Ɏw�肳�ꂽ�p�����[�^�ւ̃|�C���^�ł��B

Arguments:
	IN	pStripOverRunCallback	�R�[���o�b�N�֐��ւ̃|�C���^���w�肵�܂��B
	IN	pCallbackArguments		callback ���Ɍďo�����֐��֓n���A�����ւ̃|�C���^���w�肵�܂��B

Result:
	KMSTATUS_SUCCESS		�o�^����

--*/

KMSTATUS KMAPI
kmSetStripOverRunCallback (
		PKMCALLBACKFUNC	pStripOverRunCallback,
		PVOID			pCallbackArguments
	);

/*++
kmSetEndOfVertexCallback

proto type:
	KMSTATUS
	kmSetEndOfVertexCallback (
			PKMCALLBACKFUNC pEndOfVertexCallback,
			PKMVOID			pCallbackArguments
		);

Description:
	�_�Ђ��烌���_�����O�n�[�h�E�F�A�ւ́A1�V�[���̃f�[�^�]�����I�������ꍇ�ɌĂ΂��R�[���o�b�N�֐���
	�o�^���܂��B�R�[���o�b�N�֐��́A�ȉ��̌`���ŃR�[�f�B���O���Ă��������B

			VOID EndOfVertexCallbackFunc(PVOID pCallbackArguments);

	pCallbackArguments(����)�F�o�^���Ɏw�肳�ꂽ�p�����[�^�ւ̃|�C���^�ł��B

Arguments:
	IN	pEndOfVertexCallback	�R�[���o�b�N�֐��ւ̃|�C���^���w�肵�܂��B
	IN	pCallbackArguments		callback ���Ɍďo�����֐��֓n���A�����ւ̃|�C���^���w�肵�܂��B

Result:
	KMSTATUS_SUCCESS		�o�^����

--*/

KMSTATUS KMAPI
kmSetEndOfVertexCallback (
		PKMCALLBACKFUNC pEndOfVertexCallback,
		PKMVOID 		pCallbackArguments
	);

/*++
kmSetEndOfYUVCallback

proto type:
	KMSTATUS
	kmSetEndOfYUVCallback(
			PKMCALLBACKFUNC pEndOfYUVCallback,
			PVOID pCallbackArguments
		);

Description:
	CLX��YUV�R���o�[�^���R���o�[�g���I�������ۂɔ��s����AYUV�I�����荞�݂ɑ΂���
	�R�[���o�b�N�֐���o�^���܂��B

		VOID EndOfYUVFunc(PVOID pCallbackArguments);

	pCallbackArguments(����)�F�o�^���Ɏw�肳�ꂽ�p�����[�^�ւ̃|�C���^�ł��B

Arguments:
	IN	pEndOfYUVCallback		YUV�R���o�[�g�I�����̃R�[���o�b�N�֐��ւ̃|�C���^���w�肵�܂��B
	IN	pCallbackArguments		callback ���Ɍďo�����֐��֓n���A�����ւ̃|�C���^���w�肵�܂��B
	
Result:
	KMSTATUS_SUCCESS		�o�^����

--*/

KMSTATUS KMAPI
kmSetEndOfYUVCallback(
		PKMCALLBACKFUNC pEndOfYUVCallback,
		PVOID pCallbackArguments
	);

/*++
kmSetWaitVsyncCallback

proto type:
	KMSTATUS
	kmSetWaitVsyncCallback(
			PKMCALLBACKFUNC pWaitVsyncCallback,
			PVOID pCallbackArguments
		);

Description:
	Vsync��WAIT���ɌĂ΂��R�[���o�b�N�֐���o�^���܂��BCD-ROM����̓ǂݏo�����o�b�N�O���E���h
	���ōs���ꍇ��A���̑�V�񓯊��������s�����߂̃R�[���o�b�N���Ƃ��Ďg�p���܂��B
	�������A���܂�傫�Ȋ֐��A�R�[���o�b�N���ł̖������[�v���͍s��Ȃ��ł��������B
	
		VOID WaitVsyncCallbackFunc(PVOID pCallbackArguments);

	pCallbackArguments(����)�F�o�^���Ɏw�肳�ꂽ�p�����[�^�ւ̃|�C���^�ł��B

Arguments:
	IN	pWaitVsyncCallback		Vsync�E�F�C�g���̃R�[���o�b�N�֐��ւ̃|�C���^���w�肵�܂��B
	IN	pCallbackArguments		callback ���Ɍďo�����֐��֓n���A�����ւ̃|�C���^���w�肵�܂��B
	
Result:
	KMSTATUS_SUCCESS		�o�^����

--*/

KMSTATUS KMAPI
kmSetWaitVsyncCallback(
		PKMCALLBACKFUNC pWaitVsyncCallback,
		PVOID pCallbackArguments
	);

/*++
kmSetPALEXTCallback

proto type:
	KMSTATUS
	kmSetPALEXTCallback(
			PKMCALLBACKFUNC pPalExtCallback,
			PVOID 			Reserved
		);

Description:
	kmSetDisplayMode ���Ăяo�����ۂɁA	PAL ??? EXT ���w�肵���ꍇ�A
	�c�̕\���䗦�����肷�邽�߂̒萔��Ԃ����߂̃R�[���o�b�N�֐��ł��B

		VOID pPalExtCallback(PVOID pData);

	pData �ɂ́A�V�X�e�������� KMPALEXTINFO �\���̂ւ̃|�C���^���n����܂��B
	nPALExtMode �����o�ɑ΂��ēK�؂Ȓl�������Ă��������B
	KMPALEXTINFO �\���̂� nDisplayMode�ɂ́A
	kmSetDisplayMode �̈������������Ă��܂��B

Arguments:
	IN	pFaltalErrorCallback	�񕜕s�\�ȃG���[�����������ꍇ�ɌĂяo�����R�[���o�b�N�֐��ł��B
	IN	reserved				NULL �����Ă��������B

Result:
	KMSTATUS_SUCCESS		�o�^����

--*/

KMSTATUS KMAPI
kmSetPALEXTCallback( 
		IN	PKMCALLBACKFUNC pPalExtCallback,
		IN	PVOID			pCallbackArguments
	);

/*++
kmStopDisplayFrameBuffer

proto type:
	KMSTATUS
	kmStopDisplayFrameBuffer ( VOID )

Description:
	Frame Buffer�̕\�����~���܂��B�A���ACRT�R���g���[�����\�����~�߂邾���ł��̂ŁA
	Frame Buffer�̏�Ԃ͕ω����܂���B

Arguments:
	None

Result:
	KMSTATUS_SUCCESS		����

--*/
KMSTATUS KMAPI
kmStopDisplayFrameBuffer ( VOID );

/*++
kmGetVersionInfo

proto type:
	KMSTATUS
	kmGetVersionInfo(
			PKMVERSIONINFO pVersionInfo
		);

Description:
	���C�u�����̃o�[�W���������擾���܂��B
	�o�[�W�������\���̂̓��e�ɂ��Ă͕ʓr�\���̈ꗗ���������������B

Arguments:
	OUT	pVersionInfo	���炩���ߊm�ۂ��Ă�����KMVERSIONINFO�\���̂ւ̃|�C���^�������܂��B

Result:
	KMSTATUS_SUCCESS		����

--*/

KMSTATUS KMAPI
kmGetVersionInfo(
		PKMVERSIONINFO pVersionInfo
	);

/*++
kmLoadTexture

proto type:

	KMSTATUS
	kmLoadTexture(
			PKMSURFACEDESC pSurfaceDesc,
			PKMDWORD pTexture,
			KMBOOLEAN fAutoMipMap,
			KMBOOLEAN fDither
		);

Description:
	kmCreateTextureSurface�Ŋm�ۂ����e�N�X�`����������̗̈�ɁA 
	pTexture�Ŏw�肳�ꂽ���C����������̃e�N�X�`����ǂݍ��݂܂��B

Arguments:
	OUT	pSurfaceDesc	kmCreateTextureSurface�Ŋm�ۂ����e�N�X�`���T�[�t�F�X�ł��B
	IN	pTexture		���C����������̃e�N�X�`���������|�C���^�ł��B
	IN	bAutoMipMap		�����I��MIPMAP�𐶐����邩�ǂ������w�肵�܂��B
						TRUE���w�肳�ꂽ�ꍇ�ɂ͎����I��MIPMAP�𐶐����܂��B
	IN	bDither			MIPMAP�̎����������w�肵���ꍇ�ɁA�����������Ƀf�B�U��������MIPMAP��
						�������邩�ǂ������w�肵�܂��BTRUE���w�肳�ꂽ�ꍇ�̓f�B�U�������܂��B
						���̃t���O��bAutoMipMap��TRUE���w�肳�ꂽ�Ƃ��̂ݗL���ł��B

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��
	KMSTATUS_INVALID_MIPMAPED_TEXTURE	MIPMAP�ł��Ȃ��e�N�X�`����
										MIPMAP���g�p���悤�Ƃ���

--*/
KMSTATUS KMAPI
kmLoadTexture(
		PKMSURFACEDESC pSurfaceDesc,
		PKMDWORD pTexture,
		KMBOOLEAN fAutoMipMap,
		KMBOOLEAN fDither
	);

/*++
kmLoadTextureBlock

proto type:

	KMSTATUS KMAPI
	kmLoadTextureBlock(
		PKMSURFACEDESC	pSurfaceDesc,
		PKMDWORD		pTexture,
		KMUINT32		nBlockNum,
		KMUINT32		nBlockSize
	)

Description:
	kmCreateTextureSurface�ŃA���P�[�g�����e�N�X�`����������̗̈�ɁA 
	pTexture�Ŏw�肳�ꂽ���C����������̃e�N�X�`���u���b�N��ǂݍ��݂܂��B

	�e�N�X�`���f�[�^���������̃u���b�N�ɕ������ēǂݍ��݂܂��B
	����ɂ��A���C����������ɑ傫�ȃ��[�N�G���A���m�ۂ��邱�ƂȂ��A
	�T�C�Y�̑傫�ȃe�N�X�`����ǂݍ��ނ��Ƃ��ł��܂��B

	�e�N�X�`���S�̂̃T�C�Y���u���b�N�T�C�Y�Ŋ���؂�Ȃ��Ă��A�������ǂݍ��܂�܂��B

	�ǂݍ��ރe�N�X�`���̃t�H�[�}�b�g�`���A�T�C�Y�Ȃǂ́ApSurfaceDesc
	���w���T�[�t�F�X�f�B�X�N���v�^��蔻�f���܂��B
	���ۂ̃e�N�X�`���̃t�H�[�}�b�g�`���Ȃǂ��ApSurfaceDesc���w���T�[�t�F�X�f�B�X�N���v�^
	�̓��e�ƈقȂ��Ă���ꍇ�́A�\�����s���ƂȂ�܂��B

	�Ȃ��A���̊֐���Small VQ�`���̃e�N�X�`���ɂ͑Ή����Ă��܂���B
	Small VQ�`����pSurfaceDesc���w�肵���ꍇ�ɂ́AKMSTATUS_INVALID_TEXTURE_TYPE��Ԃ��܂��B


	�܂��AARC1�ł́AVQ�AMipmap�t�H�[�}�b�g�ɂ͑Ή����Ă��܂���B

Arguments:
	IN	pSurfaceDesc	kmCreateTextureSurface/kmCreateCombinedTextureSurface��
						�A���P�[�g�����e�N�X�`���T�[�t�F�X�ł��B
	IN	pTexture		���C����������̃e�N�X�`���u���b�N�̐擪�������|�C���^�ł��B
	IN	nBlockNum		�e�N�X�`���̃u���b�N�ԍ��� 0 ���� n ( n�̓t�H�[�}�b�g/�T�C�Y�ɂ��)�Ŏw�肵�܂��B
	IN	nBlockSize		�u���b�N�̃T�C�Y�� 32�o�C�g�P�ʂŎw�肵�܂��B
						�u���b�N�T�C�Y(�o�C�g)�� 32 �Ŋ������l���w�肵�Ă��������B
						�Ȃ��A�e�N�X�`���S�̂̃T�C�Y���u���b�N�T�C�Y�Ŋ���؂��K�v�͂���܂���B

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_BLOCKNUMBER		�u���b�N�ԍ����s��
	KMSTATUS_INVALID_ADDRESS			�w�肳�ꂽ�A�h���X��擪�Ɏ��������u���b�N��
										�A���P�[�g����Ă��Ȃ�
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��

--*/

KMSTATUS KMAPI
kmLoadTextureBlock(
		PKMSURFACEDESC	pSurfaceDesc,
		PKMDWORD		pTexture,
		KMUINT32		nBlockNum,
		KMUINT32		nBlockSize
	);

/*++
kmLoadTexturePart

proto type:

	KMSTATUS KMAPI
	kmLoadTexturePart(
			PKMSURFACEDESC	pSurfaceDesc,
			PKMDWORD		pTexture,
			KMUINT32		nOffset,
			KMUINT32		nSize
		)

Description:
	kmCreateTextureSurface�ŃA���P�[�g�����e�N�X�`����������̗̈�ɁA 
	pTexture�Ŏw�肳�ꂽ���C����������̃e�N�X�`��(����)��ǂݍ��݂܂��B

	�e�N�X�`���f�[�^���������̕����ɕ������ēǂݍ��݂܂��B
	����ɂ��A���C����������ɑ傫�ȃ��[�N�G���A���m�ۂ��邱�ƂȂ��A
	�T�C�Y�̑傫�ȃe�N�X�`����ǂݍ��ނ��Ƃ��ł��܂��B

	kmLoadTextureBlock�ƈقȂ�A��̃e�N�X�`�����A�u�T�C�Y�̈قȂ�v
	�����̕����ɕ����ēǂݍ��ނ��Ƃ��ł��܂��B�������A���܂łɓǂݍ���
	�e�N�X�`���̃T�C�Y(�擪����̃I�t�Z�b�g��)�́A���[�U���ŊǗ�����
	�K�v������܂��B

	�ǂݍ��ރe�N�X�`���̃t�H�[�}�b�g�`���A�T�C�Y�Ȃǂ́ApSurfaceDesc
	�Ŏw�肳���T�[�t�F�X�f�B�X�N���v�^��蔻�f����܂��B
	���ۂ̃e�N�X�`���̃t�H�[�}�b�g�`���Ȃǂ��ApSurfaceDesc�Ŏw�肳���
	�T�[�t�F�X�f�B�X�N���v�^�̓��e�ƈقȂ��Ă���ꍇ�́A�\�����s���ƂȂ�܂��B

	�Ȃ��A���̊֐���Small VQ�`���̃e�N�X�`���ɂ͑Ή����Ă��܂���B
	Small VQ�`����pSurfaceDesc���w�肵���ꍇ�ɂ́AKMSTATUS_INVALID_TEXTURE_TYPE��Ԃ��܂��B


	�܂��AARC1�ł́AVQ�AMipmap�t�H�[�}�b�g�ɂ͑Ή����Ă��܂���B

Arguments:
	IN	pSurfaceDesc	kmCreateTextureSurface/kmCreateCombinedTextureSurface��
						�A���P�[�g�����e�N�X�`���T�[�t�F�X�ł��B
	IN	pTexture		���C����������̃e�N�X�`���u���b�N�̐擪�������|�C���^�ł��B
	IN	nOffset			���łɓǂݍ��񂾃e�N�X�`���̃T�C�Y(�擪����̃I�t�Z�b�g��)��
						�o�C�g�P�ʂŎw�肵�܂��B����́A����ǂݍ��ރe�N�X�`���f�[�^��
						�]�������A�e�N�X�`���̈�̐擪�A�h���X�ƂȂ�܂��B
	IN	nSize			����ǂݍ��ޕ����̃T�C�Y���o�C�g�P�ʂŎw�肵�܂��B
						�Ȃ��AnSize���A�e�N�X�`���̎c��T�C�Y ( = �e�N�X�`���T�C�Y - nOffset)
						���傫���ꍇ�́A�c��T�C�Y�݂̂𐳂����ǂݍ���Ő���I�����܂��B

Usage:
	nOffset = 0;
	nSize   = ***;
	pTexture�Ƀe�N�X�`���f�[�^�̍ŏ���nSize�o�C�g�����[�h;
	while(KMSTATUS_SUCCESS == kmLoadTexturePart(...);
		nOffset = nOffset + nSize;
		nSize   = ????;
		pTexture�Ɏ���nSize�o�C�g�����[�h;
	}

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_ADDRESS			nOffset���e�N�X�`���T�C�Y���z���Ă���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��

--*/

KMSTATUS KMAPI
kmLoadTexturePart(
	IN	PKMSURFACEDESC	pSurfaceDesc,
	IN	PKMDWORD		pTexture,
	IN	KMUINT32		nOffset,
	IN	KMUINT32		nSize
	);


/*++
kmLoadRectangleTexturePart

proto type:

	KMSTATUS KMAPI
	kmLoadRectangleTexturePart(
			PKMSURFACEDESC	pSurfaceDesc,
			PKMDWORD		pTexture,
			KMUINT32		width,
			KMUINT32		height,
			KMUINT32		dst_X,
			KMUINT32		dst_Y,
			KMUINT32		src_X,
			KMUINT32		src_Y,
			KMUINT32		src_U
			)

Description:
	kmCreateTextureSurface�ŃA���P�[�g����Rectangle/Stride�`��
	�e�N�X�`����������̋�`�̈�ɁApTexture�Ŏw�肳�ꂽ���C��
	��������̃e�N�X�`���̋�`�̈�(����)���������݂܂��B

	Rectangle/Stride�`���e�N�X�`���̈ꕔ�����������邱�Ƃ��ł��܂��B

	�]����̋�`�̈�́A( dst_X, dst_Y )-( dst_X + width, dst_Y + height )�ł��B
	�]�����̋�`�̈�́A( src_X, src_Y )-( src_X + width, src_Y + height )�ł��B
	src_U���[���ł������ꍇ�́A�]�����e�N�X�`���̃T�C�Y�͋�`�̈�̕���
	����(width,height)�Ɠ��������̂Ƃ݂Ȃ��܂��B

	�Ȃ��A���̊֐���Rectangle/Stride�`���e�N�X�`���ɂ̂ݑΉ����Ă��܂��B
	�����ȊO��pSurfaceDesc���w�肵���ꍇ�ɂ́A
	KMSTATUS_INVALID_TEXTURE_TYPE��Ԃ��܂��B

	��`�̈�́A�]����E�]�����e�N�X�`���̗̈���Ɋ��S�Ɋ܂܂�Ă��Ȃ�
	��΂Ȃ�܂���B
	�����łȂ��ꍇ�ɂ́A�]����e�N�X�`�����܂߁A���̃e�N�X�`���̃f�[�^
	���j�󂳂��ꍇ������܂��B
	�_�Ђł́A���̃`�F�b�N�͍s���܂���B

Arguments:
	IN	pSurfaceDesc	kmCreateTextureSurface/kmCreateCombinedTextureSurface��
						�A���P�[�g����Rectangle/Stride�`���̃e�N�X�`���T�[�t�F�X�ł��B
						(�]����e�N�X�`��)
	IN	pTexture		���C����������̃e�N�X�`���f�[�^�̐擪�������|�C���^�ł��B
						(�]�����e�N�X�`��)
	IN	width,height	�]�������`�̈�̕��ƍ������e�N�Z�����Ŏw�肵�܂��B
	IN	dst_X,dst_Y		�]����e�N�X�`���ɉ������`�̈��X,Y���W�ł��B
						�]����e�N�X�`���̍���(�擪)�e�N�Z�������
						���΃e�N�Z�����Ŏw�肵�܂��B
	IN	src_X,src_Y		�]�����e�N�X�`���ɉ������`�̈��X,Y���W�ł��B
						�]�����e�N�X�`���̍���(�擪)�e�N�Z�������
						���΃e�N�Z�����Ŏw�肵�܂��B
	IN	src_U			�]�����e�N�X�`���̕����e�N�Z�����Ŏw�肵�܂��B
						���ꂪ�[���ł������ꍇ�́A�]�����e�N�X�`���̃T�C�Y��
						��`�̈�̕��ƍ���(width,height)�Ɠ��������̂Ƃ݂Ȃ��܂��B
						���̂Ƃ��́Asrc_X,src_Y�̒l�͖�������܂��B(0�Ƃ݂Ȃ���܂�)

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��

--*/

KMSTATUS KMAPI
kmLoadRectangleTexturePart(
		PKMSURFACEDESC	pSurfaceDesc,
		PKMDWORD		pTexture,
		KMUINT32		width,
		KMUINT32		height,
		KMUINT32		dst_X,
		KMUINT32		dst_Y,
		KMUINT32		src_X,
		KMUINT32		src_Y,
		KMUINT32		src_U
	);


/*++
kmFreeTexture

proto type:
	KMSTATUS
	kmFreeTexture(
			PKMSURFACEDESC pSurfaceDesc
		);

Description:
	�w�肵���e�N�X�`���T�[�t�F�X��������܂��B

Arguments:
	I/O	pSurfaceDesc	kmCreateTextureSurface�Ŋm�ۂ����e�N�X�`���T�[�t�F�X�ł��B

Result:
	KMSTATUS_SUCCESS				�������
	KMSTATUS_INVALID_PARAMETER		������s�A�e�N�X�`���̎w�肪�s��

--*/

KMSTATUS KMAPI
kmFreeTexture(
		PKMSURFACEDESC pSurfaceDesc
	);


/*++
kmGetFreeTextureMem

proto type:
	KMSTATUS
	kmGetFreeTextureMem(
		PKMUINT32 pSizeOfTexture,
		PKMUINT32 pMaxBlockSizeOfTexture
		);

Description:
	�e�N�X�`���������̎c�e�ʂ�Ԃ��܂��B

Arguments:
	OUT	pSizeOfTexture
			�e�N�X�`���������̎c�e�ʂ�Ԃ�KMDWORD�̈�ւ̃|�C���^�ł��B
	OUT	pMaxBlockSizeOfTexture
			�e�N�X�`���������̋󂫃u���b�N�̍ő�e�ʂ�Ԃ�KMDWORD�̈�ւ̃|�C���^�ł��B
Result:
	KMSTATUS_SUCCESS		����

--*/

KMSTATUS KMAPI
kmGetFreeTextureMem(
		PKMUINT32 pSizeOfTexture,
		PKMUINT32 pMaxBlockSizeOfTexture
	);

/*++
kmReLoadMipmap

proto type:
	KMSTATUS
	kmReLoadMipmap(
			PKMSURFACEDESC 	pSurfaceDesc,
			PKMVOID	 		pTexture,
			KMINT32	 		nMipmapCount
		);

Description:
	kmCreateTextureSurface�Ŋm�ۂ����e�N�X�`����������̗̈�ɁA 
	pTexture�Ŏw�肳�ꂽ���C����������̃~�b�v�}�b�v�e�N�X�`�����㏑���ǂݍ��݂��܂��B

Arguments:
	I/O	pSurfaceDesc	kmCreateTextureSurface�Ŋm�ۂ����e�N�X�`���T�[�t�F�X�ł��B
						��Reload��ł���

	IN	pTexture		���C����������̃~�b�v�}�b�v�e�N�X�`���������|�C���^�ł��B
						��Reload���ł���

	IN	nMipmapCount	�ǂݍ��ރ~�b�v�}�b�v�e�N�X�`���̃��x�����w�肵�܂��B
						���L�̂����ꂩ���w�肷�邱�Ƃ��ł��܂��B

						nMipmapCount			Texture Size
						KM_MAPSIZE_1x1				   1x1
						KM_MAPSIZE_2x2				   2x2
						KM_MAPSIZE_4x4				   4x4
						KM_MAPSIZE_8x8				   8x8
						KM_MAPSIZE_16x16			  16x16
						KM_MAPSIZE_32x32			  32x32
						KM_MAPSIZE_64x64			  64x64
						KM_MAPSIZE_128x128			 128x128
						KM_MAPSIZE_256x256			 256x256
						KM_MAPSIZE_512x512			 512x512
						KM_MAPSIZE_1024x1024		1024x1024
	

Result:
	KMSTATUS_SUCCESS			����
	KMSTATUS_INVALID_PARAMETER	�p�����[�^���s��
	KMSTATUS_INVALID_TEXTURE	�����ȃe�N�X�`�����w�肵��

--*/
KMSTATUS KMAPI
kmReLoadMipmap(
		PKMSURFACEDESC 	pSurfaceDesc,
		PKMVOID		 	pTexture,
		KMINT32	 		nMipmapCount
	);

/*++
kmGetTexture

proto type:

	KMSTATUS
	kmGetTexture(
		PKMDWORD		pTexture,
		PKMSURFACEDESC	pSurfaceDesc
		);

Description:
	pSurfaceDesc�Ŏw�肵���e�N�X�`����������̃e�N�X�`�����A 
	pTexture�Ŏw�肳�ꂽ���C����������ɓǂݏo���܂��B
	�o�͂ɂ́AKAMUI�e�N�X�`���t�H�[�}�b�g�ɏ]����16�o�C�g�̃w�b�_���t������܂��B

Arguments:
	OUT	pTexture		���C����������̃e�N�X�`����ۑ�����̈�������|�C���^�ł��B
	IN	pSurfaceDesc	�e�N�X�`�����ۑ�����Ă���e�N�X�`���T�[�t�F�X�ł��B

Result:
	KMSTATUS_SUCCESS					�ǂݏo������
	KMSTATUS_INVALID_ADDRESS			�w�肳�ꂽ�e�N�X�`���T�[�t�F�X��
										�m�ۂ���Ă��Ȃ�

--*/

KMSTATUS KMAPI
kmGetTexture(
		PKMDWORD		pTexture,
		PKMSURFACEDESC	pSurfaceDesc
	);


/*++
kmGarbageCollectTexture

proto type:
	KMSTATUS
	kmGarbageCollectTexture(VOID);

Description:
	 Frame Buffer �������̃K�x�[�W�R���N�V�������s���܂��B

Arguments:

Result:
	KMSTATUS_SUCCESS					�K�x�[�W�R���N�V��������
	KMSTATUS_NOT_ENOUGH_MEMORY			�������e�ʂ�����Ȃ�

--*/

KMSTATUS KMAPI
kmGarbageCollectTexture(KMVOID);



/*++
kmSetFramebufferTexture

proto type:
	KMSTATUS 
	kmSetFramebufferTexture(
		IN	OUT	PKMSURFACEDESC	pSurfaceDesc
	);

Description:
	 Frame Buffer �̏����A�e�N�X�`���p��SurfaceDesc�ɓǂݏo���܂��B
	���O�� Frame Buffer �̓��e���AStride-Rectanglar-Texture�Ƃ���SurfaceDesc�ɐݒ肳��܂��B
	����SurfaceDesc���g�p���ăe�N�X�`���}�b�v���邱�Ƃɂ��A���O�� Frame Buffer 
	�̓��e���e�N�X�`���Ƃ��Ďg�p���邱�Ƃ��ł��܂��B
	�e�N�X�`���Ƃ��Ďg�p���悤�Ƃ��� Frame Buffer �́A���L�̐ݒ�ł���K�v������܂��B

	�EkmSetDisplayMode�ŁABitDepth �����L�̂��Âꂩ���w�肳��Ă��邱�ƁB
		KM_DSPBPP_ARGB1555
		KM_DSPBPP_RGB565

Arguments:
	IN	OUT	pSurfaceDesc	KMSURFACEDESC �\���̗̂̈�������|�C���^�ł��B
							 Frame Buffer �̏�񂪕Ԃ���܂��B

Result:
		KMSTATUS_SUCCESS				 Frame Buffer �̏��ǂݏo������
		KMSTATUS_INVALID_TEXTURE_TYPE	���݂� Frame Buffer �̐ݒ�̓e�N�X�`���Ƃ��Ďg�p�ł��Ȃ�

Sample:
	kmSetStrideWidth(nScreenWidth);					// Set screen width
	....(Setup vertex)....
	kmRender();										// Generate previous Frame-Buffer
	kmSetFramebufferTexture(pSurfaceDesc);			// Get Framebuffer information
	VertexContext.pTextureSurfaceDesc	= &pSurfaceDesc;
	kmProcessVertexRenderState(&VertexContext);		// Use Framebuffer as texture
	kmSetVertexRenderState(&VertexContext);			// Set new vertex-context
	....(Setup vertex)....
	kmRender();										// Render!!

--*/

KMSTATUS KMAPI
kmSetFramebufferTexture(
		PKMSURFACEDESC	pSurfaceDesc
	);


/*++
kmLoadVQCodebook

proto type:

	KMSTATUS
	kmLoadVQCodebook(
			PKMSURFACEDESC pSurfaceDesc,
			PKMDWORD pTexture
		);

Description:
	pSurfaceDesc�Ŏw�肳�ꂽVQ�e�N�X�`���T�[�t�F�X�ɁApTexture�Ŏw�肳�ꂽ
	���C�����������VQ�e�N�X�`���̃R�[�h�u�b�N�����݂̂�ǂݍ��݂܂��B
	���[�h�ς݂�VQ�e�N�X�`���́A�R�[�h�u�b�N(800h�o�C�g)�݂̂�����������
	�J���[�p���b�g���ʂ��o�������Ƃ��Ɏg�p���܂��B

Arguments:
	OUT	pSurfaceDesc	kmCreateTextureSurface�Ŋm�ۂ����e�N�X�`���T�[�t�F�X�ł��B
						���̃T�[�t�F�X�̃J�e�S���́AKM_TEXTURE_VQ�܂���KM_TEXTURE_VQ_MM
						�̂ǂ��炩�łȂ���΂Ȃ�܂���B
	IN	pTexture		���C����������̃e�N�X�`��(�R�[�h�u�b�N)�������|�C���^�ł��B
						����͊��S��VQ�e�N�X�`���ł���K�v�͂���܂��񂪁A
						���Ȃ��Ƃ��擪��800h�o�C�g�̃R�[�h�u�b�N���܂�ł���K�v������܂��B

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��

--*/

KMSTATUS KMAPI
kmLoadVQCodebook(
		PKMSURFACEDESC	pSurfaceDesc,
		PKMDWORD		pTexture
	);


/*++
kmCreateContiguousTextureSurface

proto type:
	KMSTATUS 
	kmCreateContiguousTextureSurface(
			PKMSURFACEDESC	pSurfaceDesc,
			KMINT32			nTexture,
			KMINT32			nWidth, 
			KMINT32			nHeight, 
			KMTEXTURETYPE	nTextureType
		);

Description:
	 Frame Buffer �̘A�������A�h���X�̈�ɁA�����ɕ����̃e�N�X�`���pSurface���m�ۂ��܂��B
	����́ATile Accelerator��YUV�R���o�[�^���g�p���āA�A�����ĕ�����YUV422�`���̃e�N�X�`��
	��ǂݍ��ނƂ��Ɏg�p���܂��B(kmLoadYUVTexture�����Q�Ƃ�������)
	YUV422�ȊO�̃e�N�X�`���pSurface�̊m�ۂɂ��g�p���邱�Ƃ��ł��܂��B

	�Ȃ��AARC1�ł́A����API��VQ,VQ-mipmap,Twiddled-mipmap�̃T�[�t�F�X���m�ۂ���
	���Ƃ͂ł��܂���B

Arguments:
	IN	OUT	pSurfaceDesc		KMSURFACEDESC �\���̂̔z��ւ̃|�C���^�ł��B
								�m�ۂ��� Texture Surface �̏�񂪕Ԃ���܂��B
								KMSTATUS ��KMSTATUS_NOT_ENOUGH_MEMORY���Ԃ��ꂽ�ꍇ�ɂ͕s��ƂȂ�܂��B

	IN	nTexture				�A�����Ċm�ۂ��� Texture Surface �̐����w�肵�܂��B

	IN	nWidth, nHeight			�e�N�X�`���̉��T�C�Y�A�c�T�C�Y���w�肵�܂��B
								nWidth, nHeight�Ɏw�肷��l��,8, 16, 32, 64, 128, 256, 512, 1024��
								�����ꂩ�łȂ���΂Ȃ�܂���B

	IN	nTextureType			�e�N�X�`���̌`�����w�肵�܂��B
								�ȉ��̃J�e�S���R�[�h�A�s�N�Z���t�H�[�}�b�g�R�[�h����
								����I�яo���A�_���a(or)���ė^���܂�

								-�J�e�S���R�[�h
									KM_TEXTURE_TWIDDLED				// Twiddled�t�H�[�}�b�g
									KM_TEXTURE_TWIDDLED_MM			// Twiddled�t�H�[�}�b�gMipmap����(ARC1�ł͎w��ł��܂���)
									KM_TEXTURE_TWIDDLED_RECTANGLE	// Twiddled-Rectangle			(ARC1�ł͎g�p�ł��܂���)
									KM_TEXTURE_VQ					// VQ���k�t�H�[�}�b�g			(ARC1�ł͎w��ł��܂���)
									KM_TEXTURE_VQ_MM				// VQ���k�t�H�[�}�b�gMipmap����	(ARC1�ł͎w��ł��܂���)
									KM_TEXTURE_PALETTIZE4			// 4bpp�p���b�g�`��				(ARC1�ł͎g�p�ł��܂���)
									KM_TEXTURE_PALETTIZE4_MM		// 4bpp�p���b�g�`��Mipmap����	(ARC1�ł͎g�p�ł��܂���)
									KM_TEXTURE_PALETTIZE8			// 8bpp�p���b�g�`��				(ARC1�ł͎g�p�ł��܂���)
									KM_TEXTURE_PALETTIZE8_MM		// 8bpp�p���b�g�`��Mipmap����	(ARC1�ł͎g�p�ł��܂���)
									KM_TEXTURE_RECTANGLE			// ��`
									KM_TEXTURE_STRIDE				// ��`(�X�g���C�h�w��L��)

								- �s�N�Z���t�H�[�}�b�g�R�[�h
									KM_TEXTURE_ARGB1555
									KM_TEXTURE_RGB565
									KM_TEXTURE_ARGB4444
									KM_TEXTURE_YUV422				//	(ARC1�ł͎g�p�ł��܂���)
									KM_TEXTURE_BUMP					//	(ARC1�ł͎g�p�ł��܂���)

Result:
		KMSTATUS_SUCCESS					�e�N�X�`���������m�ې���
		KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��
		KMSTATUS_NOT_ENOUGH_MEMORY			�������e�ʂ�����Ȃ�

--*/

KMSTATUS KMAPI
kmCreateContiguousTextureSurface(
	IN	OUT	PKMSURFACEDESC	pSurfaceDesc,
	IN		KMINT32			nTexture,
	IN		KMINT32			nWidth,
	IN		KMINT32			nHeight,
	IN		KMTEXTURETYPE	nTextureType
	);


/*++
kmLoadYUVTexture

proto type:

	KMSTATUS
	kmLoadYUVTexture(
		PPKMSURFACEDESC	ppSurfaceDesc,
		PKMDWORD		pTexture,
		KMINT32			nWidth,
		KMINT32			nHeight,
		KMINT32			nFormat,
		KMBOOLEAN		bWaitEndOfDMA
		);

Description:
	kmCreateTextureSurface/kmCreateCombinedTextureSurface/kmCreateContiguousTextureSurface
	�Ŋm�ۂ����e�N�X�`����������̗̈�ɁApTexture�Ŏw�肳�ꂽ���C�����������
	YUV420-data/YUV422-data���ANon-Twiddled YUV422�e�N�X�`���ɕϊ����ēǂݍ��݂܂��B
	CLX1�� Tile Accelerator �ɓ�������Ă��� YUV-data converter ���g�p���āA�ϊ����Ȃ���
	�ǂݍ��݂܂��B

	YUV-data converter �̏o�͂� Non-Twiddled �ł��邽�߁A����API�Ŏw�肷��ǂݍ��ݐ��
	Texture Surface �̌`���́A�ȉ��̂����ꂩ�łȂ���΂Ȃ�܂���B
		KM_TEXTURE_RECTANGLE | KM_TEXTURE_YUV422	// ��`
		KM_TEXTURE_STRIDE    | KM_TEXTURE_YUV422	// ��`(�X�g���C�h�w��L��)

	������YUV-data���A��x�ɘA�����ēǂݍ��ޏꍇ(nTexture > 1 �̎�)�́A�X�̃e�N�X�`����
	�T�C�Y��16x16�e�N�Z���łȂ���΂Ȃ�܂���B����API�Ŏw�肷��ǂݍ��ݐ��Texture Surface
	�̃T�C�Y�w��ɂ����ӂ��������B
	�܂��A���̏ꍇ�́A�ǂݍ��ݐ��Texture Surface�� Frame Buffer ��ŘA�������A�h���X��
	�m�ۂ���Ă��邱�Ƃ��K�v�ł��B"kmCreateContiguousTextureSurface" API���g�p����
	�m�ۂ���Texture Surface���w�肵�Ă��������B

Arguments:
	IN	ppSurfaceDesc	�A���P�[�g�ς݂̃e�N�X�`���T�[�t�F�X������KMSURFACEDESC �\���̂ւ�
						�|�C���^�z��̃|�C���^�ł��B
	IN	pTexture		���C�����������YUV420-data/YUV422-data�������|�C���^�ł��B
	IN	nWidth,
	IN	nHeight,
						�A�����ēǂݍ��� Texture �}�N���u���b�N�̐����c�Ɖ��̐��Ŏw�肵�܂��B
						�w��ł���l�́A���ꂼ�� 1 ���� 64 �̂����ꂩ�ł��B
	IN	nFormat			�ǂݍ��ރf�[�^�̌`�����w�肵�܂��B�ȉ��̂����ꂩ���w�肵�܂��B
						KM_TEXTURE_YUV420		���̓f�[�^��YUV420-data�ł��邱�Ƃ������܂��B
						KM_TEXTURE_YUV422		���̓f�[�^��YUV422-data�ł��邱�Ƃ������܂��B
	IN	bWaitEndOfDMA	TRUE�̏ꍇ�AYUV�R���o�[�^�ւ̃f�[�^�]����DMA����������̂�҂��܂��B
									DMA���I������܂ŁA�{API�͏I�����܂���B
						FALSE�̏ꍇ�ADMA�̏I����҂��܂���BDMA�̏I�������m�������ꍇ��
									�R�[���o�b�N"kmSetEndOfYUVCallback"���g�p���Ă��������B

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��

--*/

KMSTATUS KMAPI
kmLoadYUVTexture(
		PKMSURFACEDESC	pSurfaceDesc,
		PKMDWORD		pTexture,
		KMINT32			nWidth,
		KMINT32			nHeight,
		KMINT32			nFormat,
		KMBOOLEAN		bWaitEndOfDMA
		);


/*++
kmChangeLatencyModel
proto type:
	KMSTATUS
	kmChangeLatencyModel(
			KMLATENCYMODEL LatencyMode,
			KMVERTEXBUFMODEL VbufModel
		);

Description:
	���݂̃��C�e���V���f����ύX���܂��B

Arguments:
 IN  LatencyMode  Latency Model���w�肵�܂�
     KM_LATENCYMODEL_3V  3V Latency Model���w�肵�܂�
     KM_LATENCYMODEL_2V  2V Latency Model���w�肵�܂�

 IN VbufModel     VertexBuffer���ǂ̂悤�Ɏg�p���邩���w�肵�܂�
	KM_VERTEXBUFMODEL_NORMAL 					3V Latency�̏ꍇ�ɂ͏�ɂ�����w�肵�Ă�������
	KM_VERTEXBUFMODEL_FLUSH_OPAQUE			  	2V Latency��Opaque�̃��X�g��Flush����ꍇ�Ɏw�肵�܂�
	KM_VERTEXBUFMODEL_FLUSH_OPAQUE_MODIFIER  	2V Latency��Opaque Modifier�̃��X�g��Flush����ꍇ�Ɏw�肵�܂�
	KM_VERTEXBUFMODEL_FLUSH_TRANS  				2V Latency��Translucent�̃��X�g��Flush����ꍇ�Ɏw�肵�܂�
	KM_VERTEXBUFMODEL_FLUSH_TRANS_MODIFIER  	2V Latency��Translucnet Modifier�̃��X�g��Flush����ꍇ�Ɏw�肵�܂�
	KM_VERTEXBUFMODEL_FLUSH_PUNCH_THROUGH 	 	2V Latency��Punch Through�̃��X�g��Flush����ꍇ�Ɏw�肵�܂�
	KM_VERTEXBUFMODEL_NOBUF_OPAQUE  			2V Latency��Opaque�̃��X�g��TA���ړ]������ꍇ�Ɏw�肵�܂�
	KM_VERTEXBUFMODEL_NOBUF_OPAQUE_MODIFIER  	2V Latency��Opaque Modifier�̃��X�g��TA���ړ]������ꍇ�Ɏw�肵�܂�
	KM_VERTEXBUFMODEL_NOBUF_TRANS  				2V Latency��Translucent�̃��X�g��TA���ړ]������ꍇ�Ɏw�肵�܂�
	KM_VERTEXBUFMODEL_NOBUF_TRANS_MODIFIER  	2V Latency��Translucnet Modifier�̃��X�g��TA���ړ]������ꍇ�Ɏw�肵�܂�
	KM_VERTEXBUFMODEL_NOBUF_PUNCH_THROUGH 	 	2V Latency��Punch Through�̃��X�g��TA���ړ]������ꍇ�Ɏw�肵�܂�

Result:

--*/
KMSTATUS KMAPI
kmChangeLatencyModel(
		KMLATENCYMODEL LatencyModel, 
		KMVERTEXBUFMODEL VbufModel
		);

/*++
kmQueryFinishFlushVertexBuffer

proto type:
	KMSTATUS
	kmQueryFinishFlushVertexBuffer(KMVOID);

Description:
	�O���kmFlushVertexBuffer()�ɂ��w��ListType��DMA�]�����I���������ǂ�����
	�`�F�b�N���܂��B�I�����Ă���ꍇ�ɂ�KMSTATUS_SUCCESS��Ԃ��܂��B
	KMSTATUS_LAST_LIST_UNDER_DMA��Ԃ����ꍇ�ɂ́A�O���Flush��DMA���ł��鎖��
	�����܂��B�O���DMA���I������܂ő҂ꍇ�ɂ́A
	while( kmQueryFinishFlushVertexBuffer() == KMSTATUS_LAST_LIST_UNDER_DMA);
	�̗l�Ɏg�p���܂��B

Arguments:
	�Ȃ�
Result:
	KMSTATUS_SUCCESS				�O���DMA�͏I�����Ă���
	KMSTATUS_LAST_LIST_UNDER_DMA	�O���DMA�͏I�����Ă��Ȃ�

--*/
KMSTATUS KMAPI
kmQueryFinishFlushVertexBuffer(KMVOID);



/*++
kmQueryFinishLastTextureDMA

proto type:
	KMSTATUS
	kmQueryFinishLastTextureDMA(KMVOID);

Description:
	�O���LoadTexture�ɂ��DMA���I���������ǂ������`�F�b�N���܂��B
	kmSetSystemConfiguration��flag��KM_CONFIGFLAG_NOWAIT_FINISH_TEXTUREDMA��
	�ꍇ�ɂ̂ݗL���ł��B����ȊO�̏ꍇ�ɂ́A���KMSTATUS_SUCCESS��Ԃ��܂��B

Arguments:
	�Ȃ�
Result:
	KMSTATUS_SUCCESS				�O���DMA�͏I�����Ă���
	KMSTATUS_NOT_FINISH_DMA			�O���DMA�͏I�����Ă��Ȃ�

--*/
KMSTATUS KMAPI
kmQueryFinishLastTextureDMA(KMVOID);



#ifdef __cplusplus
}
#endif 

#endif
