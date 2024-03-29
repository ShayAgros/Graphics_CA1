/***** Implementation of the CEx1Doc class *****/

#include "stdafx.h"
#include "Ex1App.h"
#include "Ex1Doc.h"
#include <propkey.h>

// CEx1Doc

IMPLEMENT_DYNCREATE(CEx1Doc, CDocument)

BEGIN_MESSAGE_MAP(CEx1Doc, CDocument)
END_MESSAGE_MAP()


// CEx1Doc construction/destruction

CEx1Doc::CEx1Doc()
{
	m_color1 = COLOR_BLACK,
	m_color2 = COLOR_WHITE;

	MODE _mode = MODE_CONT;

	m_a = 1;
	m_b = 1;

	m_s = SIZE_X / 10;
}

CEx1Doc::~CEx1Doc()
{
}

BOOL CEx1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

// CEx1Doc serialization

void CEx1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	} else
	{
		// TODO: add loading code here
	}
}