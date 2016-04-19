#include "Parser.h"
#include "NazvyPrikazov.h"

#include <string>
#include <iterator>
#include <vector>
#include <sstream>

using namespace std;

Parser::Parser(istream * stream) :
	_stream(stream),
	prikazUkonceniaSpusteny_(false)
{
}

Parser::Parser(const Parser & other) :
	_stream(other._stream),
	prikazUkonceniaSpusteny_(other.prikazUkonceniaSpusteny_)
{
}


IPrikaz * Parser::nacitajPrikaz()
{
	string riadok;
	NazvyPrikazov nazvyPrikazov;

	getline(*_stream, riadok);
	if (_stream->eof() == true) // Koniec suboru
	{
		return nullptr;
	}

	if (riadok.length() == 0) // Prazdny prikaz
	{
		return nazvyPrikazov.dajPrikazBezParametrov("__prazdny__");
	}

	istringstream slovo(riadok);
	istream_iterator<string> zaciatok(slovo), koniec;
	vector<string> slova(zaciatok, koniec);

	if (slova.size() == 0)
	{
		return nazvyPrikazov.dajPrikazBezParametrov("__prazdny__");
	}

	if (slova[0] == "ukonci")
	{
		prikazUkonceniaSpusteny_ = true;
	}
	string param[10];
	for (int i = 0; i < static_cast<int>(slova.size()); i++) {
		param[i] = slova[i];
	}
	if ((slova[0] == "objednavka") && (slova[1] == "pridaj"))
	{
		string polozkyObjednavky = spracujPolozkyObjednavky();
		param[slova.size()] = polozkyObjednavky;
	}

	return nazvyPrikazov.dajPrikaz(param);
}

Parser & Parser::operator=(const Parser & ine)
{
	if (this != &ine) {
		_stream = ine._stream;
		prikazUkonceniaSpusteny_ = ine.prikazUkonceniaSpusteny_;
	}

	return *this;
}

bool Parser::bolPrikazUkonceniaSpusteny() const
{
	return prikazUkonceniaSpusteny_;
}

string Parser::spracujPolozkyObjednavky() const
{
	string zaznamy;
	string oddelovac = "";
	while (true)
	{
		string riadok;
		getline(*_stream, riadok);
		if (_stream->eof())
		{
			return zaznamy;
		}
		if (riadok.length() == 1)
		{
			if (riadok.find(";") != string::npos)
			{
				return zaznamy;
			}
		}
		zaznamy += (oddelovac + riadok);
		oddelovac = " | ";

		if (riadok.find(";") != string::npos)
		{
			return zaznamy;
		}
	}
}
