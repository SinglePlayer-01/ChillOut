#include"MainWindow.h"
#include"MW_GraphicParameters.h"

template <class T> void SafeRelease(T** ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}

void MainWindow::Discard_GraphicResources()
{
    SafeRelease(&m_pFactory_graphic);
    SafeRelease(&m_pRenderTarget);
    SafeRelease(&m_pGradStopCollection);
    SafeRelease(&m_pGradBrush_wallpaper);
    SafeRelease(&m_pSolBrush_toolbar);
    SafeRelease(&m_pSolBrush_toolbar_frameSwitch);
    SafeRelease(&m_pSolBrush_toolbar_frameSwitch_caret);
    SafeRelease(&m_pFactory_write);
    SafeRelease(&m_pTextFormat_1);
    SafeRelease(&m_pTextFormat_2);
    SafeRelease(&m_pTextFormat_3);
    SafeRelease(&m_pSolBrush_text_full);
    SafeRelease(&m_pSolBrush_text_half);
}

HRESULT MainWindow::Create_Factory()
{
    HRESULT hr = S_OK;
    if (D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pFactory_graphic) == S_FALSE)   return S_FALSE;
    if (DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&m_pFactory_write)) == S_FALSE) return S_FALSE;
    return hr;
}

HRESULT MainWindow::Create_GraphicResources()
{
    HRESULT hr = S_OK;

    RECT rc;
    GetClientRect(m_hwnd, &rc);

    if (m_pRenderTarget == NULL)
    {
        hr = m_pFactory_graphic->CreateDCRenderTarget(&props, &m_pRenderTarget);
        if (hr == S_OK)
        {
            D2D1_GRADIENT_STOP stop[2];
            stop[0].color = MW::color_wallpaper_1;
            stop[0].position = 0.0f;
            stop[1].color = MW::color_wallpaper_2;
            stop[1].position = 1.0f;

            m_pRenderTarget->CreateGradientStopCollection(stop, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &m_pGradStopCollection);

            hr = m_pRenderTarget->CreateLinearGradientBrush(D2D1::LinearGradientBrushProperties(D2D1::Point2F(0, 0), D2D1::Point2F(rc.right, rc.bottom)), m_pGradStopCollection, &m_pGradBrush_wallpaper);
        }
        if (hr == S_OK)
        {
            m_pRenderTarget->CreateSolidColorBrush(MW::color_toolbar, &m_pSolBrush_toolbar);
            m_pRenderTarget->CreateSolidColorBrush(MW::color_toolbar_frameSwitch, &m_pSolBrush_toolbar_frameSwitch);
            m_pRenderTarget->CreateSolidColorBrush(MW::color_toolbar_frameSwitch_caret, &m_pSolBrush_toolbar_frameSwitch_caret);
            m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &m_pSolBrush_text_full);
            m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Gray), &m_pSolBrush_text_half);
        }
        if (hr == S_OK)
        {
            m_pFactory_write->CreateTextFormat(L"Stadio Now Monolinea", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 24.0f, L"en-us", &m_pTextFormat_1);
            m_pFactory_write->CreateTextFormat(L"Stadio Now Monolinea", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 14.0f, L"en-us", &m_pTextFormat_2);
            m_pFactory_write->CreateTextFormat(L"Stadio Now Monolinea", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 14.0f, L"en-us", &m_pTextFormat_3);

            m_pTextFormat_1->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            m_pTextFormat_1->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

            m_pTextFormat_2->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            m_pTextFormat_2->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

            m_pTextFormat_3->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            m_pTextFormat_3->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
        }
    }
    return hr;
}

void MainWindow::Draw_GraphicResources()
{
    HRESULT hr = Create_GraphicResources();
    RECT Client_Rect;
    GetClientRect(m_hwnd, &Client_Rect);
    if (hr == S_OK)
    {
        PAINTSTRUCT ps{ };

        HDC hdc = BeginPaint(m_hwnd, &ps);

        m_pRenderTarget->BindDC(hdc, &Client_Rect);
        m_pRenderTarget->BeginDraw();

        m_pRenderTarget->FillRectangle(D2D1::RectF(0, 0, Client_Rect.right, Client_Rect.bottom), m_pGradBrush_wallpaper);
        m_pRenderTarget->FillRectangle(D2D1::RectF(0, 0, Client_Rect.right,60), m_pSolBrush_toolbar);
        m_pRenderTarget->FillRoundedRectangle(MW::toolbar_frameSwitch, m_pSolBrush_toolbar_frameSwitch);
        m_pRenderTarget->FillRoundedRectangle(MW::toolbar_searche, m_pSolBrush_toolbar_frameSwitch);
        switch (FrameSwitch)
        {
            case 1:
                m_pRenderTarget->FillRoundedRectangle(MW::toolbar_frameSwitch_caret_1, m_pSolBrush_toolbar_frameSwitch_caret);
            break;

            case 2:
                m_pRenderTarget->FillRoundedRectangle(MW::toolbar_frameSwitch_caret_2, m_pSolBrush_toolbar_frameSwitch_caret);
            break;

            case 3:
                m_pRenderTarget->FillRoundedRectangle(MW::toolbar_frameSwitch_caret_3, m_pSolBrush_toolbar_frameSwitch_caret);
            break;
        }
        m_pRenderTarget->DrawText(L"Liblary", ARRAYSIZE(L"Liblary"), m_pTextFormat_1,   D2D1::RectF(29, 5, 229, 55), m_pSolBrush_text_full);
        m_pRenderTarget->DrawText(L"Shop", ARRAYSIZE(L"Liblary"), m_pTextFormat_1,      D2D1::RectF(229, 5, 429, 55), m_pSolBrush_text_full);
        m_pRenderTarget->DrawText(L"Community", ARRAYSIZE(L"Liblary"), m_pTextFormat_1, D2D1::RectF(429, 5, 629, 55), m_pSolBrush_text_full);
        m_pRenderTarget->EndDraw();

        EndPaint(m_hwnd, &ps);

    }
}