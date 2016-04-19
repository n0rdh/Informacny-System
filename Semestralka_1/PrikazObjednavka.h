#pragma once
#include "IPrikaz.h"
#include <string>

using namespace std;
class PrikazObjednavka :
	public IPrikaz
{
private:
	string parameter[10];
public:
	PrikazObjednavka(string param[]);
	~PrikazObjednavka();

	// Inherited via IPrikaz
	virtual void pomoc() override;
	virtual void vykonaj() override;
};

