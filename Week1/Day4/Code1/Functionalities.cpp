#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"
#include "Car.h"

void CreateObjects(Container &data)
{
    data.push_back(std::make_shared<Car>("c101", 600000.0f, "Dzire", std::make_shared<Engine>(300, 110.0f), CarType::SEDAN));
    data.push_back(std::make_shared<Car>("c102", 1779000.0f, "Nexon", std::make_shared<Engine>(300, 34500.0f), CarType::SEDAN));
    data.push_back(std::make_shared<Car>("c103", 7579000.0f, "Creta", std::make_shared<Engine>(9800, 7890.0f), CarType::SUV));
}

// void DeleteObjects(const Container &data)
// {
//     if (data.empty())
//     {
//         throw EmptyContainerException("Data is Empty");
//     }
//     for (Car *c : data)
//     {
//         delete c->engine(); // due to composition rule !!
//         delete c;
//     }
// }

int TotalHorsepower(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is Empty");
    }
    float total = 0.0f;
    for (const CarPointer &c : data)
    {
       if (c->engine() != nullptr)  // Check if _engine pointer is not null
        {
            total += c->engine()->horsepower();
        }
        else
        {
            // Handle the case where _engine pointer is null (e.g., log an error)
            std::cerr << "Warning: Car with null engine pointer found." << std::endl;
        }
    }
    return total;
}

bool IsContainerAllCarAbover7l(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is Empty");
    }
    for (const CarPointer &c: data)
    {
        if (c->price() <= 700000.0f)
        {
            return false;
        }
    }
    return true;
}

EnginePointer EnginePointerToMinPriceCar(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is Empty");
    }
    // asssume the first data value as your min

    float price = data[0]->price();
    EnginePointer e = data[0]->engine();

    for (const CarPointer &c: data)
    {
        if (c->price() < price)
        {
            price = c->price();
            e = c->engine();
        }
    }

    return e;
}

float AverageEngineTorque(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is Empty");
    }
    float total_value=0.0f;
    for(const CarPointer &c:data){
        if (c->engine() != nullptr)  // Check if _engine pointer is not null
        {
            total_value += c->engine()->torque();
        }
        else
        {
            // Handle the case where _engine pointer is null (e.g., log an error)
            std::cerr << "Warning: Car with null engine pointer found." << std::endl;
        }
    }
    return total_value/data.size();
}

std::string FindCarModelByID(const Container &data , std::string carId)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is Empty");
    }

    for(const CarPointer &c:data){
        if(c->id()==carId){
            return c->model();
        }
    }
    throw IdNotFoundException("Id not Found for this Car ID!!");
}
