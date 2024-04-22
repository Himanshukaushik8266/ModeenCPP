#include "Functionalities.h"

void CreateObjects(Container &data, CarContainer &car1, CarContainer &car2, CarContainer &car3)
{
    // Cars for First Brand

    car1.push_back(Car(2, "Verna", 1674558.89f));
    car1.push_back(Car(5, "Creta", 145753.89f));
    car1.push_back(Car(2, "Iconiq", 3467436.89f));
    data.push_back(std::make_shared<Brand>("Hyundai", CarRefArray{car1[0], car1[1], car1[2]}));

    // Cars for Second Brand

    car2.push_back(Car(5, "City", 4237865.89f));
    car2.push_back(Car(3, "Civic", 52345.89f));
    car2.push_back(Car(5, "BRV", 5428765.89f));
    data.push_back(std::make_shared<Brand>("Honda", CarRefArray{car2[0], car2[1], car2[2]}));

    // Car for Third Brand

    car3.push_back(Car(5, "800", 4237865.89f));
    car3.push_back(Car(5, "Baleno", 52345.89f));
    car3.push_back(Car(7, "Ertiga", 5428765.89f));
    data.push_back(std::make_shared<Brand>("Maruti", CarRefArray{car3[0], car3[1], car3[2]}));
}

void DisplayData(Container &data)
{

    for (std::shared_ptr<Brand> b : data)
    {
        std::cout << *b << std::endl;
    }
}

std::optional<CarRefArray> ReturnMatchingCarArray(Container &data, std::string checker)
{
    bool flag=true;
    // for (std::shared_ptr<Brand> ptr : data)
    // {
    //     if (ptr->name() == checker)
    //     {
    //         flag=false;
    //         result=ptr->cars();
    //     }
    // }
    // if(flag){
    //     return std::nullopt;
    // }
    // else{
    //     return result;
    // }

    auto itr=std::find_if(data.begin(),data.end(),[&](const std::shared_ptr<Brand> ptr){
        if(ptr->name()==checker){
            flag=false;
            return true;
        }
        return false;
    });

    if(flag){
        return std::nullopt;
    }
    return (*itr)->cars();
}
