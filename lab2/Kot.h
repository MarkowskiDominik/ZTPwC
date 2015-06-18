//ZTP11 Markowski

#ifndef KOT_H
#define KOT_H

#include "Zwierz.h"

class Kot : public Zwierz
{
public:
	Kot();
	Kot(string imie);
	~Kot();

	string pobierzRodzaj() const;
	string pobierzGlos() const;
};

#endif