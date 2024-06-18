#include "MainWindow.h"

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CREATE:
			GetClientRect(m_hwnd, &ClientRect);
			Create_Factory();
			Create_GraphicResources();
			
			Send_GraphicResources();

			log.Create(L"LoginWindow", WS_BORDER | WS_VISIBLE, NULL, 500, 500, 600, 400, NULL, NULL);

			TB.Create(NULL, WS_CHILDWINDOW | WS_VISIBLE, NULL, 0, 0, ClientRect.right, 60, m_hwnd, NULL);

		return 0;

		case WM_SIZE:
			DestroyWindow(TB.Window());
			Send_GraphicResources();
			GetClientRect(m_hwnd, &ClientRect);
			TB.Create(NULL, WS_CHILDWINDOW | WS_VISIBLE, NULL, 0, 0, ClientRect.right, 60, m_hwnd, NULL);
		return 0;

		case WM_PAINT:
			Draw_GraphicResources();
			return 0;

		case WM_DESTROY:
			Discard_GraphicResources();
			PostQuitMessage(0);
		return 0;
	
	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}