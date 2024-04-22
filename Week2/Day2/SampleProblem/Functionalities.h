#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "TouristVehicle.h"
#include<vector>
using VehiclePointer=std::shared_ptr<TouristVehicle>;
using Container=std::vector<VehiclePointer>;


void CreateObjects(Container & data);
Container FirstNInstancesConditional(Container & data ,unsigned int N);
float AveragePerHourBooking(Container & data,VehicleType type);
std::string  PermitSerialMaximumBooking(Container & data);
Container FirstNInstancesConditional(Container & data ,unsigned int N);


#endif // FUNCTIONALITIES_H
