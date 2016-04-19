#pragma once

#include <string>

using namespace std;

class IUkladatelny
{
public:

	IUkladatelny()
	{
	}

	virtual ~IUkladatelny()
	{
	}

	virtual string dajPrikazNaUlozenie() const = 0;
};

