#pragma once
#include <iostream>
#include "Dodavatel.h"
#include "IUkladatelny.h"

class Mineralna_voda  : public IUkladatelny
{
public:
	Mineralna_voda(const std::string& nazovVody, const  std::string& ean,Dodavatel& dodavatel);
	Mineralna_voda(const Mineralna_voda& mineralkaD);																

	Mineralna_voda& operator=(const Mineralna_voda& mineralkaD);
	friend inline bool operator==(const Mineralna_voda& prva, const Mineralna_voda& druha);

	const std::string& dajNazov() const;
	const std::string& dajNazovDodavatela() const;
	std::string& dajEAN() const;
	Dodavatel * dajDodavatela() const;
	std::string dajPrikazNaUlozenie() const override;
	~Mineralna_voda();
private:
	std::string* ean_;	
	std::string* nazov_;
	Dodavatel* dodavatel_;
};
inline bool operator==(const Mineralna_voda& prva, const Mineralna_voda& druha)
{
	return *prva.ean_ == *druha.ean_;
}