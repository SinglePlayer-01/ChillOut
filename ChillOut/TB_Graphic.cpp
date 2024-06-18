#include"ToolBar.h"
#include"TB_GraphicParameters.h"

template <class T> void SafeRelease(T** ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}

void ToolBar::Discard_GraphicResources()
{

    SafeRelease(&m_pRenderTarget);
    SafeRelease(&m_pGradStopCollection);
    SafeRelease(&m_pGradBrush_wallpaper);
    SafeRelease(&m_pSolBrush_toolbar);
    SafeRelease(&m_pSolBrush_toolbar_frameSwitch);
    SafeRelease(&m_pSolBrush_toolbar_frameSwitch_caret);

    SafeRelease(&m_pTextFormat_1);

    SafeRelease(&m_pSolBrush_text_full);
    SafeRelease(&m_pSolBrush_text_half);
}

void ToolBar::Draw_GraphicResources()
{
    RECT Client_Rect;
    GetClientRect(m_hwnd, &Client_Rect);

        PAINTSTRUCT ps{ };

        HDC hdc = BeginPaint(m_hwnd, &ps);

        m_pRenderTarget->BindDC(hdc, &Client_Rect);
        m_pRenderTarget->BeginDraw();

        m_pRenderTarget->FillRectangle(D2D1::RectF(0, 0, Client_Rect.right, Client_Rect.bottom), m_pGradBrush_wallpaper);
        m_pRenderTarget->FillRectangle(D2D1::RectF(0, 0, Client_Rect.right, 60), m_pSolBrush_toolbar);
        m_pRenderTarget->FillRoundedRectangle(TB::toolbar_frameSwitch, m_pSolBrush_toolbar_frameSwitch);
        m_pRenderTarget->FillRoundedRectangle(TB::toolbar_searche, m_pSolBrush_toolbar_frameSwitch);
        switch (frameswitch)
        {
        case 1:
            m_pRenderTarget->FillRoundedRectangle(TB::toolbar_frameSwitch_caret_1, m_pSolBrush_toolbar_frameSwitch_caret);
            break;

        case 2:
            m_pRenderTarget->FillRoundedRectangle(TB::toolbar_frameSwitch_caret_2, m_pSolBrush_toolbar_frameSwitch_caret);
            break;

        case 3:
            m_pRenderTarget->FillRoundedRectangle(TB::toolbar_frameSwitch_caret_3, m_pSolBrush_toolbar_frameSwitch_caret);
            break;
        }
        m_pRenderTarget->DrawText(L"Liblary", ARRAYSIZE(L"Liblary"), m_pTextFormat_1, D2D1::RectF(29, 5, 229, 55), m_pSolBrush_text_full);
        m_pRenderTarget->DrawText(L"Shop", ARRAYSIZE(L"Liblary"), m_pTextFormat_1, D2D1::RectF(229, 5, 429, 55), m_pSolBrush_text_full);
        m_pRenderTarget->DrawText(L"Community", ARRAYSIZE(L"Liblary"), m_pTextFormat_1, D2D1::RectF(429, 5, 629, 55), m_pSolBrush_text_full);
        m_pRenderTarget->EndDraw();

        EndPaint(m_hwnd, &ps);
}
void Button_Search::Draw_GrapgicResources()
{
    RECT Client_Rect;
    GetClientRect(m_hwnd, &Client_Rect);

    PAINTSTRUCT ps{ };

    HDC hdc = BeginPaint(m_hwnd, &ps);

    m_pRenderTarget->BindDC(hdc, &Client_Rect);
    m_pRenderTarget->BeginDraw();

    if (mouse_hover == true)
    {
        m_pRenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(12.14,12.14), 12, 12),m_pSolBrush_toolbar_button_search,2);
        m_pRenderTarget->DrawLine(D2D1::Point2F(19.58, 19.8), D2D1::Point2F(38, 30), m_pSolBrush_toolbar_button_search, 2);
    }
    else
    {
        m_pRenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(12.14, 12.14), 12, 12), m_pSolBrush_text_half, 2);
        m_pRenderTarget->DrawLine(D2D1::Point2F(19.58, 19.8), D2D1::Point2F(38, 30), m_pSolBrush_text_half, 2);
    }

    m_pRenderTarget->EndDraw();

    EndPaint(m_hwnd, &ps);
}

void ToolBar::Send_GraphicResources()
{
    BT_Search.m_pRenderTarget = m_pRenderTarget;
    BT_Search.m_pSolBrush_text_half = m_pSolBrush_text_half;
    BT_Search.m_pSolBrush_toolbar_button_search = m_pSolBrush_toolbar_button_search;
}