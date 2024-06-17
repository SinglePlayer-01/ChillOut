#pragma once

#include<d2d1.h>

namespace TB
{
	D2D1_ROUNDED_RECT toolbar_frameSwitch = D2D1::RoundedRect(D2D1::RectF(29, 5, 629, 55), 25, 25);
	D2D1_ROUNDED_RECT toolbar_searche = D2D1::RoundedRect(D2D1::RectF(1103, 5, 1703, 55), 25, 25);

	D2D1_ROUNDED_RECT toolbar_frameSwitch_caret_1 = D2D1::RoundedRect(D2D1::RectF(29, 5, 229, 55), 25, 25);
	D2D1_ROUNDED_RECT toolbar_frameSwitch_caret_2 = D2D1::RoundedRect(D2D1::RectF(229, 5, 429, 55), 25, 25);
	D2D1_ROUNDED_RECT toolbar_frameSwitch_caret_3 = D2D1::RoundedRect(D2D1::RectF(429, 5, 629, 55), 25, 25);
}