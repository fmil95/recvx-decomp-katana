/****************************************************
 *													*
 *	Dreamcast Sound Library							*
 *													*
 *		Copyright 1997-1999 (C)SEGA Enterprises		*
 *			Programmed By T.Jokagi					*
 *													*
 ****************************************************/

#ifndef	_SG_SD2_H_
#define	_SG_SD2_H_

#include	<sg_xpt.h>

/*****************************************************
 *
 *	�萔��`
 *
 */
/*
 *	�o�[�W�����ԍ�
 *	Number of version
 */
/*	���l�ł̒�`  */
#define	SDD_LIB_VER_MAJOR	(0x02)
#define	SDD_LIB_VER_MINOR	(0x00)
#define	SDD_LIB_VER_DEBUG	(0x03)
/*	������ł̒�`  */
#define	SDD_LIB_VER_STRING	"2.00.03"

/*
 *	�������u���b�N�֌W
 *	Memory Block
 */
/*	�������u���b�N�n���h���ő�쐬��  */
/*	Max of memory block handle  */
#define	SDD_MEMBLK_HANDLE_NUM	( 64)
/*	�������u���b�N�n���h���L���[�ő�쐬��  */
/*	Max of memory block queue  */
#define	SDD_MEMBLK_QUEUE_NUM	( 64)
/*
 *	�z�X�g�R�}���h�֌W
 *	Host command
 */
/*	�Z�J���_���z�X�g�R�}���h�ő�o�^��  */
/*	Max of secondary buffer of host command  */
#define	SDD_HOST_CMD_2ND_BUF_NUM		( 256)

/*
 *	�e�퉹���̍ő�|�[�g��
 *	Max of sound module port
 */
#define	SDD_MIDI_PORT_NUM		( 0x00000008)
#define	SDD_SHOT_PORT_NUM		( 0x00000040)
#define	SDD_PSTM_PORT_NUM		( 0x00000010)

/*	PCM Stream�|�[�g��1�|�[�g������̍ő�`�����l����  */
#define	SDD_PSTM_PORT_SLOT_NUM	( 0x00000004)

/*
 *	�e�퉹���̍ő唭����
 */
#define	SDD_MIDI_SLOT_NUM		( 0x00000040)
#define	SDD_SHOT_SLOT_NUM		( 0x00000040)
#define	SDD_PSTM_SLOT_NUM		( 0x00000010)

/*
 *	MIDI�`�����l��
 */
#define	SDD_MIDI_CH_NUM		( 0x00000010)
#define	SDD_MIDI_CH_MIN		( 0x00000000)
#define	SDD_MIDI_CH_MAX		( 0x0000000F)

/*
 *	�m�[�g�ԍ�
 */
#define	SDD_MIDI_NOTE_NUM	( 0x00000080)
#define	SDD_MIDI_NOTE_MIN	( 0x00000000)
#define	SDD_MIDI_NOTE_MAX	( 0x0000007F)

/*
 *	MIDI���b�Z�[�W
 */
#define	SDD_MIDI_MES_NOTE_OFF	( 0x00000080)
#define	SDD_MIDI_MES_NOTE_ON	( 0x00000090)
#define	SDD_MIDI_MES_MONO_PRES	( 0x000000A0)
#define	SDD_MIDI_MES_CTL_CHG	( 0x000000B0)
#define	SDD_MIDI_MES_PRG_CHG	( 0x000000C0)
#define	SDD_MIDI_MES_POLY_PRES	( 0x000000D0)
#define	SDD_MIDI_MES_PITCH_BEND	( 0x000000E0)

#define	SDD_MIDI_CTL_CHG_LSB		( 0x00000000)
#define	SDD_MIDI_CTL_CHG_MSB		( 0x00000020)

/*	�v���O�����o���N�`�F���W  */
#define	SDD_MIDI_CTL_CHG_BANK	( 0x00000000)
/*	���W�����[�V�����`�F���W  */
#define	SDD_MIDI_CTL_CHG_MODULATION	( 0x00000001)
/*	�{�����[���`�F���W  */
#define	SDD_MIDI_CTL_CHG_VOL		( 0x00000007)
/*	�p���|�b�g�`�F���W  */
#define	SDD_MIDI_CTL_CHG_PAN		( 0x0000000A)
/*	�G�N�X�v���b�V�����`�F���W  */
#define	SDD_MIDI_CTL_CHG_EXPRESSION	( 0x0000000B)

/*
 *	PCM Stream�̃X���b�g�ʖ�
 *	alias of PCM Stream slot
 */
#define	SDD_PSTM_PORT_SLOT_ALL		( ( Sint8)0xFF)
#define	SDD_PSTM_PORT_SLOT_LEFT		( ( Sint8)0x00)
#define	SDD_PSTM_PORT_SLOT_RIGHT	( ( Sint8)0x01)

/*
 *	PCM Stream�̃X���b�g�t�B���^
 *	Filter of PCM Stream slot
 */
#define	SDD_PSTM_PORT_SLOT_FILTER_THROUGH	( ( Sint16)-1)

/*
 *	�|�[�g�̃t���O�̃r�b�g�A�T�C��
 */
