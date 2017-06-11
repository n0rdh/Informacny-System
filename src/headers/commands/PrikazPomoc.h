#pragma once
#include "IPrikaz.h"
#include <string>

using namespace std;
class PrikazPomoc :
	public IPrikaz
{
private:
	string _param[10];
public:
	PrikazPomoc(string param[]);
	~PrikazPomoc();

	virtual void pomoc() override;
	virtual void vykonaj() override;
};

