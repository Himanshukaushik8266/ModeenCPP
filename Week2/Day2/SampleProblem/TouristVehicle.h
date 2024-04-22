#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H
#include<iostream>
#include<memory>
#include"VehicleType.h"
#include"Permit.h"
using PermitPointer=std::shared_ptr<Permit>;
class TouristVehicle
{
private:
    /* data */
    std::string _number;
    VehicleType _type;
    unsigned int _seat_count;
    float _per_hour_booking_charge;
    PermitPointer _permit;
    
public:
    TouristVehicle()=default;
    TouristVehicle(const TouristVehicle &)=delete;
    TouristVehicle(TouristVehicle && )=delete;
    TouristVehicle & operator=(const TouristVehicle & )=delete;
    TouristVehicle &operator=(TouristVehicle &&)=delete;
    ~TouristVehicle()=default;


    TouristVehicle(std::string number,VehicleType type,unsigned int seatCount,float perhourbookingcharge, PermitPointer permit);

    std::string number() const { return _number; }
    void setNumber(const std::string &number) { _number = number; }

    VehicleType type() const { return _type; }
    void setType(const VehicleType &type) { _type = type; }

    unsigned int seatCount() const { return _seat_count; }
    void setSeatCount(unsigned int seat_count) { _seat_count = seat_count; }

    float perHourBookingCharge() const { return _per_hour_booking_charge; }
    void setPerHourBookingCharge(float per_hour_booking_charge) { _per_hour_booking_charge = per_hour_booking_charge; }

    PermitPointer permit() const { return _permit; }
    void setPermit(const PermitPointer &permit) { _permit = permit; }

    friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
};

#endif // TOURISTVEHICLE_H
