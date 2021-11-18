#pragma once

template <typename T>
class MyIterator;

template <typename T>
class Array
{
private:
	T* mass;
	size_t size;
public:
	Array() : mass{ nullptr }, size{} {}

	Array(size_t _size) : size{ _size }
	{
		mass = new T[size];
	}

	Array(const std::initializer_list<T>& iList) : Array(iList.size())
	{
		size_t idx{};

		for (const auto& elem : iList)
		{
			mass[idx] = elem;
			++idx;
		}
	}

	~Array()
	{
		delete[] mass;
	}

	T& operator[](size_t idx)
	{
		return mass[idx];
	}

	typedef MyIterator<T> iterator;
	typedef MyIterator<const T> const_iterator;

	iterator begin()
	{
		return iterator(mass);
	}

	iterator end()
	{
		return iterator(mass + size);
	}

	const_iterator begin() const
	{
		return const_iterator(mass);
	}

	const_iterator end() const
	{
		return const_iterator(mass + size);
	}
};



