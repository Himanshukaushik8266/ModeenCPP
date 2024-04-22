#include <iostream>
#include <functional>
/*
    Swap Parameter
    fixing parameter
    discarding
    lambda
    Member function  

*/
class Action
{
private:
    /* data */
    int _id{98};

public:
    Action() = default;
    ~Action() = default;

    void Operation(int number) { std::cout << _id * number<<"\n"; }
};

int main()
{
    Action a;
    auto binded_operation = std::bind(&Action::Operation,a, 40);
    /*
        Non static member fucntion of the class can only be binded using & in front of the function
    */
    binded_operation();         //a1.operation(40);  ------------> Internal Meaning

        return 0;
}