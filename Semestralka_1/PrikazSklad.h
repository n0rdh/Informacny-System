#pragma once
#include "IPrikaz.h"
#include <string>

using namespace std;
class PrikazSklad :
	public IPrikaz
{
private:
	string _param[10];
public:
	PrikazSklad(string param[]);
	~PrikazSklad();

	virtual void pomoc() override;
	virtual void vykonaj() override;
};

