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

void Operation(int *arr, int size, std::function<void(int)> fn)
{
    for (int i = 0; i < size; i++)
    {
        fn(arr[i]);
    }
}
int main()
{
    std::cout<<"Sample 2 :"<<std::endl;
    int arr[5] = {10, 20, 30, 40, 50};
    Operation(arr, 5, Cube);
}
