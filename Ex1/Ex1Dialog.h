#pragma once

#include "stdafx.h"

/*****  Header for the Ex1Dialog class *****/

class CEx1Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(CEx1Dialog)

public:
	// static colors
	COLORREF m_color1,
			 m_color2;
	int m_a,
		m_b,
		m_s;

	CEx1Dialog(CWnd* pParent = NULL);   // standard constructor
	CEx1Dialog(COLORREF C1, COLORREF C2, int a, int b, int s, CWnd* pParent = nullptr);


	virtual ~CEx1Dialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedMfcbutton1();
	CMFCButton A_color_button;
	afx_msg void OnBnClickedMfcbutton2();
	CMFCButton B_color_button;

	DECLARE_MESSAGE_MAP()
};
