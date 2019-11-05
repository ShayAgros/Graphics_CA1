#pragma once
#include <afxwin.h>
#include <afxbutton.h>
#include <afxdlgs.h>
#include "resource.h"

// MyParamDialog dialog

class MyParamDialog : public CDialog
{
	DECLARE_DYNAMIC(MyParamDialog)
	// static colors
	COLORREF color1, color2;
	int a, b, s;

public:
	

	MyParamDialog(CWnd* pParent = nullptr); // standard constructor
	MyParamDialog(COLORREF C1, COLORREF C2, int a, int b, int s,CWnd* pParent = nullptr);
	virtual ~MyParamDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
	CMFCButton A_color_button;
	afx_msg void OnBnClickedMfcbutton2();
	CMFCButton B_color_button;
};
