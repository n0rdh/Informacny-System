#pragma once
#include "Objednavka.h"
#include "Stack.h"
						 
class AutoPrevoz
{

public:
	AutoPrevoz();
	AutoPrevoz(const AutoPrevoz& dalsiaDodavkaP);
	~AutoPrevoz();

	AutoPrevoz& operator=(const AutoPrevoz& dalsiaDodavkaP);
	void pridajObjednavku(Objednavka* novaObjednavka);
	void distribuj();

private:
	DS::Stack<Objednavka*>* objednavky_;
};
