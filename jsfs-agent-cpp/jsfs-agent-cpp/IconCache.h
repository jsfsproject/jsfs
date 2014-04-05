#pragma once

#include "Byps.h"

class IconCache
{
	IconCache(void);
public:
	static byps::PBytes getPngIcon(const std::wstring& fname);
};

