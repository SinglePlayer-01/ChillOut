#pragma once

#include<Windows.h>
#include<d2d1.h>
#include<dwrite.h>

#pragma comment(lib,"d2d1")
#pragma comment(lib,"dwrite")

#include"BaseWindow.h"
#include"ToolBar.h"

class MainWindow : public BaseWindow<MainWindow>
{
	RECT ClientRect;

	ID2D1Factory* m_pFactory_graphic;
	ID2D1DCRenderTarget* m_pRenderTarget;

	ID2D1GradientStopCollection* m_pGradStopCollection;
	ID2D1LinearGradientBrush* m_pGradBrush_wallpaper;
	ID2D1SolidColorBrush* m_pSolBrush_toolbar;
	ID2D1SolidColorBrush* m_pSolBrush_toolbar_frameSwitch;
	ID2D1SolidColorBrush* m_pSolBrush_toolbar_frameSwitch_caret;

	D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_DEFAULT, D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE), 0, 0, D2D1_RENDER_TARGET_USAGE_NONE, D2D1_FEATURE_LEVEL_DEFAULT);

	IDWriteFactory* m_pFactory_write;
	IDWriteTextFormat* m_pTextFormat_1;
	IDWriteTextFormat* m_pTextFormat_2;
	IDWriteTextFormat* m_pTextFormat_3;
	ID2D1SolidColorBrush* m_pSolBrush_text_full;
	ID2D1SolidColorBrush* m_pSolBrush_text_half;

	HRESULT Create_Factory();
	HRESULT Create_GraphicResources();
	void	Draw_GraphicResources();
	void	Discard_GraphicResources();
	void	Send_GraphicResources();

	int FrameSwitch = 1;

	HWND hwnd_enterField_search;
	HFONT hfont_enterField_search;

	ToolBar TB;

public:
	PCWSTR ClassName() const { return L"Mainwindow class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

