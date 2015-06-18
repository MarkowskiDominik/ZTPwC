//Markowski Dominik

#include "Vector.h"
#include <utility>

template<typename T, typename A = std::allocator<T>>
Vector<T, A>::Vector(const A& a = A()) : alloc(a), elem(nullptr), sz(nullptr), last(nullptr)
{}

template<typename T, typename A = std::allocator<T>>
Vector<T, A>::Vector(size_type count, const T& val = T(), const A& a = A()) : alloc(a), elem(alloc.allocate(count)), sz(elem + count), last(elem + count)
{
	uninitialized_fill(begin(), end(), val);
	//uninitialized_fill_n(begin(), count, val);
}

template<typename T, typename A = std::allocator<T>>
Vector<T, A>::Vector(const Vector& a) : alloc(a.alloc), elem(alloc.allocate(a.capacity())), sz(elem + a.size()), last(elem + a.capacity())
{
	uninitialized_copy(a.begin(), a.end(), begin());
	//uninitialized_copy_n(a.cbegin(), a.size(), begin());
}

template<typename T, typename A = std::allocator<T>>
Vector<T, A>::Vector(Vector&& a) : elem(a.elem), sz(a.sz), last(a.last), alloc(a.alloc)
{
	a.elem = a.sz = a.last = nullptr;
}

template<typename T, typename A = std::allocator<T>>
Vector<T, A>::Vector(std::initializer_list<T> il, const A& = A()) : alloc(A()), elem(alloc.allocate(il.size())), sz(elem + il.size()), last(elem + il.size())
{
	uninitialized_copy(il.begin(), il.end(), begin());
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
		for (size_type i = 0; i < size(); i++)
			alloc.destroy(elem + i);
		alloc.deallocate(elem, capacity());

		alloc = v.alloc;
		elem(alloc.allocate(size()));
		sz = elem + v.size();
		last = elem + v.capacity();

		uninitialized_copy(v.cbegin(), v.cend(), begin());
		//uninitialized_copy_n(v.cbegin(), v.size(), begin());
	}
	return *this;
}

template<typename T, typename A = std::allocator<T>>
Vector<T, A>& Vector<T, A>::operator=(Vector&& v)
{
	if (v != this)
	{
		for (size_type i = 0; i < size(); i++)
			alloc.destroy(elem + i);
		alloc.deallocate(elem, capacity());

		sz = v.sz;
		last = v.last;
		alloc = v.alloc;
		elem = v.elem;
		v.elem = v.sz = v.last = nullptr;
	}
	return *this;
}

template<typename T, typename A = std::allocator<T>>
Vector<T, A>& Vector<T, A>::operator=(std::initializer_list<T> il)
{
	if (!empty())
	{
		for (size_type i = 0; i < size(); i++)
			alloc.destroy(elem + i);
		alloc.deallocate(elem, capacity());
	}

	T* tmp = alloc.allocate(il.size());
	sz = tmp + il.size();
	(il.size() > size()) ? last = tmp + il.size() : last = tmp + capacity();
	elem = tmp;

	if (il.size() != 0) uninitialized_copy(il.begin(), il.end(), begin());
	//if (il.size() != 0) uninitialized_copy_n(il.begin(), il.size(), begin());
	
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
	std::swap(alloc, v.alloc);

	/*
	Vector tmp(std::move(v));
	v = std::move(*this);
	*this = std::move(tmp);
	*/
}

template<typename T, typename A = std::allocator<T>>
bool Vector<T, A>::empty() const
{
	return sz == elem;
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::size_type Vector<T, A>::capacity() const
{
	return last - elem;
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::size_type Vector<T, A>::size() const
{
	return sz - elem;
}

template<typename T, typename A = std::allocator<T>>
void Vector<T, A>::reserve(size_type newCapacity)
{
	if (newCapacity > capacity())
	{
		T* tmp = alloc.allocate(newCapacity);
		//uninitialized_copy(cbegin(), cend(), tmp);
		//uninitialized_copy_n(cbegin(), size(), tmp);

		for (size_type i = 0; i < size(); i++)
		{
			tmp[i] = std::move(elem[i]);
			alloc.destroy(&elem[i]);
		}
		alloc.deallocate(elem, capacity());

		sz = tmp + size();
		elem = tmp;
		last = elem + newCapacity;
	}
}

template<typename T, typename A = std::allocator<T>>
void Vector<T, A>::resize(size_type newSize, const T& val = {})
{
	if (newSize > size())
	{
		if (newSize > capacity()) reserve(newSize);
		uninitialized_fill(end(), elem + capacity(), val);
		//uninitialized_fill_n(end(), newSize - size(), val);

		sz = elem + newSize;
	}
}

template<typename T, typename A = std::allocator<T>>
void Vector<T, A>::shrink_to_fit()
{
	if (capacity() > size())
	{
		T* tmp = alloc.allocate(size());
		//uninitialized_copy(cbegin(), cend(), tmp);
		//uninitialized_copy_n(cbegin(), size(), tmp);

		for (size_type i = 0; i < size(); i++)
		{
			tmp[i] = std::move(elem[i]);
			alloc.destroy(&elem[i]);
		}

		alloc.deallocate(elem, capacity());

		sz = tmp + size();
		elem = tmp;
		last = elem + size();
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
		T* tmp = alloc.allocate(capacity() + static_cast<int>(capacity() * 1.5));

		uninitialized_copy(cbegin(), pos, tmp);

		T* returnIt = tmp + (pos - cbegin());
		*returnIt = T(val);

		uninitialized_copy(pos, cend(), returnIt + 1);

		for (size_type i = 0; i < size(); i++)
			alloc.destroy(&elem[i]);
		alloc.deallocate(elem, capacity());

		sz = tmp + size() + 1;
		last = tmp + static_cast<int>(capacity() * 1.5);
		elem = tmp;
		return returnIt;
	}
	else
	{
		for (it = end(); it != pos; it--)
			*it = T(std::move(*(it - 1)));
		*it = T(val);

		sz++;
		return it;
	}
}

template<typename T, typename A = std::allocator<T>>
typename Vector<T, A>::iterator Vector<T, A>::insert(const_iterator pos, T&& val)
{
	iterator it;
	if (size() == capacity())
	{
		T* tmp = alloc.allocate(capacity() + static_cast<int>(capacity() * 1.5));

		uninitialized_copy(cbegin(), pos, tmp);

		T* returnIt = tmp + (pos - cbegin());
		*returnIt = T(std::move(val));

		uninitialized_copy(pos, cend(), returnIt + 1);

		for (size_type i = 0; i < size(); i++)
			alloc.destroy(&elem[i]);
		alloc.deallocate(elem, capacity());

		sz = tmp + size() + 1;
		last = tmp + static_cast<int>(capacity() * 1.5);
		elem = tmp;
		return returnIt;
	}
	else
	{
		for (it = end(); it != pos; it--)
			*it = T(std::move(*(it - 1)));
		*it = T(std::move(val));

		sz++;
		return it;
	}
}

template<typename T, typename A = std::allocator<T>>
void Vector<T, A>::clear()
{
	for (size_type i = 0; i < size(); i++)
		alloc.destroy(elem + i);
	sz = elem;
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
	//return sz;
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
	//return sz;
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
	//return sz;
}