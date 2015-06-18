//ZTP11 Markowski

#ifndef ZWIERZ_H
#define ZWIERZ_H

#include<string>
#include<iostream>

using namespace std;

class Zwierz
{
public:
	Zwierz();
	Zwierz(string imie);
	~Zwierz();

	virtual string pobierzRodzaj() const = 0;
	string pobierzImie();
	virtual string pobierzGlos() const = 0;
private:
	std::string imie;
};

std::ostream& operator<<(std::ostream&os, Zwierz& z);
#endif