#include "ZJBaseWnd.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{

	RECT rc = {200, 100, 1000, 700};
	ZJBaseWnd myWnd;

	DWORD wStyle = WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX;

	if(NULL == myWnd.Create(NULL, rc, _T("Cda ATL Learn"), wStyle)){
		return 0;
	}
	myWnd.ShowWindow(nCmdShow);
	myWnd.UpdateWindow();

	MSG msg;
	msg.message = ~(UINT)WM_QUIT;
	while(WM_QUIT != msg.message)
	{
		if(GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 1;	
}