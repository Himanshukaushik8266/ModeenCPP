#include <iostream>
#include <functional>
void Magic(int a, int b, int c)
{
    std::cout << a + b + c << std::endl;
}

class Demo
{
private:
    /* data */
    int _id{78};

public:
    Demo() = default;
    ~Demo() = default;

    void Operation(int k, int j)
    {
        std::cout << k * 2 + j + _id << std::endl;
    }
};

int main()
{

    auto binded_magic = std::bind(Magic, 100, std::placeholders::_1, std::placeholders::_2); // fixing

    binded_magic(120, 80);

    auto binded_magic2 = std::bind(Magic, 300, std::placeholders::_3, std::placeholders::_1); // Swapping

    binded_magic2(300, 78, 76); // discarding

    Demo d;

    auto binded_magic3 = std::bind(&Demo::Operation, d, 90, std::placeholders::_1); // class member

    binded_magic3(6);

    auto binded_lambda_function = std::bind([](int number)
                                            { return number * 5; },
                                            78); // lambda function binding

    std::cout << binded_lambda_function() << std::endl;

    return 0;
}