//Markowski Dominik

#include "Vector.h"
#include <utility>

template<typename T, typename A = std::allocator<T>>
Vector<T, A>::Vector(const A& a = A()) : elem(nullptr), sz(), last(), alloc(a)
{}

template<typename T, typename A = std::allocator<T>>
Vector<T, A>::Vector(size_type count, const T& val = T(), const A& a = A()) : elem(alloc.allocate(count)), sz(count), last(count), alloc(a)
{
	for (size_type i = 0; i < size(); i++)
		alloc.construct(&elem[i], val);
}

template<typename T, typename A = std::allocator<T>>
Vector<T, A>::Vector(const Vector& a) : elem(alloc.allocate(a.last)), sz(a.sz), last(a.last), alloc(a.alloc)
{
	for (size_type i = 0; i < size(); i++)
		elem[i] = a.elem[i];
}

template<typename T, typename A = std::allocator<T>>
Vector<T, A>::Vector(Vector&& a) : elem(a.elem), sz(a.sz), last(a.last), alloc(a.alloc)
{
	a.elem = nullptr;
	a.sz = 0;
}

template<typename T, typename A = std::allocator<T>>
Vector<T, A>::~Vector()
{
	clear();
	alloc.deallocate(elem, capacity());
}

template<typename T, typename A = std::allocator<T>>
Vector<T, A>& Vector<T, A>::operator=(const Vector& v)
{
	if (v != this)
	{
		sz = v.sz;
		last = v.last;
		alloc = v.alloc;
		elem(alloc.allocate(sz));
		for (auto i = 0; i < size(); i++) elem[i] = v.elem[i];
	}
	return *this;
}

template<typename T, typename A = std::allocator<T>>
Vector<T, A>& Vector<T, A>::operator=(Vector&& v)
{
	if (v != this)
	{
		sz = v.sz;
		v.sz = 0;
		last = v.last;
		alloc = v.alloc;
		elem = v.elem;
		v.elem = nullptr;
	}
	return *this;
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::reference Vector<T, A>::operator[](size_type i) const
{
	return elem[i];
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::reference Vector<T, A>::at(size_type i) const
{
	if (i < 0 || size() <= i)
		throw out_of_range("przekroczenie zakresu");
	else
		return elem[i];
}

template<typename T, typename A = std::allocator<T>>
void Vector<T, A>::swap(Vector& v)
{
	std::swap(elem, v.elem);
	std::swap(sz, v.sz);
	std::swap(last, v.last);
}

template<typename T, typename A = std::allocator<T>>
bool Vector<T, A>::empty() const
{
	return sz == 0;
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::size_type Vector<T, A>::capacity() const
{
	return last;
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::size_type Vector<T, A>::size() const
{
	return sz;
}

template<typename T, typename A = std::allocator<T>>
void Vector<T, A>::reserve(size_type newCapacity)
{
	if (newCapacity > capacity())
	{
		T* tmp = alloc.allocate(newCapacity);
		for (size_type i = 0; i < size(); i++)
		{
			tmp[i] = std::move(elem[i]);
			alloc.destroy(&elem[i]);
		}

		alloc.deallocate(elem ,capacity());
		elem = tmp;
		last = newCapacity;
	}
}

template<typename T, typename A = std::allocator<T>>
void Vector<T, A>::resize(size_type newSize, const T& val = {})
{
	if (newSize > size())
	{
		if (newSize > capacity()) reserve(newSize);
		for (size_type i = size(); i < newSize; i++)
			elem[i] = T(val);

		sz = newSize;
	}
}

template<typename T, typename A = std::allocator<T>>
void Vector<T, A>::shrink_to_fit()
{
	if (capacity () > size())
	{
		T* tmp = alloc.allocate(size());
		for (size_type i = 0; i < size(); i++)
		{
			tmp[i] = std::move(elem[i]);
			alloc.destroy(&elem[i]);
		}

		alloc.deallocate(elem, capacity());
		elem = tmp;
		last = size();
	}
}

template<typename T, typename A = std::allocator<T>>
void Vector<T, A>::push_back(const T& val)
{
	if (size() == capacity())
		reserve(static_cast<int>(capacity() * 1.5));

	elem[size()] = val;
	sz++;
}

template<typename T, typename A = std::allocator<T>>
void Vector<T, A>::push_back(T&& val)
{
	if (size() == capacity())
		reserve(static_cast<int>(capacity() * 1.5));

	elem[size()] = std::move(val);
	sz++;
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::iterator Vector<T, A>::insert(const_iterator pos, const T& val)
{
	iterator it;
	if (size() == capacity())
	{
		last = static_cast<int>(capacity() * 1.5);
		T* startNewTab = alloc.allocate(last);
		T* itNewTab = startNewTab;

		for (it = begin(); it != pos; it++, itNewTab++)
			*itNewTab = T(std::move(*(it)));

		*itNewTab = T(val);
		T* returnIt = itNewTab;
		itNewTab++;

		for (; it != end(); it++, itNewTab++)
			*itNewTab = T(std::move(*(it)));
		
		for (size_type i = 0; i < size(); i++)
			alloc.destroy(&elem[i]);

		alloc.deallocate(elem, capacity());
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

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::iterator Vector<T, A>::insert(const_iterator pos, T&& val)
{
	iterator it;
	if (size() == capacity())
	{
		last = static_cast<int>(capacity() * 1.5);
		T* startNewTab = alloc.allocate(last);
		T* itNewTab = startNewTab;

		for (it = begin(); it != pos; it++, itNewTab++)
			*itNewTab = T(std::move(*(it)));

		*itNewTab = T(std::move(val));
		T* returnIt = itNewTab;
		itNewTab++;

		for (; it != end(); it++, itNewTab++)
			*itNewTab = T(std::move(*(it)));

		for (size_type i = 0; i < size(); i++)
			alloc.destroy(&elem[i]);

		alloc.deallocate(elem, capacity());
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

template<typename T, typename A = std::allocator<T>>
void Vector<T, A>::clear()
{
	for (size_type i = 0; i < size(); i++)
		alloc.destroy(elem + i);
	sz = 0;
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::iterator Vector<T, A>::begin()
{
	return elem;
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::iterator Vector<T, A>::end()
{
	return elem + size();
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::const_iterator Vector<T, A>::begin() const
{
	return elem;
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::const_iterator Vector<T, A>::end() const
{
	return elem + size();
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::const_iterator Vector<T, A>::cbegin() const
{
	return elem;
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::const_iterator Vector<T, A>::cend() const
{
	return elem + size();
}