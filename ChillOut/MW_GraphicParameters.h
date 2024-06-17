#pragma once

#include<d2d1.h>

namespace MW
{
	D2D1_COLOR_F color_wallpaper_1 = D2D1::ColorF((UINT32)RGB(74, 34, 29), 1.0f);
	D2D1_COLOR_F color_wallpaper_2 = D2D1::ColorF((UINT32)RGB(109, 52, 101), 1.0f);

	D2D1_COLOR_F color_toolbar = D2D1::ColorF((UINT32)RGB(56, 38, 30), 1.0f);
	D2D1_COLOR_F color_toolbar_frameSwitch = D2D1::ColorF((UINT32)RGB(101, 66, 51), 1.0f);
	D2D1_COLOR_F color_toolbar_frameSwitch_caret = D2D1::ColorF((UINT32)RGB(190, 99, 150),1.0f);

	D2D1_ROUNDED_RECT toolbar_frameSwitch = D2D1::RoundedRect(D2D1::RectF(29, 5, 629, 55), 25, 25);
	D2D1_ROUNDED_RECT toolbar_searche = D2D1::RoundedRect(D2D1::RectF(1103, 5, 1703, 55),25, 25);
	D2D1_ROUNDED_RECT toolbar_frameSwitch_caret = D2D1::RoundedRect(D2D1::RectF(429, 5, 629, 55), 25, 25);
}