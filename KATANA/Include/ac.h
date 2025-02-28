// -------------------------------------------------------------------------------------------------
// ac.h
//
// Header for the AC layer code
//
// COPYRIGHT (C) SEGA OF AMERICA, INC. 1998
// All rights reserved.
//
// Author: Ralph "Cooksey" Thomas
//
// Tabs: 4
//
// Rev	10/21/98	File Originated
//
//		04/28/99	1.75.d.4
//
//		06/11/99	1.80.b.1
//
//		09/29/99	8.2.a
//
//		10/01/99	8.2.b
//
//		10/05/99	8.2.b.2
// -------------------------------------------------------------------------------------------------
 
#ifndef _AC_H
#define _AC_H

#include <actypes.h>

#ifdef __SHC__
#include <math.h> 	// for pow()
#include <string.h>	// for strcpy in acError.c and memset
#include <stdlib.h> // for malloc in amMem.c
#endif


// ------------------------------------------------------------------------------------------------
// Revision numbers
// ------------------------------------------------------------------------------------------------

#define AUDIO_64_REVISION				"\nAudio64 Ver 9.0.b.1 Build:"	// for Sega extractable revision info

#define AC_MAJOR_REVISION				((KTU8)1)
#define AC_MINOR_REVISION				((KTU8)90)
#define AC_LOCAL_REVISION				((KTCHAR)'b')

// ------------------------------------------------------------------------------------------------
// Build directives
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// Constants
// ------------------------------------------------------------------------------------------------

// the aica sample rates
#define AC_44K_SAMPLE_RATE					 0	//	44100
#define AC_22K_SAMPLE_RATE					-1	//	22050
#define AC_11K_SAMPLE_RATE					-2	//	11025
#define AC_5K_SAMPLE_RATE					-3	//	5012
#define AC_2K_SAMPLE_RATE					-4	//	2506
#define AC_1K_SAMPLE_RATE					-5	//	1253
#define AC_626HZ_SAMPLE_RATE				-6	//	626
#define AC_313HZ_SAMPLE_RATE				-7	//	313
#define AC_156HZ_SAMPLE_RATE				-8	//	156

// the aica pan values
#define AC_PAN_LEFT							0
#define AC_PAN_RIGHT						31
#define AC_PAN_CENTER						15

// the highest tone bank slot (0-15)
#define AC_MAX_TONEBANK_SLOT				15

// the highest midi port (0-15)
#define AC_MAX_MIDI_PORT					15

// the highest midi channel (1-16)
#define AC_MAX_MIDI_CHANNEL					16

// the highest midi program change number (0-127)
#define AC_MAX_MIDI_PROGRAM_NUMBER			127

// maximum midi note number (0-127)
#define AC_MAX_MIDI_NOTE_NUMBER				127

// maximum midi velocity value
#define AC_MAX_MIDI_VELOCITY				127

// maximum midi velocity
#define AC_MAX_MIDI_VOLUME					127

// maximum midi velocity
#define AC_MAX_MIDI_PAN						127

// aica max volume and pan
#define	AC_MAX_VOLUME						15
#define	AC_MAX_PAN							31

// the aica loop flag values
#define AC_LOOP_ON							0xff
#define AC_LOOP_OFF							0x00

// acfile.c
#define AC_FILE_BOUNDRY_ALIGNMENT 			32

// other aica flag values
#define AC_GM_OFF							0x00		// GM mode off
#define AC_GM_ON							0xff		// GM mode on

// bank slots for general midi tone banks
#define AC_GM_INST_BANK_SLOT				0
#define AC_GM_DRUM_BANK_SLOT				1

#define AC_MTT_TABLE_OFF					0x00	// MTT table off

// acInt.c
#define AC_ARM_INTERRUPT_HANDLER_ID			0x67676767
#define AC_ARM_POLLING_HANDLER_ID			0x64646464

// midi commands
#define AC_MIDI_PROGRAM_CHANGE				0xc0	// midi program change message
#define AC_MIDI_CONTROL_CHANGE				0xb0	// midi control change message
#define AC_MIDI_NOTE_ON						0x90	// midi note on message
#define AC_MIDI_NOTE_OFF					0x80	// midi note off message
#define AC_MIDI_FULL_VOLUME					0x7f	// max volume
#define AC_MIDI_VOLUME_CC					0x07	// midi volume control change #
#define AC_MIDI_PAN_CC						0x0a	// midi panpot control change #
#define AC_MIDI_BANK_SELECT_CC				0x20	// bank select MSB control change #
#define	AC_MIDI_PITCH_CC					0xe0	// midi note pitch bend
 
