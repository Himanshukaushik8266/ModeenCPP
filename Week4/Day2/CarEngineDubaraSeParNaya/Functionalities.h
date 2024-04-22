#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Car.h"
/*
    deafulted & deleted special member functions
    override
    member list initialisation
    inn-class initilization
    for-each(range based for loop)
    enum class 
    constructor delegation

*/
#include<unordered_map>//STL Map
#include<vector>
#include<memory>
using CarPointer=std::shared_ptr<Car>;
using Container =std::unordered_map<std::string, CarPointer>;      //Modern CPP alternate for typedef
using EnginePointer=std::shared_ptr<Engine>;

void CreateObjects(Container &data);


/*
    Input : Container
    output : int
*/

int TotalHorsepower(const Container &data);


/*
    Is this conditon true or false : All cars in the conatiner have a price above 700000
*/

bool IsContainerAllCarAbover7l(const Container &data);

/*
    return the _engine pointer of the car whose price is lowest 
    if multiple Car instance have the same minimum, consider first minimum found
*/

EnginePointer EnginePointerToMinPriceCar(const Container &data);

/*
    Find the average torque for engine in the Car Container
*/

float AverageEngineTorque(const Container &data);

/*
    A function to print the model name of the car Whose _id is passed as a parameter
*/

std::string FindCarModelByID(const Container &data, const std::string carId);


#endif // FUNCTIONALITIES_H
