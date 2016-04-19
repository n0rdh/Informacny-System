#pragma once
#include "System.h"
#include "Velkosklad.h"
#include <iostream>
class IPrikaz
{
public:

	IPrikaz()
	{
	}

	~IPrikaz()
	{
	}

	virtual void pomoc() = 0;
	virtual void vykonaj() = 0;
};