#include <iostream>
#include <algorithm>

#include "Array.h"
#include "MyIterator.h"

int main()
{
    int arr[5] = { 5,4,3,2,1 };
    MyIterator first(arr), last(arr + 5);

    std::sort(first, last);

    for (auto x : arr) std::cout << x << '\n';

    auto [min_it, max_it](std::minmax_element(first, last));
    std::cout << *min_it << " - " << *max_it << '\n';

    Array<int> arr2 = { 1, 2, 3, 4, 5 };

    std::sort(arr2.begin(), arr2.end());

    for (auto x : arr2) std::cout << x << '\n';

    auto [min_it2, max_it2](std::minmax_element(arr2.begin() + 1, --arr2.end()));
    std::cout << *min_it2 << " - " << *max_it2 << '\n';

}






