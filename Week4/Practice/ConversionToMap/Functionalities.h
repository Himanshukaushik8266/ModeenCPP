#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<iostream>
#include<vector>
#include<unordered_map>
#include "Device.h"
#include<memory>
#include "EmptyContainerException.h"
#include "NullPointerException.h"
using DevicePointer=std::shared_ptr<Device>;
using Container=std::vector<DevicePointer>;

using MContainer=std::unordered_map<int, DevicePointer>;


void CreateObjects(MContainer &data);

void FindDiscountPrice(MContainer &data);

int FindTaxAmount(MContainer &data);

bool CheckAllSameLicense(MContainer &data);


void DisplayObjects(MContainer &data);

#endif // FUNCTIONALITIES_H
