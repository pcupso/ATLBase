#include "stdafx.h"

#ifndef HOMEWND_H
#define HOMEWND_H

#include <atlbase.h>
#include <atlstr.h>
#include <atlwin.h>

#define CREATE_BTN_ID 2000
#define Close_BTN_ID 2001

class ZJBaseWnd
	: public CWindowImpl<ZJBaseWnd, CWindow, CWinTraits<WS_OVERLAPPEDWINDOW, 0> >
{
public:
	DECLARE_WND_CLASS(_T("Home Window"))
	BEGIN_MSG_MAP(ZJBaseWnd)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_QUIT,	OnQuit)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)

		COMMAND_HANDLER(CREATE_BTN_ID, 0, OnCreateBtnDown)	
		COMMAND_HANDLER(Close_BTN_ID, 0, OnCloseBtnDown)	
	END_MSG_MAP()

public:
	ZJBaseWnd();
	~ZJBaseWnd();

	//Message Functions
	LRESULT OnClose	(UINT nMsg,	WPARAM wParam, LPARAM lParam, BOOL &bHandled);
	LRESULT OnQuit	(UINT nMsg,	WPARAM wParam, LPARAM lParam, BOOL &bHandled);
	LRESULT OnCreate(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
	LRESULT OnPaint	(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);

	LRESULT OnCreateBtnDown(WPARAM, LPARAM, HWND, BOOL&);
	LRESULT OnCloseBtnDown(WPARAM, LPARAM, HWND, BOOL&);

private:
	HWND	createBtn;
};

#endif