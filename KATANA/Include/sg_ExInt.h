/* 
 *  Shinobi Library
 *  Copyright (c) 1998-2000 SEGA
 *
 * File: sg_ExInt.h
 * Desc: interrupt handler library for Dreamcast Extension BOX
 * Auth: Jiro Terakwa(SYSTEM R&D)
 * Create: 1999/04/07 Jiro Terakawa: Ver. 1.00
 * Change: 
 *         
 */
#ifndef _SG_EXINT_H_
#define _SG_EXINT_H_

/* Define devices by generic device number */
#define SYD_EXTINT_EDEV_DEV0   0
#define SYD_EXTINT_EDEV_DEV1   1
#define SYD_EXTINT_EDEV_DEV2   2
#define SYD_EXTINT_EDEV_DEV3   3
#define SYD_EXTINT_EDEV_DEV4   4
#define SYD_EXTINT_EDEV_DEV5   5
#define SYD_EXTINT_EDEV_DEV6   6
#define SYD_EXTINT_EDEV_DEV7   7
#define SYD_EXTINT_EDEV_DEV8   8
#define SYD_EXTINT_EDEV_DEV9   9
#define SYD_EXTINT_EDEV_DEV10 10
#define SYD_EXTINT_EDEV_DEV11 11
#define SYD_EXTINT_EDEV_DEV12 12
#define SYD_EXTINT_EDEV_DEV13 13
#define SYD_EXTINT_EDEV_DEV14 14
#define SYD_EXTINT_EDEV_DEV15 15
#define SYD_EXTINT_EDEV_DEV16 16
#define SYD_EXTINT_EDEV_DEV17 17
#define SYD_EXTINT_EDEV_DEV18 18
#define SYD_EXTINT_EDEV_DEV19 19
#define SYD_EXTINT_EDEV_DEV20 20
#define SYD_EXTINT_EDEV_DEV21 21
#define SYD_EXTINT_EDEV_DEV22 22
#define SYD_EXTINT_EDEV_DEV23 23
#define SYD_EXTINT_EDEV_DEV24 24
#define SYD_EXTINT_EDEV_DEV25 25
#define SYD_EXTINT_EDEV_DEV26 26
#define SYD_EXTINT_EDEV_DEV27 27
#define SYD_EXTINT_EDEV_DEV28 28
#define SYD_EXTINT_EDEV_DEV29 29
#define SYD_EXTINT_EDEV_DEV30 30
#define SYD_EXTINT_EDEV_DEV31 31

#define SYD_EXTINT_EDEV_MAX_DEVICE 32
/* Define events for already allocated devices */
#define  SYD_EXTINT_EVENT_IML4_BRIDGE SYD_EXTINT_EVENT_IML4_DEV0
#define  SYD_EXTINT_EVENT_IML4_ZIP    SYD_EXTINT_EVENT_IML4_DEV1
#define  SYD_EXTINT_EVENT_IML4_USBPCI SYD_EXTINT_EVENT_IML4_DEV2
#define  SYD_EXTINT_EVENT_IML4_LANPCI SYD_EXTINT_EVENT_IML4_DEV5

/* Define events by generic device number */
#define SYD_EXTINT_EVENT_IML4_DEV0   0
#define SYD_EXTINT_EVENT_IML4_DEV1   1
#define SYD_EXTINT_EVENT_IML4_DEV2   2
#define SYD_EXTINT_EVENT_IML4_DEV3   3
#define SYD_EXTINT_EVENT_IML4_DEV4   4
#define SYD_EXTINT_EVENT_IML4_DEV5   5
#define SYD_EXTINT_EVENT_IML4_DEV6   6
#define SYD_EXTINT_EVENT_IML4_DEV7   7
#define SYD_EXTINT_EVENT_IML4_DEV8   8
#define SYD_EXTINT_EVENT_IML4_DEV9   9
#define SYD_EXTINT_EVENT_IML4_DEV10 10
#define SYD_EXTINT_EVENT_IML4_DEV11 11
#define SYD_EXTINT_EVENT_IML4_DEV12 12
#define SYD_EXTINT_EVENT_IML4_DEV13 13
#define SYD_EXTINT_EVENT_IML4_DEV14 14
#define SYD_EXTINT_EVENT_IML4_DEV15 15
#define SYD_EXTINT_EVENT_IML4_DEV16 16
#define SYD_EXTINT_EVENT_IML4_DEV17 17
#define SYD_EXTINT_EVENT_IML4_DEV18 18
#define SYD_EXTINT_EVENT_IML4_DEV19 19
#define SYD_EXTINT_EVENT_IML4_DEV20 20
#define SYD_EXTINT_EVENT_IML4_DEV21 21
#define SYD_EXTINT_EVENT_IML4_DEV22 22
#define SYD_EXTINT_EVENT_IML4_DEV23 23
#define SYD_EXTINT_EVENT_IML4_DEV24 24
#define SYD_EXTINT_EVENT_IML4_DEV25 25
#define SYD_EXTINT_EVENT_IML4_DEV26 26
#define SYD_EXTINT_EVENT_IML4_DEV27 27
#define SYD_EXTINT_EVENT_IML4_DEV28 28
#define SYD_EXTINT_EVENT_IML4_DEV29 29
#define SYD_EXTINT_EVENT_IML4_DEV30 30
#define SYD_EXTINT_EVENT_IML4_DEV31 31

/* Define events for already allocated devices */
#define  SYD_EXTINT_EVENT_IML4_BRIDGE SYD_EXTINT_EVENT_IML4_DEV0
#define  SYD_EXTINT_EVENT_IML4_ZIP    SYD_EXTINT_EVENT_IML4_DEV1
#define  SYD_EXTINT_EVENT_IML4_USBPCI SYD_EXTINT_EVENT_IML4_DEV2

typedef Sint16 SY_EXTINT_EVENT;

typedef Uint32 SYEXTINT;

Void syExtIntInit(Void);
Void syExtIntFinish(Void);
SYCHAIN syExtIntAddHandler(SY_EXTINT_EVENT event,
			   Void (*usrIsr)(Void *),
			   Uint32 priority,
			   Void *arg);
Void syExtIntDeleteHandler(SYEXTINT extint);

#endif /* _SG_EXINT_H_ */



