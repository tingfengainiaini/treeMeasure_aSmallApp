// SkinH_Attach_Ex.h : main header file for the SKINH_ATTACH_EX application
//

#if !defined(AFX_SKINH_ATTACH_EX_H__4742B7EA_1F00_47E3_90E4_F3BA34B548E8__INCLUDED_)
#define AFX_SKINH_ATTACH_EX_H__4742B7EA_1F00_47E3_90E4_F3BA34B548E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSkinH_Attach_ExApp:
// See SkinH_Attach_Ex.cpp for the implementation of this class
//

class CSkinH_Attach_ExApp : public CWinApp
{
public:
	CSkinH_Attach_ExApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinH_Attach_ExApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSkinH_Attach_ExApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINH_ATTACH_EX_H__4742B7EA_1F00_47E3_90E4_F3BA34B548E8__INCLUDED_)
