#pragma once
#include "IPrikaz.h"
class PrikazUkonci :
	public IPrikaz
{
public:
	PrikazUkonci();

	void pomoc() override;
	void vykonaj() override;
};

