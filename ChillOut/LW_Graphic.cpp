#include"LoginWindow.h"
#include"LW_GraphicParameters.h"

template <class T> void SafeRelease(T** ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}

void LoginWindow::Discard_GraphicResources()
{

    SafeRelease(&m_pRenderTarget);
    SafeRelease(&m_pGradStopCollection);
    SafeRelease(&m_pGradBrush_wallpaper);
    SafeRelease(&m_pGradBrush_enterfield);
    SafeRelease(&m_pSolBrush_button_center);

    SafeRelease(&m_pTextFormat_1);
    SafeRelease(&m_pTextFormat_2);
    SafeRelease(&m_pTextFormat_3);
    SafeRelease(&m_pSolBrush_text_full);
    SafeRelease(&m_pSolBrush_text_half);
}

HRESULT LoginWindow::Create_GraphicResources()
{
    HRESULT hr = S_OK;
    if (m_pRenderTarget == NULL)
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
                stop[0].color = LW::color_wallpaper_1;
                stop[0].position = 0.0f;
                stop[1].color = LW::color_wallpaper_2;
                stop[1].position = 1.0f;

                m_pRenderTarget->CreateGradientStopCollection(stop, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &m_pGradStopCollection);

                hr = m_pRenderTarget->CreateLinearGradientBrush(D2D1::LinearGradientBrushProperties(D2D1::Point2F(0, 0), D2D1::Point2F(rc.right, rc.bottom)), m_pGradStopCollection, &m_pGradBrush_wallpaper);
            }
            if (hr == S_OK)
            {
                D2D1_GRADIENT_STOP stop[2];
                stop[0].color = LW::color_EnterField_1;
                stop[0].position = 0.0f;
                stop[1].color = LW::color_EnterField_2;
                stop[1].position = 1.0f;

                m_pRenderTarget->CreateGradientStopCollection(stop, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &m_pGradStopCollection);

                hr = m_pRenderTarget->CreateLinearGradientBrush(D2D1::LinearGradientBrushProperties(D2D1::Point2F(100, 0), D2D1::Point2F(500, 0)), m_pGradStopCollection, &m_pGradBrush_enterfield);
            }
            if (hr == S_OK)
            {

                m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &m_pSolBrush_text_full);
                m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Gray), &m_pSolBrush_text_half);
                m_pRenderTarget->CreateSolidColorBrush(LW::color_button_center, &m_pSolBrush_button_center);
            }
            if (hr == S_OK)
            {
                m_pFactory_write->CreateTextFormat(L"Stadio Now Monolinea", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 40.0f, L"en-us", &m_pTextFormat_1);
                m_pFactory_write->CreateTextFormat(L"Stadio Now Monolinea", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 20.0f, L"en-us", &m_pTextFormat_2);
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
}

void LoginWindow::Draw_GraphicResources()
{
    RECT Client_Rect;
    GetClientRect(m_hwnd, &Client_Rect);

    PAINTSTRUCT ps{ };

    HDC hdc = BeginPaint(m_hwnd, &ps);

    m_pRenderTarget->BindDC(hdc, &Client_Rect);
    m_pRenderTarget->BeginDraw();

    m_pRenderTarget->FillRectangle(D2D1::RectF(0, 0, Client_Rect.right, Client_Rect.bottom), m_pGradBrush_wallpaper);
    m_pRenderTarget->DrawRoundedRectangle(LW::enterField_Login, m_pGradBrush_enterfield, 2);
    m_pRenderTarget->DrawRoundedRectangle(LW::enterField_Password, m_pGradBrush_enterfield, 2);
    m_pRenderTarget->DrawText(L"Login", ARRAYSIZE(L"Login"), m_pTextFormat_1,D2D1::RectF(100, 20, 500, 72),m_pSolBrush_text_full);
    m_pRenderTarget->DrawText(L"Password", ARRAYSIZE(L"Password"), m_pTextFormat_1, D2D1::RectF(100, 139, 500, 191), m_pSolBrush_text_full);

    m_pRenderTarget->EndDraw();

    EndPaint(m_hwnd, &ps);
}
void LoginWindow::Send_GraphicResources()
{
    BT_help.m_pRenderTarget = m_pRenderTarget;
    BT_help.m_pSolBrush_text_half = m_pSolBrush_text_half;
    BT_help.m_pSolBrush_text_full = m_pSolBrush_text_full;
    BT_help.m_pTextFormat_2 = m_pTextFormat_2;

    BT_Registration.m_pRenderTarget = m_pRenderTarget;
    BT_Registration.m_pSolBrush_text_half = m_pSolBrush_text_half;
    BT_Registration.m_pSolBrush_text_full = m_pSolBrush_text_full;
    BT_Registration.m_pTextFormat_2 = m_pTextFormat_2;

    BT_Google.m_pRenderTarget = m_pRenderTarget;
    BT_Google.m_pSolBrush_text_half = m_pSolBrush_text_half;
    BT_Google.m_pSolBrush_text_full = m_pSolBrush_text_full;

    BT_Center.m_pRenderTarget = m_pRenderTarget;
    BT_Center.m_pSolBrush_button_center = m_pSolBrush_button_center;

    BT_Telegram.m_pRenderTarget = m_pRenderTarget;
    BT_Telegram.m_pSolBrush_text_half = m_pSolBrush_text_half;
    BT_Telegram.m_pSolBrush_text_full = m_pSolBrush_text_full;
}


