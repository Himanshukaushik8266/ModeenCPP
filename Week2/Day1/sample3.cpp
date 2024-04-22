#include <iostream>
#include<functional> //We have to use functional wrapper for modern cpp functional, programming !!
void Square(int number)
{
    std::cout << "Sqaure of  : " << number << " is : " << number * number << "\n";
}

void Cube(int number)
{
    std::cout << "Cube of " << number << " is :" << number * number * number << "\n";
}

void Operation(const std::vector<int> &data , std::function<void(int)> fn)
{
    for (int d:data)
    {
        fn(d);
    }
}
int main()
{
    std::cout<<"Sample 3 :"<<std::endl;
    std::vector<int> v1{10, 20, 30, 40, 50};
    Operation(std::vector<int>{10, 20, 30, 40, 50}, Cube);
}
