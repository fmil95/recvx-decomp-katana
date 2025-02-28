/*++

  COPYRIGHT        (C) NEC        Corporation 1997 - 1999

  All rights reserved by NEC Corporation. This program must be
  used solely for the purpose for which it was furnished by NEC
  Corporation. No part of this program may be reproduced or
  disclosed to others, in any form, without the prior written
  permission of NEC Corporation.
  Use of copyright notice does not evidence publication of this
  program.

  Author     :		T.Hirata(NEC Software,Ltd.)
  Module Name:		km2api.h

  Abstract:
	KAMUI = Kamui is abstruction model that is ultimate interface for PowerVR.
	'km2api_cfg.h' defines kmSetSystemConfiguration();

  Environment:
	ANSI C Compiler.

  Notes:
	kmSetSystemConfiguration();

  Revision History:

--*/

#if !defined(__kamui2_configuration_api_h)
#define __kamui2_configuration_api_h

/*++
kmSetSystemConfiguration

proto type:
	KMSTATUS kmSetSystemConfiguration(
			PKMSYSTEMCONFIGSTRUCT pSystemConfigStruct
	)

Description:
		KMSYSTEMCONFIGSTRUCT�^�\���̂Ɏw�肵���p�����[�^�ɏ]���A�_�Ђ̃V�X�e���\����ݒ肵�܂��B

		 Texture/Frame Buffer �S�̗̂e��  -  (�w�肳�ꂽ�ő�e�N�X�`���g�p�T�C�Y + �\���pFrame Buffer)
				=	 Native Buffer

Arguments:
	IN	OUT	pSystemConfigStruct
							KMSYSTEMCONFIGSTRUCT�^�\���̂ւ̃|�C���^���w�肵�܂��B
							�{�\���̂̃����o�͈ȉ��̗l�ɐݒ肵�܂��B

				dwSize		KMSYSTEMCONFIGSTRUCT �\���̂̃T�C�Y �������܂��B
							pSystemConfigStruct->dwSize = sizeof(KMSYSTEMCONFIGSTRUCT);

				flags		�V�X�e���̓�����w�肵�܂��B
								KM_CONFIGFLAG_ENABLE_CLEAR_FRAMEBUFFER	Frame Buffer �m�ێ��Ƀo�b�t�@�̓��e���N���A���܂��B
								KM_CONFIGFLAG_ENABLE_STRIPBUFFER		Strip Buffer ��L���ɂ��܂��B
								KM_CONFIGFLAG_ENABLE_2V_LATENCY			2V Laytency Mode �ɂ��܂��B
								KM_CONFIGFLAG_NOWAITVSYNC				V-SYNC ��҂��Ȃ����[�h�ł��B

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

				nTextureMemorySize
							�g�p����e�N�X�`���������̃T�C�Y���w�肵�܂��B

				pBufferDesc
						KMVERTEXBUFFDESC �\���̂ւ̃|�C���^�ł��B

				pVertexBuffer
				nVertexBufferSize;
						���_�o�b�t�@�ւ̃x�[�X�A�h���X/�T�C�Y���w�肵�܂��B

Result:
	KMSTATUS_SUCCESS			����
	KMSTATUS_NOT_ENOUGH_MEMORY	Native Buffer/Frame Buffer �̂��߂̃������e�ʂ�����܂���

--*/

KMSTATUS KMAPI
kmSetSystemConfiguration(
		IN	OUT	PKMSYSTEMCONFIGSTRUCT pSystemConfigStruct
	);
#endif
