/***** Interface of the CEx1View class *****/

#pragma once

#include "Ex1Dialog.h"

class CEx1View : public CView
{
protected: // create from serialization only
	CEx1View();
	DECLARE_DYNCREATE(CEx1View)

public:
	CEx1Doc* GetDocument() const;

	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	virtual ~CEx1View();

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};
