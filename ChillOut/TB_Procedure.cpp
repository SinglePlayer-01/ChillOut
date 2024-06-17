#include "ToolBar.h"

LRESULT ToolBar::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
		hwnd_enterField_search = CreateWindow(L"EDIT", L"Search...", WS_CHILD | WS_VISIBLE, 1141, 18, 500, 32, m_hwnd, NULL, NULL, NULL);
		BT_Liblary.Create(NULL, WS_CHILD | WS_VISIBLE, NULL, 29, 5, 200, 50, m_hwnd, NULL);
		BT_Shop.Create(NULL, WS_CHILD | WS_VISIBLE, NULL, 229, 5, 200, 50, m_hwnd, NULL);
		BT_Community.Create(NULL, WS_CHILD | WS_VISIBLE, NULL, 429, 5, 200, 50, m_hwnd, NULL);

		HFONT hfont = CreateFont(30, 0, 0, 0, FW_THIN, 0, 0, 0, 0, 0, DRAFT_QUALITY, 0, 0, L"Stadio Now Monolinea");
		SendMessage(hwnd_enterField_search, WM_SETFONT, (WPARAM)hfont, TRUE);
	}
	return 0;

	case WM_PAINT:
		Draw_GraphicResources();
		return 0;

	case WM_DESTROY:
		return 0;

	case WM_COMMAND:
	{
		
		switch (LOWORD(wParam))
		{
		case Button_Liblary_Down:
			frameswitch = 1;

			GetClientRect(m_hwnd, &rc);
			InvalidateRect(m_hwnd, NULL, FALSE);
			RedrawWindow(m_hwnd, &rc, NULL, RDW_UPDATENOW);
			return 0;

		case Button_Show_Down:
			frameswitch = 2;
			
			GetClientRect(m_hwnd, &rc);
			InvalidateRect(m_hwnd, NULL, FALSE);
			RedrawWindow(m_hwnd, &rc, NULL, RDW_UPDATENOW);
			return 0;

		case Button_Community_Down:
			frameswitch = 3;
			
			GetClientRect(m_hwnd, &rc);
			InvalidateRect(m_hwnd, NULL, FALSE);
			RedrawWindow(m_hwnd, &rc, NULL, RDW_UPDATENOW);
			return 0;
		}
		switch (HIWORD(wParam))
		{
		case EN_CHANGE:
			ShowWindow(HWND(lParam), SW_HIDE);
			ShowWindow(HWND(lParam), SW_SHOW);
			SetFocus(HWND(lParam));
			break;
		}
	}
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


LRESULT Button_Shop::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	case WM_MOUSEMOVE:
		TRACKMOUSEEVENT tme1;
		TRACKMOUSEEVENT tme2;

		tme1.cbSize = sizeof(TRACKMOUSEEVENT);
		tme1.dwFlags = TME_HOVER;
		tme1.dwHoverTime = 3;
		tme1.hwndTrack = m_hwnd;

		tme2.cbSize = sizeof(TRACKMOUSEEVENT);
		tme2.dwFlags = TME_LEAVE;
		tme2.dwHoverTime = 3;
		tme2.hwndTrack = m_hwnd;

		TrackMouseEvent(&tme1);
		TrackMouseEvent(&tme2);

		return 0;

	case WM_MOUSEHOVER:
	{
		HCURSOR hCursor;
		hCursor = LoadCursor(NULL, IDC_HAND);
		SetCursor(hCursor);
		
		mouse_hover = true;
	}
	return 0;

	case WM_LBUTTONDOWN:
	{
		if (mouse_hover == true)
		{
			SendMessage(GetParent(m_hwnd), WM_COMMAND, Button_Show_Down, NULL);
		}
	}
	return 0;

	case WM_MOUSELEAVE:
	{
		HCURSOR hCursor;
		hCursor = LoadCursor(NULL, IDC_ARROW);
		SetCursor(hCursor);
		mouse_hover = false;
	}
	return 0;
	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}
LRESULT Button_Liblary::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	case WM_MOUSEMOVE:
		TRACKMOUSEEVENT tme1;
		TRACKMOUSEEVENT tme2;

		tme1.cbSize = sizeof(TRACKMOUSEEVENT);
		tme1.dwFlags = TME_HOVER;
		tme1.dwHoverTime = 3;
		tme1.hwndTrack = m_hwnd;

		tme2.cbSize = sizeof(TRACKMOUSEEVENT);
		tme2.dwFlags = TME_LEAVE;
		tme2.dwHoverTime = 3;
		tme2.hwndTrack = m_hwnd;

		TrackMouseEvent(&tme1);
		TrackMouseEvent(&tme2);

		return 0;

	case WM_MOUSEHOVER:
	{
		HCURSOR hCursor;
		hCursor = LoadCursor(NULL, IDC_HAND);
		SetCursor(hCursor);
		mouse_hover = true;
	}
	return 0;

	case WM_LBUTTONDOWN:
	{
		if (mouse_hover == true)
		{
			SendMessage(GetParent(m_hwnd), WM_COMMAND, Button_Liblary_Down, NULL);
		}
	}
	return 0;

	case WM_MOUSELEAVE:
	{
		HCURSOR hCursor;
		hCursor = LoadCursor(NULL, IDC_ARROW);
		SetCursor(hCursor);
		mouse_hover = false;
	}
	return 0;
	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}
LRESULT Button_Community::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	case WM_MOUSEMOVE:
		TRACKMOUSEEVENT tme1;
		TRACKMOUSEEVENT tme2;

		tme1.cbSize = sizeof(TRACKMOUSEEVENT);
		tme1.dwFlags = TME_HOVER;
		tme1.dwHoverTime = 3;
		tme1.hwndTrack = m_hwnd;

		tme2.cbSize = sizeof(TRACKMOUSEEVENT);
		tme2.dwFlags = TME_LEAVE;
		tme2.dwHoverTime = 3;
		tme2.hwndTrack = m_hwnd;

		TrackMouseEvent(&tme1);
		TrackMouseEvent(&tme2);

		return 0;

	case WM_MOUSEHOVER:
	{
		HCURSOR hCursor;
		hCursor = LoadCursor(NULL, IDC_HAND);
		SetCursor(hCursor);
		mouse_hover = true;
	}
	return 0;

	case WM_LBUTTONDOWN:
	{
		if (mouse_hover == true)
		{
			SendMessage(GetParent(m_hwnd), WM_COMMAND, Button_Community_Down, NULL);
		}
	}
	return 0;

	case WM_MOUSELEAVE:
	{
		HCURSOR hCursor;
		hCursor = LoadCursor(NULL, IDC_ARROW);
		SetCursor(hCursor);
		mouse_hover = false;
	}
	return 0;
	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}