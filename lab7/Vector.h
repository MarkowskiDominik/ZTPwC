//Markowski Dominik

#ifndef VECTOR_H
#define VECTOR_H

template<typename T> class Vector
{
public:
	Vector();					// konstruktor domyœlny (tworzy wektor pusty)
	Vector(int s);				// konstruktor
	Vector(const Vector<T>& a);	// konstruktor kopiuj¹cy
	Vector(Vector<T>&& a);		// konstruktor przenosz¹cy
	~Vector();					// destruktor

	Vector<T>& operator=(const Vector& a);	// przypisanie kopiuj¹ce
	Vector<T>& operator=(Vector<T>&& a);	// przypisanie przenosz¹ce

	T& operator[](int i) const;				// bez kontroli zakresu
	T& at(int i) const;						// z kontrol¹ zakresu (rzuca wyj¹tek
											// out_of_range{ "Vector::operator[]" })

	int size() const;		// zwraca liczbê elementów
	bool empty() const;		// sprawdza, czy wektor jest pusty

private:
	T* elem;	// elem wskazuje tablicê sz elementów typu T
	int sz;		// liczba elementów
};
#endif