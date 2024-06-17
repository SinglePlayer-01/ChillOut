#include "MainWindow.h"

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CREATE:
			Create_Factory();
			Create_GraphicResources();

			hwnd_enterField_search = CreateWindow(L"EDIT", L"Serch....", WS_CHILD | WS_VISIBLE, 1141, 18, 400, 30, m_hwnd, NULL, NULL, NULL);

			hfont_enterField_search = CreateFont(20, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");

			SendMessage(hwnd_enterField_search, WM_SETFONT, (WPARAM)hfont_enterField_search, TRUE);

			SetFocus(m_hwnd);

		return 0;

		case WM_PAINT:
			Draw_GraphicResources();
			return 0;

		case WM_COMMAND:
			switch (LOWORD(wParam))
			{

			}
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
				ShowWindow(HWND(lParam), SW_HIDE);
				ShowWindow(HWND(lParam), SW_SHOW);
				SetFocus(HWND(lParam));
				break;
			}
			return 0;

		case WM_DESTROY:
			Discard_GraphicResources();
		return 0;
	
		case WM_CTLCOLORBTN:
		case WM_CTLCOLOREDIT:
		case WM_CTLCOLORSTATIC:
			SetTextColor(HDC(wParam), (COLORREF)RGB(255, 255, 255));
			SetBkMode(HDC(wParam), TRANSPARENT);
			return LRESULT(HBRUSH(GetStockObject(NULL_BRUSH)));

	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}