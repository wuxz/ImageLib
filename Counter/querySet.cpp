// querySet.cpp : implementation of the CQuerySet class
//

#include "stdafx.h"
#include "querySet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuerySet implementation

IMPLEMENT_DYNAMIC(CQuerySet, CRecordset)

CQuerySet::CQuerySet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CQuerySet)
	m_link = _T("");
	m_count = 0;
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}

CString CQuerySet::GetDefaultConnect()
{
	return _T("ODBC;DSN=counter");
}

CString CQuerySet::GetDefaultSQL()
{
	return _T("[counter]");
}

void CQuerySet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CQuerySet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[link]"), m_link);
	RFX_Long(pFX, _T("[count]"), m_count);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CQuerySet diagnostics

#ifdef _DEBUG
void CQuerySet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CQuerySet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
