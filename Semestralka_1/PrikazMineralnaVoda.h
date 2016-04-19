#pragma once
#include "IPrikaz.h"
class PrikazMineralnaVoda :
	public IPrikaz
{
private:
	string _param[10];
public:
	PrikazMineralnaVoda(string param[]);
	~PrikazMineralnaVoda();

	// Inherited via IPrikaz
	virtual void pomoc() override;
	virtual void vykonaj() override;
};