#define	SDD_PORT_FLG_PLAY		( ( Uint32)0x00000001)
#define	SDD_PORT_FLG_PAUSE		( ( Uint32)0x00000002)
#define	SDD_PORT_FLG_CHG_VOL	( ( Uint32)0x00000004)
#define	SDD_PORT_FLG_CHG_SPEED	( ( Uint32)0x00000008)
#define	SDD_PORT_FLG_CHG_PAN	( ( Uint32)0x00000010)
#define	SDD_PORT_FLG_CHG_PITCH	( ( Uint32)0x00000020)
#define	SDD_PORT_FLG_TROUBLE	( ( Uint32)0x00000080)

/*
 *	�|�[�g�̃G���[�̃r�b�g�A�T�C��
 */
#define	SDD_PORT_ERR_PRIORITY				( ( Uint32)0x00000002)
#define	SDD_PORT_ERR_REQUEST_NUM			( ( Uint32)0x00000004)
#define	SDD_PORT_ERR_MIDI_BUF_NO_ENOUGH		( ( Uint32)0x00000020)
#define	SDD_PORT_ERR_MIDI_SEQ_BUF_NO_ENOUGH	( ( Uint32)0x00000040)
#define	SDD_PORT_ERR_SLOT_NO_ENOUGH			( ( Uint32)0x00000080)

#define	SDD_PORT_ERR_BANK_NOT_FOUND			( ( Uint32)0x00000100)
#define	SDD_PORT_ERR_BANK_ILLEGAL_ID		( ( Uint32)0x00000200)
#define	SDD_PORT_ERR_BANK_ILLEGAL_SZ		( ( Uint32)0x00000400)
#define	SDD_PORT_ERR_BANK_ILLEGAL_VER		( ( Uint32)0x00000800)

/*
 *	�O���[�o���ȃG���[�̃r�b�g�A�T�C��
 */
#define	SDD_DRV_ERR_BANK_NO_DOWNLOAD	( ( Uint32)0x00000008)
#define	SDD_DRV_ERR_BANK_ILLEGAL_ID		( ( Uint32)0x00000010)
#define	SDD_DRV_ERR_BANK_ILLEGAL_END_ID	( ( Uint32)0x00000020)
#define	SDD_DRV_ERR_BANK_ILLEGAL_VER	( ( Uint32)0x00000040)
#define	SDD_DRV_ERR_BANK_ILLEGAL_NUM	( ( Uint32)0x00000080)

/*
 *	�������u���b�N�n���h���̓���ݒ�
 */
/*	�������u���b�N�]���Ŋ֐���o�^���Ȃ��ꍇ  */
#define	SDD_MEMBLK_NO_FUNC		( ( SD_MEMBLK_CALLBACK_FUNC)0x00000000)
/*	�������u���b�N�]���œ������[�h���s���ꍇ  */
#define	SDD_MEMBLK_SYNC_FUNC	( ( SD_MEMBLK_CALLBACK_FUNC)0xFFFFFFFF)
/*	���[�J���Ƀ������m�ے萔���鎞  */
#define	SDD_MEMBLK_LOCAL_ALLOCATE	( ( SDMEMBLK)0xF0000000)

/*
 *	���ʌ݊��ׂ̈̃}�N���萔
 */
#ifdef SDD_LIB_VER1_NAME_AVAILABLE
#define	SDD_MIDI_PORT_MAX		( SDD_MIDI_PORT_NUM)
#define	SDD_SHOT_PORT_MAX		( SDD_SHOT_PORT_NUM)
#define	SDD_PSTM_PORT_MAX		( SDD_PSTM_PORT_NUM)

#define	SDD_PSTM_PORT_SLOT_MAX	( SDD_PSTM_PORT_SLOT_NUM)
#define	SDD_PSTM_PORT_CH_MAX	( SDD_PSTM_PORT_SLOT_NUM)

#define	SDD_MIDI_SLOT_MAX		( SDD_MIDI_SLOT_NUM)
#define	SDD_SHOT_SLOT_MAX		( SDD_SHOT_SLOT_NUM)
#define	SDD_PSTM_SLOT_MAX		( SDD_PSTM_SLOT_NUM)

#define	SDD_MIDI_NOTE_OFF	( SDD_MIDI_MES_NOTE_OFF)
#define	SDD_MIDI_NOTE_ON	( SDD_MIDI_MES_NOTE_ON)
#define	SDD_MIDI_MONO_PRES	( SDD_MIDI_MES_MONO_PRES)
#define	SDD_MIDI_CTL_CHG	( SDD_MIDI_MES_CTL_CHG)
#define	SDD_MIDI_PRG_CHG	( SDD_MIDI_MES_PRG_CHG)
#define	SDD_MIDI_POLY_PRES	( SDD_MIDI_MES_POLY_PRES)
#define	SDD_MIDI_PITCH_BEND	( SDD_MIDI_MES_PITCH_BEND)

#define	SDD_PSTM_PORT_CH_ALL	( SDD_PSTM_POR_SLOT_ALL)
#define	SDD_PSTM_PORT_ALL_CH	( SDD_PSTM_POR_SLOT_ALL)
#define	SDD_PSTM_PORT_LEFT_CH	( SDD_PSTM_POR_SLOT_LEFT)
#define	SDD_PSTM_PORT_RIGHT_CH	( SDD_PSTM_POR_SLOT_RIGHT)

