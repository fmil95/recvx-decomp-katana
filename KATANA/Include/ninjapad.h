/*
	Ninja Library

	COPYRIGHT (C) SEGA ENTERSRISES,LTD.
*/

#ifndef _NINJAPAD_H_
#define _NINJAPAD_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <sg_pad.h>

/*
 *  DEFINES / MACROS
 */

/******** �|�[�g�ԍ��萔 ***************************************************/
#define NJD_PORT_A0   PDD_PORT_A0              /* �|�[�gA0                 */
#define NJD_PORT_A1   PDD_PORT_A1              /* �|�[�gA1                 */
#define NJD_PORT_A2   PDD_PORT_A2              /* �|�[�gA2                 */
#define NJD_PORT_A3   PDD_PORT_A3              /* �|�[�gA3                 */
#define NJD_PORT_A4   PDD_PORT_A4              /* �|�[�gA4                 */
#define NJD_PORT_A5   PDD_PORT_A5              /* �|�[�gA5                 */
#define NJD_PORT_B0   PDD_PORT_B0              /* �|�[�gB0                 */
#define NJD_PORT_B1   PDD_PORT_B1              /* �|�[�gB1                 */
#define NJD_PORT_B2   PDD_PORT_B2              /* �|�[�gB2                 */
#define NJD_PORT_B3   PDD_PORT_B3              /* �|�[�gB3                 */
#define NJD_PORT_B4   PDD_PORT_B4              /* �|�[�gB4                 */
#define NJD_PORT_B5   PDD_PORT_B5              /* �|�[�gB5                 */
#define NJD_PORT_C0   PDD_PORT_C0              /* �|�[�gC0                 */
#define NJD_PORT_C1   PDD_PORT_C1              /* �|�[�gC1                 */
#define NJD_PORT_C2   PDD_PORT_C2              /* �|�[�gC2                 */
#define NJD_PORT_C3   PDD_PORT_C3              /* �|�[�gC3                 */
#define NJD_PORT_C4   PDD_PORT_C4              /* �|�[�gC4                 */
#define NJD_PORT_C5   PDD_PORT_C5              /* �|�[�gC5                 */
#define NJD_PORT_D0   PDD_PORT_D0              /* �|�[�gD0                 */
#define NJD_PORT_D1   PDD_PORT_D1              /* �|�[�gD1                 */
#define NJD_PORT_D2   PDD_PORT_D2              /* �|�[�gD2                 */
#define NJD_PORT_D3   PDD_PORT_D3              /* �|�[�gD3                 */
#define NJD_PORT_D4   PDD_PORT_D4              /* �|�[�gD4                 */
#define NJD_PORT_D5   PDD_PORT_D5              /* �|�[�gD5                 */

/******** �{�^���E���o�[�T�|�[�g��� ***************************************/
#define NJD_DEV_SUPPORT_AY2 PDD_DEV_SUPPORT_AY2 /* �A�i���O��Y2������      */
#define NJD_DEV_SUPPORT_AX2 PDD_DEV_SUPPORT_AX2 /* �A�i���O��X2������      */
#define NJD_DEV_SUPPORT_AY1 PDD_DEV_SUPPORT_AY1 /* �A�i���O��Y1������      */
#define NJD_DEV_SUPPORT_AX1 PDD_DEV_SUPPORT_AX1 /* �A�i���O��X1������      */
#define NJD_DEV_SUPPORT_AL  PDD_DEV_SUPPORT_AL  /* �A�i���O��L������       */
#define NJD_DEV_SUPPORT_AR  PDD_DEV_SUPPORT_AR  /* �A�i���O��R������       */
#define NJD_DEV_SUPPORT_KRB PDD_DEV_SUPPORT_KRB /* �\���L�[B�E������       */
#define NJD_DEV_SUPPORT_KLB PDD_DEV_SUPPORT_KLB /* �\���L�[B��������       */
#define NJD_DEV_SUPPORT_KDB PDD_DEV_SUPPORT_KDB /* �\���L�[B��������       */
#define NJD_DEV_SUPPORT_KUB PDD_DEV_SUPPORT_KUB /* �\���L�[B�������       */
#define NJD_DEV_SUPPORT_TD  PDD_DEV_SUPPORT_TD  /* D�{�^��������           */
#define NJD_DEV_SUPPORT_TX  PDD_DEV_SUPPORT_TX  /* X�{�^��������           */
#define NJD_DEV_SUPPORT_TY  PDD_DEV_SUPPORT_TY  /* Y�{�^��������           */
#define NJD_DEV_SUPPORT_TZ  PDD_DEV_SUPPORT_TZ  /* Z�{�^��������           */
#define NJD_DEV_SUPPORT_KR  PDD_DEV_SUPPORT_KR  /* �\���L�[A�E������       */
#define NJD_DEV_SUPPORT_KL  PDD_DEV_SUPPORT_KL  /* �\���L�[A��������       */
#define NJD_DEV_SUPPORT_KD  PDD_DEV_SUPPORT_KD  /* �\���L�[A��������       */
#define NJD_DEV_SUPPORT_KU  PDD_DEV_SUPPORT_KU  /* �\���L�[A�������       */
#define NJD_DEV_SUPPORT_ST  PDD_DEV_SUPPORT_ST  /* �X�^�[�g�{�^��������    */
#define NJD_DEV_SUPPORT_TA  PDD_DEV_SUPPORT_TA  /* A�{�^��������           */
#define NJD_DEV_SUPPORT_TB  PDD_DEV_SUPPORT_TB  /* B�{�^��������           */
#define NJD_DEV_SUPPORT_TC  PDD_DEV_SUPPORT_TC  /* C�{�^��������           */

