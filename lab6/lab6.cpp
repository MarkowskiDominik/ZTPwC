//Dominik Markowski

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <regex>

using namespace std;

bool czyZPrzedzialu(int number, int x, int y)
{
	return x <= number && number <= y;
}

template<class T1, class T2>
struct Pair
{
	T1 first;
	T2 second;

	//ZAD 2a - konstruktory
	Pair() : first(), second()
	{}

	Pair(const T1 &Val1, const T2 &Val2) : first(Val1), second(Val2)
	{}

	template<class TF, class TS>
	Pair(const Pair<TF, TS> &tmp) : first(tmp.first), second(tmp.second)
	{}

	//ZAD 2b - operator przypisania
	template<class TF, class TS>
	Pair& operator= (const Pair<TF, TS>& tmp)
	{
		first = tmp.first;
		second = tmp.second;
		return *this;
	}

	//ZAD 2d - operator porownania
	template<class TF, class TS>
	bool operator== (const Pair<TF, TS>& tmp)
	{
		return (first == tmp.first && second == tmp.second);
	}

	//ZAD 2e - operator porownania leksykograficznego
	template<class TF, class TS>
	bool operator< (const Pair<TF, TS>& tmp)
	{
		if (first == tmp.first)
		{
			if (second <= tmp.second) return 1;
		}
		else
		{
			if (first < tmp.first) return 1;
		}
		return 0;
	}
};

//ZAD 2c - szablon funkcji make_pair
template <class T1, class T2>
Pair<T1, T2> make_Pair(T1&& x, T2&& y)
{
	return Pair<T1, T2>(x, y);
}

//ZAD 2f - operator wstawiania do strumienia
template<class TF, class TS>
ostream& operator<< (ostream&os, Pair<TF, TS> &tmp)
{
	return os << "(" << tmp.first << ", " << tmp.second << ")";
}

//ZAD 2g - operator pobierania ze strumienia
template<class TF, class TS>
istream& operator>> (istream&is, Pair<TF, TS>& tmp)
{
	char znak;
	is >> znak;
	if (znak != '(') throw runtime_error("wrong Pair format");
	is >> tmp.first;

	is >> znak;
	if (znak != ',') throw runtime_error("wrong Pair format");
	is >> tmp.second;

	is >> znak;
	if (znak != ')') throw runtime_error("wrong Pair format");

	//ios_base::badbit
	//is.fail();
	//is.bad();
	return is;
}

int main()
{
	//ZAD 1
	int x, y;
	cout << "podaj x: ";
	cin >> x;
	do
	{
		cout << "podaj y: ";
		cin >> y;
	} while (y - 1 < x);

	vector<int> coll;
	for (int i = 50; i < 100; i++) coll.push_back(i);

	auto it = find_if(coll.cbegin(), coll.cend(), bind(czyZPrzedzialu, placeholders::_1, x, y));
	if (it != coll.cend())
		cout << "pierwsza liczba: " << *it << endl;
	else
		cout << "brak liczb z podanego zakresu" << endl;

	//ZAD 2
	Pair<int, string> para1;
	cout << "\nkonstruktor domyslny: " << para1 << endl;

	Pair<int, string> para2(2, "para2");
	cout << "\nkonstruktor inicjujacy: " << para2 << endl;

	Pair<int, string> para3(para2);
	cout << "\nkonstruktor kupijacy: " << para3 << endl;

	Pair<int, string> para4(4, "para4");
	para1 = para4;
	cout << "\noperator przypisania: " << para1 << endl;

	auto para5 = make_Pair(10, 10);
	cout << "\nfunkcja make_Pair: " << para5 << endl;

	cout << "\noperator porownania:\n";
	cout << para1 << " == " << para2 << " : " << (para1 == para2) << endl;
	cout << para1 << " == " << para1 << " : " << (para1 == para1) << endl;
	cout << para1 << " == " << para4 << " : " << (para1 == para4) << endl;

	cout << "\noperator porownania leksykograficznego:\n";
	Pair<int, int> para_int1(1, 1);
	cout << para_int1 << " < " << para_int1 << " : " << (para_int1 < para_int1) << endl;
	Pair<int, int> para_int2(2, 2);
	cout << para_int1 << " < " << para_int2 << " : " << (para_int1 < para_int2) << endl;
	cout << para_int2 << " < " << para_int1 << " : " << (para_int2 < para_int1) << endl;
	auto para_int3 = make_Pair(1, 3);
	cout << para_int1 << " < " << para_int3 << " : " << (para_int1 < para_int3) << endl;
	cout << para_int3 << " < " << para_int1 << " : " << (para_int3 < para_int1) << endl;

	cout << "\npobieranie ze strumienia:\n";
	cin >> para_int3;
	cout << para_int3 << endl;

	system("PAUSE");
	return 0;
}