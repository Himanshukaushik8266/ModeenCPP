/*
    system which accepts data values and "logic". This will applied on every single data values received and corresponding x
    output will be shown

    fn(data,logic)

*/
#include <iostream>
void Square(int number)
{
    std::cout << "Sqaure of  : " << number << " is : " << number * number << "\n";
}

void Cube(int number)
{
    std::cout << "Cube of " << number << " is :" << number * number * number << "\n";
}

//Operation function either accepts or returns (or both) function thus it is called higher order function.

//This is C style functional programming syntax

//In modern cpp we have lambda functions
void Operation(int * arr, int size, void (*ptr)(int)){
    for (int i=0;i<size;i++){
        (*ptr)(arr[i]);
    }
}
int main()
{
    // void (*ptr)(int)=Square;
    // void (*ptr2)(int)=Cube;
    int arr[5]={10,20,30,40,50};
    Operation(arr,5,Square);
}

/*
    Higher order functions!
    Anonymous functions
    Functional programming paraigm
    no state
    immutable
    currying
    First-class functions
*/