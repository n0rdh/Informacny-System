#pragma once

#include "IPrikaz.h"

class PrikazPrazdny :
	public IPrikaz
{
public:
	void pomoc() override;
	void vykonaj() override;
};

