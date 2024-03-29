/***** Interface of the CEx1Frame class *****/

#pragma once

class CEx1Frame : public CFrameWnd
{
protected: // create from serialization only
	CEx1Frame();
	DECLARE_DYNCREATE(CEx1Frame)

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	virtual ~CEx1Frame();

	// Generated message map functions
protected:
	afx_msg void OnModeDiscrete();
	afx_msg void OnModeContig();
	afx_msg void OnEditParams();

	afx_msg void OnUpdateModeContig(CCmdUI *pCmdUI);
	afx_msg void OnUpdateModeDiscrete(CCmdUI *pCmdUI);

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
};


