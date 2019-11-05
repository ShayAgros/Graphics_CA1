#pragma once

#include <afxwin.h>
#include "resource.h"

// Enumerator for paint mode
typedef enum {
	MODE_VALUES,
	MODE_ZEROS
} MODE;

class MainApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

class MainWin : public CFrameWnd {
	CMenu m_main_menu;
	// static colors
	COLORREF color1 = RGB(0, 0, 0),
			 color2 = RGB(255, 255, 255);

	// The mode we will paint with
	MODE mode = MODE_VALUES;

	// The parameters we will use
	int a, b, s;

public:
	MainWin();
	afx_msg void OnModeDiscrete();
	afx_msg void OnModeContig();
	afx_msg void OnParams();
	afx_msg void OnParametersEditparams();

	afx_msg void OnUpdateModeContig(CCmdUI *pCmdUI);
	afx_msg void OnUpdateModeDiscrete(CCmdUI *pCmdUI);


protected:
	afx_msg void OnPaint();
	BOOL PreCreateWindow(CREATESTRUCT& cs);
	DECLARE_MESSAGE_MAP();
};