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

    T& operator[](size_t idx) { return mass[idx]; }

    const T& operator[](size_t idx) const { return mass[idx]; }

    //Определение типов итераторов

    using iterator = MyIterator<T>;
    using const_iterator = MyIterator<const T>;
    using reverse_iterator = std::reverse_iterator<MyIterator<T>>;
    using const_reverse_iterator = std::reverse_iterator<MyIterator<const T>>;

    //Прямой итератор

    iterator begin() { return iterator(mass); }

    iterator end() { return iterator(mass + size); }

    iterator begin() const { return iterator(mass); }

    iterator end() const { return iterator(mass + size); }

    const_iterator cbegin() const { return const_iterator(mass); }

    const_iterator cend() const { return const_iterator(mass + size); }

    //Обратный итератор

    reverse_iterator rbegin() { return reverse_iterator(mass + size); }

    reverse_iterator rend() { return reverse_iterator(mass); }

    reverse_iterator rbegin() const { return reverse_iterator(mass + size); }

    reverse_iterator rend() const { return reverse_iterator(mass); }

    const_reverse_iterator crbegin() const { return const_reverse_iterator(mass + size); }

    const_reverse_iterator crend() const { return const_reverse_iterator(mass); }




};



