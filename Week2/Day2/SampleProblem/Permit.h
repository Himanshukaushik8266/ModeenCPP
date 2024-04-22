#ifndef PERMIT_H
#define PERMIT_H
#include<iostream>
#include "PermitType.h"
class Permit
{
private:
    /* data */
    std::string _serial_number;
    PermitType _permit_type;
    unsigned int _permit_duration_left;
public:
    Permit()=default;
    Permit(const Permit &)=delete;
    Permit(Permit && )=delete;
    Permit & operator=(const Permit & )=delete;
    Permit &operator=(Permit &&)=delete;
    ~Permit()=default;


    Permit(std::string serialNumber,PermitType type,unsigned int permitDurationLeft);

    unsigned int permitDurationLeft() const { return _permit_duration_left; }
    void setPermitDurationLeft(unsigned int permit_duration_left) { _permit_duration_left = permit_duration_left; }

    PermitType permitType() const { return _permit_type; }
    void setPermitType(const PermitType &permit_type) { _permit_type = permit_type; }

    std::string serialNumber() const { return _serial_number; }
    void setSerialNumber(const std::string &serial_number) { _serial_number = serial_number; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

#endif // PERMIT_H
