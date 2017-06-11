#pragma once
#include "IPrikaz.h"
#include <string>

using namespace std;
class PrikazDodavka :
	public IPrikaz
{
private:
	string _param[10];
public:
	PrikazDodavka(string param[]);
	~PrikazDodavka();

	// Inherited via IPrikaz
	virtual void pomoc() override;
	virtual void vykonaj() override;
};

