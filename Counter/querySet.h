// querySet.h : interface of the CQuerySet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUERYSET_H__EBD3B059_45C1_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_QUERYSET_H__EBD3B059_45C1_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CQuerySet : public CRecordset
{
public:
	CQuerySet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CQuerySet)

// Field/Param Data
	//{{AFX_FIELD(CQuerySet, CRecordset)
	CString	m_link;
	long	m_count;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuerySet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYSET_H__EBD3B059_45C1_11D3_A7FE_0080C8763FA4__INCLUDED_)

