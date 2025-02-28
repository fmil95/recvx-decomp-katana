/****************************************************
 *													*
 *	Dreamcast G2 Library							*
 *			Library Development Kit					*
 *													*
 *			Copyright 1998 (C)SEGA Enterprises		*
 *			Programmed By T.Jokagi					*
 *													*
 ****************************************************/

#ifndef	_SG_SYG2_H_
#define	_SG_SYG2_H_

#include	<sg_xpt.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*****************************************************
 *
 *	�萔��`
 *
 */

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
enum SYE_G2_ERR
{
	SYE_G2_ERR_NOTHING				= 0x00000000,	/*	�G���[����  */
	SYE_G2_ERR_MODE_ILLEGAL			= 0x00010010,	/*	DMA�̃��[�h�w�肪�ȏ�  */
	SYE_G2_ERR_G2_ADR_NULL			= 0x00020000,	/*	G2�A�h���X�w�肪NULL  */
	SYE_G2_ERR_G2_ADR_ILLEGAL		= 0x00020001,	/*	G2�A�h���X�w�肪�ُ�  */
	SYE_G2_ERR_ROOT_BUS_ADR_NULL	= 0x00030000,	/*	G2�A�h���X�w�肪NULL  */
	SYE_G2_ERR_ROOT_BUS_ADR_ILLEGAL	= 0x00030001,	/*	G2�A�h���X�w�肪�ُ�  */
	SYE_G2_ERR_DMA_ALREADY_OPEN		= 0x00090101,	/*	G2 DMA�͎g�p��  */
	SYE_G2_ERR_DMA_NOT_OPEN			= 0x00090102,	/*	G2 DMA�͖��g�p  */
	SYE_G2_ERR_DMA_SUSPEND			= 0x00090140,	/*	G2 DMA�̓T�X�y���h��  */
	SYE_G2_ERR_DMA_BUSY				= 0x00090180,	/*	G2 DMA�͓��쒆  */
	SYE_G2_ERR_UNKNOW				= 0x7FFFFFFF	/*	���m�̃G���[  */
};
typedef enum SYE_G2_ERR	SYE_G2_ERR;

enum SYE_G2_DATA_WIDTH
{
	SYE_G2_DATA_WIDTH_8BIT	= 0x01,		/*	�f�[�^��8�r�b�g��  */
	SYE_G2_DATA_WIDTH_16BIT	= 0x02,		/*	�f�[�^��16�r�b�g��  */
	SYE_G2_DATA_WIDTH_32BIT	= 0x04		/*	�f�[�^��32�r�b�g��  */
};
typedef enum SYE_G2_DATA_WIDTH	SYE_G2_DATA_WIDTH;

enum SYE_G2_ADR_MODE
{
	SYE_G2_ADR_MODE_FIX,	/*	�A�h���X�Œ�  */
	SYE_G2_ADR_MODE_ADD,	/*	�A�h���X���Z  */
	SYE_G2_ADR_MODE_SUB		/*	�A�h���X���Z  */
};
typedef enum SYE_G2_ADR_MODE	SYE_G2_ADR_MODE;

/*******************************************
 *
 *	DMA�`�����l����`
 */
enum SYE_G2_DMA_TYPE
{
	SYE_G2_DMA_TYPE_AICA,	/*	AICA DMA	*/
	SYE_G2_DMA_TYPE_EXT0,	/*	EXT0 DMA	*/
	SYE_G2_DMA_TYPE_EXT1,	/*	EXT1 DMA	*/
	SYE_G2_DMA_TYPE_DEV		/*	Dev DMA		*/
};
typedef enum SYE_G2_DMA_TYPE	SYE_G2_DMA_TYPE;

enum SYE_G2_DMA_DIR
{
	SYE_G2_DMA_DIR_ROOT_TO_G2,		/*	���[�g�o�X����G2�o�X  */
	SYE_G2_DMA_DIR_G2_TO_ROOT		/*	G2�o�X���烋�[�g�o�X  */
};
typedef enum SYE_G2_DMA_DIR	SYE_G2_DMA_DIR;

enum SYE_G2_DMA_TRIGGER
{
	SYE_G2_DMA_TRIGGER_CPU = 0x00000000,	/*	CPU �ɂ�G2 DMA���N��  */
	SYE_G2_DMA_TRIGGER_INT = 0x00000002		/*	���荞�ݐM���ɂ�G2 DMA���N��  */
};
typedef enum SYE_G2_DMA_TRIGGER	SYE_G2_DMA_TRIGGER;

enum SYE_G2_DMA_STAT
{
	SYE_G2_DMA_STAT_STOP,		/*	�~�܂��Ă���  */
	SYE_G2_DMA_STAT_PROGRESS,	/*	���쒆�Ŏ��ۂɓ����Ă���  */
	SYE_G2_DMA_STAT_SUSPEND,	/*	���쒆�ňꎞ��~���Ă���  */
	SYE_G2_DMA_STAT_REMAIN,		/*	�܂������ĂȂ�  */
	SYE_G2_DMA_STAT_FINISHED	/*	�]���͏I��  */
};
typedef enum SYE_G2_DMA_STAT	SYE_G2_DMA_STAT;

/********************************
 *
 *	�P���^�C�v��`
 *
 */
