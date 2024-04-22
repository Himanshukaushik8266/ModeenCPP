#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include "Enums.h"
#include "Account.h"
class Customer:public Account
{
private:
    /* data */
    std::string _fullName;
    Gender _gender;
public:
    Customer() =delete;
    Customer(const Customer&)=delete;
    Customer(Customer &&)=delete;
    Customer & operator =(const Customer &)=delete;
    Customer && operator =(Customer &&)=delete;
    ~Customer()=default;

    Customer(std::string name,std::string fullname,Gender gender);

    void RegisterAccount() override;

    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);


};

#endif // CUSTOMER_H

