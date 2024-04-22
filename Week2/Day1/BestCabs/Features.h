#ifndef FEATURES_H
#define FEATURES_H

#include <iostream>
#include <vector>
#include <functional>
#include "Enums.h"
#include "Account.h"
using AccountContainer = std::vector<Account *>;

class Features
{
private:
    /* data */
public:
    Features(/* args */) {}
    ~Features() {}
    /*
        Should accept reference of a container
        Enum to decide type of account,
        then accept input call correct constructor and store pointer in account.
    */
    static void CreateAccount(AccountContainer & account,AccountType type);
};

#endif // FEATURES_H
