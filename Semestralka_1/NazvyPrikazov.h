#pragma once

#include "IPrikaz.h"

#include <string>

using namespace std;
class NazvyPrikazov
{
public:

	IPrikaz* dajPrikazBezParametrov(string nazov);
	IPrikaz* dajPrikaz(string parametre[]);
	void vypisVsetkyPrikazy();
};