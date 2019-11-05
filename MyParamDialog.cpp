// MyParamDialog.cpp : implementation file
#include "MyParamDialog.h"


// MyParamDialog dialog

IMPLEMENT_DYNAMIC(MyParamDialog, CDialog)

MyParamDialog::MyParamDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, a(0)
	, b(0)
	, s(0)
{

}

MyParamDialog::MyParamDialog(COLORREF C1, COLORREF C2, int a, int b, int s, CWnd* pParent /*= nullptr */)
	: CDialog(IDD_DIALOG1, pParent)
{

	this->color1 = C1;
	this->color2 = C2;
	this->a = a;
	this->b = b;
	this->s = s;
}

MyParamDialog::~MyParamDialog()
{
}

BOOL MyParamDialog::OnInitDialog()
{
	BOOL result;
	char buffer[30];

	result = CDialog::OnInitDialog();

	/* Make the color buttons represent the configured color */
	this->A_color_button.SetFaceColor(this->color1);
	this->B_color_button.SetFaceColor(this->color2);

	/* put current values of a, b, s im the text boxes */
	sprintf_s(buffer, sizeof(buffer), "%d", this->a);
	GetDlgItem(IDC_EDIT1)->SetWindowText(buffer);
	sprintf_s(buffer, sizeof(buffer), "%d", this->b);
	GetDlgItem(IDC_EDIT2)->SetWindowText(buffer);
	sprintf_s(buffer, sizeof(buffer), "%d", this->s);
	GetDlgItem(IDC_EDIT3)->SetWindowText(buffer);

	return result;
}

void MyParamDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON1, A_color_button);
	DDX_Control(pDX, IDC_MFCBUTTON2, B_color_button);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDV_MinMaxInt(pDX, a, 0, INT_MAX);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDV_MinMaxInt(pDX, b, 0, INT_MAX);
	DDX_Text(pDX, IDC_EDIT3, s);
	DDV_MinMaxInt(pDX, s, 0, INT_MAX);
}


BEGIN_MESSAGE_MAP(MyParamDialog, CDialog)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &MyParamDialog::OnBnClickedMfcbutton1)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &MyParamDialog::OnBnClickedMfcbutton2)
END_MESSAGE_MAP()


// MyParamDialog message handlers

void MyParamDialog::OnBnClickedMfcbutton1()
{
	CColorDialog color_chooser;
	
	if (color_chooser.DoModal() == IDOK) {
		COLORREF color = color_chooser.GetColor();
		this->color1 = color;
		this->A_color_button.SetFaceColor(color);
	}

	this->SetFocus();
}


void MyParamDialog::OnBnClickedMfcbutton2()
{
	CColorDialog color_chooser;

	if (color_chooser.DoModal() == IDOK) {
		COLORREF color = color_chooser.GetColor();
		this->color2 = color;
		this->B_color_button.SetFaceColor(color);
	}
	this->SetFocus();
}