#define	SDD_PSTM_FREQ_48000		( 48000)
#define	SDD_PSTM_FREQ_44100		( 44100)
#define	SDD_PSTM_FREQ_37800		( 37800)
#define	SDD_PSTM_FREQ_32000		( 32000)
#define	SDD_PSTM_FREQ_24000		( 24000)
#define	SDD_PSTM_FREQ_22050		( 22050)
#define	SDD_PSTM_FREQ_18900		( 18900)
#define	SDD_PSTM_FREQ_16000		( 16000)
#define	SDD_PSTM_FREQ_12000		( 12000)
#define	SDD_PSTM_FREQ_11025		( 11025)
#define	SDD_PSTM_FREQ_08820		(  8820)
#define	SDD_PSTM_FREQ_08000		(  8000)
#endif

/*****************************************************
 *
 *	�}�N���֐��錾
 *
 */

#define	SDD_INT32(data)							\
	( ( ( ( data >> 24) & 0x000000FF)      )	\
	| ( ( ( data >> 16) & 0x000000FF) <<  8)	\
	| ( ( ( data >>  8) & 0x000000FF) << 16)	\
	| ( ( ( data      ) & 0x000000FF) << 24))

#define	SDD_CHAR32(d1,d2,d3,d4)					\
	( ( d1      )								\
	| ( d2 <<  8)								\
	| ( d3 << 16)								\
	| ( d4 << 24))

/*****************************************************
 *
 *	�f�[�^�^�C�v��`
 *
 */

/********************************
 *
 *	�񋓑̃^�C�v��`
 *
 */
/*
 *	�T�E���h�G���[�^��`
 */
enum SDE_ERR
{
	SDE_ERR_NOTHING					= 0x00000000,	/*	�m�[�G���[  */

	SDE_ERR_GD_FS_LIB_ERR			= 0x01000001,	/*	GD-FS���C�u�����G���[  */

	SDE_ERR_PRM_OVER_RANGE			= 0x03000001,	/*	�p�����[�^�����W�I�[�o�[  */
	SDE_ERR_PRM_ILLEGAL_VALUE		= 0x03000002,	/*	�p�����[�^�̒l����������  */

	SDE_ERR_MODULE_SLOT_NO_ENOUGH	= 0x05000001,	/*	�����̃X���b�g������Ȃ�  */

	SDE_ERR_MEMBLK_ALREADY_TRANSFER	= 0x06000001,	/*	��d�]���G���[  */
	SDE_ERR_MEMBLK_QUEUE_NO_ENOUGH	= 0x06000101,	/*	�������u���b�N�L���[�̋󂫂�����  */

	SDE_ERR_HANDLE_NO_ENOUGH		= 0x07000101,	/*	�n���h���̋󂫂�����  */
	SDE_ERR_HANDLE_ILLEGAL_VALUE	= 0x07000102,	/*	�s���ȃn���h��  */
	SDE_ERR_HANDLE_NULL				= 0x07000103,	/*	�n���h����0�A�h���X���w���Ă���  */

	SDE_ERR_PTR_ILLEGAL_VALUE		= 0x07000202,	/*	�|�C���^�̃A�h���X����������  */
	SDE_ERR_PTR_NULL				= 0x07000203,	/*	�|�C���^��0�A�h���X���w���Ă���  */

	SDE_ERR_BANK_ILLEGAL_TYPE		= 0x09000001,	/*	�o���N�^�C�v���Ⴄ  */
	SDE_ERR_BANK_ILLEGAL_VER		= 0x09000002,	/*	�o���N�o�[�W�������Â�  */
	SDE_ERR_BANK_NOTHING			= 0x09000003,	/*	�o���N�������D�������͖��ݒ�  */
	SDE_ERR_BANK_ILLEGAL_NUM		= 0x09000004,   /*	�o���N�ԍ�����������  */
	SDE_ERR_BANK_NO_MAPPING			= 0x09000110,	/*	�o���N�p�Ƀ������}�b�s���O����Ă��Ȃ�  */
	SDE_ERR_DATA_ILLEGAL_TYPE		= 0x09000101,	/*	�f�[�^�^�C�v���Ⴄ  */
	SDE_ERR_DATA_ILLEGAL_VER		= 0x09000102,	/*	�f�[�^�o�[�W�������Â�  */
	SDE_ERR_DATA_NOTHING			= 0x09000103,	/*	�f�[�^�������D�������͖��ݒ�  */
	SDE_ERR_DATA_ILLEGAL_NUM		= 0x09000104,   /*	�o���N�ԍ�����������  */

	SDE_ERR_HOST_CMD_BUF_NO_ENOUGH	= 0x0A000001,	/*	�z�X�g�R�}���h�o�b�t�@�t��  */

	SDE_ERR_SND_DRV_PROBLEM			= 0x0B000001,	/*	�T�E���h�h���C�o�̓���s��  */
	SDE_ERR_SND_DRV_ILLEGAL_VER		= 0x0B000002,	/*	�h���C�o�Ƃ̃o�[�W�����s��v  */
	SDE_ERR_SND_DRV_BUSY			= 0x0B000003,	/*	�h���C�o������  */

