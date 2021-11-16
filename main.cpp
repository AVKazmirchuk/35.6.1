#include <iostream>

template <typename T>
class Array
{
private:
	T* mass;
	size_t length;
public:
	Array() : mass{ nullptr }, length{} {}

	Array(size_t _length) : length{_length}
	{
		mass = new T[length];
	}

	Array(const std::initializer_list<T>& iList) : Array(iList.size)
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

	class Iterator
	{
	private:
		T* ptr;
		Iterator(T* _ptr) : ptr{_ptr} {}
	public:
		Iterator()
		{
			ptr{ nullptr };
		}
		
		Iterator(const Iterator& it) : Iterator(it.ptr) {}

		Iterator& operator=(const Iterator& it)
		{
			if (this == &it) return *this;

			ptr = it.ptr;

			return *this;
		}

		//-------------------------

		bool operator==(const Iterator& it)
		{
			return ptr == it.ptr;
		}

		bool operator!=(const Iterator& it)
		{
			return !(*this == it);
		}

		T& operator*()
		{
			return *ptr;
		}

		Iterator& operator++()
		{
			++ptr;
			return *this;
		}

		Iterator& operator--()
		{
			--ptr;
			return *this;
		}

		Iterator operator++(T)
		{
			T tmp;
			++(*this);
			return tmp;
		}

		Iterator operator--(T)
		{
			T tmp;
			--(*this);
			return tmp;
		}


	};
};
