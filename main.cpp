#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

#include "Array.h"
#include "MyIterator.h"

int main()
{
    int arr[5] = { 5,4,3,2,1 };
    MyIterator first(arr), last(arr + 5);
    std::sort(first, last);
    for (auto x : arr) std::cout << x << ' ';
    std::cout << '\n';
    auto [min_it, max_it](std::minmax_element(first, last));
    std::cout << *min_it << " - " << *max_it;
    std::cout << '\n';

    Array<int> arr2 = { 5, 2, 3, 4, 1 };
    std::sort(arr2.begin(), arr2.end());
    for (auto it{ arr2.begin() }; it != arr2.end(); ++it) std::cout << *it << ' ';
    std::cout << '\n';
    auto [min_it2, max_it2](std::minmax_element(arr2.begin() + 1, --arr2.end()));
    std::cout << *min_it2 << " - " << *max_it2 << '\n';

    std::for_each(arr2.begin(), arr2.end(), [](auto& elem) {
        std::cout << elem << " ";
        });
    std::cout << '\n';

    std::for_each(arr2.begin(), arr2.end(), [](auto& elem) {
        elem += 10;
        });
    for (auto x : arr2) std::cout << x << ' ';
    std::cout << '\n';

    std::for_each(arr2.begin(), arr2.end(), [=](auto& elem) {
        elem += *arr2.begin();
        });
    for (auto x : arr2) std::cout << x << ' ';
    std::cout << '\n';

    
}






