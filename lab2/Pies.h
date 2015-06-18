//ZTP11 Markowski

#ifndef PIES_H
#define PIES_H

#include "Zwierz.h"

class Pies : public Zwierz
{
public:
	Pies();
	Pies(string imie);
	~Pies();

	string pobierzRodzaj() const;
	string pobierzGlos() const;
};

#endif