// these are for the voiceChannel/port/midiPort allocator for the hybrid driver
#define AC_FIRST_HYBRID_DA_VOICE						0
#define AC_LAST_HYBRID_DA_VOICE							16
#define AC_FIRST_MIDI_VOICE								16
#define AC_LAST_MIDI_VOICE								32

// the driver commands

#define AC_CMD_SET_PORT_SPEED				0x27

#define AC_CMD_CDDA_VOLUME					0x35
#define AC_CMD_CDDA_PANPOT					0x36
#define AC_CMD_CDDA_MIXER					0x3e

#define AC_CMD_SET_TONE_BANK				0xa0
#define AC_CMD_OPEN_MIDI_PORT				0xa1
#define AC_CMD_CLOSE_MIDI_PORT				0xa2
#define AC_CMD_REQUEST_MIDI_PORT_PAUSE		0xa3
#define AC_CMD_REQUEST_MIDI_PORT_RESUME		0xa4
#define AC_CMD_REQUEST_MIDI_PORT_EVENT		0xa5
#define AC_CMD_MIDI_PORT_PLAY				0xa6
#define AC_CMD_MIDI_PORT_STOP				0xa7
#define AC_CMD_MIDI_PORT_VOLUME				0xa8
#define AC_CMD_MIDI_PORT_RESET				0xa9
#define	AC_CMD_MIDI_PORT_SENDMESSAGE		0xaa
#define AC_CMD_MIDI_PORT_SET_TEMPO			0xab
#define AC_CMD_SET_PORT_SAMPLE_RATE			0xac	
#define AC_CMD_PORT_PLAY_WITH_PARAMS 		0xad

#define AC_CMD_OPEN_PORT	 				0x90
#define AC_CMD_CLOSE_PORT					0x91
#define AC_CMD_REQUEST_PORT_EVENT			0x92
#define AC_CMD_PORT_PLAY					0x93
#define AC_CMD_PORT_STOP					0x94
#define AC_CMD_MIXER_SET					0x95
#define AC_CMD_SET_VOLUME					0x96
#define AC_CMD_SET_PANPOT					0x97
#define AC_CMD_SET_PORT_PITCH				0x98	
#define AC_CMD_SET_QSOUND_PAN				0x99	
#define AC_CMD_LOAD_DSP_PROGRAM				0x9a
#define AC_CMD_LOAD_DSP_OUTPUT_MIXER		0x9b
#define AC_CMD_PORT_MULTIPLAY				0x9c
#define AC_CMD_PORT_MULTISTOP				0x9d
#define AC_CMD_INT							0x9e

// magic numbers
#define AC_BASE_OF_SOUND_MEMORY				(KTU32 *)0xa0800000
#define AC_INT_ARRAY_OFFSET					(0xe4/4)
#define AC_PORT_STATUS_FLAG					(0xe0/4)
#define AC_COMMAND_BUFFER_OFFSET			(0xd0/4)
#define AC_COMMAND_FLAG_OFFSET				(0xc8/4)
#define AC_PORT_CURRENT_READ_ADDRESS		(0xe8/4)
#define AC_NEXT_DRIVER_COMMAND_REGISTER		(0xf4/4)
#define AC_ARM_RESET_REGISTER				(volatile KTU32 *)0xa0702c00
#define AC_INT_ENABLE_REGISTER				(volatile KTU32 *)0xa07028b4 // 0x20 is enabled
#define AC_INT_PENDING_REGISTER				(volatile KTU32 *)0xa07028b8 // 0x20 hold pending
#define AC_INT_RESET_REGISTER				(volatile KTU32 *)0xa07028bc // 0x20 is cleared
#define AC_INT_PEND_REGISTER				(volatile KTU32 *)0xa07028b8	// 0x20 is cleared
#define AC_TOTAL_VOICES						64
#define AC_INT_AICA_CHAIN_ID				0x0B20
#define AC_DMA_CALLBACK_ID					(void *)0x102552				// the DMA callback ID






// ------------------------------------------------------------------------------------------------
// Enumerations
// ------------------------------------------------------------------------------------------------

