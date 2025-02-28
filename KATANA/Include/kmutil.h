/*++

  COPYRIGHT        (C) NEC        Corporation 1997

  All rights reserved by NEC Corporation. This program must be
  used solely for the purpose for which it was furnished by NEC
  Corporation. No part of this program may be reproduced or
  disclosed to others, in any form, without the prior written
  permission of NEC Corporation.
  Use of copyright notice does not evidence publication of this
  program.

  Author	:  		T.Muto(NEC Software Ltd.,)
  Module Name:		kmutil.h

  Abstract:
	KAMUI = Kamui is abstruction model that is ultimate interface for PowerVR.
	'kmutil.h' utilities functions for KAMUI.

  Environment:
	Microsoft Compiler.

  Notes:

  Revision History:

--*/

#if !defined(__kamui_utility_h)
#define __kamui_utility_h

#ifdef __cplusplus
extern "C" {
#endif 

#include "kamui.h"

/*
 * KMUPASSSTATUS is kmuXxxPassTable Status.
 */
typedef KMUINT32	KMUPASSSTATUS;

/*
 *	for kmutil target
 */
#define	KMU_TARGET_ARC1			(0x00000001)
#define	KMU_TARGET_CLX1			(0x00000002)
#define	KMU_TARGET_CLX2			(0x00000003)

/*
 *	for kmuXxxPassTable
 */
#define KMU_PASS_OK							 0L
#define KMU_PASS_ERROR_VERTEXCONTEXT		 1L
#define KMU_PASS_ERROR_VERTEXCONTEXT_PASS	 2L
#define KMU_PASS_ERROR_PARAMTYPE			 3L
#define KMU_PASS_ERROR_LISTTYPE				 4L
#define KMU_PASS_ERROR_MIPMAP_D_ADJUST		 5L
#define KMU_PASS_ERROR_FOGMODE				 6L
#define KMU_PASS_ERROR_FILTERMODE			 7L
#define KMU_PASS_ERROR_TEXTURESHADINGMODE	 8L
#define KMU_PASS_ERROR_COLORTYPE			 9L
#define KMU_PASS_ERROR_SHADINGMODE			10L
#define KMU_PASS_ERROR_USERCLIPMODE			11L
#define KMU_PASS_ERROR_TRILINEAR_SETTING	12L
#define KMU_PASS_ERROR_SPRITE_SETTING		13L
#define KMU_PASS_ERROR_BLENDINGMODE_SETTING	14L
#define KMU_PASS_ERROR_MODIFIER_SETTING		15L

#define KMU_PASS_ERROR_NOT_IMPLEMENTED	   120L

/*++
kmuSetTarget

proto type:

	KMSTATUS
	kmuSetTarget(
			IN	KMDWORD				dwTarget
		);

Description:
	�_�Ѓ��[�e�B���e�B���C�u�����̓���Target��ݒ肵�܂��B
	(�f�t�H���g�̐ݒ�́A�r���h�����Ƃ���Target�ł�)

Arguments:
	IN		dwTarget		�_�Ѓ��[�e�B���e�B���C�u�����̓���Target��ݒ肵�܂��B
							�ݒ�́A���L�̒��̂����ꂩ���w�肵�܂��B
								KMU_TARGET_ARC1			����Target�� ARC1�ɂ���
								KMU_TARGET_CLX1			����Target�� CLX1�ɂ���
								KMU_TARGET_CLX2			����Target�� CLX2�ɂ���

Result:
	KMSTATUS_SUCCESS				�ݒ萬��

--*/

KMSTATUS KMAPI
kmuSetTarget(
		IN	KMDWORD				dwTarget
	);



/*++
kmuCreateTwiddledTexture

proto type:

	KMSTATUS
	kmuCreateTwiddledTexture(
			PKMDWORD		pOutputTexture,
			PKMDWORD		pInputTexture,
			KMBOOLEAN		bAutoMipMap,
			KMBOOLEAN		bDither,
			KMINT32			USize,
			KMTEXTURETYPE	nTextureType
		);

Description:
	���C�����������KM_TEXTURE_BMP�`��(ABGR8888)�̃e�N�X�`�����A
	Twiddled / Twiddled Mipmap �`���̃e�N�X�`���ɕϊ����܂��B
	bAutoMipMap��TRUE���w�肵���ꍇ�́A�~�b�v�}�b�v�̎����������s���܂��B
	bDither��TRUE���w�肵���ꍇ�́A�f�B�U���s���܂��B
	���ӁF�~�b�v�}�b�v�A�f�B�U�̎w����s�����Ƃ���
			���̓e�N�X�`���f�[�^�̓��e�͔j�󂳂�܂��B

Arguments:
	OUT	pOutputTexture	�ϊ���̃e�N�X�`���f�[�^���������ރ��C����������̃A�h���X�ł��B
	IN	pInputTexture	KM_TEXTURE_BMP�`���̓��̓e�N�X�`���������|�C���^�ł��B
	IN	bAutoMipMap		�����I��MIPMAP�𐶐����邩�ǂ������w�肵�܂��B
						TRUE���w�肳�ꂽ�ꍇ�ɂ͎����I��MIPMAP�𐶐����܂��B
						(�o�͂�KM_TEXTURE_TWIDDLED_MM�`���ɂȂ�܂�)
						FALSE���w�肳�ꂽ�ꍇ�ɂ�MIPMAP�����͍s���܂���B
						(�o�͂�KM_TEXTURE_TWIDDLED�`���ɂȂ�܂�)
	IN	bDither			�f�B�U�������邩�ǂ������w�肵�܂��B
						TRUE���w�肳�ꂽ�ꍇ�̓f�B�U�������܂��B
	IN	USize			�e�N�X�`���̈�ӂ̃e�N�Z�������w�肵�܂��B
						���L�̒��̂����ꂩ���w�肵�܂��B
						KM_MAPSIZE_8
						KM_MAPSIZE_16
						KM_MAPSIZE_32
						KM_MAPSIZE_64
						KM_MAPSIZE_128
						KM_MAPSIZE_256
						KM_MAPSIZE_512
						KM_MAPSIZE_1024
	IN	nTextureType	�ϊ���̃e�N�X�`���̃s�N�Z���t�H�[�}�b�g���w�肵�܂��B
						���L�̒��̂����ꂩ���w�肵�܂��B
						KM_PIXELFORMAT_ARGB1555
						KM_PIXELFORMAT_RGB565
						KM_PIXELFORMAT_ARGB4444

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v�A�T�C�Y���w�肵��

--*/

KMSTATUS KMAPI
kmuCreateTwiddledTexture(
	PKMDWORD		pOutputTexture,
	PKMDWORD		pInputTexture,
	KMBOOLEAN		bAutoMipMap,
	KMBOOLEAN		bDither,
	KMINT32			USize,
	KMTEXTURETYPE	nTextureType
	);


/*++
kmuConvertFBtoBMP

proto type:

	KMSTATUS
	kmuConvertFBtoBMP(
			PKMDWORD		pOutputData,
			PKMDWORD		pInputData,
			KMINT32			nWidth,
			KMINT32			nHeight,
			KMBPPMODE		nBpp
		);

Description:
	kmGetTexture�Ń��C����������ɓǂݏo�����t���[���o�b�t�@�̓��e���A
	Windows �t���J���[BMP�`���̃s�N�Z���f�[�^�Ƃ��āA��������ɏ����o���܂��B
	�Ȃ��A���̏o�͂ɂ�Windows BMP�̃w�b�_54�o�C�g�͐�������܂���B

Arguments:
	OUT	pOutputData		�ϊ���̃s�N�Z���f�[�^���������ރ��C����������̃A�h���X�ł��B
	IN	pInputData		�t���[���o�b�t�@�̓��e�������|�C���^�ł��B
						kmGetTexture�ŁA�t���[���o�b�t�@�T�[�t�F�X�ւ̃f�B�X�N���v�^��
						�w�肵�ēǂݏo�����t���[���o�b�t�@�̃s�N�Z���f�[�^���w���Ă��Ȃ����
						�����܂���BKAMUI�e�N�X�`���f�[�^�͎w��s�\�ł��B
	IN	nWidth,nHeight	�ǂݏo�����t���[���o�b�t�@�̃T�C�Y���w�肵�܂��B
	IN	nBpp			�ǂݏo�����t���[���o�b�t�@�̃s�N�Z���t�H�[�}�b�g���w�肵�܂��B
						���L�̒��̂����ꂩ���w�肵�܂��B
							KM_DSPBPP_RGB565
							KM_DSPBPP_RGB555
							KM_DSPBPP_ARGB4444
							KM_DSPBPP_ARGB1555

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���

--*/

KMSTATUS KMAPI
kmuConvertFBtoBMP(
		PKMDWORD		pOutputData,
		PKMDWORD		pInputData,
		KMINT32			nWidth,
		KMINT32			nHeight,
		KMBPPMODE		nBpp
		);


/*++
kmuGeneratePassTable

proto type:

	KMUPASSSTATUS
	kmuGeneratePassTable(
			IN	PKMVERTEXCONTEXT	pVertexContext,
			IN	KMUINT32			nNumContext,
			OUT	PPKMVERTEXCONTEXT	ppVertexContextTable,
			OUT	PKMUINT32			pPass
		);

Description:
	�ݒ肳�ꂽ�����_�����O�w��(pVertexContext)�����ƂɁA�}���`�p�X(Trilinear)�̊ePass��
	�K�v�ȃR���e�L�X�g�𐶐����܂��B
	  pVertexContext��Trilinear��1Pass�ڂ�KMVERTEXCONTEXT����͂���ƁA���̐ݒ�l���
	�ePass�ŕK�v��KMVERTEXCONTEXT�𐶐����܂�(Opaque:2Pass,Trans:3Pass)
	  TransPolygon��Trilinear�̏ꍇ��3Pass�ڂ�BlendingMode�̐ݒ�͔C�ӂɐݒ�\�ł����A
	�{�֐����g�p�����ꍇ�ɂ́A���L�̐ݒ�ɂȂ�܂��B
	(TransPolygon���g�p�����ꍇ��3Pass��)
		SRCBlendingMode	:: KM_SRCALPHA
		DSTBlendingMode	:: KM_INVSRCALPHA
	ppVertexContextTable��NULL���w�肳�ꂽ�ꍇ��pPass�֕K�v�ȃp�X���݂̂��ԋp���܂��B

Arguments:
	IN		pVertexContext			�����_�����O�������w�肷��KMVERTEXCONTEXT�ւ̃|�C���^
									��ݒ肵�܂��B
	IN		nNumContext				��������ppVertexContextTable�̃G���g����(�p�X��)��ݒ肵�܂��B
									���ꂪ���ۂɕK�v�ȃp�X����菬�����ꍇ�́A
									KMU_PASS_ERROR_VERTEXCONTEXT_PASS���Ԃ���A
									pPass�֕K�v�ȃp�X���݂̂��Ԃ���ďI�����܂��B
	OUT		ppVertexContextTable	�������ꂽ�}���`�p�X�pKMVERTEXCONTEXT���󂯎�邽�߂́A
									KMVERTEXCONTEXT�ւ̃|�C���^�̔z��ւ̃|�C���^��ݒ肵�܂��B
									������NULL���w�肳�ꂽ�ꍇ��pPass�֕K�v�ȃp�X���݂̂�Ԃ��܂��B
	OUT		pPass					�ݒ肳�ꂽ�����_�����O�w��ŕK�v�ƂȂ�}���`�p�X����Ԃ��܂��B

Result:
	KMU_PASS_OK							�ݒ萬��
	KMU_PASS_ERROR_NOT_IMPLEMENTED		���݂̃V�X�e���ł́A�{�֐��͑Ή����Ă܂���
	KMU_PASS_ERROR_VERTEXCONTEXT		pVertexContext���s��(NULL)�ł�
	KMU_PASS_ERROR_VERTEXCONTEXT_PASS	�w�肵���p�X��(nNumContext)�ł͕s�����Ă��܂�
--*/

KMUPASSSTATUS KMAPI
kmuGeneratePassTable(
		IN	PKMVERTEXCONTEXT	pVertexContext,
		IN	KMUINT32			nNumContext,
		OUT	PPKMVERTEXCONTEXT	ppVertexContextTable,
		OUT	PKMUINT32			pPass
	);


/*++
kmuCheckPassTable

proto type:

	KMUPASSSTATUS
	kmuCheckPassTable(
			IN	PPKMVERTEXCONTEXT	ppVertexContextTable,
			IN	KMUINT32			nNumContext,
			OUT	PKMUINT32			pPass
		);

Description:
	�w�肳�ꂽKMVERTEXCONTEXT�e�[�u���̊e�R���e�L�X�g�̓��e�����������ۂ����`�F�b�N���܂��B

Arguments:
	IN		ppVertexContextTable	��������KMVERTEXCONTEXT�ւ̃|�C���^�̔z��ւ̃|�C���^��ݒ肵�܂��B
	IN		nNumContext				��������ppVertexContextTable�̃G���g������ݒ肵�܂��B
	OUT		pPass					�G���[�����������ꍇ�ɂ́A�Ԉ���Ă���KMVERTEXCONTENT��
									�G���g���ԍ����Z�b�g���܂��B

Result:
	KMU_PASS_OK								�ݒ萬��
	KMU_PASS_ERROR_VERTEXCONTEXT			KMVERTEXCONTEXT���s��(NULL)�ł�
	KMU_PASS_ERROR_VERTEXCONTEXT_PASS		nNumContext���s��(1����)�ł�
	KMU_PASS_ERROR_PARAMTYPE				KMVERTEXCONTEXT�� ParamType���s���ł�
	KMU_PASS_ERROR_LISTTYPE					KMVERTEXCONTEXT�� ListType���s���ł�
	KMU_PASS_ERROR_MIPMAP_D_ADJUST			KMVERTEXCONTEXT�� MipMapAdjust���s���ł�
	KMU_PASS_ERROR_FOGMODE					KMVERTEXCONTEXT�� FogMode���s���ł�
	KMU_PASS_ERROR_FILTERMODE				KMVERTEXCONTEXT�� FilterMode���s���ł�
	KMU_PASS_ERROR_TEXTURESHADINGMODE		KMVERTEXCONTEXT�� TextureShadingMode���s���ł�
	KMU_PASS_ERROR_COLORTYPE				KMVERTEXCONTEXT�� ColorType���s���ł�
	KMU_PASS_ERROR_SHADINGMODE				KMVERTEXCONTEXT�� ShadingMode���s���ł�
	KMU_PASS_ERROR_USERCLIPMODE				KMVERTEXCONTEXT�� UserClipMode���s���ł�
	KMU_PASS_ERROR_TRILINEAR_SETTING		Trilinear�ݒ�̑g�ݍ��킹���s���ł�
											 KMVERTEXCONTEXT�� ListType/ShadingMode/FilterMode
											SRCBlendingMode/DSTBlendingMode/bSRCSel/bSRCSel
											�̂����ꂩ���ATrilinear�Ŏg�p�ł��Ȃ��ݒ�ł��B
	KMU_PASS_ERROR_SPRITE_SETTING			Sprite�ݒ�̑g�ݍ��킹���s���ł�
											 KMVERTEXCONTEXT�� ShadingMode/ColorType/UVFormat
											�̂����ꂩ���ASprite�Ŏg�p�ł��Ȃ��ݒ�ł��B
	KMU_PASS_ERROR_BLENDINGMODE_SETTING		BlendingMode�ݒ�̑g�ݍ��킹���s���ł�
											 OpaquePolygon�g�p��(ListType:KM_OPAQUE_POLYGON)��
											KMVERTEXCONTEXT�� SRCBlendingMode/DSTBlendingMode��
											�ݒ�s�̑g�ݍ��킹���w�肳�ꂽ�ꍇ�ł�
											(SRCBlendingMode:KM_ONE , DSTBlendingMode:KM_ZERO�ȊO)
	KMU_PASS_ERROR_MODIFIER_SETTING			Modifier�ݒ�̑g�ݍ��킹���s���ł�
											 Modifier�g�p��(ParamType:KM_MODIFIERVOLUME)��
											KMVERTEXCONTEXT�� ModifierInstruction���s���ȏꍇ�ł��B

--*/

KMUPASSSTATUS KMAPI
kmuCheckPassTable(
		IN	PPKMVERTEXCONTEXT	ppVertexContextTable,
		IN	KMUINT32			nNumContext,
		OUT	PKMUINT32			pPass
	);



#ifdef __cplusplus
}
#endif 

#endif
