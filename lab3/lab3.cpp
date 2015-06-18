//Dominik Markowski

#include <cstdio>
#include <iostream>
#include <forward_list>
#include <utility>
#include <iterator>

using namespace std;

//1a
template <class T>
void wypisz_for(T kontener)
{
	for (auto tmp : kontener) cout << tmp << "  ";
	cout << endl;
}

//1b
template <class T>
void wypisz_iterator(T kontener)
{
	for (auto it = kontener.begin(); it != kontener.end(); ++it)
		cout << *it << "  ";
	cout << endl;
}

//2
template<class T>
T last(forward_list<T> kontener)
{
	if (kontener.empty()) throw out_of_range("lista pusta");

	auto it = kontener.begin();
	while (next(it) != kontener.end()) it++;
	return *it;
}

//3a
template<class T>
pair<T, T> ends(forward_list<T> kontener)
{
	if (kontener.empty()) throw out_of_range("lista pusta");

	return make_pair(kontener.front(), last(kontener));
}

//3b
template<class T>
pair<T, T> ends2(forward_list<T> kontener)
{
	if (kontener.empty()) throw out_of_range("lista pusta");

	T tmp = kontener.front();
	kontener.reverse();
	return make_pair(tmp, kontener.front());
}

int main()
{
	forward_list<int> lista_pusta;
	forward_list<int> lista = { 1, 2, 3, 4, 5 };
	lista.push_front(4);
	lista.push_front(0);

	wypisz_for(lista);
	wypisz_iterator(lista);

	last(lista);
	try
	{
		cout << last(lista_pusta) << endl;
	}
	catch (out_of_range err)
	{
		cout << err.what() << endl;
	}

	try
	{
		pair<int, int> tmp = ends(lista);
		cout << tmp.first << " " << tmp.second << endl;
	}
	catch (out_of_range err)
	{
		cout << err.what() << endl;
	}

	try
	{
		pair<int, int> tmp = ends2(lista);
		cout << tmp.first << " " << tmp.second << endl;
	}
	catch (out_of_range err)
	{
		cout << err.what() << endl;
	}

	system("PAUSE");
	return 0;
}