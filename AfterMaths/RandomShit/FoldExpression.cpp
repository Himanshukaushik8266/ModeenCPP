#include <iostream>
#include <vector>
#include <algorithm>

template <typename... Args>
int Sum(Args... args)
{
    int sum = 0;
    (std::for_each(args.begin(), args.end(), [&](int i){ sum += i; }),...);
    return sum;
}

int main()
{
    int k = Sum(std::vector<int>{1, 2, 4, 4, 5}, std::vector<int>{5, 3, 6, 76, 3}, std::vector<int>{4, 5, 67, 7});
    std::cout << "The sum is : " << k << std::endl;
}