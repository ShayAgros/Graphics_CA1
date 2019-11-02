#include "my_win.h"

#define COLOR_BLACK 0x00000000
#define COLOR_WHITE 0x00FFFFFF

BOOL MainApp::InitInstance() {
	this->m_pMainWnd = new MainWin();
	this->m_pMainWnd->ShowWindow(SW_NORMAL);
	this->m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(MainWin, CFrameWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_PARAMETERS_EDITPARAMS, &MainWin::OnParametersEditparams)
END_MESSAGE_MAP()

MainWin::MainWin() {
	Create(NULL, _T("The Hello Application"));
	
	// set menu
	this->m_main_menu.LoadMenu(IDR_MENU1);
	SetMenu(&this->m_main_menu);

	// set default values
	this->C1 = COLOR_BLACK;
	this->C2 = COLOR_WHITE;
}

void MainWin::OnPaint() {
	CPaintDC dc(this);
	CRect rect;

	GetClientRect(&rect);

	dc.DrawText(_T("Hello, MFC"), -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

/* "edit params" menu item handler */
void MainWin::OnParametersEditparams()
{
	AfxMessageBox("Key pressed", MB_OK);
}

MainApp mainApp;