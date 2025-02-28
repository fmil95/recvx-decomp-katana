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
  Module Name:		km2api_ver.h

  Abstract:
	KAMUI = Kamui is abstruction model that is ultimate interface for PowerVR.
	'km2api_ver.h' define Version API.

  Environment:
	ANSI C Compiler.

  Notes:
	define Kamui's version api proto-types.

  Revision History:

--*/

#if !defined(__kamui2_version_api_h__)
#define __kamui2_version_api_h__
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
	OUT	pVersionInfo		���炩���ߊm�ۂ��Ă�����KMVERSIONINFO�\���̂ւ̃|�C���^�������܂��B

Result:
	KMSTATUS_SUCCESS		����

--*/

KMSTATUS KMAPI
kmGetVersionInfo(
		PKMVERSIONINFO pVersionInfo
	);
#endif
