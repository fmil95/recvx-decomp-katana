/*++

  COPYRIGHT        (C) NEC        Corporation 1997 - 1999

  All rights reserved by NEC Corporation. This program must be
  used solely for the purpose for which it was furnished by NEC
  Corporation. No part of this program may be reproduced or
  disclosed to others, in any form, without the prior written
  permission of NEC Corporation.
  Use of copyright notice does not evidence publication of this
  program.

  Author	:  		T.Muto(NEC Software Ltd.,)
  Module Name:      km2util.h

  Abstract:
	KAMUI = Kamui is abstruction model that is ultimate interface for PowerVR.
    'km2util.h' utilities functions for KAMUI.

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

#include "kamui2.h"

/*
 * KMUPASSSTATUS is kmuXxxPassTable Status.
 */
typedef KMUINT32	KMUPASSSTATUS;

/*
 *  for km2util target
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

/*
 * for kmuCalculateKamuiWorkareaSize
 */
typedef struct tagKMWORKAREASIZE
{
	/* Inputs by user */
	KMDWORD		dwNumberOfFameBuffes;		/* Number of Frame buffers */
	KMDWORD		dwNumberOfNativeBuffers;	/* Number of Native buffer */
	KMDWORD		dwNumberOfTextures;			/* Number of Textures (No small VQ) */
	KMDWORD		dwNumberOf8x8SmallVQ;		/* Number of 8x8 small VQ texture */
	KMDWORD		dwNumberOf8x8SmallVQmm;		/* Number of 8x8 small VQ mipmap texture */
	KMDWORD		dwNumberOf16x16SmallVQ;		/* Number of 16x16 small VQ texture */
	KMDWORD		dwNumberOf16x16SmallVQmm;	/* Number of 16x16 small VQ mipmap texture */
	KMDWORD		dwNumberOf32x32SmallVQ;		/* Number of 32x32 small VQ texture */
	KMDWORD		dwNumberOf32x32SmallVQmm;	/* Number of 32x32 small VQ mipmap texture */
	KMDWORD		dwNumberOf64x64SmallVQ;		/* Number of 64x64 small VQ texture */
	KMDWORD		dwNumberOf64x64SmallVQmm;	/* Number of 64x64 small VQ mipmap texture */

	/* Outputs for SystemConfigStruct */
	KMDWORD		dwTextureStructNum;			/* Number of texture structure */
	KMDWORD		dwSmallVQStructNum;			/* Number of small VQ texture structure */
	KMDWORD		dwKamuiWorkareaSize;		/* Size of Kamui work area */
} KMWORKAREASIZE, *PKMWORKAREASIZE;


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
	OUT	PKMDWORD		pOutputTexture,
	IN	PKMDWORD		pInputTexture,
	IN	KMBOOLEAN		bAutoMipMap,
	IN	KMBOOLEAN		bDither,
	IN	KMINT32			USize,
	IN	KMTEXTURETYPE	nTextureType
	);


/*++
kmuCreateTwiddledTextureEx

proto type:

	KMSTATUS
	kmuCreateTwiddledTextureEx(
		OUT	PKMDWORD		pOutputTexture,
		IN	PKMDWORD		pInputTexture,
		IN	KMBOOLEAN		bAutoMipMap,
		IN	KMBOOLEAN		bDither,
		IN	KMINT32			USize,
		IN	KMINT32			VSize,
		IN	KMTEXTURETYPE	nTextureType,
		IN	PKMDWORD		pWorkarea
		);

Description:
	���C�����������KM_TEXTURE_BMP�`��(ABGR8888)�̃e�N�X�`�����A
	Twiddled / Twiddled Mipmap �`���̃e�N�X�`���ɕϊ����܂��B
	bAutoMipMap��TRUE���w�肵���ꍇ�́A�~�b�v�}�b�v�̎����������s���܂��B
	bDither��TRUE���w�肵���ꍇ�́A�f�B�U���s���܂��B
	USize��VSize�ɈقȂ�l���w�肵���ꍇ�ɂ́ATwiddledRectangle�`��
	�̃e�N�X�`���𐶐����܂��B
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
	IN	USize, VSize	�e�N�X�`���̈�ӂ̃e�N�Z�������w�肵�܂��B
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
	IN	pWorkarea		���̓f�[�^�Ɠ����T�C�Y�̃��[�N�G���A���������A
						���̐擪�A�h���X���w�肵�܂��B
						�����̃e�N�X�`����Twiddled-Rectangle�`���ɕϊ�����ꍇ�ɕK�v�ł��B
						���̑��̏ꍇ�ɂ̓��[�N�G���A�͕K�v����܂���B
						���̏ꍇ�ɂ�NULL���w�肵�Ă��������B

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v�A�T�C�Y���w�肵��

--*/