typedef enum
	{
	AC_DMA_STATUS_STOPPED		=	0,	
	AC_DMA_STATUS_PROGRESSING	=	1,	
	AC_DMA_STATUS_SUSPENDED		=	2,	
	AC_DMA_STATUS_REMAIN		=	3,			
	AC_DMA_STATUS_FINISHED		=	4
	}AC_DMA_STATUS;

typedef AC_DMA_STATUS * AC_DMA_STATUS_PTR;

typedef enum
	{
	AC_DMA_NOP			=	0,				// nothing
	AC_DMA_SUSPEND_ALL	=	7,				// suspend all channels
	AC_DMA_RESUME_ALL	=	8				// resume all channels
	}AC_DMA_TRANSFER_OPERATION;
	
typedef AC_DMA_TRANSFER_OPERATION * AC_DMA_TRANSFER_OPERATION_PTR;


typedef enum					// arg for acG2FifoCheck()
	{
	AC_G2_UNINITIALIZED	=	0,	// What I said.
	AC_G2_WRITE_FIFO	=	1,	// AICA internal write buffer (bit 0)
	AC_G2_READ_FIFO		=	2,	// Holly CPU & G2 i/f block internal write buffer (bits 4, 5 and 0)
	}AC_G2_FIFO_TYPE;

// acDigiPlayWithParameters frequency/cent switch
typedef enum
	{
	AC_PITCH_NO_CHANGE		=	0,
	AC_PITCH_AS_SAMPLE_RATE	=	1,
	AC_PITCH_AS_CENT_VALUE	=	2
	}AC_PITCH_SET_TYPE;
	

typedef enum
	{
	AC_UNINITIALIZED_BANK_TYPE	=	0,
	AC_MELODIC_BANK				=	1,
	AC_DRUM_BANK				=	2
	}AC_BANK_TYPE;


typedef enum
	{
	AC_16BIT		=	0,
	AC_8BIT			=	1,
	AC_ADPCM		=	2,
	AC_ADPCM_LOOP	=	3
	}AC_AUDIO_TYPE;

typedef AC_AUDIO_TYPE * AC_AUDIO_TYPE_PTR;


// arg for acIntSetMessagingMode()
typedef enum
	{
	AC_INTERRUPT_MESSAGES	=	0,
	AC_POLL_MESSAGES		=	1
	}AC_MESSAGE_MODE;

// acError.c
typedef enum
	{
	
	AC_NO_ERROR						=	0,		// all is well
	// memory allocation 1-100
	
	// bad parameters 101-200
	AC_NULL_PARAMETER				=	101,	// a pointer parameter is NULL
	AC_OUT_OF_RANGE_PARAMETER		=	102,	// a parameter is out of range
	AC_0_SIZE_PARAMETER				=	103,	// the parameter size is 0
	AC_UNSUPPORTED_SAMPLE_RATE		=	104,	// a sample rate > 1128900 was requested
	// file system 201-300
	AC_SEEK_FAIL					=	201,
	AC_READ_FAIL					=	202,
	AC_GET_SIZE_FAIL				=	203,
	AC_CLOSE_FAIL					=	204,
	AC_FILE_NOT_FOUND				=	205,
	// driver 301-400
	AC_CANT_SEND_DRIVER_COMMAND		=	301,
	AC_DRIVER_IS_INSTALLED			=	302,
	AC_DRIVER_IS_NOT_INSTALLED		=	303,
	AC_INCORRECT_DRIVER_REVISION	=	304,
	AC_FAILED_TO_SET_CALLBACK		=	305,	// failed to set event request
	// warns 401-500
	AC_OUT_OF_RANGE_PARAMETER_FIXED	=	401,
	// memory 501-600
	AC_NON_32_BYTE_ALIGNED_ADDRESS	=	501,
	AC_NON_32_BYTE_ALIGNED_SIZE		=	501,
	AC_NON_DWORD_COPY				=	505,
	AC_ADDRESS_NOT_IN_AICA_MEMORY	=	506,
	AC_ADDRESS_IS_IN_AICA_MEMORY	=	507,
	AC_MEMORY_READ_ERROR			=	508,
	// system
	AC_INTERNAL_ERROR				=	601,
	// queue
	AC_DRIVER_QUEUE_FULL			=	701,
	AC_DRIVER_QUEUE_CORRUPT			=	702,
	// interrupt 1201-1300
	AC_FAIL_TO_CHAIN_INT_HANDLER	=	1201,
	AC_FAIL_TO_CHAIN_POLL_HANDLER	=	1202,
	// dma 1301-1400
	AC_DMA_HANDLER_IS_INSTALLED		=	1301,
	AC_DMA_HANDLER_NOT_INSTALLED	=	1302,
	

	AC_LAST_ERROR					=	5000
	}AC_ERROR_TYPE;


