#pragma once
#include "IPrikaz.h"
class PrikazDodavatel :
	public IPrikaz
{
private:
	string _param[10];
public:
	PrikazDodavatel(string param[]);
	~PrikazDodavatel();

	// Inherited via IPrikaz
	virtual void pomoc() override;
	virtual void vykonaj() override;
};

