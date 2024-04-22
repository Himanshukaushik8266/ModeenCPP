#include "Functionality.h"
#include "ElectricCar.h"
#include<iostream>
#include<vector>

void CreateObjects(std::vector<Car*> & data)
{
        data.push_back(new ElectricCar("NexonEv", 100,120,125000.0f,34556.88f,4.0f,8900.87f,9087766.0f,7894.0f));

}

void DeleteObjects(std::vector<Car *> &data)
{
        //Modern CPP
        for(Car * p: data){
                delete p;
        }
}