#define AC_ERROR_MESSAGE_LENGTH	255

typedef struct 
	{
	char 			message[AC_ERROR_MESSAGE_LENGTH];
	AC_ERROR_TYPE	number;
	}AC_ERROR;

typedef AC_ERROR * AC_ERROR_PTR;

extern AC_ERROR		gAcError; // errors are reported via this structure

// ------------------------------------------------------------------------------------------------
// Proc pointers
// ------------------------------------------------------------------------------------------------

// acInt.c
typedef void	(*AC_CALLBACK_HANDLER)			(volatile KTU32);
typedef void 	(*AC_ARM_INTERRUPT_HANDLER)		(void *);
typedef KTU32 	(*AC_INT_CHAIN_ADD_MANAGER)		(KTS16	chainTo,AC_ARM_INTERRUPT_HANDLER theInterruptHandler,KTU32 priority,void *theInterruptId);
typedef void	(*AC_INT_CHAIN_DELETE_MANAGER)	(KTU32	theChainId);

// this is NON-R8
extern AC_CALLBACK_HANDLER				gAcCallbackHandler;
extern AC_ARM_INTERRUPT_HANDLER			gAcArmInterruptHandler;
extern AC_INT_CHAIN_ADD_MANAGER			gAcInterruptChainAddManager;
extern AC_INT_CHAIN_DELETE_MANAGER		gAcInterruptChainDeleteManager;

// R8.2
typedef void 	(*AC_DMA_CALLBACK)				(void *);
typedef KTBOOL 	(*AC_DMA_TRANSFER_PROC)			(volatile KTU32 *,volatile KTU32 *,KTU32,AC_DMA_TRANSFER_OPERATION,AC_DMA_CALLBACK);

// ------------------------------------------------------------------------------------------------
// Aggregates
// ------------------------------------------------------------------------------------------------

typedef struct
{
volatile KTU32 *		processerHalt;
volatile KTU32 *		soundMemoryBaseAddress;
volatile KTU32 *		firstFreeMemory;
volatile KTU32 *		commandBuffer;
volatile KTS16			commandSlot;
volatile KTU32 *		commandFlag;
KTU32					armCallbackEventId;	// same as a SYCHAIN type
volatile KTU32 *		intArrayStartPtr;
volatile KTU32			intArrayStartOffset;
volatile KTU8			intArray			[AC_TOTAL_VOICES];
volatile KTU32 *		intResetFlag;
volatile KTU32 *		intEnableRegister;
volatile KTU32 *		intPendingRegister;
KTU32					maxVoices;
}AC_SYSTEM_STRUCT;

extern AC_SYSTEM_STRUCT			gAcSystem;

typedef struct
	{
	KTU8 number;
	KTU8 enable;
	KTU8 parameter[14];
	} AC_COMMAND;

typedef AC_COMMAND *  AC_COMMAND_PTR;

// these relate to the command queue's functionality...
#define AC_COMMAND_ARRAY_LENGTH			512
#define AC_COMMAND_LAST_INDEX			(AC_COMMAND_ARRAY_LENGTH-1)
#define AC_COMMAND_CLEAR				0xffffffff
#define AC_COMMAND_INTERRUPT_ID			((KTU8)0xff)
#define AC_COMMAND_DRIVER_QUEUE_LENGTH	32
#define AC_COMMAND_NUMBER_PER_DUMP		31

typedef struct
	{
	AC_COMMAND	array[AC_COMMAND_ARRAY_LENGTH];
	KTU32		driverIndex;						// index of next empty slot in ARM side
	KTU32		index;								// index of next empty slot in SH4 side
	KTU32		numberOfCommandsInQueue;			// the number of commands in the queue
	KTU32		start;								// start 
	KTBOOL		pending;							// true ? hold pending
	KTU32		total;
	}AC_COMMAND_QUEUE;



// ------------------------------------------------------------------------------------------------
// Abstract types (non-aggregate)
// ------------------------------------------------------------------------------------------------

typedef KTU32 ACFILE;

// ------------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

