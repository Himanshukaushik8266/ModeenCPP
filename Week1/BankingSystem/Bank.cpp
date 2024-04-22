#include "Bank.h"

Bank::Bank(std::string name ,float balance ,AccountType type)
{
    _accountDetails=std::make_shared<Account>(name,balance,type);
}
std::ostream &operator<<(std::ostream &os, const Bank &rhs) {
    os << "_bankName: " << rhs._bankName
       << " _ifscCode: " << rhs._ifscCode
       << " _branch: " << rhs._branch
       << " _state: " << rhs._state
       << " _accountDetails: " << *rhs._accountDetails;
    return os;
}
