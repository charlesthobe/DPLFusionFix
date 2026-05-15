#pragma once
//#define _SHOW_WINDOW_ON_CREATE

#include <iostream>

static float g_fPedDensityBaseNoPingInRadius;
static float g_fPedDensitySubtractionNoPingInRadius;
static float g_fPedDensityDensityMultiplier;

HWND CreateCustomWindow(HINSTANCE hamsterModule, DWORD zero);
