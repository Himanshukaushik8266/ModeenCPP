#include "Vendor.h"
#include <iostream>

Vendor::Vendor(std::string name, std::string vendorname) : Account(name), _vendorName{vendorname}
{
}

Vendor::Vendor(std::string name, std::string vendorname, const DriverContainer &drivers)
    : Vendor(name, vendorname)
{
    _drivers = drivers;
}
Vendor::Vendor(std::string name, std::string vendorname, const DriverContainer &drivers, const CabUnitsContainer &cabUnits)
    : Vendor(name, vendorname, drivers)
{
    _cabUnits = cabUnits;
}
void Vendor::RegisterAccount()
{
    std::cout << "Vendor is verified as per government norms" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Vendor &rhs)
{
    os << "_vendorName: " << rhs._vendorName;
    return os;
}
