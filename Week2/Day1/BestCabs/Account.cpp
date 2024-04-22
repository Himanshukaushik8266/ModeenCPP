#include "Account.h"
unsigned long Account :: counter=0;

std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "_username: " << rhs._username
       << " _id: " << rhs._userid;
    return os;
}

Account::Account(std::string name)
: _username{name},_userid{++counter}{}

