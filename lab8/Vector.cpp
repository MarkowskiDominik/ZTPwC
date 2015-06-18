//Markowski Dominik

#include "Vector.h"
#include <utility>

template<typename T>
Vector<T>::Vector() : elem(nullptr), sz()
{}

template<typename T>
Vector<T>::Vector(size_type s) : elem(new T[s]), sz(s)
{
	for (size_type i = 0; i < size(); i++)
		elem[i] = T();
}

template<typename T>
Vector<T>::Vector(const Vector<T>& a) : elem(new T[a.sz]), sz(a.sz)
{
	for (size_type i = 0; i < size(); i++)
		elem[i] = a.elem[i];
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
Vector<T>& Vector<T>::operator=(const Vector& v)
{
	if (v != this)
	{
		sz = v.sz;
		elem = new T[sz];
		for (auto i = 0; i < size(); i++) elem[i] = v.elem[i];
	}
	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& v)
{
	if (v != this)
	{
		sz = v.sz;
		v.sz = 0;
		elem = v.elem;
		v.elem = nullptr;
	}
	return *this;
}

template<typename T>
typename Vector<T>::reference Vector<T>::operator[](size_type i) const
{
	return elem[i];
}

template<typename T>
typename Vector<T>::reference Vector<T>::at(size_type i) const
{
	if (i < 0 || size() <= i)
		throw out_of_range("przekroczenie zakresu");
	else
		return elem[i];
}

template<typename T>
void Vector<T>::swap(Vector& v)
{
	std::swap(elem, v.elem);
	std::swap(sz, v.sz);
	std::swap(last, v.last);
}

template<typename T>
bool Vector<T>::empty() const
{
	return sz == 0;
}

template<typename T>
typename Vector<T>::size_type Vector<T>::capacity() const
{
	return sz;
}

template<typename T>
typename Vector<T>::size_type Vector<T>::size() const
{
	return sz;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
	return elem;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end()
{
	return elem + size();
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const
{
	return elem;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::end() const
{
	return elem + size();
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
	return elem;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const
{
	return elem + size();
}