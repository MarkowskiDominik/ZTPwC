//Markowski Dominik

#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "Vector.h"
#include "Vector.cpp"

using namespace std;

template <typename T>
void print(T &wektor)
{
	for (unsigned int i = 0; i < wektor.size(); i++)
		cout << wektor[i] << " ";
	cout << endl;
}

int main()
{
	cout << boolalpha;

	Vector<int> wektor_1;
	cout << "\nkonstruktor domyslny";
	cout << "\nwektor 1: " << wektor_1.size() << ", " << wektor_1.empty() << "\t"; print(wektor_1);

	Vector<int> wektor_2(3);
	cout << "\nkonstruktor z rozmiarem 3";
	cout << "\nwektor 2: " << wektor_2.size() << ", " << wektor_2.empty() << "\t"; print(wektor_2);

	Vector<int> wektor_3(wektor_2);
	cout << "\nkonstruktor kopiujacy";
	cout << "\nwektor 3: " << wektor_3.size() << ", " << wektor_3.empty() << "\t"; print(wektor_3);
	for (unsigned int i = 0; i < wektor_2.size(); i++) wektor_2[i] = i;
	cout << "wektor 3 po zmianie wektora inicjalizujacego: "; print(wektor_3);

	Vector<int> wektor_4(move(wektor_2));
	cout << "\nkonstruktor przenoszacy";
	cout << "\nwektor 4: " << wektor_4.size() << ", " << wektor_4.empty() << "\t"; print(wektor_4);
	cout << "\nwektor 2: " << wektor_2.size() << ", " << wektor_2.empty() << "\t"; print(wektor_2);
	try
	{
		cout << wektor_2.at(0);
	}
	catch (out_of_range& oor)
	{
		cout << "\nproba dostepu do elementu wektora 2 - " << oor.what() << '\n';
	}

	cout << "\ntest destruktora\n";
	Vector<int>* p_wektor = new Vector<int>(3);
	delete p_wektor;
	p_wektor = new Vector<int>();
	delete p_wektor;

	cout << "\noperator przypisania";
	Vector<int> wektor_5 = wektor_3;
	cout << "\nwektor 5: " << wektor_5.size() << ", " << wektor_5.empty() << "\t"; print(wektor_5);

	cout << "\noperator przniesienia";
	Vector<int> wektor_6 = move(wektor_3);
	cout << "\nwektor 6: " << wektor_6.size() << ", " << wektor_6.empty() << "\t"; print(wektor_6);
	cout << "wektor 3: " << wektor_3.size() << ", " << wektor_3.empty() << "\t"; print(wektor_3);

	cout << "\ntest swap";
	cout << "\nwektor 4:\t"; print(wektor_4);
	cout << "wektor 6:\t"; print(wektor_6);
	wektor_4.swap(wektor_6);
	cout << "wektor 4:\t"; print(wektor_4);
	cout << "wektor 6:\t"; print(wektor_6);

	cout << "\ntest iteratorow";
	cout << "\nbegin, end:\t";
	for (auto it = wektor_6.begin(); it != wektor_6.end(); it++)
		cout << *it << ", ";
	cout << "\nconst begin, const end:\t";
	for (Vector<int>::const_iterator it = wektor_6.begin(); it != wektor_6.end(); it++)
		cout << *it << ", ";
	cout << "\ncbegin, cend:\t";
	for (auto it = wektor_6.cbegin(); it != wektor_6.cend(); it++)
		cout << *it << ", ";

	cout << endl;
	system("PAUSE");
	return 0;
}