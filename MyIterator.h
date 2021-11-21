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

    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    MyIterator(T* _ptr) : ptr{ _ptr } {}


    //Требования последовательного итератора


    MyIterator() {};

    MyIterator(const MyIterator& it)
    {
        ptr = it.ptr;
    }

    MyIterator& operator=(const MyIterator& it)
    {
        if (this == &it) return *this;

        ptr = it.ptr;

        return *this;
    }

    ~MyIterator() {};

    friend bool operator==(const MyIterator& lhs, const MyIterator& rhs) { return lhs.ptr == rhs.ptr; }

    friend bool operator!=(const MyIterator& lhs, const MyIterator& rhs) { return !(lhs.ptr == rhs.ptr); }
    //----------
    reference operator*() { return *(this->ptr); }
    const reference operator*() const { return *(this->ptr); }
    //----------
    MyIterator& operator++() { ++this->ptr; return *this; }

    MyIterator operator++(T) { MyIterator tmp = *this; ++(*this); return tmp; }


    //Требования двунаправленного итератора (в дополнение к последовательному итератору)


    MyIterator& operator--() { --this->ptr; return *this; }

    MyIterator operator--(T) { MyIterator tmp = *this; --(*this); return tmp; }


    //Требования итератора произвольного доступа (в дополнение к двунаправленному итератору)


    MyIterator& operator+=(const difference_type n)
    {
        difference_type m = n;
        if (m >= 0)
            while (m--) ++(*this);
        else
            while (m++) --(*this);

        return *this;
    }

    MyIterator& operator-=(const difference_type n) { return *this += -n; }

    MyIterator operator+(const difference_type n) { MyIterator tmp = *this; return tmp += n; }

    MyIterator operator-(const difference_type n) { MyIterator tmp = *this; return tmp -= n; }

    friend MyIterator operator+(const difference_type n, MyIterator it) { return it + n; }
    //----------
    reference operator[](const difference_type n) { return *(*this + n); }
    const reference operator[](const difference_type n) const { return *(*this + n); }
    //----------
    friend difference_type operator-(const MyIterator& lhs, const MyIterator& rhs) { return lhs.ptr - rhs.ptr; }

    friend bool operator<(const MyIterator& lhs, const MyIterator& rhs) { return (rhs - lhs) > 0; }

    friend bool operator>(const MyIterator& lhs, const MyIterator& rhs) { return rhs < lhs; }

    friend bool operator>=(const MyIterator& lhs, const MyIterator& rhs) { return !(lhs < rhs); }

    friend bool operator<=(const MyIterator& lhs, const MyIterator& rhs) { return !(lhs > rhs); }


    void swap(MyIterator& lhs, MyIterator& rhs) { std::swap(lhs.ptr, rhs.ptr); }

};

template <typename T>
struct std::iterator_traits<MyIterator<T>>
{
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
};
