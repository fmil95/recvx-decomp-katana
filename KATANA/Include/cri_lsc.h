#ifndef	_CRI_LSC_H_INCLUDED
#define	_CRI_LSC_H_INCLUDED
/****************************************************************************/
/*																			*/
/*			$title$ �A���X�g���[���R���g���[�� ���C�u����					*/
/*				LSC (Linking Stream Controller) Library						*/
/*																			*/
/*			Copyright (c) 1999 CSK Research Institute						*/
/*				1998.7.12		written by S.Hosaka							*/
/*																			*/
/****************************************************************************/

/****************************************************************************/
/*	�C���N���[�h�t�@�C��													*/
/****************************************************************************/

#include	<sj.h>

/****************************************************************************/
/*	�萔�}�N��																*/
/****************************************************************************/

/*	Version No.					*/
#define	LSC_VER				"0.90"

/*	�ő�X�g���[����			*/
#define	LSC_STM_MAX			(16)

/*	�n���h���̌�				*/
#define	LSC_OBJ_MAX			(4)

/*	�t�@�C�����̍ő啶����		*/
#define	LSC_FNAME_MAX		(32)

/*	������					*/
#define	LSC_STAT_STOP		(0)
#define	LSC_STAT_WAIT		(1)
#define	LSC_STAT_EXEC		(2)
#define	LSC_STAT_ERR		(3)

/*	�X�g���[���ǂݍ��݂̏��	*/
#define	LSC_STM_STAT_WAIT	(0)
#define	LSC_STM_STAT_READ	(1)
#define	LSC_STM_STAT_END	(2)

/****************************************************************************/
/*	�񋓒萔																*/
/****************************************************************************/

/****************************************************************************/
/*	�����}�N��																*/
/****************************************************************************/

/****************************************************************************/
/*	�f�[�^�^																*/
/****************************************************************************/

/*	�G���[�o�^�֐�				*/
typedef void (*LSC_ERRFN)(void *obj, char *msg);
typedef void (*LSC_STATFN)(void *obj1, void *obj2);

/*	�X�g���[�����				*/
#ifndef LSC_SINFO_DEFINED
#define LSC_SINFO_DEFINED
typedef struct _lsc_sinfo {
	long		sid;						/*	�X�g���[��ID				*/
	char		fname[LSC_FNAME_MAX];		/*	�t�@�C����					*/
	long		stat;						/*	�X�g���[���̓ǂݍ��ݏ��	*/
	long		rdsct;						/*	�ǂݍ��݃Z�N�^��			*/
} LSC_SINFO;
#endif

#ifndef LSC_FP_DEFINED
#define LSC_FP_DEFINED
typedef void	*LSC_FP;
#endif

/*	�n���h��					*/
#ifndef LSC_DEFINED
#define LSC_DEFINED
typedef struct _lsc_obj {
	long		used;						/*	�g�p�����ۂ�				*/
	SJ			sj;							/*	�X�g���[���W���C���g		*/
	SJCK		ck;
	long		stat;						/*	�n���h�����				*/
	long		bufmin;						/*	�o�b�t�@���ʉ����l			*/
	long		bsize;
	long		wpos;
	long		rpos;
	long		nstm;						/*	�o�^�X�g���[����			*/
	long		pause;
	LSC_FP		fp;
	long		fsct;
	long		reqsct;
	long		rdflg;
	LSC_SINFO	sinfo[LSC_STM_MAX];			/*	�ǂݍ��ݒ��̃X�g���[�����	*/
} LSC_OBJ;
typedef LSC_OBJ *LSC;
#endif

/****************************************************************************/
/*	�ϐ��錾																*/
/****************************************************************************/

/****************************************************************************/
/*	�֐��錾																*/
/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*	������					*/
void LSC_Init(void);

/*	�I������				*/
void LSC_Finish(void);

/*	�G���[�����֐��̓o�^	*/
void LSC_EntryErrFunc(LSC_ERRFN errfn, void *obj);

/*	�n���h���̐���			*/
LSC LSC_Create(SJ sj);

/*	�n���h���̏���			*/
void LSC_Destroy(LSC lsc);

/*	�X�g���[���̓o�^		*/
long LSC_EntryFname(LSC lsc, char *fname);

/*	�ǂݍ��݊J�n			*/
void LSC_Start(LSC lsc);

/*	�ǂݍ��ݒ�~			*/
void LSC_Stop(LSC lsc);

/*	�|�[�Y�E�|�[�Y����		*/
void LSC_Pause(LSC lsc, long sw);

/*	�T�[�o�֐�				*/
void LSC_ExecServer(void);

/*	�n���h����Ԃ̎擾		*/
long LSC_GetStat(LSC lsc);

/*	�o�^�X�g���[�����̎擾	*/
long LSC_GetNumStm(LSC lsc);

/*	�ǂݍ��ݒ��̃X�g���[��ID�̎擾	*/
long LSC_GetStmId(LSC lsc, long no);

/*	�t�@�C�����̎擾	*/
char *LSC_GetStmFname(LSC lsc, long sid);

/*	�X�g���[���ǂݍ��݂̏�Ԏ擾	*/
long LSC_GetStmStat(LSC lsc, long sid);

/*	�ǂݍ��񂾃f�[�^�T�C�Y�̎擾(sector)	*/
long LSC_GetStmRdSct(LSC lsc, long sid);

/*	�o�b�t�@���ʉ����l�̐ݒ�	*/
void LSC_SetFlowLimit(LSC lsc, long min);

/*	�o�b�t�@���ʉ����l�̎擾	*/
long LSC_GetFlowLimit(LSC lsc);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif	/* _CRI_LSC_H_INCLUDED */
