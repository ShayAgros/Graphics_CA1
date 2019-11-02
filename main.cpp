#include "my_win.h"

BOOL MainApp::InitInstance() {
	this->m_pMainWnd = new MainWin();
	this->m_pMainWnd->ShowWindow(SW_NORMAL);
	this->m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(MainWin, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()

MainWin::MainWin() {
	Create(NULL, _T("The Hello Application"));
}

void MainWin::OnPaint() {
	CPaintDC dc(this);
	CRect rect;

	GetClientRect(&rect);

	dc.DrawText(_T("Hello, MFC"), -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

MainApp mainApp;