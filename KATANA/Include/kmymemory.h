/*++

  COPYRIGHT        (C) NEC        Corporation 1998 - 1999

  All rights reserved by NEC Corporation. This program must be
  used solely for the purpose for which it was furnished by NEC
  Corporation. No part of this program may be reproduced or
  disclosed to others, in any form, without the prior written
  permission of NEC Corporation.
  Use of copyright notice does not evidence publication of this
  program.

  Author     :		M.Imanishi(NEC Semiconductor,)
  Module Name:		kmymemory.h

  Abstract:
	Memory Copy And Memset Functions

  Environment:
	Hitachi C - Compiler

  Notes:
	Copy funcions for Memory to Memory.

  Revision History:

--*/

#if !defined(__kmyMemory_h)
#define __kmyMemory_h

#ifdef __cplusplus
extern "C" {
#endif

/*++
kmyMemCopy

proto type:

	KMVOID KMAPI
	kmyMemCopy(
			IN	KMVOID *dst,
			IN	KMVOID *src,
			IN	KMDWORD size
		);

Description:
	�������[�������ԃR�s�[���s���܂��B�R�s�[����T�C�Y�A�A���C�������g��
	�`�F�b�N���ăG���[���N����Ȃ��悤�]�����܂��B

Arguments:

Result:
	void
--*/
KMVOID KMAPI
kmyMemCopy (
		IN	KMVOID *dst,
		IN	KMVOID *src,
		IN	KMDWORD size
	);

/*++
kmyZeroMemroy

proto type:

	KMVOID KMAPI
	kmiZeroMemory(
			IN	KMVOID *addr,
			IN	KMDWORD size
		);

Description:
	�T�C�Y�A�A���C�������g���`�F�b�N���ăG���[���N����Ȃ��悤Fill���܂��B

Arguments:

Result:
	void
--*/

KMVOID KMAPI
kmyZeroMemory (
		IN	KMVOID	*addr,
		IN	KMDWORD	size
	);

/*++
kmyPurgeCache

proto type:

	KMVOID KMAPI
	kmyPurgeCache(
			PKMVOID addr
		);

Description:
	addr���܂ރL���b�V�����C���̃p�[�W���s���܂��B

Arguments:

Result:
	void
--*/
KMVOID KMAPI
kmyPurgeCache (
		IN	PKMVOID addr
	);
#ifdef __cplusplus
}
#endif
#endif