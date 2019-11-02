#pragma once

#include <afxwin.h>
#include "resource.h"

class MainApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

class MainWin : public CFrameWnd {
	CMenu m_main_menu;
	COLORREF C1, C2;

public:
	MainWin();

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP();
public:
	afx_msg void OnParametersEditparams();
};