// acError.c
void 			acErrorSet		(AC_ERROR_TYPE errorNumber,KTSTRING errorMessage);
AC_ERROR_PTR 	acErrorGetLast	(void);
KTBOOL 			acErrorExists	(void);
void 			acErrorClear	(void);

// dma functions
KTBOOL acDmaInstallHandler		(AC_DMA_TRANSFER_PROC theTransferProc);
KTBOOL acDmaInit				(void);
KTBOOL acDmaShutdown			(void);
KTBOOL acDmaSuspendAll			(void);
KTBOOL acDmaResumeAll			(void);

// digital audio functions
KTBOOL acDigiOpen				(KTU32 port,KTU32 address,KTU32 sizeInBytes, AC_AUDIO_TYPE aicaAudioType,KTU32 sampleRate);
KTBOOL acDigiClose				(KTU32 port);
KTBOOL acDigiSetCurrentPitch	(KTU32 port,KTS32 pitchOffsetInCents);
KTBOOL acDigiSetSampleRate		(KTU32 port,KTU32 sampleRate);
KTBOOL acDigiSetVolume			(KTU32 port,KTU32 aicaVolume);
KTBOOL acDigiSetPan				(KTU32 port,KTU32 aicaPan);
KTBOOL acDigiRequestEvent		(volatile KTU32 port,volatile KTU32 offsetFromBeginningInFrames);
KTBOOL acDigiStop				(KTU32 port);
KTBOOL acDigiMultiStop			(KTU32 upperMask, KTU32 lowerMask);
KTBOOL acDigiMultiPlay			(KTS32 aicaLoopFlag, KTU32 upperMask, KTU32 lowerMask);
KTBOOL acDigiMultiSetMask		(KTU32 port,KTU32 *upperMask, KTU32 *lowerMask);
KTBOOL acDigiPlay					(KTU32 port,KTU32 startOffset, KTS16 aicaLoopFlag);
KTBOOL acDigiPlayWithParameters		(KTU32 port,KTU32 volume,KTU32 pan,KTU32 dspMixerChannel,KTU32 dspSendLevel,KTS32 frequencyOrCentsOffset,AC_PITCH_SET_TYPE frequencyOrCentsFlag,KTU32 callbackOffsetInFrames,KTU16 loopStartOffsetInFrames,KTU16 loopEndOffsetInFrames);
KTBOOL acDigiPlayWithLoopParameters	(KTU32 port,KTU32 startOffset, KTS32 aicaLoopFlag,KTU16 loopStartOffsetInFrames,KTU16 loopEndOffsetInFrames);
KTBOOL acDigiGetCurrentReadPosition	(volatile KTU32 voiceChannel,volatile KTU32 *currentSampleFrame);

// acInt.c, manages interrupts received from the ARM/AICA hardware
KTBOOL	acIntInit							(void);
void	acIntShutdown						(void);
KTBOOL 	acIntInstallCallbackHandler			(AC_CALLBACK_HANDLER theCallbackHandler);
KTBOOL 	acIntInstallArmInterruptHandler		(AC_ARM_INTERRUPT_HANDLER theInterruptHandler);
KTBOOL 	acIntInstallOsChainAddManager		(AC_INT_CHAIN_ADD_MANAGER theChainAddManager);
KTBOOL 	acIntInstallOsChainDeleteManager	(AC_INT_CHAIN_DELETE_MANAGER theChainDeleteManager);
void 	acIntSetAicaChainId					(KTU32 chainId);
KTBOOL 	acIntSetMessagingMode				(AC_MESSAGE_MODE messageMode);
void 	acIntSetPollingRate					(KTU32 pollingRate);
void 	_acIntPolledMessageHandler			(void *chainId);
void	_acIntDefaultArmInterruptHandler	(void *theInterruptId);
void 	_acIntPollingArmInterruptHandler	(void *theInterruptId);
void 	_acIntDefaultCallbackHandler		(volatile KTU32 callbackMessage);

// DSP functions
KTBOOL acDspInstallOutputMixer	(KTU32 address,KTU32 sizeInBytes);
KTBOOL acDspInstallProgram		(KTU32 address,KTU32 sizeInBytes);
KTBOOL acDspSetMixerChannel		(KTU32 port,KTU32 toMixerChannel,KTU32 sendLevel);
KTBOOL acDspSetQSoundAngle		(KTU32 qSoundChannel,KTU32 angle);

