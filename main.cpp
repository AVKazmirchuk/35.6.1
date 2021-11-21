#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <functional>

#include "Array.h"
#include "MyIterator.h"

int main()
{
    std::cout << "Static mass:        ";
    
    int arr[9] = { 3, 5, 1, 4, 7, 2, 9, 6, 8 };

    MyIterator first(arr), last(arr + 9);

    for (auto& elem : arr) std::cout << elem << ' ';
    std::cout << '\n';
    
    std::cout << "std::sort<less>:    ";
    std::sort(first, last);
    for (auto& elem : arr) std::cout << elem << ' ';
    std::cout << '\n';
    
    std::cout << "std::sort<greater>: ";
    std::sort(first, last, std::greater{});
    for (auto& elem : arr) std::cout << elem << ' ';
    std::cout << '\n';

    auto [min_it, max_it](std::minmax_element(first, last));
    std::cout << "min: " << *min_it << ", max: " << *max_it;
    std::cout << "\n\n";
    
    //----------
    
    std::cout << "Array:                          ";
    
    Array<int> arr2 = { 3, 5, 1, 4, 7, 2, 9, 6, 8 };

    for (const auto& elem : arr2) std::cout << elem << ' ';
    std::cout << '\n';

    std::cout << "std::sort<less>:                ";
    std::sort(arr2.begin(), arr2.end());
    for (auto it{ arr2.cbegin() }; it != arr2.cend(); ++it) std::cout << *it << ' ';
    std::cout << '\n';

    std::cout << "std::sort<greater>:             ";
    std::sort(arr2.begin(), arr2.end(), std::greater{});
    auto it{ arr2.cbegin() };
    while (it != arr2.cend()) { std::cout << *it << ' '; ++it; }
    std::cout << '\n';

    auto [min_it2, max_it2](std::minmax_element(arr2.cbegin() + 1, --arr2.cend()));
    std::cout << "min: " << *min_it2 << ", max: " << *max_it2 << '\n';
    
    std::cout << "std::for_each, output:          ";
    std::for_each(arr2.cbegin(), arr2.cend(), [](auto& elem) { std::cout << elem << " "; });
    std::cout << '\n';

    std::cout << "std::for_each, +10:             ";
    std::for_each(arr2.begin(), arr2.end(), [](auto& elem) { elem += 10; });
    for (const auto& elem : arr2) std::cout << elem << ' ';
    std::cout << '\n';

    std::cout << "std::for_each, +*arr2.begin():  ";
    std::for_each(arr2.begin(), arr2.end(), [value{ *arr2.begin() }](auto& elem) {
        elem += value; });
    for (const auto& elem : arr2) std::cout << elem << ' ';
    std::cout << '\n';

    //Выходит утверждение: _CrtIsValidHeapPointer(block)
    //Но, если как в функции выше, лямбда захватит значение в переменную, то отрабатывается без ошибок

    /*std::cout << "std::transform, +*arr2.begin(): ";
    std::transform(arr2.begin(), arr2.end(), arr2.begin(), [=](auto elem) {
        return elem + *arr2.begin(); });
    for (auto&& elem : arr2) std::cout << elem << ' ';
    std::cout << '\n';*/
    
    std::cout << "std::for_each, output (reverse_iterator):          ";
    std::for_each(arr2.crbegin(), arr2.crend(), [](auto& elem) { std::cout << elem << " "; });
    std::cout << '\n';

    std::cout << "std::for_each, +10 (reverse_iterator):             ";
    std::for_each(arr2.rbegin(), arr2.rend(), [](auto& elem) { elem += 10; });
    for (auto& elem : arr2) std::cout << elem << ' ';
    std::cout << '\n';

    std::cout << "std::for_each, +*arr2.begin() (reverse_iterator):  ";
    std::for_each(arr2.rbegin(), arr2.rend(), [value{ *arr2.rbegin() }](auto& elem) {
        elem += value; });
    for (auto&& elem : arr2) std::cout << elem << ' ';
    std::cout << '\n';

    std::cout << "std::count_if, ";
    auto num = std::count_if(arr2.cbegin(), arr2.cend(), [](auto& elem) {return elem % 2 == 0; });
    std::cout << "number of even elements: " << num;
    std::cout << '\n';

    std::cout << "std::find_if_not, ";
    auto it2 = std::find_if_not(arr2.cbegin(), arr2.cend(), [](auto& elem) {return elem >= 84; });
    if (it2 != arr2.cend()) std::cout << "the first element is less than 84: " << *it2;
    else std::cout << "- element not found";
    std::cout << '\n';
}