typedef	Void	( *SYE_G2_CALLBACK_FUNC)( Void *arg);

/********************************
 *
 *	�\���̃^�C�v��`
 *
 */
struct SYS_G2_DMA_HANDLE
{
	Void	*m_Member;
};
typedef struct SYS_G2_DMA_HANDLE	*SYG2DMA;

struct SYS_G2_VER
{
	Sint8	m_MajorVer;	/*	���W���[�o�[�W����  */
	Sint8	m_MinorVer;	/*	�}�C�i�[�o�[�W����  */
	Sint8	m_DebugVer;	/*	�f�o�O�o�[�W����  */
	Sint8	rsv;		/*	���U�[�u  */
};
typedef struct SYS_G2_VER	SYS_G2_VER;

/*****************************************************
 *
 *	�v���g�^�C�v�錾
 *
 */
/*
 *	�V�X�e��API
 */
/*	������  */
EXTERN SYE_G2_ERR	syG2SysInit( Void *prm_ptr);
/*	�I��  */
EXTERN SYE_G2_ERR	syG2SysFinish( Void);
/*	�o�[�W�����擾  */
EXTERN SYE_G2_ERR	syG2SysGetVer( SYS_G2_VER *lib_ver);
/*	�����݋֎~�g�p���[�h  */
EXTERN SYE_G2_ERR	syG2SysSetInterruptMask( Bool flg);
/*	���C�u�������U���g�E�H�b�`�ϐ��o�^�i�g���܂���j  */
EXTERN SYE_G2_ERR	syG2SysSetResultWatch( SYE_G2_ERR *result_watch_ptr);

/*
 *	G2�R�����R���g���[��API
 */
/*	G2�o�X�̃X�e�[�^�X�擾  */
EXTERN SYE_G2_ERR	syG2BusGetStat( Uint32 *stat);

/*
 *	SH-4�ł̓ǂݏ���API
 */
/*	SH-4�ł�G2�o�X�̓ǂݍ���  */
EXTERN SYE_G2_ERR	syG2Read( Void *g2_adr, Void *buf_ptr, SYE_G2_DATA_WIDTH data_width, Sint32 data_num, SYE_G2_ADR_MODE src_mode,  SYE_G2_ADR_MODE dst_mode);
/*	SH-4�ł�G2�o�X�̏�������  */
EXTERN SYE_G2_ERR	syG2Write( Void *buf_ptr, Void *g2_adr, SYE_G2_DATA_WIDTH data_width, Sint32 data_num, SYE_G2_ADR_MODE src_mode,  SYE_G2_ADR_MODE dst_mode);

