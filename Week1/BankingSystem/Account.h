#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <ostream>
#include "Enums.h"

class Account
{
private:
    long _accountNumber{0};
    float _balance{0};
    std::string _name{""};
    AccountType _type;

public:
    static long Acounter;
    Account() =default;
    Account(const Account &)=delete;
    Account(const Account &&)=delete;
    Account & operator=(const Account&)=delete;
    Account & operator=(const Account&&)=delete;

    Account(std::string name,float balance,AccountType type);

    ~Account()=default;

    long accountNumber() const { return _accountNumber; }

    float balance() const { return _balance; }

    void setBalance(float balance) { _balance += balance; }

    void withdraw(float balance){_balance-=balance;}

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    AccountType type() const { return _type; }
    void setType(const AccountType &type) { _type = type; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);

};


#endif // ACCOUNT_H
