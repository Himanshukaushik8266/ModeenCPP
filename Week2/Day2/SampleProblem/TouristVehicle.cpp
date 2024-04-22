#include "TouristVehicle.h"
std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs) {
    std::string val="";
    if(rhs.type()==VehicleType::BIKE){
        val="Bike";
    }
    else if (rhs.type()==VehicleType::BUS){
        val="BUS";

    }
    else{
        val="Car";
    }
    os << "_number: " << rhs._number
       << " _type: " << val
       << " _seat_count: " << rhs._seat_count
       << " _per_hour_booking_charge: " << rhs._per_hour_booking_charge
       << " _permit: " << rhs._permit;
    return os;
}


TouristVehicle::TouristVehicle(std::string number, VehicleType type, unsigned int seatCount, float perhourbookingcharge, PermitPointer permit)
:_number{number},_type{type},_seat_count{seatCount},_per_hour_booking_charge{perhourbookingcharge},_permit{permit}
{
}