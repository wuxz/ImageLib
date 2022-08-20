#if !defined(AFX_COUNTER_H__EBD3B044_45C1_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_COUNTER_H__EBD3B044_45C1_11D3_A7FE_0080C8763FA4__INCLUDED_

// COUNTER.H - Header file for your Internet Server
//    Counter Extension

#include "resource.h"
#include "querySet.h"

class CMyDatabase;

class CCounterExtension : public CHttpServer
{
public:
	CCounterExtension();
	~CCounterExtension();

	CQuerySet m_querySet;
	CMyDatabase * m_pdb;
	TCHAR m_strPath[256];

// Overrides
	// ClassWizard generated virtual function overrides
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//{{AFX_VIRTUAL(CCounterExtension)
	public:
	virtual BOOL GetExtensionVersion(HSE_VERSION_INFO* pVer);
	//}}AFX_VIRTUAL
	virtual BOOL TerminateExtension(DWORD dwFlags);

	// TODO: Add handlers for your commands here.
	// For example:

	void Default(CHttpServerContext* pCtxt, LPTSTR strLink, LPTSTR strStyle,
		short nWidth, LPTSTR strOrd, LPTSTR clrBack, LPTSTR clrFore);

	DECLARE_PARSE_MAP()

	//{{AFX_MSG(CCounterExtension)
	//}}AFX_MSG
protected:
	BOOL ConvertCharToByte(TCHAR ch, BYTE & btRet);
	BOOL ConvertStrToRGB(CString strClr, COLORREF& clrRet);
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COUNTER_H__EBD3B044_45C1_11D3_A7FE_0080C8763FA4__INCLUDED)
