//Markowski Dominik

#ifndef VECTOR_H // include guard = stra�nik do��czania
#define VECTOR_H

#include <memory>

template<typename T>
class Vector {
public:
	using value_type = T;										// typ elementu (w ka�dym kontenerze)
	using size_type = typename std::allocator<T>::size_type;	// bezznakowy typ
																// indeks�w kontenera, rozmiaru itp. (np. unsigned int)

	using iterator = T*;				// zale�ny od implementacji
	using const_iterator = const T*;	// zale�ny od implementacji
	using reference = value_type&;

	Vector();						// konstruktor domy�lny (tworzy wektor pusty)
	explicit Vector(size_type s);	// konstruktor
	Vector(const Vector& v);		// konstruktor kopiuj�cy
	Vector(Vector<T>&& v);			// konstruktor przenosz�cy
	~Vector();						// destruktor

	Vector<T>& operator=(const Vector& v);		// przypisanie kopiuj�ce
	Vector<T>& operator=(Vector<T>&& v);		// przypisanie przenosz�ce

	reference operator[](size_type i) const;	// bez kontroli zakresu
	reference at(size_type i) const;			// z kontrol� zakresu (rzuca wyj�tek
												// out_of_range{ "Vector::at()" })

	void swap(Vector& v);	// zamienia elementy aktualnego wektora z wektorem v
	bool empty() const;		// sprawdza, czy wektor jest pusty
	size_type capacity() const;	// zwraca najwi�ksz� mo�liw� liczb�
								// element�w bez realokacji (pojemno��)
	size_type size() const;	// zwraca aktualn� liczb� element�w
							// (rozmiar)
	void reserve(size_type newCapacity);			// zwi�ksza pojemno�� do newCapacity
	void resize(size_type newSize, const T& = {});	// zmienia rozmiar do newSize
	void push_back(const T& val);
	void push_back(T&& val);
	iterator insert(const_iterator pos, const T& val);
	iterator insert(const_iterator pos, T&& val);

	iterator begin();				// wskazuje na pierwszy element
	iterator end();					// wskazuje na element pierwszy za ostatnim
	const_iterator begin() const;
	const_iterator end() const;
	const_iterator cbegin() const;	// od C++11
	const_iterator cend() const;	// od C++11

private:
	T* elem;		// elem wskazuje tablic� sz element�w typu T
	size_type sz;	// liczba element�w w tablicy
	size_type last; // liczba element�w + wolna przestrze� (bie��cy rozmiar alokacji)
};
#endif