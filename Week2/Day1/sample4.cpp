/*
    The Lambda Function

        -> When we don't want the function to be in global scope
        -> Very small body of that function, creating it outside is not a valid reason
        -> Don't need to maintain its existance in the program
        -> These functions are considered to be as rvalue in the program(But we can make it as lvalue as well)
        -> Some times logic in our mind is one time logic


*/

#include <iostream>
#include <functional>

void Operation(const std::vector<int> &data, std::function<void(int)> fn)
// we can use const and & here int fucntion wrapper as well  ideally DONT use it because object of function is very small we can copy it
{
    for (int d : data)
    {
        fn(d);
    }
}
int main()
{

    auto f1 = [](int number) -> void
    { std::cout << "Cube of " << number << " is :" << number * number * number << "\n"; };
    /*
        auto keyword is used because we can't predict the type of lambda functions.
        This is not as efficient as square implementation because of the scope reservation in main itself.
        []->capture clause It is used for creating lambda closure in cpp.
    */
    std::cout << "Sample 3 :" << std::endl;
    Operation(std::vector<int>{10, 20, 30, 40, 50},
              [](int number) -> void
              { std::cout << "Sqaure of  : " << number << " is : " << number * number << "\n"; });

    Operation(std::vector<int>{10, 20, 30, 40, 50}, f1);
}
