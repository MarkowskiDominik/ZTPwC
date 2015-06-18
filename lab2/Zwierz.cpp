//ZTP11 Markowski

#include "Zwierz.h"

using namespace std;

Zwierz::Zwierz()
{
}

Zwierz::Zwierz(string imie)
{
	this->imie = imie;
}

Zwierz::~Zwierz()
{
}

string Zwierz::pobierzImie()
{
	return imie;
}

ostream& operator<<(std::ostream&os, Zwierz& z)
{
	return os << z.pobierzRodzaj() << " " + z.pobierzImie() << " daje g³os " << z.pobierzGlos() << "!";
}