	SDE_ERR_NO_INIT					= 0x0D000001,	/*	��������  */
	SDE_ERR_ALREADY_INIT			= 0x0D000002,	/*	���łɏ������ς�  */

	SDE_ERR_HARD_WARE				= 0x0F000001,	/*	�n�[�h�E�F�A����s��  */
	SDE_ERR_MAIN_MEM_ADR_ERR		= 0x0F010001,	/*	���C���������A�h���X�G���[  */
	SDE_ERR_SND_MEM_ADR_ERR			= 0x0F010101,	/*	�T�E���h�������A�h���X�G���[  */

	SDE_ERR_UNKNOW_NUM				= 0x7FFFFFFF	/*	���m�̃G���[  */
};
typedef enum SDE_ERR	SDE_ERR;

/*
 *	�T�E���h�f�[�^�^��`
 */
enum SDE_DATA_TYPE
{
	SDE_DATA_TYPE_SND_DRV		= SDD_CHAR32('S','D','R','V'),	/*	SDRV  */
	SDE_DATA_TYPE_MULTI_UNIT	= SDD_CHAR32('S','M','L','T'),	/*	SMLT  */
	SDE_DATA_TYPE_MIDI_DRM_BANK	= SDD_CHAR32('S','M','D','B'),	/*	SMDB  */
	SDE_DATA_TYPE_MIDI_SEQ_BANK	= SDD_CHAR32('S','M','S','B'),	/*	SMSB  */
	SDE_DATA_TYPE_MIDI_PRG_BANK	= SDD_CHAR32('S','M','P','B'),	/*	SMPB  */
	SDE_DATA_TYPE_SHOT_BANK		= SDD_CHAR32('S','O','S','B'),	/*	SOSB  */
	SDE_DATA_TYPE_PSTM_RING_BUF	= SDD_CHAR32('S','P','S','R'),	/*	SPSR  */
	SDE_DATA_TYPE_FX_OUT_BANK	= SDD_CHAR32('S','F','O','B'),	/*	SFOB  */
	SDE_DATA_TYPE_FX_PRG_BANK	= SDD_CHAR32('S','F','P','B'),	/*	SFPB  */
	SDE_DATA_TYPE_FX_PRG_WRK	= SDD_CHAR32('S','F','P','W')	/*	SFPW  */
};
typedef enum SDE_DATA_TYPE	SDE_DATA_TYPE;

/*
 *	�p���|�b�g�̃��[�h�ݒ�f�[�^�^�C�v
 */
enum SDE_PAN_MODE
{
	SDE_PAN_MODE_MONO,		/*	���m����  */
	SDE_PAN_MODE_STEREO,	/*	�X�e���I  */
	SDE_PAN_MODE_DISABLE = SDE_PAN_MODE_MONO,
	SDE_PAN_MODE_ENABLE = SDE_PAN_MODE_STEREO
};
typedef enum SDE_PAN_MODE	SDE_PAN_MODE;

/*
 *	MIDI�|�[�g��GM���[�h
 */
enum SDE_MIDI_GM_MODE
{
	SDE_MIDI_GM_MODE_ON = ON,
	SDE_MIDI_GM_MODE_OFF = OFF
};
typedef enum SDE_MIDI_GM_MODE	SDE_MIDI_GM_MODE;

/*
 *	One Shot�̂̍Đ����Ԑݒ胂�[�h
 */
enum SDE_SHOT_PLAY_TIME
{
	SDE_SHOT_PLAY_TIME_RELATIVE,	/*	���Βl�w��  */
	SDE_SHOT_PLAY_TIME_RATIO,		/*	�����w��  */
	SDE_SHOT_PLAY_TIME_ABSOLUTE		/*	��Βl�w��  */
};
typedef enum SDE_SHOT_PLAY_TIME	SDE_SHOT_PLAY_TIME;

/*
 *	PCM�̎�ތ^��`
 */
enum SDE_PCM_TYPE
{
	SDE_PCM_TYPE_8BIT_LINEAR,
	SDE_PCM_TYPE_16BIT_LINEAR,
	SDE_PCM_TYPE_4BIT_ADPCM,
	SDE_PCM_TYPE_8BIT_PCM = SDE_PCM_TYPE_8BIT_LINEAR,
	SDE_PCM_TYPE_16BIT_PCM = SDE_PCM_TYPE_16BIT_LINEAR
};
typedef enum SDE_PCM_TYPE	SDE_PCM_TYPE;

/*
 *	�T�E���h�������u���b�N�]���X�e�[�^�X�^��`
 */
enum SDE_MEMBLK_STAT
{
	SDE_MEMBLK_STAT_TRANSFER_REMAIN,
	SDE_MEMBLK_STAT_TRANSFER_FINISHED,
	SDE_MEMBLK_STAT_TRANSFER_PROGRESS
};
typedef enum SDE_MEMBLK_STAT	SDE_MEMBLK_STAT;

/*
 *	�T�E���h�������u���b�N�]�����[�h�^��`
 */
enum SDE_MEMBLK_TRANSFER_MODE
{
	SDE_MEMBLK_TRANSFER_MODE_CPU,
	SDE_MEMBLK_TRANSFER_MODE_DMA
};
typedef enum SDE_MEMBLK_TRANSFER_MODE	SDE_MEMBLK_TRANSFER_MODE;

