#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"
#include "Car.h"

void CreateObjects(Container &data)
{
    data[0] = new Car("c101", 600000.0f, "Dzire", new Engine(300, 110.0f), CarType::SEDAN);
    data[1] = new Car("c102", 1779000.0f, "Nexon", new Engine(300, 34500.0f), CarType::SEDAN);
    data[2] = new Car("c103", 7579000.0f, "Creta", new Engine(9800, 7890.0f), CarType::SUV);
}

void DeleteObjects(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is Empty");
    }
    for (Car *c : data)
    {
        delete c->engine(); // due to composition rule !!
        delete c;
    }
}

int TotalHorsepower(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is Empty");
    }
    float total = 0.0f;
    for (Car *c : data)
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
    for (Car *c : data)
    {
        if (c->price() <= 700000.0f)
        {
            return false;
        }
    }
    return true;
}

Engine *EnginePointerToMinPriceCar(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Data is Empty");
    }
    // asssume the first data value as your min

    float price = data[0]->price();
    Engine *e = data[0]->engine();

    for (Car *c : data)
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
    for(Car * c:data){
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

    for(Car *c:data){
        if(c->id()==carId){
            return c->model();
        }
    }
    throw IdNotFoundException("Id not Found for this Car ID!!");
}
