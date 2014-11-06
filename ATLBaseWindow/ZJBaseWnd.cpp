#include "ZJBaseWnd.h"


ZJBaseWnd::ZJBaseWnd()
{

}

ZJBaseWnd::~ZJBaseWnd()
{

}

LRESULT ZJBaseWnd::OnClose(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
	exit(0);
	return S_OK;
}

LRESULT ZJBaseWnd::OnCreate(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
	SetClassLong(m_hWnd, GCL_HBRBACKGROUND,
		(long)RGB(0, 200, 225));

	RECT rect;
	GetClientRect(&rect);

	createBtn = CreateWindow(WC_BUTTON,
		_T("Create"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		rect.right /2 - 40,
		rect.bottom / 2 - 20,
		80, 40,
		m_hWnd,
		(HMENU)CREATE_BTN_ID,
		_AtlBaseModule.GetResourceInstance(),NULL);

	return S_OK;
}

LRESULT ZJBaseWnd::OnQuit(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
	exit(0);
	return S_OK;
}

LRESULT ZJBaseWnd::OnCreateBtnDown(WPARAM, LPARAM, HWND, BOOL&)
{
	MessageBox(_T("Create Btn Down"));
	return S_OK;
}

LRESULT ZJBaseWnd::OnCloseBtnDown(WPARAM, LPARAM, HWND, BOOL&)
{
	MessageBox(_T("Close Btn down"));
	return S_OK;
}