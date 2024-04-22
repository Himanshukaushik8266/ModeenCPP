#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<iostream>
#include<vector>
#include "Base.h"

using Container=std::vector<Base *>; 
using DContainer=std::vector<Derived *>; 

void CreateBaseObjects(DContainer &derivedData,Container &data);
void CreateDerivedObjects(DContainer &data);

void DeleteBaseObjects(Container &data);
void DeleteDerivedObjects(DContainer &data);

void ShowDerivedData(DContainer &data);
void ShowBaseData(Container &data);

#endif // FUNCTIONALITIES_H
