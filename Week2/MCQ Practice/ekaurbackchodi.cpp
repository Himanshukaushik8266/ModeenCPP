#include<iostream>
#include<functional>
class Calculator
{
private:
    int multiply_factors = 2;

public:
    void performOperations(std::function<int()> fun)
    {
            std::cout << fun() << std::endl;

    }

    void performOperations(int a, int b)

    /*
            performOperation

            int a                        int b
            3                              5 
            0x119H                        0x77f
    
    */
    {
        auto op = [&]() mutable{a = 60; return a * b ;};
        op();                               // we have to execute before see the chnaged values.
        std::cout<<a<<std::endl;
        performOperations(op);
    }
};

int main()
{

    Calculator c;
    c.performOperations(3, 5);

}