//Dominik Markowski

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

//Zad 1
bool isPrime(int number)
{
	int i = 2;
	while (number % i != 0 && i*i < number) i++;
	return (i*i) > number;
}

//Zad 3c
bool czyZPrzedzialu(int number)
{
	int x = 55;
	int y = 75;
	return x <= number && number <= y;
}

//Zad 3d
class obiekt
{
	const int x;
	const int y;
public:
	obiekt(const int & X, const int & Y) : x(X), y(Y)
	{ }

	bool operator()(const int &tmp) const
	{
		return x <= tmp && tmp <= y;
	}
};

int main()
{
	//test isPrime
	for (int i = 1; i < 20; i++) cout << i << " - " << isPrime(i) << ", ";
	cout << endl;

	//Zad 2a
	vector<int> coll;
	for (int i = 50; i < 100; i++) coll.push_back(i);
	auto it = find_if(coll.cbegin(), coll.cend(), isPrime);
	cout << "1. liczba pierwsza: " << *it << endl;

	//Zad 2b
	vector<int> primes;
	copy_if(coll.cbegin(), coll.cend(), back_inserter(primes), isPrime);
	cout << "kolekcja primes: ";
	for (int tmp : primes) cout << tmp << ", ";
	cout << endl;

	int x, y;
	cout << "podaj x: ";
	cin >> x;
	do
	{
		cout << "podaj y: ";
		cin >> y;
	} while (y - 1 < x);

	cout << endl << "1. liczba z zakresu" << endl;
	//Zad 3a
	for (int tmp : coll)
	{
		if (x <= tmp && tmp <= y)
		{
			cout << "petla: " << tmp << endl;
			break;
		}
	}

	//Zad 3b
	it = find_if(coll.cbegin(), coll.cend(), [x, y](int tmp){return x <= tmp && tmp <= y; });
	if (it != coll.cend())
		cout << "lambda: " << *it << endl;
	else cout << "brak liczb z podanego zakresu" << endl;

	//Zad 3c
	it = find_if(coll.cbegin(), coll.cend(), czyZPrzedzialu);
	if (it != coll.cend())
		cout << "funkcja: " << *it << endl;
	else cout << "brak liczb z podanego zakresu" << endl;

	//Zad 3d
	obiekt ob(x, y);
	it = find_if(coll.cbegin(), coll.cend(), ob);
	if (it != coll.cend())
		cout << "obiekt: " << *it << endl;
	else cout << "brak liczb z podanego zakresu" << endl;

	system("PAUSE");
	return 0;
}
