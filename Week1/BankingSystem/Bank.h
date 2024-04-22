#ifndef BANK_H
#define BANK_H
#include<iostream>
#include<memory>
#include "Account.h"
class Bank
{
private:
    /* data */
    std::string _bankName{"DedoLelo Bank"};
    std::string _ifscCode{"DL0006205"};
    std::string _branch{"Pune"};
    std::string _state{"Maharashtra"};
    std::shared_ptr<Account> _accountDetails;

public:
    Bank()=default;
    Bank(std::string name,float balance,AccountType type);
    Bank(const Bank &)=delete;
    Bank(const Bank &&)=delete;
    Bank & operator=(const Bank&)=delete;
    Bank & operator=(const Bank&&)=delete;
    ~Bank() =default;

    std::shared_ptr<Account> accountDetails() const { return _accountDetails; }
    void setAccountDetails(const std::shared_ptr<Account> &accountDetails) { _accountDetails = accountDetails; }

    friend std::ostream &operator<<(std::ostream &os, const Bank &rhs);
      
};

#endif // BANK_H