/******** �{�^���萔 *******************************************************/
#define NJD_DGT_TL    PDD_DGT_TL           /* L�{�^��(�G�~�����[�V����)    */
#define NJD_DGT_TR    PDD_DGT_TR           /* R�{�^��(�G�~�����[�V����)    */
#define NJD_DGT_KRB   PDD_DGT_KRB          /* �f�W�^���\���L�[B�E          */
#define NJD_DGT_KLB   PDD_DGT_KLB          /* �f�W�^���\���L�[B��          */
#define NJD_DGT_KDB   PDD_DGT_KDB          /* �f�W�^���\���L�[B��          */
#define NJD_DGT_KUB   PDD_DGT_KUB          /* �f�W�^���\���L�[B��          */
#define NJD_DGT_TD    PDD_DGT_TD           /* D�{�^��                      */
#define NJD_DGT_TX    PDD_DGT_TX           /* X�{�^��                      */
#define NJD_DGT_TY    PDD_DGT_TY           /* Y�{�^��                      */
#define NJD_DGT_TZ    PDD_DGT_TZ           /* Z�{�^��                      */
#define NJD_DGT_KR    PDD_DGT_KR           /* �f�W�^���\���L�[A�E          */
#define NJD_DGT_KL    PDD_DGT_KL           /* �f�W�^���\���L�[A��          */
#define NJD_DGT_KD    PDD_DGT_KD           /* �f�W�^���\���L�[A��          */
#define NJD_DGT_KU    PDD_DGT_KU           /* �f�W�^���\���L�[A��          */
#define NJD_DGT_ST    PDD_DGT_ST           /* �X�^�[�g�{�^��               */
#define NJD_DGT_TA    PDD_DGT_TA           /* A�{�^��                      */
#define NJD_DGT_TB    PDD_DGT_TB           /* B�{�^��                      */
#define NJD_DGT_TC    PDD_DGT_TC           /* C�{�^��                      */


/*
 *  TYPEDEFS
 */

typedef PDS_PERIPHERAL NJS_PERIPHERAL;

#if 0
/******** �y���t�F�����f�[�^�\���� *****************************************/
typedef struct {
	Uint32 id;                            /* �f�o�C�XID                    */
	Uint32 support;                       /* �{�^���̃T�|�[�g���          */
	Uint32 on;                            /* ���݉�����Ă���{�^��        */
	Uint32 off;                           /* ���ݕ�����Ă���{�^��        */
#ifdef USE_UNION
	union {
		Uint32 push;                      /* ���݉����ꂽ�u�Ԃɂ���{�^��  */
#endif
		Uint32 press;
#ifdef USE_UNION
	};
#endif
#ifdef USE_UNION
	union {
		Uint32 pull;                      /* ���ݕ����ꂽ�u�Ԃɂ���{�^��  */
#endif
		Uint32 release;
#ifdef USE_UNION
	};
#endif
	Uint16 r;                             /* ���f�[�^R     (     0�`255  ) */
	Uint16 l;                             /* ���f�[�^L     (     0�`255  ) */
	Sint16 x1;                            /* ���f�[�^X1    (  -128�`127  ) */
	Sint16 y1;                            /* ���f�[�^Y1    (  -128�`127  ) */
	Sint16 x2;                            /* ���f�[�^X2    (  -128�`127  ) */
	Sint16 y2;                            /* ���f�[�^Y2    (  -128�`127  ) */
	char* name;                           /* �f�o�C�X����                  */
	void* extend;                         /* �g���f�[�^�A�h���X            */
	Uint32 old;                           /* �\��                          */
	PDS_PERIPHERALINFO* info;             /* �y���t�F�������ւ̃|�C���^  */
} PDS_PERIPHERAL;
#endif


#define NJD_USER_CONTINUE  0
#define NJD_USER_EXIT      (-1)

extern const NJS_PERIPHERAL* njGetPeripheral(Uint32 port);
extern void njPrintPeripheralInfo(Int loc, Uint32 port);
extern void njUserInit(void);
extern Sint32 njUserMain(void);
extern void njUserExit(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _NINJAPAD_H_ */

