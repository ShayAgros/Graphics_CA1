/***** Implementation of the CEx1Frame class *****/

#include "stdafx.h"
#include "Ex1App.h"
#include "Ex1Dialog.h"
#include "Ex1Frame.h"
#include "Ex1Doc.h"

// CEx1Frame

IMPLEMENT_DYNCREATE(CEx1Frame, CFrameWnd)

BEGIN_MESSAGE_MAP(CEx1Frame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_EDITPARAMS, &CEx1Frame::OnEditParams)
	ON_COMMAND(ID_MODE_DISCRETE, &CEx1Frame::OnModeDiscrete)
	ON_COMMAND(ID_MODE_CONTIG, &CEx1Frame::OnModeContig)
	ON_UPDATE_COMMAND_UI(ID_MODE_CONTIG, &CEx1Frame::OnUpdateModeContig)
	ON_UPDATE_COMMAND_UI(ID_MODE_DISCRETE, &CEx1Frame::OnUpdateModeDiscrete)
END_MESSAGE_MAP()

// CEx1Frame construction/destruction

CEx1Frame::CEx1Frame()
{
}

CEx1Frame::~CEx1Frame()
{
}

int CEx1Frame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}

BOOL CEx1Frame::PreCreateWindow(CREATESTRUCT& cs)
{
	// Reduce window size for faster drawing
	cs.cx = SIZE_X;
	cs.cy = SIZE_Y;

	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	return TRUE;
}

/* "edit params" menu item handler */
void CEx1Frame::OnEditParams()
{
	CEx1Doc* doc = (CEx1Doc*)this->GetActiveDocument();

	MODE _mode = doc->m_mode;

	int a = doc->m_a,
		b = doc->m_b,
		s = doc->m_s;

	COLORREF color1 = doc->m_color1,
		     color2 = doc->m_color2;

	CEx1Dialog param_dialog(color1, color2, a, b, s);

	if (param_dialog.DoModal() == IDOK) {
		doc->m_color1 = param_dialog.m_color1;
		doc->m_color2 = param_dialog.m_color2;

		doc->m_a = param_dialog.m_a;
		doc->m_b = param_dialog.m_b;
		doc->m_s = param_dialog.m_s;

		this->Invalidate();
		this->UpdateWindow();
	}
}

void CEx1Frame::OnModeContig()
{
	CEx1Doc* doc = (CEx1Doc*)GetActiveDocument();
	doc->m_mode = MODE_CONT;

	this->Invalidate();
	this->UpdateWindow();
}

void CEx1Frame::OnModeDiscrete()
{
	CEx1Doc* doc = (CEx1Doc*)GetActiveDocument();
	doc->m_mode = MODE_DISCRETE;

	this->Invalidate();
	this->UpdateWindow();
}

void CEx1Frame::OnUpdateModeContig(CCmdUI *pCmdUI)
{
	CEx1Doc* doc = (CEx1Doc*)GetActiveDocument();
	pCmdUI->SetCheck((doc->m_mode == MODE_CONT) ? 1 : 0);
}

void CEx1Frame::OnUpdateModeDiscrete(CCmdUI *pCmdUI)
{
	CEx1Doc* doc = (CEx1Doc*)GetActiveDocument();
	pCmdUI->SetCheck((doc->m_mode == MODE_DISCRETE) ? 1 : 0);
}