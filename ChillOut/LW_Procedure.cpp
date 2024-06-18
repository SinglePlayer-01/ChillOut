#include "LoginWindow.h"

LRESULT LoginWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CREATE:
			Create_GraphicResources();
			Send_GraphicResources();
			BT_help.Create(NULL, WS_CHILD | WS_VISIBLE, NULL, 40, 330, 44, 24, m_hwnd, NULL);
			BT_Registration.Create(NULL, WS_CHILD | WS_VISIBLE, NULL, 450, 330, 114, 24, m_hwnd, NULL);
		return 0;

		case WM_PAINT:
			Draw_GraphicResources();
		return 0;

		case WM_DESTROY:
			Discard_GraphicResources();
			return 0;
	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}

LRESULT Button_help::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
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

	case WM_PAINT:
		ShowWindow(m_hwnd, SW_SHOW);
		Draw_GrapgicResources();
		return 0;

	case WM_MOUSEHOVER:
	{
		HCURSOR hCursor;
		hCursor = LoadCursor(NULL, IDC_HAND);
		SetCursor(hCursor);
		mouse_hover = true;
		RECT rc;
		ShowWindow(m_hwnd, SW_HIDE);
		GetClientRect(m_hwnd, &rc);
		InvalidateRect(m_hwnd, NULL, FALSE);
		ShowWindow(m_hwnd, SW_SHOW);
	}
	return 0;

	case WM_LBUTTONDOWN:
	{
		if (mouse_hover == true)
		{
			//SendMessage(GetParent(m_hwnd), WM_COMMAND, Button_Search_Down, NULL);
		}
	}
	return 0;

	case WM_MOUSELEAVE:
	{
		HCURSOR hCursor;
		hCursor = LoadCursor(NULL, IDC_ARROW);
		SetCursor(hCursor);
		mouse_hover = false;
		RECT rc;
		ShowWindow(m_hwnd, SW_HIDE);
		GetClientRect(m_hwnd, &rc);
		InvalidateRect(m_hwnd, NULL, FALSE);
		ShowWindow(m_hwnd, SW_SHOW);
	}
	return 0;
	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}

LRESULT Button_Registration::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
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

	case WM_PAINT:
		ShowWindow(m_hwnd, SW_SHOW);
		Draw_GrapgicResources();
		return 0;

	case WM_MOUSEHOVER:
	{
		HCURSOR hCursor;
		hCursor = LoadCursor(NULL, IDC_HAND);
		SetCursor(hCursor);
		mouse_hover = true;
		RECT rc;
		ShowWindow(m_hwnd, SW_HIDE);
		GetClientRect(m_hwnd, &rc);
		InvalidateRect(m_hwnd, NULL, FALSE);
		ShowWindow(m_hwnd, SW_SHOW);
	}
	return 0;

	case WM_LBUTTONDOWN:
	{
		if (mouse_hover == true)
		{
			//SendMessage(GetParent(m_hwnd), WM_COMMAND, Button_Search_Down, NULL);
		}
	}
	return 0;

	case WM_MOUSELEAVE:
	{
		HCURSOR hCursor;
		hCursor = LoadCursor(NULL, IDC_ARROW);
		SetCursor(hCursor);
		mouse_hover = false;
		RECT rc;
		ShowWindow(m_hwnd, SW_HIDE);
		GetClientRect(m_hwnd, &rc);
		InvalidateRect(m_hwnd, NULL, FALSE);
		ShowWindow(m_hwnd, SW_SHOW);
	}
	return 0;
	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}