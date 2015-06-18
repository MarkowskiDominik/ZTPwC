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
	for (int i = 0; i < wektor.size(); i++)
		cout << wektor[i] << " ";
	cout << endl;
}

int main()
{
	cout << boolalpha;
	
	Vector<int> wektor_1;
	cout << "\ndomyslny\n" << wektor_1.size() << "\t" << wektor_1.empty();
	cout << "\nwektor 1: "; print(wektor_1);

	Vector<int> wektor_2(3);
	cout << "\nkonstruktor\n" << wektor_2.size() << "\t" << wektor_2.empty();
	cout << "\nwektor 2: "; print(wektor_2);

	Vector<int> wektor_3(wektor_2);
	cout << "\nkopiujacy\n" << wektor_3.size() << "\t" << wektor_3.empty();
	cout << "\nwektor 3: "; print(wektor_3);
	for (int i = 0; i < wektor_2.size(); i++) wektor_2[i] = 0;
	cout << "wektor 3 po zmianie wektora inicjalizujacego: "; print(wektor_3);

	Vector<int> wektor_4(move(wektor_2));
	cout << "\nprzenoszacy\n" << wektor_4.size() << "\t" << wektor_4.empty();
	cout << "\nwektor 4: "; print(wektor_4);
	cout << "\nwektor 2: " << wektor_2.size() << "\t" << wektor_2.empty();
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

	cout << "\noperator przypisania";
	Vector<int> wektor_5 = wektor_3;
	cout << "\nwektor 5: " << wektor_5.size() << "\t" << wektor_5.empty() << "\n\t";
	print(wektor_5);

	cout << "\noperator przniesienia";
	Vector<int> wektor_6 = move(wektor_3);
	cout << "\nwektor 6: " << wektor_6.size() << "\t" << wektor_6.empty() << "\n\t";
	print(wektor_6);
	cout << "wektor 3: " << wektor_3.size() << "\t" << wektor_3.empty() << "\n\t";
	print(wektor_3);

	system("PAUSE");
	return 0;

}