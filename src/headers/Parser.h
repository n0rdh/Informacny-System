#pragma once
#include <istream>
#include "IPrikaz.h"

using namespace std;
class Parser
{
private:
	istream* _stream;
	bool prikazUkonceniaSpusteny_;

public:
	Parser(istream* stream);
	Parser(const Parser& other);

	IPrikaz* nacitajPrikaz();
	Parser& operator=(const Parser& ine);

	bool bolPrikazUkonceniaSpusteny() const;
private:
	string spracujPolozkyObjednavky() const;
};

