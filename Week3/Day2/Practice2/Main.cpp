#include <iostream>

#include "Functionalities.h"
int main()
{

    Container data;
    CreateObjects(data);
    std::cout << "*******************************************" << std::endl;
    CommonFunction(data);
    std::cout << "*******************************************" << std::endl;
    NotSoCommonFunction(data);
    std::cout << "*******************************************" << std::endl;
    DeleteObjects(data);
    return 0;
}