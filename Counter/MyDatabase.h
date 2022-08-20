#if !defined(AFX_MYDATABASE_H__E8DA5F16_45EC_11D3_B446_0080C8F18522__INCLUDED_)
#define AFX_MYDATABASE_H__E8DA5F16_45EC_11D3_B446_0080C8F18522__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyDatabase.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyDatabase DAO recordset

class CMyDatabase : public CDatabase
{
public:
	virtual BOOL OpenEx(LPCTSTR lpszConnectString, DWORD dwOptions);
	CMyDatabase();
	DECLARE_DYNAMIC(CMyDatabase)

// Field/Param Data
	//{{AFX_FIELD(CMyDatabase, CDaoRecordset)
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDatabase)
	//}}AFX_VIRTUAL

// Implementation
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDATABASE_H__E8DA5F16_45EC_11D3_B446_0080C8F18522__INCLUDED_)