// MIDI functions
KTBOOL acMidiClose				(KTU32 port);
KTBOOL acMidiOpen				(KTU32 port,KTU8  gmMode,KTU32 address,KTU32 sizeInBytes,KTU32 pulsesPerQuarterNote);
KTBOOL acMidiPlay				(KTU32 port,KTU32 startOffset,KTS16 aicaLoopFlag);
KTBOOL acMidiStop				(KTU32 port);
KTBOOL acMidiPause				(KTU32 port);
KTBOOL acMidiResume				(KTU32 port);
KTBOOL acMidiSetVolume			(KTU32 port,KTU32 portMasterVolume);
KTBOOL acMidiSetTempo			(KTU32 port,KTU32 microSecondsPerQuarterNote);
KTBOOL acMidiReset				(KTU32 port);
KTBOOL acMidiSendMessage		(KTU32 port,KTU32 channel,KTU32 command,KTU32 value1,KTU32 value2);
KTBOOL acMidiRequestEvent		(KTU32 port,KTU32 offsetFromBeginningInBytes);
KTBOOL acMidiSetTonebank		(KTU8 toneBank,AC_BANK_TYPE bankType,KTU32 address,KTU32 sizeInBytes,KTU32 mttPtr);

// Redbook Functions
KTBOOL acCdSetVolume			(KTU32 leftVolume, KTU32 rightVolume);
KTBOOL acCdSetPan				(KTU32 leftPan, KTU32 rightPan);
KTBOOL acCdInit					(void);



// acsystem.c
KTBOOL 				acSystemInit					(void);
void 				acSystemShutdown				(void);
KTBOOL				acSystemInstallDriver			(KTU32 *driverImage,KTU32 driverSize,KTU32 lengthOfIntArray);
void				acSystemResetArmInterrupt		(void);
void				acSystemDisableArmInterrupts	(void);
KTBOOL 				acSystemRequestArmInterrupt		(KTU32 interruptId);
void				acSystemEnableArmInterrupts		(void);
volatile KTU32 *	acSystemGetCommandFlag			(void);
volatile KTU32 *	acSystemGetFirstFreeSoundMemory	(void);
KTBOOL				acSystemGetSystemFlag			(void);
void				acSystemDelay					(KTU32 delay);
KTU32 *				acSystemRead					(volatile KTU32 *address,volatile KTU32 *result);
KTU32 				acSystemGetG2WaitCount			(void);
KTU32 				acSystemGetInterruptArrayLength	(KTU32 *driverImage,KTU32 *interruptArrayLength);
KTBOOL 				acSystemGetIntArrayLength		(KTU32 *interruptArrayLength);
KTBOOL 				acSystemGetIntArray				(char **interruptArray);
KTBOOL 				acSystemGetIntArrayStartPtr		(char **intArrayStartPointer);
KTBOOL 				acSystemGetIntArrayStartOffset	(KTU32 *interruptArrayStartOffset);
KTBOOL 				acSystemGetBaseOfSoundMemory	(KTU32 *baseOfSoundMemory);
KTBOOL 				acSystemGetDriverRevision		(KTU8 *driver,KTU8 *major,KTU8 *minor,KTCHAR *local);
KTBOOL 				acSystemCheckDriverRevision		(KTU8 *driver,KTU8 major,KTU8 minor,KTCHAR local);
KTBOOL 				acSystemIsSoundMemory			(volatile KTU32 *address);


// acG2.c
void 	acG2FifoCheck		(void);
KTBOOL 	acG2Fill			(volatile KTU32 *target,KTU8 value,KTU32 sizeInBytes);
KTBOOL 	acG2Read			(volatile KTU32 *target,volatile KTU32 *source,KTU32 sizeInBytes);
KTBOOL 	acG2ReadLong		(volatile KTU32 *address,KTU32 *value);
KTBOOL 	acG2WriteLong		(volatile KTU32 *address,KTU32 value);
KTBOOL 	acG2Write			(volatile KTU32 *target,volatile KTU32 *source,KTU32 sizeInBytes);
// internals for ac.c
void 	_acG2WriteCommand	(volatile KTU32 * pcmd,volatile KTU32 * pcmdNext);
KTBOOL 	_acG2SetHostCommand		(AC_COMMAND_PTR pcmd);
void	acG2ClearDspRegisters	(void);

#ifdef __cplusplus
}
#endif


#endif // end of #ifndef _AC_H

// -------------------------------------------------------------------------------------------
// end of file: ac.h
// -------------------------------------------------------------------------------------------
