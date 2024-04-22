/*
    _id;
    _username;
    static counter;
    disable all special member except destructor
    output stream operator
    Account must be abstract
    Register Account -----> Pure virtual function
*/
#include<iostream>
#ifndef ACCOUTN_H
#define ACCOUTN_H
class Account
{
private:
    /* data */
    static unsigned long counter;
    std::string _username;
    unsigned long _userid;
public:
    Account() =delete;
    Account(const Account&)=delete;
    Account(Account &&)=delete;
    Account & operator =(const Account &)=delete;
    Account && operator =(Account &&)=delete;
    ~Account()=default;

    virtual void RegisterAccount()=0;
    explicit Account(std::string name);

    std::string username() const { return _username; }
    void setUsername(const std::string &username) { _username = username; }

    unsigned long id() const { return _userid; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
};


#endif // ACCOUTN_H
