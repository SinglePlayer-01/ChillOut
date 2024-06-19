#pragma once

#include<d2d1.h>

namespace LW
{
	D2D1_COLOR_F color_wallpaper_1 = D2D1::ColorF((UINT32)RGB(74, 34, 29), 1.0f);
	D2D1_COLOR_F color_wallpaper_2 = D2D1::ColorF((UINT32)RGB(109, 52, 101), 1.0f);

	D2D1_COLOR_F color_EnterField_1 = D2D1::ColorF((UINT32)RGB(207, 22, 181),1.0f);
	D2D1_COLOR_F color_EnterField_2 = D2D1::ColorF((UINT32)RGB(164, 171, 33), 1.0f);

	D2D1_COLOR_F color_button_center = D2D1::ColorF((UINT32)RGB(209, 255, 0), 1.0f);

	D2D1_ROUNDED_RECT enterField_Login = D2D1::RoundedRect(D2D1::RectF(100, 74, 500, 124), 25, 25);
	D2D1_ROUNDED_RECT enterField_Password = D2D1::RoundedRect(D2D1::RectF(100, 193, 500, 243), 25, 25);
}