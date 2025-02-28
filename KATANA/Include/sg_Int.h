/*
 * File: sg_Int.h
 * Desc: RAW interrupt handler library
 * Auth: Jiro Terakwa(SYSTEM R&D)
 * Create: 1998/02/20 Jiro Terakawa: Ver. 0.1
 * Change: 1998/03/01 Jiro Terakawa: Ver. 0.2
 *         SH4 exception cause added to INTC_EVENT
 *         INTC_DMTE4 -> INTC_DMAE : fixed
 *         1998/05/01 coding standard
 *
 * Note: (Ver. 0.1) Stack only for interrupt is not supported.(1998/02/20)
 *
 */

#ifndef _SG_INT_H_
#define _SG_INT_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * ���o�^�ł��銄���݊֐��̎d�l
 * R0_BANK,-R7_BANK ���g�p����ꍇ�́A�����őҔ��A���A����B
 *
 * ���d�����݂�������ꍇ�ɂ́A�����݊֐��擪�ŁA�����ݗv�����N���A������A
 * set_imask(LEVEL), SR.BL=0) ���s�����Ƃ��K�v�B
 * �i�܂�A�����ݏ������C�u�����ł́A���d�����݂�ϋɓI�ɂ̓T�|�[�g���Ȃ��j
 */

/* ���}�N����` */
#define	USER_VECT(CODE)	*((Uint32*)((Uint32)get_vbr()+0x200+(((CODE)-0x200)>>3)))

/* ���^��` */
#define SYD_INT_EVENT_TLBMISR 0x040 /* TLB mis (READ) */
#define SYD_INT_EVENT_TLBMISW 0x060 /* TLB mis (WRITE) */
#define SYD_INT_EVENT_TLBFWR 0x080  /* TLB new page first write */
#define SYD_INT_EVENT_TLBPR  0x0A0 /* TLB protection (READ) */
#define SYD_INT_EVENT_TLBPW  0x0C0 /* TLB protection (WRITE) */
#define SYD_INT_EVENT_ADRERRR 0x0E0 /* ADDRESS ERROR (READ) */
#define SYD_INT_EVENT_ADRERRW 0x100 /* ADDRESS ERROR (WRITE) */
#define SYD_INT_EVENT_FPUE  0x120 /* FPU exception */
#define SYD_INT_EVENT_TRAPA 0x160 /* TRAPA exception */
#define SYD_INT_EVENT_OPCG  0x180 /* BAD OPCODE */
#define SYD_INT_EVENT_OPCS  0x1A0 /* BAD SLOT OPCODE */
#define SYD_INT_EVENT_NMI   0x1C /* NMI */
#define SYD_INT_EVENT_UBC 0x1E0   /* UBC break */
  /* EXTERNAL INT */
#define SYD_INT_EVENT_IRL6 0x320
#define SYD_INT_EVENT_IRL4 0x360
#define SYD_INT_EVENT_IRL2 0x3A0
  /* TMU */
#define SYD_INT_EVENT_TUNI0 0x400
#define SYD_INT_EVENT_TUNI1 0x420
#define SYD_INT_EVENT_TUNI2 0x440
#define SYD_INT_EVENT_TICPI2 0x460
  /* RTC */
#define SYD_INT_EVENT_ATI 0x480
#define SYD_INT_EVENT_PRI 0x4A0
  /* SCI */
#define SYD_INT_EVENT_CUI 0x4C0
#define SYD_INT_EVENT_ERI 0x4E0
#define SYD_INT_EVENT_RXI 0x500
#define SYD_INT_EVENT_TXI 0x520
#define SYD_INT_EVENT_TEI 0x540
  /* WDT */
#define SYD_INT_EVENT_ITI 0x560
  /* REF */
#define SYD_INT_EVENT_RCMI 0x580
#define SYD_INT_EVENT_ROVI 0x5A0
  /* EMU */
#define SYD_INT_EVENT_SDI 0x600
  /* DMAC */
#define SYD_INT_EVENT_DMTE0 0x640
#define SYD_INT_EVENT_DMTE1 0x660
#define SYD_INT_EVENT_DMTE2 0x680
#define SYD_INT_EVENT_DMTE3 0x6A0
#define SYD_INT_EVENT_DMAE 0x6C0
  /* SCIF */
#define SYD_INT_EVENT_FERI 0x700
#define SYD_INT_EVENT_FRXI 0x720
#define SYD_INT_EVENT_FSBRK 0x740
#define SYD_INT_EVENT_FTXI 0x760
#define SYD_INT_EVENT_FPUG 0x800
#define SYD_INT_EVENT_FPUS 0x820

typedef Sint16 SY_INT_EVENT;

#define SYD_INT_MODE_INTSTACK   0x80000000
#define SYD_INT_MODE_LOCALSTACK 0x00000000
typedef Uint32 SY_INT_MODE;

/* functions */
Void syIntInit(SY_INT_MODE mode, Void *stack); /* initialize intc library */
Void syIntEnableInt(Uint32 imask); /* ���̊֐����ďo�����ɑ��d�����݂������� (BL=0) */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SG_INT_H_ */