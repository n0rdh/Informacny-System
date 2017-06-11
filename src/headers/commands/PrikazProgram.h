#pragma once
#include "IPrikaz.h"
#include <string>

using namespace std;
class PrikazProgram :
	public IPrikaz
{
private:
	string _param[10];
public:
	PrikazProgram(string param[]);
	~PrikazProgram();

	void pomoc() override;
	void vykonaj() override;
private:
	static void nacitajZoSuboru();
	static void ulozDoSuboru();
};

