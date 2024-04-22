#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<iostream>
#include <vector>
#include "Demo.h"
#include "EmptyContainerException.h"
using Container=std::vector<Demo *>;

void CreateObjects(Container & data);
void PrintObjects(Container & data );
void DeleteObjects(Container & data);

#endif // FUNCTIONALITIES_H
