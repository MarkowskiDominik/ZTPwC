//ZTP11 Markowski

#include "Pies.h"

using namespace std;

Pies::Pies() : Zwierz()
{
}

Pies::Pies(string imie) : Zwierz(imie)
{
}

Pies::~Pies()
{
}

string Pies::pobierzRodzaj() const
{
	return "Pies";
}

string Pies::pobierzGlos() const
{
	return "Hau Hau";
}
