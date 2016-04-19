#pragma once
#include "IPrikaz.h"
class PrikazPredajna :
	public IPrikaz
{
private:
	string _param[10];
public:
	PrikazPredajna(string param[]);
	~PrikazPredajna();

	// Inherited via IPrikaz
	virtual void pomoc() override;
	virtual void vykonaj() override;
};