/*
 *	�|�[�g�̍Đ���~���̃����[�X���[�h�^��`
 */
enum SDE_PORT_RELEASE_MODE
{
	SDE_PORT_RELEASE_MODE_ENABLE,	/*	�Đ���~�E�ꎞ��~���̓����[�X�L��  */
	SDE_PORT_RELEASE_MODE_DISABLE	/*	�Đ���~�E�ꎞ��~���̓����[�X����  */
};
typedef enum SDE_PORT_RELEASE_MODE	SDE_PORT_RELEASE_MODE;

/********************************
 *
 *	�P���^�C�v��`
 *
 */
typedef Void	( *SD_CALLBACK_FUNC)( Void *first_arg);	/*	�ėp�R�[���o�b�N  */
typedef SD_CALLBACK_FUNC	SD_MEMBLK_CALLBACK_FUNC;	/*	�������u���b�N�R�[���o�b�N  */

/********************************
 *
 *	�\���̃^�C�v��`
 *
 */
/*
 *	�o�[�W�����^��`
 */
struct SDS_VER
{
#ifndef	SDD_LIB_VER1_NAME_AVAILABLE
	Uint8	m_Major;	/*	���W���[�o�[�W����  */
	Uint8	m_Minor;	/*	�}�C�i�[�o�[�W����  */
	Uint8	m_Debug;	/*	�f�o�O�o�[�W����  */
#else
	Uint8	m_MajorVer;	/*	���W���[�o�[�W����  */
	Uint8	m_MinorVer;	/*	�}�C�i�[�o�[�W����  */
	Uint8	m_DebugVer;	/*	�f�o�O�o�[�W����  */
#endif
	Uint8	rsv;		/*	�\��̈�  */
};
typedef struct SDS_VER	SDS_VER;

/*
 *	�T�E���hMIDI���b�Z�[�W�^��`
 */
struct SDS_MIDI_MES
{
	Uint8	m_Member[ 0x04];
};
typedef struct SDS_MIDI_MES	SDS_MIDI_MES;

/*
 *	FX Output�p�����[�^
 */
struct SDS_FX_OUT_PRM
{
	Sint8	m_Lev;
	Sint8	m_Ch;
};
typedef struct SDS_FX_OUT_PRM	SDS_FX_OUT_PRM;

/*
 *	MIDI�|�[�g�̃X�e�[�^�X�^��`
 */
struct SDS_MIDI_STAT
{
	Sint16	rsv;				/*	���U�[�u  */
	Sint8	m_Vol;				/*	�{�����[��  */
	Sint8	m_Pan;				/*	�p���|�b�g  */
	Sint8	m_FxLev;			/*	FX���x��  */
	Sint8	m_DrctLev;			/*	�_�C���N�g���x��  */
	Sint16	m_Pitch;			/*	�s�b�`  */
	Sint16	m_Speed;			/*	�X�s�[�h  */
	Uint32	m_TotalBeatTime;	/*	�����t����  */
	Sint32	m_CurAdr;			/*	�J�����g���t�A�h���X  */
	Uint32	m_Err;				/*	�G���[�X�e�[�^�X  */
	Uint32	m_Flg;				/*	�e��t���O  */
};
typedef struct SDS_MIDI_STAT	SDS_MIDI_STAT;

/*
 *	One Shot�|�[�g�̃X�e�[�^�X�^��`
 */
struct SDS_SHOT_STAT
{
	Sint16	rsv;				/*	���U�[�u  */
	Sint8	m_Vol;				/*	�{�����[��  */
	Sint8	m_Pan;				/*	�p���|�b�g  */
	Sint8	m_FxLev;			/*	FX���x��  */
	Sint8	m_DrctLev;			/*	�_�C���N�g���x��  */
	Sint16	m_Pitch;			/*	�s�b�`  */
	Sint16	rsv2;				/*	���U�[�u  */
	Uint32	m_TotalSmpFrame;	/*	�����t�T���v����  */
	Sint32	m_CurAdr;			/*	�J�����g���t�A�h���X  */
	Uint32	m_Err;				/*	�G���[�X�e�[�^�X  */
	Uint32	m_Flg;				/*	�e��t���O  */
};
typedef struct SDS_SHOT_STAT	SDS_SHOT_STAT;

/*
 *	PCM Stream�|�[�g�̃X�e�[�^�X�^��`
 */
struct SDS_PSTM_STAT
{
	Sint16	rsv;				/*	���U�[�u  */
	Sint8	m_Vol;				/*	�{�����[��  */
	Sint8	m_Pan;				/*	�p���|�b�g  */
	Sint8	m_FxLev;			/*	FX���x��  */
	Sint8	m_DrctLev;			/*	�_�C���N�g���x��  */
	Sint16	m_Pitch;			/*	�s�b�`  */
	Sint16	rsv2;				/*	���U�[�u  */
	Uint32	m_TotalSmpFrame;	/*	�����t�T���v����  */
	Sint32	m_CurAdr;			/*	�J�����g���t�A�h���X  */
	Uint32	m_Err;				/*	�G���[�X�e�[�^�X  */
	Uint32	m_Flg;				/*	�e��t���O  */
};
typedef struct SDS_PSTM_STAT	SDS_PSTM_STAT;

