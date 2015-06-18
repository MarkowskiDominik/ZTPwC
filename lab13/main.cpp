//Markowski Dominik

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

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

	//TESTY LAB8
	Vector<int> wektor1;
	cout << "\nkonstruktor domyslny";
	cout << "\nwektor 1: " << wektor1.size() << ", " << wektor1.empty() << "\t"; print(wektor1);

	Vector<int> wektor2(3);
	cout << "\nkonstruktor z rozmiarem 3";
	cout << "\nwektor 2: " << wektor2.size() << ", " << wektor2.empty() << "\t"; print(wektor2);

	Vector<int> wektor3(wektor2);
	cout << "\nkonstruktor kopiujacy";
	cout << "\nwektor 3: " << wektor3.size() << ", " << wektor3.empty() << "\t"; print(wektor3);
	for (unsigned int i = 0; i < wektor2.size(); i++) wektor2[i] = i;
	cout << "wektor 3 po zmianie wektora inicjalizujacego: "; print(wektor3);

	Vector<int> wektor4(move(wektor2));
	cout << "\nkonstruktor przenoszacy";
	cout << "\nwektor 4: " << wektor4.size() << ", " << wektor4.empty() << "\t"; print(wektor4);
	cout << "wektor 2: " << wektor2.size() << ", " << wektor2.empty() << "\t"; print(wektor2);
	try
	{
		cout << wektor2.at(0);
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
	Vector<int> wektor5 = wektor3;
	cout << "\nwektor 5: " << wektor5.size() << ", " << wektor5.empty() << "\t"; print(wektor5);

	cout << "\noperator przeniesienia";
	Vector<int> wektor6 = move(wektor3);
	cout << "\nwektor 6: " << wektor6.size() << ", " << wektor6.empty() << "\t"; print(wektor6);
	cout << "wektor 3: " << wektor3.size() << ", " << wektor3.empty() << "\t"; print(wektor3);

	cout << "\ntest swap";
	cout << "\nwektor 4:\t"; print(wektor4);
	cout << "wektor 6:\t"; print(wektor6);
	wektor4.swap(wektor6);
	cout << "wektor 4:\t"; print(wektor4);
	cout << "wektor 6:\t"; print(wektor6);

	cout << "\ntest iteratorow";
	cout << "\nbegin, end:\t";
	for (auto it = wektor6.begin(); it != wektor6.end(); it++)
		cout << *it << ", ";
	cout << "\nconst begin, const end:\t";
	for (Vector<int>::const_iterator it = wektor6.begin(); it != wektor6.end(); it++)
		cout << *it << ", ";
	cout << "\ncbegin, cend:\t";
	for (auto it = wektor6.cbegin(); it != wektor6.cend(); it++)
		cout << *it << ", ";
	cout << endl;

	//TESTY LAB10
	std::vector<int> wektor_std1;
	Vector<int> wektor_1;
	cout << "\nwektor 1 std:\tsize: " << wektor_std1.size() << ", capacity: " << wektor_std1.capacity() << "\t"; print(wektor_std1);
	cout << "wektor 1:\tsize: " << wektor_1.size() << ", capacity: " << wektor_1.capacity() << "\t"; print(wektor_1);

	cout << "resize(7)";
	wektor_std1.resize(7);
	wektor_1.resize(7);
	cout << "\nwektor 1 std:\tsize: " << wektor_std1.size() << ", capacity: " << wektor_std1.capacity() << "\t"; print(wektor_std1);
	cout << "wektor 1:\tsize: " << wektor_1.size() << ", capacity: " << wektor_1.capacity() << "\t"; print(wektor_1);

	cout << "reserve(10)";
	wektor_std1.reserve(10);
	wektor_1.reserve(10);
	cout << "\nwektor 1 std:\tsize: " << wektor_std1.size() << ", capacity: " << wektor_std1.capacity() << "\t"; print(wektor_std1);
	cout << "wektor 1:\tsize: " << wektor_1.size() << ", capacity: " << wektor_1.capacity() << "\t"; print(wektor_1);

	std::vector<int> wektor_std2(3);
	Vector<int> wektor_2(3);
	cout << "\nwektor 2 std:\tsize: " << wektor_std2.size() << ", capacity: " << wektor_std2.capacity() << "\t"; print(wektor_std2);
	cout << "wektor 2:\tsize: " << wektor_2.size() << ", capacity: " << wektor_2.capacity() << "\t"; print(wektor_2);

	cout << "resize(6,2)";
	wektor_std2.resize(6, 2);
	wektor_2.resize(6, 2);
	cout << "\nwektor 2 std:\tsize: " << wektor_std2.size() << ", capacity: " << wektor_std2.capacity() << "\t"; print(wektor_std2);
	cout << "wektor 2:\tsize: " << wektor_2.size() << ", capacity: " << wektor_2.capacity() << "\t"; print(wektor_2);

	cout << "reserve(9)";
	wektor_std2.reserve(9);
	wektor_2.reserve(9);
	cout << "\nwektor 2 std:\tsize: " << wektor_std2.size() << ", capacity: " << wektor_std2.capacity() << "\t"; print(wektor_std2);
	cout << "wektor 2:\tsize: " << wektor_2.size() << ", capacity: " << wektor_2.capacity() << "\t"; print(wektor_2);

	cout << "\npush_back(5)";
	wektor_std2.push_back(5);
	wektor_2.push_back(5);
	cout << "\npush_back(5)";
	wektor_std2.push_back(5);
	wektor_2.push_back(5);
	cout << "\npush_back(5)";
	wektor_std2.push_back(5);
	wektor_2.push_back(5);
	cout << "\nwektor 2 std:\tsize: " << wektor_std2.size() << ", capacity: " << wektor_std2.capacity() << "\t"; print(wektor_std2);
	cout << "wektor 2:\tsize: " << wektor_2.size() << ", capacity: " << wektor_2.capacity() << "\t"; print(wektor_2);
	cout << "\npush_back(7)";
	wektor_std2.push_back(7);
	wektor_2.push_back(7);
	cout << "\nwektor 2 std:\tsize: " << wektor_std2.size() << ", capacity: " << wektor_std2.capacity() << "\t"; print(wektor_std2);
	cout << "wektor 2:\tsize: " << wektor_2.size() << ", capacity: " << wektor_2.capacity() << "\t"; print(wektor_2);

	std::vector<int> wektor_std3(30);
	Vector<int> wektor_3(30);
	cout << "\nwektor 3 std:\tsize: " << wektor_std3.size() << ", capacity: " << wektor_std3.capacity() << "\t"; print(wektor_std3);
	cout << "wektor 3:\tsize: " << wektor_3.size() << ", capacity: " << wektor_3.capacity() << "\t"; print(wektor_3);
	wektor_std3.push_back(1);
	wektor_3.push_back(1);
	cout << "\nwektor 3 std:\tsize: " << wektor_std3.size() << ", capacity: " << wektor_std3.capacity() << "\t"; print(wektor_std3);
	cout << "wektor 3:\tsize: " << wektor_3.size() << ", capacity: " << wektor_3.capacity() << "\t"; print(wektor_3);

	cout << "\nwektor 2 std:\tsize: " << wektor_std2.size() << ", capacity: " << wektor_std2.capacity() << "\t"; print(wektor_std2);
	cout << "wektor 2:\tsize: " << wektor_2.size() << ", capacity: " << wektor_2.capacity() << "\t"; print(wektor_2);
	cout << "insert(3), insert(4)";
	auto it_std = wektor_std2.begin();
	while (*it_std < 5) it_std++;
	wektor_std2.insert(it_std, 3);
	wektor_std2.insert(it_std, 4);
	auto it = wektor_2.begin();
	while (*it < 5) it++;
	wektor_2.insert(it, 3);
	wektor_2.insert(it, 4);
	cout << "\nwektor 2 std:\tsize: " << wektor_std2.size() << ", capacity: " << wektor_std2.capacity() << "\t"; print(wektor_std2);
	cout << "wektor 2:\tsize: " << wektor_2.size() << ", capacity: " << wektor_2.capacity() << "\t"; print(wektor_2);
	cout << "insert(5), insert(6)";
	wektor_std2.insert(it_std, 5);
	wektor_2.insert(it, 5);
	wektor_std2.insert(it_std, 6);
	wektor_2.insert(it, 6);
	cout << "\nwektor 2 std:\tsize: " << wektor_std2.size() << ", capacity: " << wektor_std2.capacity() << "\t"; print(wektor_std2);
	cout << "wektor 2:\tsize: " << wektor_2.size() << ", capacity: " << wektor_2.capacity() << "\t"; print(wektor_2);

	//TESTY LAB11
	cout << "\nshrink_to_fit()";
	wektor_std2.shrink_to_fit();
	wektor_2.shrink_to_fit();
	cout << "\nwektor 2 std:\tsize: " << wektor_std2.size() << ", capacity: " << wektor_std2.capacity() << "\t"; print(wektor_std2);
	cout << "wektor 2:\tsize: " << wektor_2.size() << ", capacity: " << wektor_2.capacity() << "\t"; print(wektor_2);

	cout << "\nclear()";
	wektor_std2.clear();
	wektor_2.clear();
	cout << "\nwektor 2 std:\tsize: " << wektor_std2.size() << ", capacity: " << wektor_std2.capacity() << "\t"; print(wektor_std2);
	cout << "wektor 2:\tsize: " << wektor_2.size() << ", capacity: " << wektor_2.capacity() << "\t"; print(wektor_2);
	
	//TESTY LAB13
	cout << "\ntest konstruktorow:\n";
	std::vector<int> ws_1;
	Vector<int> w_1;
	cout << "\nws_1\t size: " << ws_1.size() << " capacity: " << ws_1.capacity() << "\t"; print(ws_1);
	cout << "w_1\t size: " << w_1.size() << " capacity: " << w_1.capacity() << "\t"; print(w_1);
	std::vector<int> ws_2{};
	Vector<int> w_2{};
	cout << "\nws_2{}\t size: " << ws_2.size() << " capacity: " << ws_2.capacity() << "\t"; print(ws_2);
	cout << "w_2{}\t size: " << w_2.size() << " capacity: " << w_2.capacity() << "\t"; print(w_2);
	std::vector<int> ws_3(1);
	Vector<int> w_3(1);
	cout << "\nws_3(1)\t size: " << ws_3.size() << " capacity: " << ws_3.capacity() << "\t"; print(ws_3);
	cout << "w_3(1)\t size: " << w_3.size() << " capacity: " << w_3.capacity() << "\t"; print(w_3);
	std::vector<int> ws_4{ 1 };
	Vector<int> w_4{ 1 };
	cout << "\nws_4{1}\t size: " << ws_4.size() << " capacity: " << ws_4.capacity() << "\t"; print(ws_4);
	cout << "w_4{1}\t size: " << w_4.size() << " capacity: " << w_4.capacity() << "\t"; print(w_4);
	std::vector<int> ws_5(3, 2);
	Vector<int> w_5(3, 2);
	cout << "\nws_5(3,2)\t size: " << ws_5.size() << " capacity: " << ws_5.capacity() << "\t"; print(ws_5);
	cout << "w_5(3,2)\t size: " << w_5.size() << " capacity: " << w_5.capacity() << "\t"; print(w_5);
	std::vector<int> ws_6{ 3, 2 };
	Vector<int> w_6{ 3, 2 };
	cout << "\nws_6{3,2}\t size: " << ws_6.size() << " capacity: " << ws_6.capacity() << "\t"; print(ws_6);
	cout << "w_6{3,2}\t size: " << w_6.size() << " capacity: " << w_6.capacity() << "\t"; print(w_6);

	cout << "\ntest operatora przypisania listy inicjalizujacej:";
	std::vector<int> ws_7;
	Vector <int> w_7;
	cout << "\nlista pusta\n";
	ws_7 = {};
	w_7 = {};
	cout << "ws_7\t size: " << ws_7.size() << " capacity: " << ws_7.capacity() << "\t"; print(ws_7);
	cout << "w_7\t size: " << w_7.size() << " capacity: " << w_7.capacity() << "\t"; print(w_7);
	cout << "\nlista {1,2,3,4,5}\n";
	ws_7 = { 1, 2, 3, 4, 5 };
	w_7 = { 1, 2, 3, 4, 5 };
	cout << "ws_7\t size: " << ws_7.size() << " capacity: " << ws_7.capacity() << "\t"; print(ws_7);
	cout << "w_7\t size: " << w_7.size() << " capacity: " << w_7.capacity() << "\t"; print(w_7);
	cout << "\nlista o mniejszej liczbie elementow {1,2,3}\n";
	ws_7 = { 1, 2, 3 };
	w_7 = { 1, 2, 3 };
	cout << "ws_7\t size: " << ws_7.size() << " capacity: " << ws_7.capacity() << "\t"; print(ws_7);
	cout << "w_7\t size: " << w_7.size() << " capacity: " << w_7.capacity() << "\t"; print(w_7);

	cout << "\ntesty z typem string:\n";
	std::vector<string> ws_1_str;
	Vector<string> w_1_str;
	cout << "\nws_1_str\t size: " << ws_1_str.size() << " capacity: " << ws_1_str.capacity() << "\t"; print(ws_1_str);
	cout << "w_1_str \t size: " << w_1_str.size() << " capacity: " << w_1_str.capacity() << "\t"; print(w_1_str);
	std::vector<string> ws_2_str{};
	Vector<string> w_2_str{};
	cout << "\nws_2_str{}\t size: " << ws_2_str.size() << " capacity: " << ws_2_str.capacity() << "\t"; print(ws_2_str);
	cout << "w_2_str{}\t size: " << w_2_str.size() << " capacity: " << w_2_str.capacity() << "\t"; print(w_2_str);
	std::vector<string> ws_3_str(2);
	Vector<string> w_3_str(2);
	cout << "\nws_3_str(2)\t size: " << ws_3_str.size() << " capacity: " << ws_3_str.capacity() << "\t"; print(ws_3_str);
	cout << "w_3_str(2)\t size: " << w_3_str.size() << " capacity: " << w_3_str.capacity() << "\t"; print(w_3_str);
	std::vector<string> ws_4_str{"a"};
	Vector<string> w_4_str{"a"};
	cout << "\nws_4_str{a}\t size: " << ws_4_str.size() << " capacity: " << ws_4_str.capacity() << "\t"; print(ws_4_str);
	cout << "w_4_str{a}\t size: " << w_4_str.size() << " capacity: " << w_4_str.capacity() << "\t"; print(w_4_str);
	std::vector<string> ws_5_str(3, "a");
	Vector<string> w_5_str(3, "a");
	cout << "\nws_5_str(3,a)\t size: " << ws_5_str.size() << " capacity: " << ws_5_str.capacity() << "\t"; print(ws_5_str);
	cout << "w_5_str(3,a)\t size: " << w_5_str.size() << " capacity: " << w_5_str.capacity() << "\t"; print(w_5_str);
	std::vector<string> ws_6_str{ "a", "b", "c" };
	Vector<string> w_6_str{ "a", "b", "c" };
	cout << "\nws_6_str{a,b,c}\t size: " << ws_6_str.size() << " capacity: " << ws_6_str.capacity() << "\t"; print(ws_6_str);
	cout << "w_6_str{a,b,c}\t size: " << w_6_str.size() << " capacity: " << w_6_str.capacity() << "\t"; print(w_6_str);

	cout << "\noperator przypisania\n";
	std::vector<string> ws_7_str;
	std::vector<string> w_7_str;
	cout << "\nlista pusta\n";
	ws_7_str = {};
	w_7_str = {};
	cout << "ws_7_str\t size: " << ws_7_str.size() << " capacity: " << ws_7_str.capacity() << "\t"; print(ws_7_str);
	cout << "w_7_str \t size: " << w_7_str.size() << " capacity: " << w_7_str.capacity() << "\t"; print(w_7_str);
	cout << "\nlista {1,2,3,4,5}\n";
	ws_7_str = { "a", "b", "c", "d", "e" };
	w_7_str = { "a", "b", "c", "d", "e" };
	cout << "ws_7_str\t size: " << ws_7_str.size() << " capacity: " << ws_7_str.capacity() << "\t"; print(ws_7_str);
	cout << "w_7_str \t size: " << w_7_str.size() << " capacity: " << w_7_str.capacity() << "\t"; print(w_7_str);
	cout << "\nlista o mniejszej liczbie elementow {1,2,3}\n";
	ws_7_str = { "a", "b", "c", };
	w_7_str = { "a", "b", "c", };
	cout << "ws_7_str\t size: " << ws_7_str.size() << " capacity: " << ws_7_str.capacity() << "\t"; print(ws_7_str);
	cout << "w_7_str \t size: " << w_7_str.size() << " capacity: " << w_7_str.capacity() << "\t"; print(w_7_str);

	system("PAUSE");
	return 0;
}