#include <bits/stdc++.h>
#include<future>
#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"

std::future_error f1(std::future_errc::broken_promise);

int main()
{

    Container data;
    // CreateObjects(data);
    // int res
try
    {
        std::future<int> ans = std::async(&TotalHorsepower,std::ref(data));

        std::future<float> result = std::async(&AverageEngineTorque,std::ref(data));

        std::future<std::string> model = std::async(&FindCarModelByID,std::ref(data),"c102");

        std::future<bool> flag = std::async(&IsContainerAllCarAbover7l,std::ref(data));

        std::future<EnginePointer> e = std::async(&EnginePointerToMinPriceCar,std::ref(data));  


        int res=ans.get();
        std::cout << "Total horse power is : " <<res << "\n";
        std::cout << "Average value of the engine torque is : " << result.get() << "\n";
        std::cout << "Model for a given ID Found : " << model.get() << std::endl;
        if (flag.get())
        {
            std::cout << "All car price above 7 Lakh" << std::endl;
        }
        else
        {
            std::cout << "Some of them are priced less than 7 lakh" << std::endl;
        }
        std::cout << "Engine Found : " << *(e.get()) << std::endl;
    }

    catch (const IdNotFoundException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (const std::future_error &fe) {
            // std::cout << "Caught std::future_error: " << fe.what() << std::endl;
            if(fe.code()==std::future_errc::no_state){
                std::cout << "Caught std::future_error: " << fe.what() << std::endl;
            }
        }
    catch(...){
        std::cout<<"Exceptions!! "<<std::endl;
    }
    


    return 0;
}