//Markowski Dominik

#ifndef VECTOR_H // include guard = stra¿nik do³¹czania
#define VECTOR_H

#include <memory>

template<typename T>
class Vector {
public:
	using value_type = T;										// typ elementu (w ka¿dym kontenerze)
	using size_type = typename std::allocator<T>::size_type;	// typ dla wartoœci
	// rozmiaru (bez znaku, np. unsigned int)

	using iterator = T*;				// zale¿ny od implementacji
	using const_iterator = const T*;	// zale¿ny od implementacji
	using reference = value_type&;

	Vector();						// konstruktor domyœlny (tworzy wektor pusty)
	explicit Vector(size_type s);	// konstruktor
	Vector(const Vector& v);		// konstruktor kopiuj¹cy
	Vector(Vector<T>&& v);			// konstruktor przenosz¹cy
	~Vector();						// destruktor

	Vector<T>& operator=(const Vector& v);		// przypisanie kopiuj¹ce
	Vector<T>& operator=(Vector<T>&& v);		// przypisanie przenosz¹ce

	reference operator[](size_type i) const;	// bez kontroli zakresu
	reference at(size_type i) const;			// z kontrol¹ zakresu (rzuca wyj¹tek
												// out_of_range{ "Vector::at()" })

	void swap(Vector& v);		// zamienia elementy aktualnego wektora z wektorem v
	bool empty() const;			// sprawdza, czy wektor jest pusty
	size_type capacity() const;	// zwraca najwiêksz¹ mo¿liw¹ liczbê
								// elementów bez realokacji
	size_type size() const;		// zwraca aktualn¹ liczbê elementów
								// u nas size() == capacity()

	iterator begin();				// wskazuje na pierwszy element
	iterator end();					// wskazuje na element pierwszy za ostatnim
	const_iterator begin() const;
	const_iterator end() const;
	const_iterator cbegin() const;	// od C++11
	const_iterator cend() const;	// od C++11

private:
	T* elem;		// elem wskazuje tablicê sz elementów typu T
	size_type sz;	// liczba elementów w tablicy
};
#endif