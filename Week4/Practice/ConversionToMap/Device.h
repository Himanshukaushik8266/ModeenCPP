#ifndef DEVICE_H
#define DEVICE_H
#include<iostream>
#include "License.h"
#include<memory>
#include "Owner.h"
#include "DeviceType.h"
using LicensePointer=std::shared_ptr<License>;
using OwnerPointer=std::shared_ptr<Owner>;

class Device
{
private:
    /* data */
    std::string _id{""};
    std::string _name{""};
    float _price{0.0f};
    float _sar_value{1.0f};
    DeviceType _type{DeviceType::ACCESSORY};
    LicensePointer _license{nullptr};
    OwnerPointer _owner{nullptr};


public:
    Device()=default;
    Device(const Device &)=delete;
    Device(const Device && )=delete;
    Device & operator=(const Device & )=delete;
    Device &operator=(const Device &&)=delete;
    ~Device()=default;

    Device(std::string id, std::string name,float price,float sarValue,DeviceType type,LicensePointer license,OwnerPointer owner);

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    float sarValue() const { return _sar_value; }
    void setSarValue(float sar_value) { _sar_value = sar_value; }

    DeviceType type() const { return _type; }
    void setType(const DeviceType &type) { _type = type; }

    OwnerPointer owner() const { return _owner; }
    void setOwner(const OwnerPointer &owner) { _owner = owner; }

    LicensePointer license() const { return _license; }
    void setLicense(const LicensePointer &license) { _license = license; }

    friend std::ostream &operator<<(std::ostream &os, const Device &rhs);
    
};

#endif // DEVICE_H
