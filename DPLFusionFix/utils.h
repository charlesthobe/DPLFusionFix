#pragma once

#include <stdint.h>

#include "utils/MemoryMgr.h"

using namespace Memory::VP;

inline void WriteAt(uintptr_t address, const char* buffer, size_t size)
{
	DWORD		dwProtect;
	VirtualProtect((void*)address, size, PAGE_READWRITE, &dwProtect);
	memcpy((void*)address, buffer, size);
	VirtualProtect((void*)address, size, dwProtect, &dwProtect);
}

template <typename T>
inline void WriteAt(uintptr_t address, T value)
{
	DWORD dwProtect;
	VirtualProtect((void*)address, sizeof(T), PAGE_READWRITE, &dwProtect);
	memcpy((void*)address, (void*)&value, sizeof(T));
	VirtualProtect((void*)address, sizeof(T), dwProtect, &dwProtect);
}
