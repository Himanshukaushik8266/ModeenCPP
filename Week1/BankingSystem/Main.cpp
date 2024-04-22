#include<iostream>
#include "Functionalities.h"
#include "BankEmptyException.h"
#include "AccountNotFoundException.h"
#include "LowBalanceException.h"

int main(){

    Container data;
    CreateAccount(data);
    try{
        std::shared_ptr<Account> e=FindAccount(data,100000003);
        std::cout<<*e<<std::endl;
        e=MaxBalanceAccount(data);
        std::cout<<*e<<std::endl;
        e=MinBalanceAccount(data);
        std::cout<<*e<<std::endl;
        float tot=TotalBalanceInAccounts(data);
        std::cout<<"Total Balance of all accounts is : "<<tot<<std::endl;

        float avg=AverageBalanceInAccounts(data);
        std::cout<<"Average balance in accounts is : "<<avg<<std::endl;

        DepositMoney(data,100000001,10);

        WithdrawMoney(data,100000001,700);
        
        PrintAllAccountDetails(data);

    }
    catch(BankEmptyException &b){
        std::cout<<b.what()<<std::endl;
    }
    catch(LowBalanceException &k){
        std::cout<<k.what()<<std::endl;
    }
    catch(AccountNotFoundException &a){
        std::cout<<a.what()<<std::endl;
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
    }

    

    return 0;
}