#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Vehicle.h"
#include <functional>
#include <vector>
#include <mutex>
#include <thread>

using VehicleType = std::vector<std::shared_ptr<Vehicle>>;
using FContainer = std::function<void(VehicleType)>;
using Container = std::vector<FContainer>;
using FReturn = std::function<void(VehicleType&)>;

extern FReturn CreateObject;
extern FReturn DisplayObject;
extern FReturn UnCommonData;
extern FReturn CommonData;

#endif // FUNCTIONALITIES_H