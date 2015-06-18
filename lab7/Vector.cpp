//Markowski Dominik

#include "Vector.h"

template<typename T>
Vector<T>::Vector() : elem(nullptr), sz()
{}

template<typename T>
Vector<T>::Vector(int s) : elem(new T[s]), sz(s)
{
	for (int i = 0; i < sz; i++) elem[i] = T();
}

template<typename T>
Vector<T>::Vector(const Vector<T>& a) : elem(new T[a.sz]), sz(a.sz)
{
	for (int i = 0; i < sz; i++) elem[i] = a.elem[i];
}

template<typename T>
Vector<T>::Vector(Vector<T>&& a) : elem(a.elem), sz(a.sz)
{
	a.elem = nullptr;
	a.sz = 0;
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] elem;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& a)
{
	if (a != this)
	{
		sz = a.sz;
		elem = new T[sz];
		for (int i = 0; i < size(); i++) elem[i] = a.elem[i];
	}
	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& a)
{
	if (a != this)
	{
		sz = a.sz;
		a.sz = 0;
		elem = a.elem;
		a.elem = nullptr;
	}
	return *this;
}

template<typename T>
T& Vector<T>::operator[](int i) const
{
	return elem[i];
}

template<typename T>
T& Vector<T>::at(int i) const
{
	if (i < 0 || size() <= i)
		throw out_of_range("przekroczenie zakresu");
	else 
		return elem[i];
}


template<typename T>
int Vector<T>::size() const
{
	return sz;
}

template<typename T>
bool Vector<T>::empty() const
{
	return size() == 0;
}