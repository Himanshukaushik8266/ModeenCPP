#include <iostream>
#include "Functionalities.h"
#include <iomanip>

int main()
{

    std::cout << std::setprecision(2) << std::fixed;
    Container data;
    CarContainer c1, c2, c3;
    CreateObjects(data,c1,c2,c3);
    DisplayData(data);

    return 0;
}