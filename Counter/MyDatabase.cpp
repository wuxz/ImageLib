// MyDatabase.cpp : implementation file
//

#include "stdafx.h"
#include "Counter.h"
#include "MyDatabase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDatabase

IMPLEMENT_DYNAMIC(CMyDatabase, CDatabase)

CMyDatabase::CMyDatabase()
{
}

BOOL CMyDatabase::OpenEx(LPCTSTR lpszConnectString, DWORD dwOptions)
{
	return CDatabase::OpenEx(lpszConnectString, dwOptions | noOdbcDialog);
}
