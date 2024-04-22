#include <iostream>
#include "Stack.hpp"
#include "StackEmptyException.hpp"
using namespace std;

int main()
{
    try
    {
        Stack<int> s;
        s.Push(10);
        s.Push(20);
        std::cout << s.Peek() << std::endl;
        s.Pop();
        s.Pop();
        std::cout << s.Peek() << std::endl;
    }
    catch (StackEmptyException &c)
    {
        std::cout << c.what() << std::endl;
    }

    return 0;
}