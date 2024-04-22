#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "NullPointerException.h"
#include "NumberException.h"


void CreateObjects(Container &data)
{
    data.push_back(std::make_shared<TouristVehicle>("UK17k3129",VehicleType::CAB,5,120.0f,std::make_shared<Permit>("S-10987",PermitType::OWNED,160)));
    data.push_back(std::make_shared<TouristVehicle>("UK87H3481",VehicleType::BUS,5,180.0f,std::make_shared<Permit>("S-105643",PermitType::LEASE,156)));
    data.push_back(std::make_shared<TouristVehicle>("UK17Q9153",VehicleType::BIKE,5,155.0f,std::make_shared<Permit>("S-145687",PermitType::OWNED,190)));
}

Container FirstNInstancesConditional(Container &data, unsigned int N)
{
    if(data.empty()){
        throw EmptyContainerException("Empty Container Exception");
    }
    return Container();
}
