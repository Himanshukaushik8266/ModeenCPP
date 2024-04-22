#ifndef BRAND_H
#define BRAND_H
#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include "Car.h"

using CarRefArray=std::array<std::reference_wrapper<Car>,3>;
class Brand
{
private:
    /* data */
    std::string _name;
    CarRefArray _cars;

public:
    Brand() = default;
    Brand(const Brand &) = delete;
    Brand(Brand &&) = delete;
    Brand &operator=(const Brand &) = delete;
    Brand &operator=(Brand &&) = delete;
    ~Brand() = default;

    Brand(std::string name, CarRefArray car);

    std::string name() const { return _name; }

    CarRefArray cars() const { return _cars; }

    friend std::ostream &operator<<(std::ostream &os, const Brand &rhs);
};

#endif // BRAND_H