/*
 *	GDDA�̃X�e�[�^�X�^��`
 */
struct SDS_GDDA_STAT
{
	Sint16	rsv;				/*	���U�[�u  */
	Sint8	m_LeftVol;			/*	���`�����l���{�����[��  */
	Sint8	m_RightVol;			/*	�E�`�����l���{�����[��  */
	Sint8	m_LeftPan;			/*	���`�����l���p���|�b�g  */
	Sint8	m_RightPan;			/*	�E�`�����l���p���|�b�g  */
	Uint32	m_Err;				/*	�G���[�X�e�[�^�X  */
	Uint32	m_Flg;				/*	�e��t���O  */
};
typedef struct SDS_GDDA_STAT	SDS_GDDA_STAT;

/*
 *	�������u���b�N�^��`
 */
struct SDS_MEMBLK
{
	Uint32	m_Member[ 16];
};
typedef struct SDS_MEMBLK	SDS_MEMBLK;
typedef struct SDS_MEMBLK	*SDMEMBLK;		/*	�������u���b�N�n���h��  */

/*
 *	�|�[�g�n���h���^��`
 */
struct SDS_PORT_REF
{
	Void	*m_Ref;	/*	���e�͉B�����Ă���̂Œ��ڑ���͕ۏ؂��܂���  */
};
typedef struct SDS_PORT_REF	SDS_PORT_REF;
typedef struct SDS_PORT_REF	*SDHANDLE;

typedef SDHANDLE	*SDMIDI;	/*	MIDI�|�[�g�n���h��  */
typedef SDHANDLE	*SDSHOT;	/*	One Shot�|�[�g�n���h��  */
typedef SDHANDLE	*SDPSTM;	/*	PCM Stream�|�[�g�n���h��  */

/*****************************************************
 *
 *	�v���g�^�C�v�錾
 *
 */
/*
 *	�T�E���h�V�X�e��API
 *	Sound System API
 */
EXTERN SDE_ERR	sdDrvCheckExecute( Void);
EXTERN SDE_ERR	sdDrvGetExecuteCounter( Uint32 *count_num);
EXTERN SDE_ERR	sdDrvDownloadFromFile( const char *file_name, SDMEMBLK work_memblk);
EXTERN SDE_ERR	sdDrvGetErr( Uint32 *err);
EXTERN SDE_ERR	sdDrvGetVer( SDS_VER *drv_ver);
EXTERN SDE_ERR	sdDrvInit( SDMEMBLK handle);
EXTERN SDE_ERR	sdLibGetVer( SDS_VER *lib_ver);
EXTERN SDE_ERR	sdLibInit( Void *wrk_ptr, Sint32 mem_blk_handle_max, Sint32 second_host_cmd_max);
EXTERN SDE_ERR	sdSysFinish( Void);
EXTERN SDE_ERR	sdSysFlushHostCmd( Void);
EXTERN SDE_ERR	sdSysServer( Void);
EXTERN SDE_ERR	sdSysSetSlotMax( const Sint32 midi_slot_max, const Sint32 shot_slot_max, const Sint32 pstm_slot_max);

/*
 *	�O���[�o���T�E���h�R���g���[��API
 *	Global Sound Control API
 */
EXTERN SDE_ERR	sdSndSetMasterVol( const Sint8 vol);
EXTERN SDE_ERR	sdSndSetPanMode( const SDE_PAN_MODE pan_mode);
EXTERN SDE_ERR	sdSndSetFxPrg( const Sint8 new_fx_prg_num, const Sint8 new_fx_out_num);
EXTERN SDE_ERR	sdSndSetFxOutPrm( const Sint8 out_num, const Sint8 out_pan, const Sint8 out_lev);
EXTERN SDE_ERR	sdSndGetFxPrg( Sint8 *cur_fx_prg_num);
EXTERN SDE_ERR	sdSndGetPanMode( SDE_PAN_MODE *cur_pan_mode);
EXTERN SDE_ERR	sdSndClearFxPrg( Void);
EXTERN SDE_ERR	sdSndSetFxOut( Sint8 const new_fx_out_num);
EXTERN SDE_ERR	sdSndGetFxOut( Sint8 *cur_fx_out_num);
EXTERN SDE_ERR	sdSndStopAll( Void);
EXTERN SDE_ERR	sdQsndSetPos( const Sint8 *pos);

/*
 *	�T�E���h�f�[�^���[�e�B���e�BAPI
 *	Sound Data Utility API
 */
EXTERN SDE_ERR	sdMultiUnitDownload( SDMEMBLK handle);
EXTERN SDE_ERR	sdMultiUnitDownloadFromFile( char *file_name, SDMEMBLK work_memblk);
EXTERN SDE_ERR	sdBankDownload( SDMEMBLK handle, const SDE_DATA_TYPE bank_type, const Sint8 bank_num);
EXTERN SDE_ERR	sdBankDownloadFromFile( char *file_name, const SDE_DATA_TYPE bank_type, const Sint8 bank_num, SDMEMBLK work_memblk);

/*
 *	�T�E���h�������R���g���[��API
 *	Sound Memory Control API
 *
 */
