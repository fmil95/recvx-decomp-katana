/*
	Nindows Library

	COPYRIGHT (C) SEGA ENTERSRISES,LTD.
*/


#ifndef _NINDOWS_H_
#define _NINDOWS_H_

#ifdef __cplusplus
extern "C"{
#endif

#include <Ninja.h>

/*--------------------------------------*/
/*      System Information              */
/*--------------------------------------*/
#define NWD_SM_CXSIZEFRAME  2           /* THICKFRAME�̃t���[���̕�         */
#define NWD_SM_CYSIZEFRAME  2           /* THICKFRAME�̃t���[���̍���       */
#define NWD_SM_CXBORDER     1           /* �V���O���{�[�_�[�̕�             */
#define NWD_SM_CYBORDER     1           /* �V���O���{�[�_�[�̍���           */
#define NWD_SM_CXMINTRACK   32          /* �ŏ��̃E�B���h�E�̕�             */
#define NWD_SM_CYMINTRACK   10          /* �ŏ��̃E�B���h�E�̍���           */
#define NWD_SM_CYCAPTION    20          /* �L���v�V�����̍���               */
#define NWD_SM_SZCAPTION    16          /* �L���v�V�����̍���               */
#define NWD_SM_CXSHADOW     8           /* �e�̂�����                     */
#define NWD_SM_CYSHADOW     8           /* �e�̂�����                     */

/*--------------------------------------*/
/*      Window Style                    */
/*--------------------------------------*/
#define NWD_WS_CAPTION      0x00000001  /* �L���v�V��������                 */
#define NWD_WS_THICKFRAME   0x00000002  /* �t���[����                     */
#define NWD_WS_BORDER       0x00000004  /* ���E�������E�B���h�E           */
#define NWD_WS_SHADING      0x00000008  /* �V�F�[�f�B���O����               */
#define NWD_WS_CONTROL      0x00000010  /* �N���[�Y�{�b�N�X����             */
#define NWD_WS_OFFSET       0x00000020  /* �e�E�B���h�E�Ƃ̑��΍��W���g�p   */
#define NWD_WS_SHADOW       0x00000040  /* �e�t���E�B���h�E                 */
#define NWD_WS_INVISIBLE    0x00000080  /* �`��Ȃ��E�B���h�E               */
#define NWD_WS_NOMOVE       0x00000100  /* �}�E�X�ł̈ړ������Ȃ�           */

#define NWD_WS_CLOSEBOX     NWD_WS_CONTROL
#define NWD_WS_MAXIMIZEBOX  0x00000200  /* �ő剻�{�b�N�X������             */
#define NWD_WS_MINIMIZEBOX  0x00000400  /* �ŏ����{�b�N�X������             */

#define NWD_WS_SB_HORZ      0x00001000  /* �����X�N���[���o�[               */
#define NWD_WS_SB_VERT      0x00002000  /* �����X�N���[���o�[               */

#define NWD_WS_CLOSE        0x80000000  /* �E�B���h�E�I���v��               */

/*--------------------------------------*/
/*      Window Class                    */
/*--------------------------------------*/
enum {
	NWD_WC_WIN,                         /* �ʏ�̃E�B���h�E             */
	NWD_WC_BUTTON,                      /* �{�^��                       */
	NWD_WC_SCRBAR,                      /* �X�N���[���o�[               */
	NWD_WC_SCRWIN,                      /* �X�N���[���E�B���h�E         */
	NWD_WC_EDITWIN,                     /* �G�f�B�b�g�E�B���h�E         */
	NWD_WC_MENUWIN,                     /* ���j���[�E�B���h�E           */

	NWD_WC_CTLBOX                       /* �R���g���[���{�b�N�X         */
};

/*--------------------------------------*/
/*      Button Status                   */
/*--------------------------------------*/
#define NWD_BS_DOWN         0x00000001      /* �{�^����������Ă���         */
#define NWD_BS_INVOKED      0x00000100      /* �{�^���̋@�\���I�����ꂽ     */
#define NWD_BS_GRAYED       0x00000002      /* �I���ł��Ȃ����             */

/*--------------------------------------*/
/*      Mouse Status                    */
/*--------------------------------------*/
#define NWD_MS_MOVE         0x00010000      /* �}�E�X���ړ�����             */

#define NWD_MS_BUTTON       0x000f          /* �{�^���������ꂽ             */
#define NWD_MS_LBUTTON      0x0001          /* ���{�^����������Ă���       */
#define NWD_MS_RBUTTON      0x0002          /* �E�{�^����������Ă���       */
#define NWD_MS_MBUTTON      0x0004          /* ���{�^����������Ă���       */

#define NWD_MS_BUTTONDOWN   0x00f0          /* �{�^�����J�����ꂽ           */
#define NWD_MS_LBUTTONDOWN  0x0010          /* ���{�^�����N���b�N���ꂽ     */
#define NWD_MS_RBUTTONDOWN  0x0020          /* �E�{�^�����N���b�N���ꂽ     */
#define NWD_MS_MBUTTONDOWN  0x0040          /* ���{�^�����N���b�N���ꂽ     */
#define NWD_MS_BUTTONUP     0x0f00          /* �{�^�����J�����ꂽ           */
#define NWD_MS_LBUTTONUP    0x0100          /* ���{�^�����J�����ꂽ         */
#define NWD_MS_RBUTTONUP    0x0200          /* �E�{�^�����J�����ꂽ         */
#define NWD_MS_MBUTTONUP    0x0400          /* ���{�^�����J�����ꂽ         */

#define NWD_MS_LBUTTONUP    0x0100          /* ���{�^�����J�����ꂽ         */
#define NWD_MS_RBUTTONUP    0x0200          /* �E�{�^�����J�����ꂽ         */
#define NWD_MS_MBUTTONUP    0x0400          /* ���{�^�����J�����ꂽ         */

#define NWD_MS_CONTROL      0x1000          /* �R���g���[���L�[�������ꂽ   */
#define NWD_MS_SHIFT        0x2000          /* �V�t�g�L�[�������ꂽ         */

/* �}�E�X�J�[�\���̌`�� */
#define NWD_MCS_DRAG        0x40000000      /* �E�B���h�E���ړ��ł���       */
#define NWD_MCS_RESIZE      0x20000000      /* �E�B���h�E���T�C�Y�ύX�ł��� */
#define NWD_MCS_AREAMASK    0x0000ffff      /*                              */

#define NWD_MCS_AREAFRAMET      0x0001      /* �E�B���h�E�t���[���̏�       */
#define NWD_MCS_AREAFRAMELT     0x0002      /* �E�B���h�E�t���[���̍���     */
#define NWD_MCS_AREAFRAMEL      0x0003      /* �E�B���h�E�t���[���̍�       */
#define NWD_MCS_AREAFRAMELB     0x0004      /* �E�B���h�E�t���[���̍���     */
#define NWD_MCS_AREAFRAMEB      0x0005      /* �E�B���h�E�t���[���̉�       */
#define NWD_MCS_AREAFRAMERB     0x0006      /* �E�B���h�E�t���[���̉E��     */
#define NWD_MCS_AREAFRAMER      0x0007      /* �E�B���h�E�t���[���̉E       */
#define NWD_MCS_AREAFRAMERT     0x0008      /* �E�B���h�E�t���[���̉E��     */
#define NWD_MCS_AREACLIENT      0x0009      /* �E�B���h�E�N���C�A���g       */
#define NWD_MCS_AREACAPTION     0x000a      /* �E�B���h�E�L���v�V����       */

/* �X�N���[���E�B���h�E�̃t���O */
#define NWD_ES_HORIZONTAL       0x00000001  /* ���������X�N���[���\       */
#define NWD_ES_VERTICAL         0x00000002  /* ���������X�N���[���\       */
#define NWD_ES_USECLIP          0x00010000  /* �N���b�s���O����             */


/*--------------------------------------*/
/*      Message Type                    */
/*--------------------------------------*/
enum {
	NWD_MSG_NULL,                           /*                              */
	NWD_MSG_ALL,                            /*                              */
	NWD_MSG_CLICK,                          /*                              */
	NWD_MSG_LBUTTONDOWN,                    /*                              */
	NWD_MSG_FOCUS,                          /*                              */
	NWD_MSG_CLOSE                           /*                              */
};

/*--------------------------------------*/
/*      Data Type                       */
/*--------------------------------------*/
enum {
	NWD_DT_CHAR,                            /* �����t���P�o�C�g             */
	NWD_DT_SHORT,                           /* �����t���Q�o�C�g             */
	NWD_DT_INT,                             /* �����t���S�o�C�g             */
	NWD_DT_LONG,                            /* �����t���S�o�C�g             */
	NWD_DT_FLOAT,                           /* �R�Q�r�b�g���������_��       */
	NWD_DT_UCHAR,                           /* �����Ȃ��P�o�C�g             */
	NWD_DT_USHORT,                          /* �����Ȃ��Q�o�C�g             */
	NWD_DT_UINT,                            /* �����Ȃ��S�o�C�g             */
	NWD_DT_ULONG                            /* �����Ȃ��S�o�C�g             */
};

/*--------------------------------------*/
/*      Menu Type                       */
/*--------------------------------------*/
#define NWD_MF_NULL       0x0000            /* ���j���[�^�[�~�l�[�^         */
#define NWD_MF_NORMAL     0x0001            /* �ʏ탁�j���[����             */
#define NWD_MF_SEPARATOR  0x0002            /* �Z�p���[�^                   */
#define NWD_MF_POPUP      0x0004            /* �T�u���j���[                 */
#define NWD_MF_CHECKED    0x8000            /* �`�F�b�N�}�[�N����           */
#define NWD_MF_GRAYED     0x0008            /* �I��s��                     */

/*--------------------------------------*/
/*      Font Size                       */
/*--------------------------------------*/
#define NWD_FONTTYPE_SMALL  1               /*                              */
#define NWD_FONTTYPE_NORMAL 2               /*                              */
#define NWD_FONTTYPE_LARGE  3               /*                              */


/*--------------------------------------*/
/*      Nindows Utility Type            */
/*--------------------------------------*/
#define NWD_DEFWIN_SYSMENU     0            /*                          */
#define NWD_DEFWIN_NINJAINFO   1            /*                          */
#define NWD_DEFWIN_WINDOWINFO  2            /*                          */
#define NWD_DEFWIN_TEXCONTROL  3            /*                          */
#define NWD_DEFWIN_TEXVIEWER   4            /*                          */
#define NWD_DEFWIN_PERINFO     5            /*                          */
#define NWD_DEFWIN_DEBUG       6            /*                          */
#define NWD_DEFWIN_PERFORMANCE 7            /*                          */


/*--------------------------------------*/
/*      Basic Structure                 */
/*--------------------------------------*/
typedef struct _NWS_RGBA {
	Uint8 r;                                /* ��(0-255)                    */
	Uint8 g;                                /* ��(0-255)                    */
	Uint8 b;                                /* ��(0-255)                    */
	Uint8 a;                                /* �����x(0-255) 255:�s����     */
} NWS_RGBA;

typedef struct _NWS_RECT {
	Sint32 left;                            /* ���[                         */
	Sint32 top;                             /* ��[                         */
	Sint32 right;                           /* �E�[                         */
	Sint32 bottom;                          /* ���[                         */
} NWS_RECT;

typedef struct _NWS_RECTF {
	Float left;                             /* ���[                         */
	Float top;                              /* ��[                         */
	Float right;                            /* �E�[                         */
	Float bottom;                           /* ���[                         */
} NWS_RECTF;

typedef struct _NWS_POINT {
	Sint32 x, y;                            /* ���W                         */
} NWS_POINT;

typedef struct _NWS_MOUSE {
	NWS_POINT pt;                           /* ���݂̍��W                   */
	Sint32    dt;                           /* ���݂̏��                   */
	Sint32    cursor;                       /* ���݂̃J�[�\�����           */
	NWS_POINT oldPt;                        /* �̂̍��W                     */
	NWS_POINT mv;                           /* �ړ���                       */
	NWS_POINT dragPt;                       /* �h���b�O�J�n�n�_             */
} NWS_MOUSE;

/*--------------------------------------*/
/*      Basic Macro                     */
/*--------------------------------------*/
#define nwSetRGBA(_d, _r, _g, _b, _a)	\
	((_d)->r = (_r), (_d)->g = (_g), (_d)->b = (_b), (_d)->a = (_a))

#define nwSetRect(a, b , c, d, e)	\
	((a)->left = (b), (a)->top = (c), (a)->right = (d), (a)->bottom = (e))

/*--------------------------------------*/
/*      Message Structure               */
/*--------------------------------------*/
typedef Bool (*NWF_MSGPROC)(Sint32 msg, Sint32 param1, Sint32 param2);

typedef struct _NWS_MSGHANDLE {
	Sint32      msg;                        /*                              */
	NWF_MSGPROC func;                       /*                              */
} NWS_MSGHANDLE;

/*--------------------------------------*/
/*      Data Structure                  */
/*--------------------------------------*/
typedef struct _NWS_DATA {
	void *dt;                               /* �f�[�^�|�C���^               */
	Sint32 type;                            /* �f�[�^�^�C�v                 */
} NWS_DATA;


/*--------------------------------------*/
/*      Window Structure                */
/*--------------------------------------*/
typedef struct _NWS_WIN {
	Sint32 style;                           /* �E�B���h�E�X�^�C��           */
	Sint32 wClass;                          /* �E�B���h�E�̃N���X           */
	char* caption;                          /* �E�B���h�E�L���v�V������     */
	Sint32 font;                            /* �t�H���g�^�C�v               */

	struct _NWS_WIN* parent;                /* �����̐e�E�B���h�E�̃|�C���^ */
	struct _NWS_WIN* child;                 /* �����̎q(��P�q)�E�B���h�E   */
	struct _NWS_WIN* before;                /* �Z��E�B���h�E�̃|�C���^     */
	struct _NWS_WIN* next;                  /* �Z��E�B���h�E�̃|�C���^     */

	Sint32 x, y;                            /* �N���C�A���g�̍��W           */
	Sint32 w, h;                            /* �N���C�A���g�̕��A����       */
/*	Sint32 sx,sy;*/                         /* �N���C�A���g�̃I�t�Z�b�g�ʒu */

	NWS_RGBA col[4];                        /* �E�B���h�E�̐F               */
	NWS_MSGHANDLE* msgHandle;               /* ���b�Z�[�W�̃n���h��         */
	void* menuTable;                        /* ���j���[�e�[�u��             */

	void* userBuf;                          /* ���[�U�[�p�o�b�t�@           */
	void (*clientDraw)(struct _NWS_WIN *NWFUNC);
	                                        /* �N���C�A���g�`��R�[���o�b�N */
	void (*execFunc)(struct _NWS_WIN *NWFUNC);
	                                        /* �E�B�h�E�����p�֐��|�C���^   */
	void (*destructor)(struct _NWS_WIN* NWFUNC);
	                                        /* �E�B���h�E�j�����R�[���o�b�N */
	Sint32 param1, param2;                  /* ���[�U�[�p�p�����[�^         */
	struct _NWS_WIN* hClose;                /* �N���[�Y�{�b�N�X�̃n���h��   */
	struct _NWS_WIN* hMaximize;             /* �ő剻�{�^���̃n���h��       */
	struct _NWS_WIN* hMinimize;             /* �ŏ����{�^���̃n���h��       */
} NWS_WIN;

typedef NWS_WIN* NWHWND;
typedef void (*NWF_BUTTONFUNC)(NWHWND);




/*--------------------------------------*/
/*      Button Structure                */
/*--------------------------------------*/
typedef struct _NWS_BUTTON {
	NWS_WIN         base;                   /* ��{�E�C���h�E               */
	NWF_BUTTONFUNC  func;                   /* �����ꂽ���ɌĂяo���֐�     */
	Sint32          state;                  /* �{�^���̏��                 */
	Sint32          count;                  /* func �̎��s�܂ł̃E�F�C�g    */
} NWS_BUTTON;

/*--------------------------------------*/
/*      ScrollBar Structure             */
/*--------------------------------------*/
typedef struct _NWS_SCRBAR {
	NWS_WIN base;                           /* ��{�E�C���h�E               */
	Float pos;                              /* ���ݒl                       */
	Float min;                              /* �ŏ��l                       */
	Float max;                              /* �ő�l                       */
	Float lineMove;                         /* �ړ��l                       */
	Float pageMove;                         /* �ړ��l                       */
	NWS_DATA dt;                            /* �f�[�^                       */
} NWS_SCRBAR;

typedef struct {
	char* caption;                          /* �L���v�V����                 */
	NWS_DATA data;                          /* �֘A�f�[�^                   */
	Float min, max;                         /* �f�[�^�ő�l�A�ŏ��l         */
	Float line, page;                       /* ���C���ړ��ʁA�y�[�W�ړ���   */
	Float pos;                              /* �f�[�^�����l                 */
} NWS_SCROLLBARINFO;

typedef struct {
	Sint32 n;                               /* �X�N���[���o�[��             */
	Sint32 style;                           /* �X�N���[���o�[�X�^�C��       */
	Sint16 x, y;                            /* ���W                         */
	Sint16 w, h;                            /* �T�C�Y                       */
	NWS_SCROLLBARINFO* info;                /* �X�N���[���o�[���           */
} NWS_SCROLLBARLIST;


/*--------------------------------------*/
/*      Scroll Window Structure         */
/*--------------------------------------*/
typedef struct _NWS_SCRWIN {
	NWS_WIN base;                           /* ��{�E�B���h�E               */
	Sint32 sx, sy;                          /* �X�N���[���|�W�V����         */
	Sint32 flag;                            /* �X�N���[���\�����t���O     */
	NWS_RECT clip;                          /* �X�N���[���\�͈�           */
} NWS_SCRWIN;

/*--------------------------------------*/
/*      Edit Window Structure           */
/*--------------------------------------*/
typedef struct _NWS_EDITLINE {
	struct _NWS_EDITLINE* before;           /* �O�̃��C���ւ̃|�C���^       */
	struct _NWS_EDITLINE* next;             /* ���̃��C���ւ̃|�C���^       */
	Sint8* buf;                             /* �����o�b�t�@�|�C���^         */
	Sint32 len;                             /* ������                       */
} NWS_EDITLINE;

typedef struct _NWS_EDITWIN {
	NWS_SCRWIN base;                        /* ��{�E�B���h�E               */
	Sint32 maxLine;                         /* �ő�s��                     */
	NWS_EDITLINE* lineBuf;                  /* �s�o�b�t�@                   */
	Sint32 lineSum;                         /* ���݂̊m�ۍs��               */
	NWS_EDITLINE* startLine;                /* �ŏ��̍s                     */
	NWS_EDITLINE* curLine;                  /* ���݂̍s                     */
} NWS_EDITWIN;

/*--------------------------------------*/
/*      Menu Handle                     */
/*--------------------------------------*/
typedef void (*NWF_MENUHANDLE)(NWHWND, Sint32 idx, Sint32 param);

/*--------------------------------------*/
/*      Menu Table Structure            */
/*--------------------------------------*/
typedef struct _NWS_MENUTABLE {
	Sint32         type;                    /* ���j���[�^�C�v               */
	char*          title;                   /* ���j���[�^�C�g��             */
	NWF_MENUHANDLE func;                    /* �R�[���o�b�N�֐�             */
	Sint32         param;                   /* �p�����[�^                   */
} NWS_MENUTABLE;


/*--------------------------------------*/
/*      Menu Window Structure           */
/*--------------------------------------*/
typedef struct _NWS_MENUWIN {
	NWS_WIN       base;                     /* ��{�E�B���h�E               */
	Sint32        check;                    /* ���݃`�F�b�N���̍���         */
	NWS_MENUTABLE* menuTable;               /* ���j���[�e�[�u��             */
} NWS_MENUWIN;


/*--------------------------------------*/
/*      Font Structure                  */
/*--------------------------------------*/
typedef struct _NWS_FONT {
	Sint32      baseChar;                   /* ��{����                     */
	Sint32      w,  h;                      /* �����̎��T�C�Y               */
	Sint32      u, v;                       /* ������uv�T�C�Y               */
	Sint32      gw, gh;                     /* �O���b�h�̃T�C�Y             */
	Sint32      dw;                         /* �e�N�X�`���̉�������         */
	NJS_TEXNAME* texname;                   /* �e�N�X�`�����               */
	Uint32      globalIndex;                /* �O���[�o���C���f�b�N�X       */
} NWS_FONT;


/*--------------------------------------*/
/*      Prototypes                      */
/*--------------------------------------*/

/****************************************/
/*      System                          */
/****************************************/

/* #ifdef __SET4__ */
#if 1  /* Modified by H.Hayashi 99/03/04 */

void nwInitSystem(Uint32 numTextures, Uint32 port);
#else
void nwInitSystem(Uint32 numTextures);
#endif
Sint32 nwExecute(void);
void nwExitSystem(void);
void nwInitResource(void);
Uint32 nwVersion(void);
Float nwGetZ(void);
Float nwAddZ(void);

/****************************************/
/*      Menu                            */
/****************************************/
NWHWND nwCreateMenuWindow(NWS_MENUTABLE* menuTbl, const char* caption,
            Sint32 x, Sint32 y, NWHWND parent);

/****************************************/
/*      Font                            */
/****************************************/
void nwTextOut(NWHWND hWnd, Sint32 x, Sint32 y, const char* fmt, ...);
void nwSetTextColor(NWS_RGBA* col);
Sint32 nwGetFontSize(Sint32* width, Sint32* height);
void nwSelectSystemFont(Sint32 fonttype);

/****************************************/
/*      Button                          */
/****************************************/

NWHWND nwCreateButton(NWF_BUTTONFUNC func, const char* title,
	Sint32 x, Sint32 y, Sint32 w, Sint32 h, NWHWND parent);
void nwEnableButton(NWHWND hWnd, Bool flag);

/****************************************/
/*      Scroll Bar                      */
/****************************************/
NWHWND nwCreateScrollBar(Sint32 type, const char* title,
	Sint32 x, Sint32 y, Sint32 w, Sint32 h, NWHWND parent);
void nwSetScrollBarPos(NWHWND hWnd, Float pos);
void nwSetScrollBarRange(NWHWND hWnd, Float min, Float max);
void nwSetScrollBarData(NWHWND hWnd, NWS_DATA *dt);
void nwSetScrollBarLineMove(NWHWND hWnd, Float step);
void nwSetScrollBarPageMove(NWHWND hWnd, Float step);
void nwCreateScrollBarArray(NWS_SCROLLBARLIST* list, NWHWND parent);

/****************************************/
/*      Scroll Window                   */
/****************************************/
Bool nwScrWinEnableScroll(NWHWND hWnd, Sint32 flag);
Bool nwScrWinSetClip(NWHWND hWNd, NWS_RECT* rect);
Bool nwScrWinScroll(NWHWND hWnd, Sint32 x, Sint32 y);
Bool nwScrWinGetScroll(NWHWND hWnd, Sint32* x, Sint32* y);

/****************************************/
/*      Edit Window                     */
/****************************************/
NWHWND nwCreateEditWindow(Sint32 lineSum, const char* caption, Sint32 style,
	Sint32 x, Sint32 y, Sint32 w, Sint32 h, NWHWND parent);
Bool nwEditWinAddString(NWHWND hWnd, const char* string);
Bool nwEditWinPrintf(NWHWND hWnd, const char* fmt, ...);

/****************************************/
/*      Window Management               */
/****************************************/
NWHWND nwCreateWindow(Sint32 wClass, const char* caption, Sint32 style,
	Sint32 x, Sint32 y, Sint32 w, Sint32 h, NWHWND parent);
void nwDestroyWindow(NWHWND hWnd);

void nwBringWindowToTop(NWHWND hWnd);
NWHWND nwFindWindow(NWHWND hWnd, const char* name);
NWHWND nwFindWindowByPos(Sint16 x, Sint16 y);
NWHWND nwFindWindowEx(NWHWND hWnd, const char* name);

void nwGetClientRect(NWHWND hWnd, NWS_RECT* rc);
Bool nwGetWindowColor(NWHWND hWnd, NWS_RGBA* col);
Bool nwGetWindowPos(NWHWND hWnd, Sint32* x, Sint32* y);
void nwGetWindowRect(NWHWND hWnd, NWS_RECT* rc);
Bool nwGetWindowSize(NWHWND hWnd, Sint32* w, Sint32* h);
Bool nwGetWindowStyle(NWHWND hWnd, Sint32* style);
Sint32 nwGetWindowText(NWHWND hWnd, char *buf, Sint32 size);

Bool nwSetWindowColor(NWHWND hWnd, NWS_RGBA* col);
Bool nwSetWindowStyle(NWHWND hWnd, Sint32 and_style, Sint32 or_style);
Bool nwSetWindowPos(NWHWND hWnd, Sint32 x, Sint32 y);
Bool nwSetWindowSize(NWHWND hWnd, Sint32 w, Sint32 h);
Bool nwSetWindowText(NWHWND hWnd, const char* text);


/****************************************/
/*      Common Dialog                   */
/****************************************/
NWHWND nwCreateColorDialog(Sint32 x, Sint32 y, NWS_RGBA* rgba, NWHWND parent);
NWHWND nwCreatePropertyDialog(NWHWND hWnd, Sint32 x, Sint32 y);

/****************************************/
/*      Nindows Utility                 */
/****************************************/
void nwDebugPrintf(Sint8 *fmt, ...);
void nwSetDefWindowColor(Sint32 win, NWS_RGBA* col);
void nwSetDefWindowStyle(Sint32 win, Sint32 and_style, Sint32 or_style);
void nwSetDefWindowPos(Sint32 win, Sint32 x, Sint32 y);
void nwSetDefWindowSize(Sint32 win, Sint32 w, Sint32 h);
void nwSetUserMenu(NWS_MENUTABLE* menu);

/****************************************/
/*      Mouse                           */
/****************************************/
void nwGetMousePosition(Sint32* x, Sint32* y);
void nwSetMousePosition(Sint32 x, Sint32 y);
void nwGetMouseSpeed(Sint32* x, Sint32* y);
void nwSetMouseSpeed(Sint32 x, Sint32 y);
void nwEnablePeripheral(Bool flag);


#ifdef __cplusplus
}
#endif

#endif /* _NINDOWS_H_ */
