/***** Interface of the CEx1Doc class *****/

#pragma once

#include "stdafx.h"

#define COLOR_BLACK RGB(0, 0, 0)
#define COLOR_WHITE RGB(255, 255, 255)

typedef enum Mode{
	MODE_CONT,
	MODE_DISCRETE
} MODE;

class CEx1Doc : public CDocument
{
public:

	// Static Colors
	COLORREF m_color1 = COLOR_BLACK,
		     m_color2 = COLOR_WHITE;

	// The Painting mode
	MODE m_mode = MODE_CONT;

	// The Parameters we will use
	int m_a, m_b, m_s;

	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

	virtual ~CEx1Doc();

protected: // create from serialization only
	CEx1Doc();
	DECLARE_DYNCREATE(CEx1Doc)

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};
