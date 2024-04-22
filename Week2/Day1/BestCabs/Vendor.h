#ifndef VENDOR_H
#define VENDOR_H
#include <iostream>
#include "Account.h"
#include "Driver.h"
#include "CabUnit.h"
#include <vector>

using DriverContainer = std::vector<Driver *>;
using CabUnitsContainer = std::vector<CabUnit *>;
class Vendor : public Account
{
private:
    /* data */
    std::string _vendorName;
    DriverContainer _drivers;
    CabUnitsContainer _cabUnits;

public:
    Vendor() = delete;
    Vendor(const Vendor &) = delete;
    Vendor(Vendor &&) = delete;
    Vendor &operator=(const Vendor &) = delete;
    Vendor &&operator=(Vendor &&) = delete;
    ~Vendor() = default;

    Vendor(std::string name, std::string vendorname); // Taking two parameter

    Vendor(std::string name, std::string vendorname, const DriverContainer &drivers);
    Vendor(std::string name, std::string vendorname, const DriverContainer &drivers, const CabUnitsContainer &cabUnits);

    void RegisterAccount() override;

    friend std::ostream &operator<<(std::ostream &os, const Vendor &rhs);
};

#endif // VENDOR_H
