#pragma once
#include <iostream>
#include "Dodavatel.h"

class Mineralna_voda
{
public:
	Mineralna_voda(const std::string& nazovVody, const  std::string& ean,Dodavatel& dodavatel);
	Mineralna_voda(const Mineralna_voda& mineralkaD);																

	Mineralna_voda& operator=(const Mineralna_voda& mineralkaD);
	friend inline bool operator==(const Mineralna_voda& a, const Mineralna_voda& b);

	std::string& dajNazov() const;
	std::string& dajNazovDodavatela() const;
	std::string& dajEAN() const;
	Dodavatel& dajDodavatela() const;

	~Mineralna_voda();
private:
	std::string* ean_;	
	std::string* nazov_;
	Dodavatel* dodavatel_;
};

inline bool operator==(const Mineralna_voda& a, const Mineralna_voda& b)
{
	return *a.ean_ == *b.ean_;
}