/*
 *	FIFO�֌WAPI
 */
/*	AICA FIFO�̏�Ԏ擾  */
EXTERN SYE_G2_ERR	syG2AicaFifoIsEmpty( Bool *flg);
/*	G2 FIFO�̏�Ԏ擾  */
EXTERN SYE_G2_ERR	syG2FifoIsEmpty( Bool *flg);
/*	AICA FIFO�̃G���v�e�B�҂�  */
EXTERN SYE_G2_ERR	syG2AicaFifoWaitEmpty( Void);
/*	AICA FIFO�̃G���v�e�B�҂��񐔂̎擾  */
EXTERN SYE_G2_ERR	syG2AicaFifoGetWaitCounter( Uint32 *count_num);
/*	G2 FIFO�̃G���v�e�B�҂�  */
EXTERN SYE_G2_ERR	syG2FifoWaitEmpty( Void);
/*	G2 FIFO�̃G���v�e�B�҂��񐔂̎擾  */
EXTERN SYE_G2_ERR	syG2FifoGetWaitCounter( Uint32 *count_num);

/*
 *	G2 DMA�֌WAPI
 */
/*	G2 DMA�A�N�Z�X���擾  */
EXTERN SYE_G2_ERR	syG2DmaOpen( SYG2DMA *handle, SYE_G2_DMA_TYPE);
/*	G2 DMA�A�N�Z�X���J��  */
EXTERN SYE_G2_ERR	syG2DmaClose( SYG2DMA handle);
/*	G2 DMA�p�����[�^�ݒ�  */
EXTERN SYE_G2_ERR	syG2DmaSetPrm( SYG2DMA handle, Void *g2_adr, Void *root_bus_adr, Sint32 sz, SYE_G2_DMA_DIR dir, Bool transfer_ctl, Bool suspend_mode, SYE_G2_CALLBACK_FUNC callback, Void *callback_1st_arg);
/*	G2 DMA�X�e�[�^�X�擾  */
EXTERN SYE_G2_ERR	syG2DmaGetStat( SYG2DMA handle, SYE_G2_DMA_STAT *dma_stat);
/*	G2 DMA�g���K  */
EXTERN SYE_G2_ERR	syG2DmaTrigger( SYG2DMA handle, SYE_G2_DMA_TRIGGER triger_mode);
/*	G2 DMA�ꎞ��~  */
EXTERN SYE_G2_ERR	syG2DmaSuspend( SYG2DMA handle);
/*	�S�Ă�G2 DMA�ꎞ��~  */
EXTERN SYE_G2_ERR	syG2DmaSuspendAll( Void);
/*	G2 DMA��~  */
EXTERN SYE_G2_ERR	syG2DmaStop( SYG2DMA handle);
/*	�S�Ă�G2 DMA��~  */
EXTERN SYE_G2_ERR	syG2DmaStopAll( Void);
/*	G2 DMA�ꎞ��~����  */
EXTERN SYE_G2_ERR	syG2DmaResume( SYG2DMA handle);
/*	�S�Ă�G2 DMA�ꎞ��~����  */
EXTERN SYE_G2_ERR	syG2DmaResumeAll( Void);
/*	DMA���N�������ǂ����`�F�b�N  */
EXTERN SYE_G2_ERR	syG2DmaIsBusy( SYG2DMA handle, Bool *flg);
/*	G2 DMA�̋N���񐔂̎擾  */
EXTERN SYE_G2_ERR	syG2DmaGetTriggerCounter( SYE_G2_DMA_TYPE type, Uint32 *counter);
/*	G2 DMA�̏I�����荞�݉񐔂̎擾  */
EXTERN SYE_G2_ERR	syG2DmaGetEndCounter( SYE_G2_DMA_TYPE type, Uint32 *counter);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	/*	#ifndef	_SG_SYG2_H_  */

/*****************************************************
 *
 *	�O���ϐ��錾
 *
 */

/*EOF*/