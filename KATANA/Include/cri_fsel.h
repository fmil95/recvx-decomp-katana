#ifndef _FSEL_H_INCLUDED
#define _FSEL_H_INCLUDED
/****************************************************************************/
/*																			*/
/*			File Select Library (for Dreamcast)								*/
/*																			*/
/*				written by M.Oshimi			1999.2.9						*/
/*																			*/
/****************************************************************************/

#define		FSEL_VER		"1.03"

/*	�t�@�C���Z���N�^�̏����� 	*/
void FSEL_Init(void *dir, char *ext);
/*	�t�@�C���I��	*/
char *FSEL_SelectFile(void);
/*	�t�@�C���I���i�������A�j	*/
char *FSEL_Select(long next, char *ext[]);
#endif
