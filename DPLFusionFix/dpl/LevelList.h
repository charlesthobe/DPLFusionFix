#pragma once
#include <iostream>

class CLevelList
{
public:
	int m_uCurrentLevel;
	int m_uLevels;
	char* buffer;

	char* GetLevelName(int nLevel);

	void NextLevel();
	void PreviousLevel();

	int GetLevelIndex();
	void SetLevelIndex(int nLevel);

	void SetCurrentCharacter(int characterId);
	int GetCurrentCharacter();

	int GetNumberOfStartPoints();
	int GetNumLevels();

	int GetCurrentStartPoint();
	void SetCurrentStartPoint(int uLevel);

	void NextStartPoint();
	void PreviousStartPoint();

	char* GetCurrentStartPointName();
};

CLevelList* GetLevelList();