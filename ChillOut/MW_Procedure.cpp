#include "MainWindow.h"

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CREATE:
			Create_Factory();
			Create_GraphicResources();
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