#include <iostream>
#include "Customer.h"

std::ostream &operator<<(std::ostream &os, const Customer &rhs)
{
    std::string val{""};
    if(rhs._gender==Gender::MALE){
        val="Male";
    }
    else if(rhs._gender==Gender::FEMALE){
        val="Female";
    }
    else{
        val="Others";
    }
    os << " _fullName: " << rhs._fullName
       << " _gender: " << val;
    return os;
}

Customer::Customer(std::string name, std::string fullname, Gender gender)
    : Account(name),_fullName{fullname},_gender{gender}
{   
}

void Customer::RegisterAccount()
{
    std::cout<<"Account verified via OTP";
}