EXTERN SDE_ERR	sdSndMemGetBankStat( const SDE_DATA_TYPE data_type, const Sint8 bank_num, Sint32 *allocate_ptr, Sint32 *allocate_size);
EXTERN SDE_ERR	sdSndMemClearBankStatAll( Void);

/*
 *	�������u���b�N�]��API
 *	Memory Block Transfer API
 */
EXTERN SDE_ERR	sdMemBlkCheck( SDMEMBLK handle);
EXTERN SDE_ERR	sdMemBlkCreate( SDMEMBLK *handle);
EXTERN SDE_ERR	sdMemBlkDestroy( SDMEMBLK handle);
EXTERN SDE_ERR	sdMemBlkSetPrm( SDMEMBLK handle, const Void *src_blk_ptr, const Sint32 src_blk_sz, const SD_MEMBLK_CALLBACK_FUNC callback_func, const Void *callback_first_arg);
EXTERN SDE_ERR	sdMemBlkGetStat( SDMEMBLK handle, SDE_MEMBLK_STAT *stat);
EXTERN SDE_ERR	sdMemBlkTransfer( SDMEMBLK handle, Sint32 dst_adr);
EXTERN SDE_ERR	sdMemBlkSetTransferMode( SDE_MEMBLK_TRANSFER_MODE transfer_mode);

/*
 *	�T�E���h���W���[���R���g���[��API
 */
/*	MIDI�|�[�g  */
EXTERN SDE_ERR	sdMidiClosePort( SDMIDI handle);
EXTERN SDE_ERR	sdMidiContinue( SDMIDI handle);
EXTERN SDE_ERR	sdMidiGetCurAdr( SDMIDI handle, Sint32 *cur_adr);
EXTERN SDE_ERR	sdMidiGetStat( SDMIDI handle, SDS_MIDI_STAT *midi_stat);
EXTERN SDE_ERR	sdMidiGetTimmingFlg( SDMIDI handle, Sint8 *num);
EXTERN SDE_ERR	sdMidiGetTotalBeatTime( SDMIDI handle, Uint32 *cur_beat_time);
EXTERN SDE_ERR	sdMidiOpenPort( SDMIDI *handle);
EXTERN SDE_ERR	sdMidiPause( SDMIDI handle);
EXTERN SDE_ERR	sdMidiPlay( SDMIDI handle, const Sint8 bank_num, const Sint8 data_num, const Sint8 priority);
EXTERN SDE_ERR	sdMidiResetPrm( SDMIDI handle);
EXTERN SDE_ERR	sdMidiResetAllPrm( Void);
EXTERN SDE_ERR	sdMidiSendMes( SDMIDI handle, const SDS_MIDI_MES *midi_mes_ptr, const Sint8 priority);
EXTERN SDE_ERR	sdMidiSetDrctLev( SDMIDI handle, const Sint8 lev);
EXTERN SDE_ERR	sdMidiSetFxLev( SDMIDI handle, const Sint8 fx_lev);
EXTERN SDE_ERR	sdMidiSetGmMode( SDMIDI handle, const SDE_MIDI_GM_MODE gm_mode);
EXTERN SDE_ERR	sdMidiSetMes( SDMIDI handle, SDS_MIDI_MES *midi_mes_ptr, const Uint8 midi_mes,... );
EXTERN SDE_ERR	sdMidiSetMuteChMask( SDMIDI handle, const Uint16 mask);
EXTERN SDE_ERR	sdMidiSetPan( SDMIDI handle, const Sint8 pan, const Sint32 fade_time);
EXTERN SDE_ERR	sdMidiSetPitch( SDMIDI handle, const Sint16 pitch, const Sint32 fade_time);
EXTERN SDE_ERR	sdMidiSetSpeed( SDMIDI handle, const Sint16 speed, const Sint32 fade_time);
EXTERN SDE_ERR	sdMidiSetReleaseMode( SDMIDI handle, SDE_PORT_RELEASE_MODE release_mode);
EXTERN SDE_ERR	sdMidiSetVol( SDMIDI handle, const Sint8 vol, const Sint32 fade_time);
EXTERN SDE_ERR	sdMidiStop( SDMIDI handle);
EXTERN SDE_ERR	sdMidiStopAll( Void);

