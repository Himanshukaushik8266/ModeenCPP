#ifndef OWNER_H
#define OWNER_H
#include<iostream>
class Owner
{
private:
    /* data */
    std::string _registered_name;

public:
    Owner() = default;
    Owner(const Owner &) = delete;
    Owner(const Owner &&) = delete;
    Owner &operator=(const Owner &) = delete;
    Owner &operator=(const Owner &&) = delete;
    ~Owner() = default;

    Owner(std::string name);

    friend std::ostream &operator<<(std::ostream &os, const Owner &rhs);
};

#endif // OWNER_H
