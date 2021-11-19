#include <iterator>


#pragma once

template <typename T>
class Array;

template <typename T>
class MyIterator
{
private:
	T* ptr{};

private:
	friend class Array<T>;
public:
	
	using difference_type = ptrdiff_t;
	using pointer = T*;
	using reference = T&;

	//Требования последовательного итератора

	MyIterator() {}

	MyIterator(T* _ptr) : ptr{ _ptr } {}

	MyIterator(const MyIterator& it) : MyIterator(it.ptr) {}

	friend bool operator==(const MyIterator& lhs, const MyIterator& rhs) { return lhs.ptr == rhs.ptr; }

	friend bool operator!=(const MyIterator& lhs, const MyIterator& rhs) { return !(lhs.ptr == rhs.ptr); }

	MyIterator& operator=(const MyIterator& it)
	{
		if (this == &it) return *this;

		ptr = it.ptr;

		return *this;
	}

	reference operator*() const { return *((*this).ptr); }

	MyIterator& operator++() { ++ptr; return *this; }

	MyIterator operator++(T) { auto tmp = *this; ++(*this); return tmp; }

	//Требования двунаправленного итератора (в дополнение к последовательному итератору)

	MyIterator& operator--() { --ptr; return *this; }

	MyIterator operator--(T) { auto tmp = *this; --(*this); return tmp; }

	//Требования итератора произвольного доступа (в дополнение к двунаправленному итератору)

	MyIterator& operator+=(difference_type n)
	{
		auto m = n;
		if (m >= 0)
			while (m--)
				++(*this);
		else
			while (m++)
				--(*this);

		return *this;
	}

	MyIterator operator+(MyIterator::difference_type n) { auto tmp = *this; return tmp += n; }

	friend MyIterator operator+(MyIterator::difference_type n, MyIterator it) { return it + n; }

	MyIterator operator-=(difference_type n) { return *this += -n; }

	MyIterator operator-(difference_type n) { auto tmp = *this; return tmp -= n; }

	friend difference_type operator-(const MyIterator& lhs, const MyIterator& rhs) { return rhs.ptr - lhs.ptr; }

	reference operator[](difference_type n) { return *(*this + n); }

	bool operator<(const MyIterator& rhs) { return (rhs.ptr - (*this).ptr) > 0; }

	bool operator>(const MyIterator& rhs) { return rhs < *this; }

	bool operator>=(const MyIterator& rhs) { return !(*this < rhs); }

	bool operator<=(const MyIterator& rhs) { return !(*this > rhs); }

};



template <typename T>
struct std::iterator_traits<MyIterator<T>>
{
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	using difference_type = ptrdiff_t;
	using pointer = T*;
	using reference = T&;
};
