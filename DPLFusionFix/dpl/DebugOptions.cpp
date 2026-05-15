#include "DebugOptions.h"

using namespace Memory::VP;

bool bDebug_ShowVersion = false;
bool bDebug_ShowFPS = false;
bool bDebug_CompleteMission = false;
bool bDebug_Display_HUD_and_Map = true;
bool bDebug_OverrideTime = false;
bool bDebug_OverrideRateOfTime = false;
bool bDebug_PlayerAlwaysEnabled = false;
bool bDebug_DisableLoadingScreen = false;
bool bDebug_InvincibleToWater = false;
bool bDebug_NoCollisions = false;

int bDebug_SetTimeHours = 13;

bool bDebug_OverrideGameDiff = false;
int bDebug_SetGameDiff = 0;
int bDebug_Max_SetGameDiff = 1000;
int bDebug_Min_SetGameDiff = 0;

void Update_Debug_DisableLoadingScreen()
{
	if (bDebug_DisableLoadingScreen)
	{
		Patch(0x4a76ef, {0xC2, 0x04, 0x00});
	}
	else
	{
		Patch(0x4a76ef, {0x56, 0x8B, 0xF1});
	}
}

void Update_Debug_InvincibleToWater()
{
	if (bDebug_InvincibleToWater)
	{
		Nop(0x4A268D, 6);
		InjectHook(0x4A268D, 0x4A27A5, HookType::Jump);
	}
	else
	{
		Patch(0x4A268D, {0x0F, 0x84, 0x12, 0x01, 0x00, 0x00});
	}
}

void Set_Debug_Cop2006InitWep(char newOne)
{
	Patch<char>(0x430046 + 0x1, newOne);
}

void Set_Debug_Cop1978InitWep(char newOne)
{
	Patch<char>(0x43004a + 0x1, newOne);
}

void Update_Debug_NoCollisions()
{
	if (bDebug_NoCollisions)
	{
		Patch<uint8_t>(0x5ccd9d, 0xc3);
	}
	else
	{
		Patch<uint8_t>(0x5ccd9d, 0x55);
	}
}