KMSTATUS KMAPI
kmuCreateTwiddledTextureEx(
	OUT	PKMDWORD		pOutputTexture,
	IN	PKMDWORD		pInputTexture,
	IN	KMBOOLEAN		bAutoMipMap,
	IN	KMBOOLEAN		bDither,
	IN	KMINT32			USize,
	IN	KMINT32			VSize,
	IN	KMTEXTURETYPE	nTextureType,
	IN	PKMDWORD		pWorkarea
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
kmuCalculateKamuiWorkareaSize

proto type:

	KMSTATUS
	kmuCalculateKamuiWorkareaSize(
			IN OUT PKMWORKAREASIZE	pWorkareaSize
		);

Description:
	KMWORKAREASIZE�\���̂Ɏw�肳�ꂽ�e��p�����[�^���A
	SystemConfigStruct �� dwTextureStructNum, dwSmallVQStructNum �����o
	�̓��e�A�y�� pAddress �����o�Ɏw�肷�郏�[�N�G���A�̈�̃T�C�Y
	�����߂܂��B

Arguments:
	IN OUT PKMWORKAREASIZE	pWorkareaSize
	���̓p�����[�^�y�ь��ʂ��ۑ������\���̂ł��B

	dwNumberOfFameBuffes
	�t���[���o�b�t�@�̐����w�肵�܂��B�Ⴆ�΁A�_�u���o�b�t�@�̏ꍇ�͂Q���w�肵�܂��B
	dwNumberOfNativeBuffers
	�l�C�e�B�u�R�}���h�o�b�t�@�̐����w�肵�܂��B�Ⴆ�΁A�_�u���o�b�t�@�̏ꍇ�͂Q���w�肵�܂��B
	KMDWORD		dwNumberOfTextures
	��x�Ɏg�p����Asmall VQ�`���ȊO�̃e�N�X�`���̑������w�肵�܂��B
	KMDWORD		dwNumberOf8x8SmallVQ
	��x�Ɏg�p����A8x8 small VQ�`���̃e�N�X�`���̑������w�肵�܂��B
	KMDWORD		dwNumberOf8x8SmallVQmm
	��x�Ɏg�p����A8x8 small VQ mipmap �`���̃e�N�X�`���̑������w�肵�܂��B
	KMDWORD		dwNumberOf16x16SmallVQ
	��x�Ɏg�p����A16x16 small VQ�`���̃e�N�X�`���̑������w�肵�܂��B
	KMDWORD		dwNumberOf16x16SmallVQmm
	��x�Ɏg�p����A16x16 small VQ mipmap �`���̃e�N�X�`���̑������w�肵�܂��B
	KMDWORD		dwNumberOf32x32SmallVQ
	��x�Ɏg�p����A32x32 small VQ�`���̃e�N�X�`���̑������w�肵�܂��B
	KMDWORD		dwNumberOf32x32SmallVQmm
	��x�Ɏg�p����A32x32 small VQ mipmap �`���̃e�N�X�`���̑������w�肵�܂��B
	KMDWORD		dwNumberOf64x64SmallVQ
	��x�Ɏg�p����A64x64 small VQ�`���̃e�N�X�`���̑������w�肵�܂��B
	KMDWORD		dwNumberOf64x64SmallVQmm
	��x�Ɏg�p����A64x64 small VQ mipmap �`���̃e�N�X�`���̑������w�肵�܂��B

	8x8 small VQ, 8x8 small VQ mipmap, 64x64 small VQ mipmap�͌��݂�Kamui
	�ł͔�Ή��ł��B�����̃����o�ɂ́A��Ƀ[�����w�肵�Ă��������B

Result:
	KMSTATUS_SUCCESS					����

--*/

KMSTATUS KMAPI
kmuCalculateKamuiWorkareaSize(
		IN OUT PKMWORKAREASIZE	pWorkareaSize
		);

/*++
kmuCreateTextureSurfaceFromFixed

proto type:

	KMSTATUS
	kmuCreateTextureSurfaceFromFixed(
		IN OUT	PKMDWORD		*pFixedArea,
		OUT		PKMSURFACEDESC	pSurfaceDesc,
		IN		KMINT32			nWidth,
		IN		KMINT32			nHeight,
		IN		KMTEXTURETYPE	nTextureType
		);

Description:
	kmCreateFixedTextureArea�Ŋm�ۂ����Œ�e�N�X�`���̈�𕡐���
	�������Ďg�p����ꍇ�̃T�[�t�F�X�f�B�X�N���v�^�𐶐����܂��B

	*pFixedArea�Ɏw�肳�ꂽ�A�h���X����A�����Ŏw�肳�ꂽ�`����
	�e�N�X�`���T�[�t�F�X���m�ۂ��邱�Ƃ�z�肵�āA�T�[�t�F�X
	�f�B�X�N���v�^�\���̂̓��e���Z�b�g���܂��B
	�܂��A*pFixedArea�ɂ́A�����Ŏw�肳�ꂽ�e�N�X�`���̗̈�T�C�Y
	�����Z����܂��B

	���̊֐��͂����܂ŃT�[�t�F�X�f�B�X�N���v�^�\���̂̓��e���Z�b�g
	���邾���ł��B�Œ�̈�̕����Ǘ����s���킯�ł͂���܂���B
	�Œ�̈�̕����Ǘ��A�c�e�ʊǗ��A�A�h���X�̃A���C�����g�Ǘ�
	�̓��[�U�[���ōs���Ă��������B

	���̊֐��́A"small VQ���k�`��"�A"small VQ���k�`��Mipmap����"
	�ɂ͑Ή����Ă��܂���B�����̃e�N�X�`�����Œ�̈�Ŏg�p����
	���ꍇ�ɂ́A�T�[�t�F�X�f�B�X�N���v�^�̐��������[�U�[���ōs��
	�Ă��������B

Arguments:
	IN OUT	*pFixedArea
		kmCreateFixedTextureArea�Ŋm�ۂ����Œ�e�N�X�`���̈�̐擪
		�A�h���X���w�肵�܂��B�����ɂ́A�w�肳�ꂽ�e�N�X�`����ۑ�
		����̂ɕK�v�ȗe�ʂ����Z����܂��B
	OUT	pSurfaceDesc(�o��)
		KMSURFACEDESC�^�̍\���̂ւ̃|�C���^�ł��B���̍\���̂ɂ́A
		�_�Ђɂ����Surface��񂪕Ԃ���܂��B
	IN	nWidth, nHeight(����)
		�e�N�X�`���̉��T�C�Y�A�c�T�C�Y���w�肵�܂��B
		MIPMAP���g�p����ꍇ�ɂ̓g�b�v���x���̃e�N�X�`���T�C�Y���w�肵�܂��B
		nWidth, nHeight�Ɏw�肷��l��,8, 16, 32, 64, 128, 256, 512, 1024��
		�����ꂩ�łȂ���΂Ȃ�܂���B
	IN	nTextureType(����)
		�e�N�X�`���̌`�����w�肵�܂��B
		"small VQ���k�`��"�A"small VQ���k�`��Mipmap����" ������
		�����ꂩ�̌`���̃e�N�X�`���T�[�t�F�X���w�肷�邱�Ƃ��ł��܂��B
		kmCreateTextureSurface�̐������������������B

Result:
	KMSTATUS_SUCCESS					����
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v�A�T�C�Y���w�肵��
	KMSTATUS_INVALID_ADDRESS			pFixedArea, pSurfaceDesc ��NULL�ł���B

--*/

KMSTATUS KMAPI
kmuCreateTextureSurfaceFromFixed(
	IN OUT	PKMDWORD		*pFixedArea,
	OUT		PKMSURFACEDESC	pSurfaceDesc,
	IN		KMINT32			nWidth,
	IN		KMINT32			nHeight,
	IN		KMTEXTURETYPE	nTextureType
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


/*++
kmuConvertStripContext

proto type:

	KMSTATUS
	kmuConvertStripContext(
		OUT	PKMVOID				pStripContext,
		IN	PKMVERTEXCONTEXT	pVertexContext1,
		IN	PKMVERTEXCONTEXT	pVertexContext2
	)

Description:
	�]���݊���KMVERTEXCONTEXT�\���̂���AKAMUI2��KMSTRIPCONTEXT(KMTWOVOLUMESTRIPCONTEXT)
	�ւ̓����ݒ�l�̃R���o�[�g�������Ȃ��܂��B

Arguments:
	OUT		pStripContext			KMSTRIPCONTEXT�܂��́AKMTWOVOLUMESTRIPCONTEXT�\���̂ւ̃|�C���^
									���w�肵�܂��BParam2���g�p����ꍇ�́AKMTWOVOLUMESTRIPCONTEXT��
									�̃|�C���^���g�p���Ă��������B
	IN		pVertexContext1			Param1�Ŏg�p����KMVERTEXCONTEXT�\���̂ւ̃|�C���^���w�肵�܂��B
	IN		pVertexContext2			Param2�Ŏg�p����KMVERTEXCONTEXT�\���̂ւ̃|�C���^���w�肵�܂��B
									Param2���g�p���Ȃ��ꍇ�́ANULL���w�肵�Ă��������B

Result:
	KMSTATUS_SUCCESS				�ݒ萬��
	KMSTATUS_INVALID_ADDRESS		�������s��(NULL)�ł��B
	KMSTATUS_INVALID_SETTING		pStripContext�̃T�C�Y�ݒ肪�s���ł��B
--*/

KMSTATUS KMAPI
kmuConvertStripContext(
		OUT	PKMVOID				pStripContext,
		IN	PKMVERTEXCONTEXT	pVertexContext1,
		IN	PKMVERTEXCONTEXT	pVertexContext2
	);

#ifdef __cplusplus
}
#endif

#endif