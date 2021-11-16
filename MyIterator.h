#include <iterator>


#pragma once

template <typename T>
class Array;

template <typename T>
class MyIterator
{
private:
	T* ptr;
	MyIterator(T* _ptr) : ptr{ _ptr } {}
private:
	friend class Array<T>;
public:
	MyIterator()
	{
		ptr{ nullptr };
	}

	MyIterator(const MyIterator& it) : MyIterator(it.ptr) {}

	MyIterator& operator=(const MyIterator& it)
	{
		if (this == &it) return *this;

		ptr = it.ptr;

		return *this;
	}

	//-------------------------

	bool operator==(const MyIterator& it)
	{
		return ptr == it.ptr;
	}

	bool operator!=(const MyIterator& it)
	{
		return !(*this == it);
	}

	T& operator*()
	{
		return *ptr;
	}

	MyIterator& operator++()
	{
		++ptr;
		return *this;
	}

	MyIterator& operator--()
	{
		--ptr;
		return *this;
	}

	MyIterator operator++(T)
	{
		T tmp;
		++(*this);
		return tmp;
	}

	MyIterator operator--(T)
	{
		T tmp;
		--(*this);
		return tmp;
	}


};



template <typename T>
struct std::iterator_traits<MyIterator<T>>
{
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	using defference_type = ptrdiff_t;
	using pointer = T*;
	using reference = T&;
};
