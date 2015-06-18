//Markowski Dominik

#include "Vector.h"
#include <utility>

template<typename T>
Vector<T>::Vector() : elem(nullptr), sz(), last()
{}

template<typename T>
Vector<T>::Vector(size_type s) : elem(new T[s]), sz(s), last(s)
{
	for (size_type i = 0; i < size(); i++)
		elem[i] = T();
}

template<typename T>
Vector<T>::Vector(const Vector<T>& a) : elem(new T[a.last]), sz(a.sz), last(a.last)
{
	for (size_type i = 0; i < size(); i++)
		elem[i] = a.elem[i];
}

template<typename T>
Vector<T>::Vector(Vector<T>&& a) : elem(a.elem), sz(a.sz), last(a.last)
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
	return last;
}

template<typename T>
typename Vector<T>::size_type Vector<T>::size() const
{
	return sz;
}

template<typename T>
void Vector<T>::reserve(size_type newCapacity)
{
	if (newCapacity > capacity())
	{
		T* tmp = new T[newCapacity];
		for (size_type i = 0; i < size(); i++)
			tmp[i] = std::move(elem[i]);

		delete[] elem;
		elem = tmp;
		last = newCapacity;
	}	
}

template<typename T>
void Vector<T>::resize(size_type newSize, const T& val = {})
{
	if (newSize > size())
	{
		if (newSize > capacity()) reserve(newSize);
		for (size_type i = size(); i < newSize; i++) elem[i] = T(val);

		sz = newSize;
	}
}

template<typename T>
void Vector<T>::push_back(const T& val)
{
	if (size() == capacity())
		reserve(static_cast<int>(capacity() * 1.5));

	elem[size()] = val;
	sz++;
}

template<typename T>
void Vector<T>::push_back(T&& val)
{
	if (size() == capacity())
		reserve(static_cast<int>(capacity() * 1.5));

	elem[size()] = std::move(val);
	sz++;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, const T& val)
{
	iterator it;
	if (size() == capacity())
	{
		last = static_cast<int>(capacity() * 1.5);
		T* startNewTab = new T[last];
		T* itNewTab = startNewTab;

		for (it = begin(); it != pos; it++, itNewTab++)
			*itNewTab = T(std::move(*(it)));

		*itNewTab = T(val);
		T* returnIt = itNewTab;
		itNewTab++;

		for (; it != end(); it++, itNewTab++)
			*itNewTab = T(std::move(*(it)));

		delete[] elem;
		elem = startNewTab;
		++sz;
		return returnIt;
	}
	else
	{
		for (it = end(); it != pos; it--)
			*it = T(std::move(*(it - 1)));
		*it = T(val);

		++sz;
		return it;
	}
}

template<typename T>
typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, T&& val)
{
	iterator it;
	if (size() == capacity())
	{
		last = static_cast<int>(capacity() * 1.5);
		T* startNewTab = new T[last];
		T* itNewTab = startNewTab;

		for (it = begin(); it != pos; it++, itNewTab++)
			*itNewTab = T(std::move(*(it)));

		*itNewTab = T(std::move(val));
		T* returnIt = itNewTab;
		itNewTab++;

		for (; it != end(); it++, itNewTab++)
			*itNewTab = T(std::move(*(it)));

		delete[] elem;
		elem = startNewTab;
		++sz;
		return returnIt;
	}
	else
	{
		for (it = end(); it != pos; it--)
			*it = T(std::move(*(it - 1)));
		*it = T(std::move(val));

		++sz;
		return it;
	}
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