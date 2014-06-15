// treemesure.h : main header file for the TREEMESURE application
//

#if !defined(AFX_TREEMESURE_H__42E82F8C_BDDB_49AD_906F_52CD4098AECF__INCLUDED_)
#define AFX_TREEMESURE_H__42E82F8C_BDDB_49AD_906F_52CD4098AECF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTreemesureApp:
// See treemesure.cpp for the implementation of this class
//

class CTreemesureApp : public CWinApp
{
public:
	CTreemesureApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreemesureApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTreemesureApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEMESURE_H__42E82F8C_BDDB_49AD_906F_52CD4098AECF__INCLUDED_)
