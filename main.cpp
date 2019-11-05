#include "my_win.h"
#include "MyParamDialog.h"

#define COLOR_BLACK RGB(0, 0, 0)
#define COLOR_WHITE RGB(255, 255, 255)

BOOL MainApp::InitInstance() {
	this->m_pMainWnd = new MainWin();
	this->m_pMainWnd->ShowWindow(SW_NORMAL);
	this->m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(MainWin, CFrameWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_PARAMETERS_EDITPARAMS, &MainWin::OnParametersEditparams)
	ON_COMMAND(ID_MODE_DISCRETE, &MainWin::OnModeDiscrete)
	ON_COMMAND(ID_MODE_CONTIG, &MainWin::OnModeContig)
	ON_UPDATE_COMMAND_UI(ID_MODE_CONTIG, &MainWin::OnUpdateModeContig)
	ON_UPDATE_COMMAND_UI(ID_MODE_DISCRETE, &MainWin::OnUpdateModeDiscrete)
END_MESSAGE_MAP()

MainWin::MainWin() {
	Create(NULL, _T("Shay & Shahaf - Ex1"));
	
	// set menu
	this->m_main_menu.LoadMenu(IDR_MENU1);
	SetMenu(&this->m_main_menu);

	CRect rect;
	GetClientRect(&rect); // Window client area

	this->a = 1;
	this->b = 1;
	this->s = rect.Width() / 10;
	
	// set default values
	this->color1 = COLOR_BLACK;
	this->color2 = COLOR_WHITE;
}

BOOL MainWin::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.cx = 800;
	cs.cy = 600;
	return CFrameWnd::PreCreateWindow(cs);
}

void MainWin::OnPaint() {
	CPaintDC dc(this); // Device context

	CRect rect;
	GetClientRect(&rect); // Window client area

	double first_arg = 0, second_arg = 0, func_val, t;

	double width = rect.Width(),
		height = rect.Height();
	int center_x = (rect.right + rect.left) / 2,
		center_y = (rect.bottom + rect.top) / 2,
		red, green, blue;

	COLORREF  curr_color;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			// Calculate function value
			first_arg = a * ((x - center_x) - (double)(width / 2));
			second_arg = b * ((y - center_y) - (double)(height / 2));
			func_val = cos((pow(first_arg, 4) + pow(second_arg, 4)) / pow(s, 3));

			switch (mode) {
			case MODE_VALUES:
				t = (func_val + 1) / 2;

				// Isolate actual color values
				red = (int)(GetRValue(color1) * (1 - t) + GetRValue(color2) * t);
				green = (int)(GetGValue(color1) * (1 - t) + GetGValue(color2) * t);
				blue = (int)(GetBValue(color1) * (1 - t) + GetBValue(color2) * t);
				curr_color = RGB(red, green, blue);
				break;
			case MODE_ZEROS:
			default:
				curr_color = (func_val > 0) ? color1 : color2;
				break;
			}

			// Rasterize			
			SetPixel(dc, x, y, curr_color);
		}
	}
}

/* "edit params" menu item handler */
void MainWin::OnParametersEditparams()
{
	MyParamDialog param_dialog(this->color1, this->color2, this->a, this->b, this->s);

	if (param_dialog.DoModal() == IDOK) {
		this->color1 = param_dialog.color1;
		this->color2 = param_dialog.color2;

		this->a = param_dialog.a;
		this->b = param_dialog.b;
		this->s = param_dialog.s;
	}

	this->Invalidate();
	this->UpdateWindow();
}


void MainWin::OnModeContig()
{
	this->mode = MODE_VALUES;
	this->Invalidate();
	this->UpdateWindow();
}

void MainWin::OnModeDiscrete()
{
	this->mode = MODE_ZEROS;
	this->Invalidate();
	this->UpdateWindow();
}

void MainWin::OnParams()
{
	/*
	Params dlg;

	if (dlg.DoModal() == IDOK)
	{
		if ((dlg.m_a <= 0) || (dlg.m_b <= 0) || (dlg.m_s <= 0))
			AfxMessageBox(_T("Please enter only positive parameter!"), MB_OK);
		else
		{
			a = dlg.m_a;
			b = dlg.m_b;
			s = dlg.m_s;
			this->Invalidate();
			this->UpdateWindow();
		}
	} */
}

void MainWin::OnUpdateModeContig(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck((mode == MODE_VALUES) ? 1 : 0);
}

void MainWin::OnUpdateModeDiscrete(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck((mode == MODE_ZEROS) ? 1 : 0);
}

MainApp mainApp;