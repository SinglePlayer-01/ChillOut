#pragma once

#include<Windows.h>
#include<d2d1.h>
#include<dwrite.h>

#pragma comment(lib,"d2d1")
#pragma comment(lib,"dwrite")

#include"BaseWindow.h"


class Button_help : public BaseWindow<Button_help>
{
	bool mouse_hover = false;

	void Draw_GrapgicResources();
public:
	ID2D1DCRenderTarget* m_pRenderTarget;

	IDWriteTextFormat* m_pTextFormat_2;

	ID2D1SolidColorBrush* m_pSolBrush_text_full;
	ID2D1SolidColorBrush* m_pSolBrush_text_half;

public:
	PCWSTR ClassName() const { return L"Button help class";}
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};
class Button_Registration : public BaseWindow<Button_Registration>
{
	bool mouse_hover = false;

	void Draw_GrapgicResources();
public:
	ID2D1DCRenderTarget* m_pRenderTarget;

	IDWriteTextFormat* m_pTextFormat_2;

	ID2D1SolidColorBrush* m_pSolBrush_text_full;
	ID2D1SolidColorBrush* m_pSolBrush_text_half;

public:
	PCWSTR ClassName() const { return L"Button Registration class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

class Button_Google : public BaseWindow<Button_Google>
{
	bool mouse_hover = false;

	void Draw_GrapgicResources();
public:
	ID2D1DCRenderTarget* m_pRenderTarget;


	ID2D1SolidColorBrush* m_pSolBrush_text_full;
	ID2D1SolidColorBrush* m_pSolBrush_text_half;

public:
	PCWSTR ClassName() const { return L"Button Google class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};
class Button_Center : public BaseWindow<Button_Center>
{
	bool mouse_hover = false;

	void Draw_GrapgicResources();
public:
	ID2D1DCRenderTarget* m_pRenderTarget;


	ID2D1SolidColorBrush* m_pSolBrush_button_center;

public:
	PCWSTR ClassName() const { return L"Button Center class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};
class Button_Telegram : public BaseWindow<Button_Telegram>
{
	bool mouse_hover = false;

	void Draw_GrapgicResources();
public:
	ID2D1DCRenderTarget* m_pRenderTarget;

	ID2D1SolidColorBrush* m_pSolBrush_text_full;
	ID2D1SolidColorBrush* m_pSolBrush_text_half;

public:
	PCWSTR ClassName() const { return L"Button Telegram class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

class LoginWindow : public BaseWindow<LoginWindow>
{
	Button_help			BT_help;
	Button_Registration BT_Registration;

	Button_Google	BT_Google;
	Button_Center	BT_Center;
	Button_Telegram BT_Telegram;

	RECT ClientRect;
public:
	ID2D1Factory* m_pFactory_graphic;
	IDWriteFactory* m_pFactory_write;
private:
	ID2D1DCRenderTarget* m_pRenderTarget;

	ID2D1GradientStopCollection* m_pGradStopCollection;
	ID2D1LinearGradientBrush* m_pGradBrush_wallpaper;
	ID2D1LinearGradientBrush* m_pGradBrush_enterfield;

	ID2D1SolidColorBrush* m_pSolBrush_button_center;

	D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_DEFAULT, D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE), 0, 0, D2D1_RENDER_TARGET_USAGE_NONE, D2D1_FEATURE_LEVEL_DEFAULT);

	IDWriteTextFormat* m_pTextFormat_1;
	IDWriteTextFormat* m_pTextFormat_2;
	IDWriteTextFormat* m_pTextFormat_3;
	ID2D1SolidColorBrush* m_pSolBrush_text_full;
	ID2D1SolidColorBrush* m_pSolBrush_text_half;

	HRESULT Create_GraphicResources();
	void	Draw_GraphicResources();
	void	Discard_GraphicResources();
	void	Send_GraphicResources();

public:
	PCWSTR ClassName() const { return L"Login window class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

