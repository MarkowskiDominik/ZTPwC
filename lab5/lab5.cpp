//Dominik Markowski

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>
#include <sstream>

using namespace std;

template <class T>
void wypisz(T kontener)
{
	for (auto tmp : kontener) cout << tmp << ", ";
	cout << endl;
}

struct Item
{
	int price, number;
	Item(int price, int number) {
		this->price = price; this->number = number;
	}
};

template <class T>
string concat(const T& napisy)
{
	stringstream zdanie;
	for (auto tmp : napisy) zdanie << tmp << " ";
	return zdanie.str();
}

int main()
{
	vector<int> liczby;
	for (int i = 1; i < 20; i++) liczby.push_back(i);
	cout << "kolekcja liczb:\n";
	wypisz(liczby);

	//ZAD 1
	vector<int> kwadraty;
	transform(liczby.cbegin(), liczby.cend(), back_inserter(kwadraty), [](int x){ return x*x; });
	cout << "\nkolekcja kwadratow liczb:\n";
	wypisz(kwadraty);

	//ZAD 2
	cout << "\nsuma liczb z kolekcji:\n" << accumulate(liczby.cbegin(), liczby.cend(), 0) << endl;

	//ZAD 3
	vector<int> liczby2;
	for (int i = 1; i < 6; i++) liczby2.push_back(i);
	cout << "\niloczyn liczb z zakresu <1;6>:\n" << accumulate(liczby2.cbegin(), liczby2.cend(), 1, [](int ilo, int x){ return ilo * x; }) << endl;

	//ZAD 4
	vector<Item> items;
	for (int i = 1; i < 6; i++) items.push_back(Item(i + 10, i));
	cout << "\nkolekcja Item:\n";
	for (auto tmp : items) cout << "n: " << tmp.number << " p:  " << tmp.price << ",\t";
	cout << "\nsuma cen z kolekcji Item:\n" << accumulate(items.cbegin(), items.cend(), 0, [](int sum, Item x) { return sum + x.price * x.number; }) << endl;

	//ZAD 5
	vector<string> napisy = { "ala", "ma", "kota", "i", "psa" };
	cout << "\nkolekcja napisow:\n";
	wypisz(napisy);
	cout << "\npolaczone napisy\n" << concat(napisy) << endl;

	system("PAUSE");
	return 0;
}