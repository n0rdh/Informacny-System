#pragma once

#include <string>

using namespace std;

class Uloz
{
public:

	Uloz()
	{
	}

	virtual ~Uloz()
	{
	}

	virtual string dajPrikazNaUlozenie() const = 0;
};

