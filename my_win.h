#pragma once

#include <afxwin.h>

class MainApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

class MainWin : public CFrameWnd {
public:
	MainWin();

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP();
};