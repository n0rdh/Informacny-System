#pragma once
#include "IPrikaz.h"
#include <string>

using namespace std;
class PrikazZakaznik :
	public IPrikaz
{
private:
	string _param[10];
public:
	PrikazZakaznik(string param[]);
	~PrikazZakaznik();

	// Inherited via IPrikaz
	virtual void pomoc() override;
	virtual void vykonaj() override;
};

