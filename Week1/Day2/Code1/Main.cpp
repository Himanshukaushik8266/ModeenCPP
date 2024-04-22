#include <bits/stdc++.h>
#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"

int main()
{

    Container data;
    try
    {
        int ans = TotalHorsepower(data);
        std::cout << "Total horse power is : " << ans << "\n";
        float result = AverageEngineTorque(data);
        std::cout << "Average value of the engine torque is : " << result << "\n";
        std::string model = FindCarModelByID(data, "c102");
        std::cout << "Model for a given ID Found : " << model << std::endl;
        bool flag = IsContainerAllCarAbover7l(data);
        if (flag)
        {
            std::cout << "All car price above 7 Lakh" << std::endl;
        }
        else
        {
            std::cout << "Some of them are priced less than 7 lakh" << std::endl;
        }
        Engine *e = EnginePointerToMinPriceCar(data);
        std::cout << "Engine Found : " << *e << std::endl;
    }
    catch (const EmptyContainerException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (const IdNotFoundException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch(...){
        std::cout<<"Exceptions!! "<<std::endl;
    }

    DeleteObjects(data);

    return 0;
}