void Button_help::Draw_GrapgicResources()
{
    RECT Client_Rect;
    GetClientRect(m_hwnd, &Client_Rect);

    PAINTSTRUCT ps{ };

    HDC hdc = BeginPaint(m_hwnd, &ps);

    m_pRenderTarget->BindDC(hdc, &Client_Rect);
    m_pRenderTarget->BeginDraw();

    if(mouse_hover == true) m_pRenderTarget->DrawText(L"Help", ARRAYSIZE(L"Help"), m_pTextFormat_2, D2D1::RectF(0, 0, Client_Rect.right, Client_Rect.bottom), m_pSolBrush_text_full);
    else                    m_pRenderTarget->DrawText(L"Help", ARRAYSIZE(L"Help"), m_pTextFormat_2, D2D1::RectF(0, 0, Client_Rect.right, Client_Rect.bottom), m_pSolBrush_text_half);

    m_pRenderTarget->EndDraw();

    EndPaint(m_hwnd, &ps);
}
void Button_Registration::Draw_GrapgicResources()
{
    RECT Client_Rect;
    GetClientRect(m_hwnd, &Client_Rect);

    PAINTSTRUCT ps{ };

    HDC hdc = BeginPaint(m_hwnd, &ps);

    m_pRenderTarget->BindDC(hdc, &Client_Rect);
    m_pRenderTarget->BeginDraw();

    if (mouse_hover == true) m_pRenderTarget->DrawText(L"Registation", ARRAYSIZE(L"Registation"), m_pTextFormat_2, D2D1::RectF(0, 0, Client_Rect.right, Client_Rect.bottom), m_pSolBrush_text_full);
    else                    m_pRenderTarget->DrawText(L"Registation", ARRAYSIZE(L"Registation"), m_pTextFormat_2, D2D1::RectF(0, 0, Client_Rect.right, Client_Rect.bottom), m_pSolBrush_text_half);

    m_pRenderTarget->EndDraw();

    EndPaint(m_hwnd, &ps);
}

void Button_Google::Draw_GrapgicResources()
{
    RECT Client_Rect;
    GetClientRect(m_hwnd, &Client_Rect);

    PAINTSTRUCT ps{ };

    HDC hdc = BeginPaint(m_hwnd, &ps);

    m_pRenderTarget->BindDC(hdc, &Client_Rect);
    m_pRenderTarget->BeginDraw();

    if (mouse_hover == true) m_pRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(Client_Rect.right / 2, Client_Rect.bottom / 2),Client_Rect.right / 2, Client_Rect.bottom / 2),m_pSolBrush_text_full);
    else m_pRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(Client_Rect.right / 2, Client_Rect.bottom / 2), Client_Rect.right / 2, Client_Rect.bottom / 2), m_pSolBrush_text_half);

    m_pRenderTarget->EndDraw();

    EndPaint(m_hwnd, &ps);
}
void Button_Center::Draw_GrapgicResources()
{
    RECT Client_Rect;
    GetClientRect(m_hwnd, &Client_Rect);

    PAINTSTRUCT ps{ };

    HDC hdc = BeginPaint(m_hwnd, &ps);

    m_pRenderTarget->BindDC(hdc, &Client_Rect);
    m_pRenderTarget->BeginDraw();

    m_pRenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(Client_Rect.right / 2, Client_Rect.bottom / 2), Client_Rect.right / 2 - 1, Client_Rect.bottom / 2 - 1), m_pSolBrush_button_center,1.4);
    m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(-45, D2D1::Point2F((20,25))));
    m_pRenderTarget->FillRectangle(D2D1::RectF(12, 16, 31, 21), m_pSolBrush_button_center);
    m_pRenderTarget->FillRectangle(D2D1::RectF(12, 16,17, 35), m_pSolBrush_button_center);
    m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

    m_pRenderTarget->EndDraw();

    EndPaint(m_hwnd, &ps);
}
void Button_Telegram::Draw_GrapgicResources()
{
    RECT Client_Rect;
    GetClientRect(m_hwnd, &Client_Rect);

    PAINTSTRUCT ps{ };

    HDC hdc = BeginPaint(m_hwnd, &ps);

    m_pRenderTarget->BindDC(hdc, &Client_Rect);
    m_pRenderTarget->BeginDraw();

    if (mouse_hover == true) m_pRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(Client_Rect.right / 2, Client_Rect.bottom / 2), Client_Rect.right / 2, Client_Rect.bottom / 2), m_pSolBrush_text_full);
    else m_pRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(Client_Rect.right / 2, Client_Rect.bottom / 2), Client_Rect.right / 2, Client_Rect.bottom / 2), m_pSolBrush_text_half);

    m_pRenderTarget->EndDraw();

    EndPaint(m_hwnd, &ps);
}