/******************************************************************************
 *
 * dbdebug.h - �f�o�b�O�o�͊֐��̐錾
 *
 * -- ���쌠�\�� --
 *
 *  Copyright(C) 1997 by ACCESS Co.,Ltd.
 *  All right reseved.
 *
 * -- �ύX�L�^ --
 *
 *  $Log: /NetFront/TCP/dm_sdk/dmcast/dbdebug.h $
 * 
 * 1     98/10/26 14:53 Ueda
 * make branch dream-cast SDK
 * 
 * 1     98/08/19 18:33 Kawaguti
 *
 *****************************************************************************/
#ifdef __cplusplus /* Support for C++ */
extern "C" {
#endif /* __cplusplus */

#if !defined(DBDEBUG_H)
#define DBDEBUG_H

/*
 * �f�o�b�O�o�͉ۃt���O
 *
 * �f�o�b�O�o�͂��s���ꍇ��1�Ƃ���B�s��Ȃ��ꍇ��,0�B
 */
extern int dbDebug;

/* �g���[�X��\������ */
#define DB_DEBUG_TRACE (0x00000001)

/* TCP�̃f�o�b�O���b�Z�[�W��\������ */
#define DB_DEBUG_TCP (0x00000002)

/* PPP�̃f�o�b�O���b�Z�[�W��\������ */
#define DB_DEBUG_PPP        (0x00000004)
#define DB_DEBUG_PPP_PACKET (0x00000008)

/* DNS�̃f�o�b�O���b�Z�[�W��\������ */
#define DB_DEBUG_DNS (0x00000010)

/*
 * �O�����J����֐��̒�`�Z�N�V����
 */

/******************************************************************************
 * dbInit - �f�o�b�O�o�͂̏�����
 *****************************************************************************/

extern void
dbInit(void);

/******************************************************************************
 * dbPrint - �f�o�b�O�\��
 *****************************************************************************/

extern void
dbPrint(int in_patt, char *in_format, ...);

/******************************************************************************
 * DB_TRACE - �g���[�X�}�N��
 *****************************************************************************/

#define DB_TRACE dbPrint(DB_DEBUG_TRACE, "DEBUG: %s(%d)\n",__FILE__,__LINE__)

#endif /* !defined(DEDEBUG_H) */
#ifdef __cplusplus

} /* End of extern "C" { */
#endif /* __cplusplus */
/*****************************************************************************/
/* Mule�̐ݒ�(�K���e�s��1�s�R�����g�łȂ���ΔF������Ȃ��̂Œ���) */
/* Local Variables: */
/* mode: c */
/* tab-width: 4 */
/*****************************************************************************/
