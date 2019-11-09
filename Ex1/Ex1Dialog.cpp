/***** Defines the class behaviors for the dialog. *****/

#include "stdafx.h"
#include "afxdialogex.h"

#include "Ex1App.h"
#include "Ex1Dialog.h"

IMPLEMENT_DYNAMIC(CEx1Dialog, CDialogEx)

CEx1Dialog::CEx1Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PARAM_DIALOG, pParent)
	, m_a(0)
	, m_b(0)
	, m_s(0)
{

}

CEx1Dialog::CEx1Dialog(COLORREF C1, COLORREF C2, int a, int b, int s, CWnd* pParent /*= nullptr */)
	: CDialogEx(IDD_PARAM_DIALOG, pParent)
{
	this->m_color1 = C1;
	this->m_color2 = C2;
	this->m_a = a;
	this->m_b = b;
	this->m_s = s;
}

CEx1Dialog::~CEx1Dialog()
{
}

BOOL CEx1Dialog::OnInitDialog()
{
	CString string;
	BOOL result = CDialogEx::OnInitDialog();

	/* Make the color buttons represent the configured color */
	this->A_color_button.SetFaceColor(this->m_color1);
	this->B_color_button.SetFaceColor(this->m_color2);

	/* put current values of a, b, s into the text boxes */
	string.Format(_T("%d"), m_a);
	GetDlgItem(IDC_A)->SetWindowText(string);
	string.Format(_T("%d"), m_b);
	GetDlgItem(IDC_B)->SetWindowText(string);
	string.Format(_T("%d"), m_s);
	GetDlgItem(IDC_S)->SetWindowText(string);

	return result;
}

void CEx1Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON1, A_color_button);
	DDX_Control(pDX, IDC_MFCBUTTON2, B_color_button);
	DDX_Text(pDX, IDC_A, m_a);
	DDV_MinMaxInt(pDX, m_a, 0, INT_MAX);
	DDX_Text(pDX, IDC_B, m_b);
	DDV_MinMaxInt(pDX, m_b, 0, INT_MAX);
	DDX_Text(pDX, IDC_S, m_s);
	DDV_MinMaxInt(pDX, m_s, 0, INT_MAX);
}


BEGIN_MESSAGE_MAP(CEx1Dialog, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CEx1Dialog::OnBnClickedMfcbutton1)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &CEx1Dialog::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// MyDialog message handlers

void CEx1Dialog::OnBnClickedMfcbutton1()
{
	CColorDialog color_chooser;

	if (color_chooser.DoModal() == IDOK) {
		COLORREF color = color_chooser.GetColor();
		this->m_color1 = color;
		this->A_color_button.SetFaceColor(color);
	}

	this->SetFocus();
}

void CEx1Dialog::OnBnClickedMfcbutton2()
{
	CColorDialog color_chooser;

	if (color_chooser.DoModal() == IDOK) {
		COLORREF color = color_chooser.GetColor();
		this->m_color2 = color;
		this->B_color_button.SetFaceColor(color);
	}
	this->SetFocus();
}