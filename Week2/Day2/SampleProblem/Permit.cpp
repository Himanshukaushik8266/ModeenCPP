#include "Permit.h"
std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    std::string val="";
    if(rhs.permitType()==PermitType::LEASE){
        val="Lease";

    }
    else{
        val="Owned";
    }
    os << "_serial_number: " << rhs._serial_number
       << " _permit_type: " << val
       << " _permit_duration_left: " << rhs._permit_duration_left;
    return os;
}

Permit::Permit(std::string serialNumber, PermitType type, unsigned int permitDurationLeft)
:_serial_number{serialNumber},_permit_type{type},_permit_duration_left{permitDurationLeft}
{
}