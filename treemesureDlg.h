// treemesureDlg.h : header file
//

#if !defined(AFX_TREEMESUREDLG_H__CB2B14E0_B3DC_4BA9_ABA1_4250F9A656BE__INCLUDED_)
#define AFX_TREEMESUREDLG_H__CB2B14E0_B3DC_4BA9_ABA1_4250F9A656BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTreemesureDlg dialog

class CTreemesureDlg : public CDialog
{
// Construction
public:
	CTreemesureDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTreemesureDlg)
	enum { IDD = IDD_TREEMESURE_DIALOG };
	CListCtrl	m_list2;
//	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreemesureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTreemesureDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_length;
//	CEdit m_curve;
	CString m_length;
//	CString m_curve;
	CString m_crossgrain;
	afx_msg void OnBnClickedButton1();
//	CComboBox m_class;
	CComboBox m_treeclass;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CString m_wide;
	CString m_area;
	CString m_wormhle;
	CString m_deadknot;
	CString m_sound;
	CString m_decay;
//	CString m_wane;
//	CEdit m_check;
//	CString m_check;
	CString m_check;
	CString m_wane;
	CString m_sagitta1;
	CString m_sagitta2;
	CString m_thickness;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEMESUREDLG_H__CB2B14E0_B3DC_4BA9_ABA1_4250F9A656BE__INCLUDED_)
