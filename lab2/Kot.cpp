//ZTP11 Markowski

#include "Kot.h"

using namespace std;

Kot::Kot() : Zwierz()
{
}

Kot::Kot(string imie) : Zwierz(imie)
{
}

Kot::~Kot()
{
}

string Kot::pobierzRodzaj() const
{
	return "Kot";
}

string Kot::pobierzGlos() const
{
	return "Miau Miau";
}
