/***** Header for the Application class *****/

#pragma once

#ifndef __AFXWIN_H__
#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "stdafx.h"
#include "resource.h"       // main symbols

#define SIZE_X 800
#define SIZE_Y 600

class CEx1App : public CWinApp
{
public:
	CEx1App();

	// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	// Implementation
	DECLARE_MESSAGE_MAP()
};

extern CEx1App theApp;
