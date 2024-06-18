#pragma once

#include<windows.h>
#include<d2d1.h>
#include<dwrite.h>

#pragma comment(lib,"d2d1")
#pragma comment(lib,"dwrite")

#include"BaseWindow.h"

#define Button_Liblary_Down 1
#define Button_Show_Down 2
#define Button_Community_Down 3
#define Button_Search_Down 4


class Button_Liblary : public BaseWindow<Button_Liblary>
{
	bool mouse_hover = false;
public:
	PCWSTR ClassName() const { return L"Button liblary class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};
class Button_Shop : public BaseWindow<Button_Shop>
{
	bool mouse_hover = false;
public:
	PCWSTR ClassName() const { return L"Button shop class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};
class Button_Community : public BaseWindow<Button_Community>
{
	bool mouse_hover = false;
public:
	PCWSTR ClassName() const { return L"Button community class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

class Button_Search : public BaseWindow<Button_Search>
{
	bool mouse_hover = false;

	void Draw_GrapgicResources();

public:
	ID2D1DCRenderTarget* m_pRenderTarget;
	ID2D1SolidColorBrush* m_pSolBrush_toolbar_button_search;
	ID2D1SolidColorBrush* m_pSolBrush_text_half;
public:
	PCWSTR ClassName() const { return L"Button search class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

class ToolBar : public BaseWindow<ToolBar>
{
public:
		ID2D1DCRenderTarget* m_pRenderTarget;

		ID2D1GradientStopCollection* m_pGradStopCollection;
		ID2D1LinearGradientBrush* m_pGradBrush_wallpaper;
		ID2D1SolidColorBrush* m_pSolBrush_toolbar;
		ID2D1SolidColorBrush* m_pSolBrush_toolbar_frameSwitch;
		ID2D1SolidColorBrush* m_pSolBrush_toolbar_frameSwitch_caret;
		ID2D1SolidColorBrush* m_pSolBrush_toolbar_button_search;

		IDWriteTextFormat* m_pTextFormat_1;
		ID2D1SolidColorBrush* m_pSolBrush_text_full;
		ID2D1SolidColorBrush* m_pSolBrush_text_half;

private:
		Button_Liblary BT_Liblary;
		Button_Shop BT_Shop;
		Button_Community BT_Community;
		Button_Search    BT_Search;

		void	Draw_GraphicResources();
		void	Discard_GraphicResources();
		void	Send_GraphicResources();

		int frameswitch = 1;
		RECT rc;
		HWND hwnd_enterField_search;
		HFONT hfont_enterField_search;

	public:
		PCWSTR ClassName() const { return L"ToolBar class"; }
		LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};