
/****** Implementation of the CEx1View class *****/

#include "stdafx.h"
#include "Ex1App.h"
#include "Ex1Doc.h"
#include "Ex1View.h"

// CEx1View

IMPLEMENT_DYNCREATE(CEx1View, CView)

BEGIN_MESSAGE_MAP(CEx1View, CView)
END_MESSAGE_MAP()

// CEx1View construction/destruction

CEx1View::CEx1View()
{
}

CEx1View::~CEx1View()
{
}

BOOL CEx1View::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

// CEx1View drawing

void CEx1View::OnDraw(CDC* pDC)
{
	CEx1Doc* doc = GetDocument();

	MODE mode = doc->m_mode;

	int a = doc->m_a,
		b = doc->m_b,
		s = doc->m_s;

	COLORREF color1 = doc->m_color1,
	       	 color2 = doc->m_color2;

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
			case MODE_CONT:
				t = (func_val + 1) / 2;

				// Isolate actual color values
				red = (int)(GetRValue(color1) * (1 - t) + GetRValue(color2) * t);
				green = (int)(GetGValue(color1) * (1 - t) + GetGValue(color2) * t);
				blue = (int)(GetBValue(color1) * (1 - t) + GetBValue(color2) * t);
				curr_color = RGB(red, green, blue);
				break;
			case MODE_DISCRETE:
			default:
				curr_color = (func_val > 0) ? color1 : color2;
				break;
			}

			// Rasterize			
			SetPixel(*pDC, x, y, curr_color);
		}
	}
}

CEx1Doc* CEx1View::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx1Doc)));
	return (CEx1Doc*)m_pDocument;
}

