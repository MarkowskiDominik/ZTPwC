//Markowski Dominik

#ifndef VECTOR_H
#define VECTOR_H

template<typename T> class Vector
{
public:
	Vector();					// konstruktor domy�lny (tworzy wektor pusty)
	Vector(int s);				// konstruktor
	Vector(const Vector<T>& a);	// konstruktor kopiuj�cy
	Vector(Vector<T>&& a);		// konstruktor przenosz�cy
	~Vector();					// destruktor

	Vector<T>& operator=(const Vector& a);	// przypisanie kopiuj�ce
	Vector<T>& operator=(Vector<T>&& a);	// przypisanie przenosz�ce

	T& operator[](int i) const;				// bez kontroli zakresu
	T& at(int i) const;						// z kontrol� zakresu (rzuca wyj�tek
											// out_of_range{ "Vector::operator[]" })

	int size() const;		// zwraca liczb� element�w
	bool empty() const;		// sprawdza, czy wektor jest pusty

private:
	T* elem;	// elem wskazuje tablic� sz element�w typu T
	int sz;		// liczba element�w
};
#endif