/*	One Shot�|�[�g  */
EXTERN SDE_ERR	sdShotClosePort( SDSHOT handle);
EXTERN SDE_ERR	sdShotGetCurAdr( SDSHOT handle, Sint32 *cur_smp_adr);
EXTERN SDE_ERR	sdShotGetStat( SDSHOT handle, SDS_SHOT_STAT *shot_stat);
EXTERN SDE_ERR	sdShotGetTotalSmpFrame( SDSHOT handle, Uint32 *cur_smp_frame);
EXTERN SDE_ERR	sdShotOpenPort( SDSHOT *handle);
EXTERN SDE_ERR	sdShotPlay( SDSHOT handle, const Sint8 bank_num, const Sint8 data_num, const Sint8 priority);
EXTERN SDE_ERR	sdShotResetPrm( SDSHOT handle);
EXTERN SDE_ERR	sdShotResetAllPrm( Void);
EXTERN SDE_ERR	sdShotSetDrctLev( SDSHOT handle, const Sint8 drct_lev);
EXTERN SDE_ERR	sdShotSetFxCh( SDSHOT handle, const Sint8 fx_in_ch, const Sint8 fx_base_lev);
EXTERN SDE_ERR	sdShotSetFxLev( SDSHOT handle, const Sint8 fx_lev);
EXTERN SDE_ERR	sdShotSetPan( SDSHOT handle, const Sint8 pan, const Sint32 fade_time);
EXTERN SDE_ERR	sdShotSetPitch( SDSHOT handle, const Sint16 pitch, const Sint32 fade_time);
EXTERN SDE_ERR	sdShotSetPlayTime( SDSHOT handle, const SDE_SHOT_PLAY_TIME scale_type, Sint32 time_value);
EXTERN SDE_ERR	sdShotSetReleaseMode( SDSHOT handle, SDE_PORT_RELEASE_MODE release_mode);
EXTERN SDE_ERR	sdShotSetVol( SDSHOT handle, const Sint8 vol, const Sint32 fade_time);
EXTERN SDE_ERR	sdShotStop( SDSHOT handle);
EXTERN SDE_ERR	sdShotStopAll( Void);

/*	PCM Stream�|�[�g  */
EXTERN SDE_ERR	sdPstmClosePort( SDPSTM handle);
EXTERN SDE_ERR	sdPstmGetCurAdr( SDPSTM handle, const Sint8 target_slot, Sint32 *cur_smp_adr);
EXTERN SDE_ERR	sdPstmGetStat( SDPSTM handle, const Sint8 target_slot, SDS_PSTM_STAT *pstm_stat);
EXTERN SDE_ERR	sdPstmGetTotalSmpFrame( SDPSTM handle, const Sint8 target_slot, Uint32 *cur_smp_frame);
EXTERN SDE_ERR	sdPstmGetNextTransferWaveDataAdr( SDPSTM handle, const Sint8 target_slot, Sint32 *adr);
EXTERN SDE_ERR	sdPstmIsTransferWaveData( SDPSTM handle, const Sint8 target_slot, const Sint32 data_sz, Bool *flg);
EXTERN SDE_ERR	sdPstmOpenPort( SDPSTM *handle, const Sint8 use_slot_num, ...);
EXTERN SDE_ERR	sdPstmPlay( SDPSTM handle, const SDE_PCM_TYPE pcm_type, const Uint16 freq);
EXTERN SDE_ERR	sdPstmOnMemPlay( SDPSTM handle, const SDE_PCM_TYPE pcm_type, const Uint16 pcm_freq, const Sint32 transfer_sz, const Bool loop_flg);
EXTERN SDE_ERR	sdPstmOnMemSetWaveData( SDPSTM handle, const Sint8 target_slot, SDMEMBLK src_handle);
EXTERN SDE_ERR	sdPstmResetPrm( SDPSTM handle, const Sint8 target_slot);
EXTERN SDE_ERR	sdPstmResetAllPrm( Void);
EXTERN SDE_ERR	sdPstmTransferWaveData( SDPSTM handle, const Sint8 target_slot, SDMEMBLK memblk);
EXTERN SDE_ERR	sdPstmSetBasePrm( SDPSTM handle, const Sint8 target_slot, const Sint8 base_vol, const Sint8 base_pan, const Sint8 fx_in_ch, const Sint8 base_fx_lev, const Sint8 base_drct_lev, const Sint16 base_filter_lev, const Sint8 base_filter_q);
EXTERN SDE_ERR	sdPstmSetDrctLev( SDPSTM handle, const Sint8 target_slot, const Sint8 drct_lev);
EXTERN SDE_ERR	sdPstmSetFxCh( SDPSTM handle, const Sint8 target_slot, const Sint8 fx_in_ch, const Sint8 fx_base_lev);
EXTERN SDE_ERR	sdPstmSetFxLev( SDPSTM handle, const Sint8 target_slot, const Sint8 fx_lev);
EXTERN SDE_ERR	sdPstmSetPan( SDPSTM handle, const Sint8 target_slot, const Sint8 pan, const Sint32 fade_time);
EXTERN SDE_ERR	sdPstmSetPitch( SDPSTM handle, const Sint8 target_slot, const Sint16 pitch, const Sint32 fade_time);
EXTERN SDE_ERR	sdPstmSetUseSlotNum( SDPSTM handle, const Sint8 use_slot_num);
EXTERN SDE_ERR	sdPstmSetVol( SDPSTM handle, const Sint8 target_slot, const Sint8 vol, const Sint32 fade_time);
EXTERN SDE_ERR	sdPstmStop( SDPSTM handle);
EXTERN SDE_ERR	sdPstmStopAll( Void);

/*	GD-DA  */
EXTERN SDE_ERR	sdGddaGetStat( SDS_GDDA_STAT *stat);
EXTERN SDE_ERR	sdGddaResetPrm( Void);
EXTERN SDE_ERR	sdGddaSetPan( const Sint8 left_pan, const Sint8 right_pan);
EXTERN SDE_ERR	sdGddaSetVol( const Sint8 left_vol, const Sint8 right_vol);

/*****************************************************
 *
 *	�O���ϐ��錾
 *
 */

#endif	/*	#ifndef	_SG_SD2_H_  */

/*EOF*/
