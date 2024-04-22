#include <iostream>
#include "Functionalities.h"
#include <iomanip>

int main()
{

    std::cout << std::setprecision(2) << std::fixed;
    Container data;
    CarContainer c1, c2, c3;
    CreateObjects(data, c1, c2, c3);
    DisplayData(data);
    std::optional<CarRefArray> result = ReturnMatchingCarArray(data, "hgfd");

    if (result.has_value())
    {
        CarRefArray resultFinal=result.value();
        for (int i = 0; i < 3; i++)
        {
            std::cout << resultFinal[i] << std::endl;
        }
    }
    else{
        std::cout<<"Brand not found!"<<std::endl;
    }

    return 0;
}