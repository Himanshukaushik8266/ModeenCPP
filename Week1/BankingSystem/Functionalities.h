#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <vector>
#include <iostream>
#include <memory>
#include "Bank.h"

using BankPtr = std::shared_ptr<Bank>;
using Container = std::vector<BankPtr>;


void CreateAccount(Container &data);                                                //Done
void PrintAllAccountDetails(Container &data);                                       //Done
std::shared_ptr<Account> FindAccount(Container& data, long accountno);              //Done
std::shared_ptr<Account> MaxBalanceAccount(Container& data);                        //Done
std::shared_ptr<Account> MinBalanceAccount(Container& data);                        //Done
float TotalBalanceInAccounts(Container &data);                                      //Done
float AverageBalanceInAccounts(Container &data);                                    //Done
void DepositMoney(Container &data,long accountno,float amount);                     //Done
void WithdrawMoney(Container &data,long accountno,float amount);                    //Done



#endif // FUNCTIONALITIES_H
