#include "Account.h"
long Account ::Acounter=100000001;
Account::Account(std::string name, float balance,AccountType type)
{
    _accountNumber=Acounter;
    Acounter++;
    _balance=balance;
    _name=name;
    _type=type;
}

std::ostream &operator<<(std::ostream &os, const Account &rhs) {

    std::string val{""};

    if(rhs._type==AccountType::SAVINGS){
        val="SAVINGS";
    }
    else{
        val="CURRENT";
    }
    os << "_accountNumber: " << rhs._accountNumber
       << " _balance: " << rhs._balance
       << " _name: " << rhs._name
       << " _type: " <<val<<" Account";
    return os;
}
