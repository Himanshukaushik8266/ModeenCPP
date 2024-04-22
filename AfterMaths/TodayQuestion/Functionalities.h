#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Brand.h"
using Container =std::vector<std::shared_ptr<Brand>>;
using CarContainer=std::vector<Car>; 


void CreateObjects(Container &data,CarContainer &car1,CarContainer &car2,CarContainer &car3);
void DisplayData(Container &data);

#endif // FUNCTIONALITIES_H
