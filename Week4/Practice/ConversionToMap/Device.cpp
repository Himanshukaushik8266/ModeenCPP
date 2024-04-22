#include "Device.h"

std::ostream &operator<<(std::ostream &os, const Device &rhs) {
    std::string val="";
    if(rhs.type()==DeviceType::MOBILE){
        val="Mobile";
    }
    else if(rhs.type()==DeviceType::WORKSTATION){
        val="Workstation";
    }
    else{
        val="Accessory";
    }
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _price: " << rhs._price
       << " _sar_value: " << rhs._sar_value
       << " _type: " << val
       << " _license: " << *rhs._license
       << " _owner: " << *rhs._owner;
    return os;
}

Device::Device(std::string id, std::string name, float price, float sarValue, DeviceType type, LicensePointer license, OwnerPointer owner)
:_id{id},_name{name},_price{price},_sar_value{sarValue},_type{type},_license{license},_owner{owner}
{
}
