#include "Functionalities.h"
#include "AccountNotFoundException.h"
#include "BankEmptyException.h"
#include "LowBalanceException.h"

void CreateAccount(Container &data)
{
    data.push_back(std::make_shared<Bank>("Himanshu", 10000.0f, AccountType::SAVINGS));
    data.push_back(std::make_shared<Bank>("Priya", 500.0f, AccountType::SAVINGS));
    data.push_back(std::make_shared<Bank>("Rakesh", 200.0f, AccountType::CURRENT));
    data.push_back(std::make_shared<Bank>("Mukesh",90.0f, AccountType::SAVINGS));
}

void PrintAllAccountDetails(Container &data)
{
    if (data.empty())
    {
        throw BankEmptyException("No Accounts in Bank!!!");
    }

    for (std::shared_ptr<Bank> c : data)
    {
        std::cout << *c << std::endl;
    }
}

std::shared_ptr<Account> FindAccount(Container &data, long accountno)
{
    if (data.empty())
    {
        throw BankEmptyException("No Accounts in Bank!!!");
    }
    for (std::shared_ptr<Bank> b : data)
    {
        if (b->accountDetails()->accountNumber() == accountno)
        {
            std::cout << "Account Found : " << std::endl;
            return b->accountDetails();
        }
    }
    throw AccountNotFoundException("Account Number not found!!");
    return nullptr;
}

std::shared_ptr<Account> MaxBalanceAccount(Container &data)
{
    if (data.empty())
    {
        throw BankEmptyException("No Accounts in Bank!!!");
    }

    float max = data[0]->accountDetails()->balance();
    std::shared_ptr<Account> re = data[0]->accountDetails();
    for (std::shared_ptr<Bank> b : data)
    {
        if (b->accountDetails()->balance() > max)
        {
            max = b->accountDetails()->balance();
            re = b->accountDetails();
        }
    }
    std::cout << "Max Balanced Account is  : " << std::endl;
    return re;
}

std::shared_ptr<Account> MinBalanceAccount(Container &data)
{
    if (data.empty())
    {
        throw BankEmptyException("No Accounts in Bank!!!");
    }

    float min = data[0]->accountDetails()->balance();
    std::shared_ptr<Account> re = data[0]->accountDetails();
    for (std::shared_ptr<Bank> b : data)
    {
        if (b->accountDetails()->balance() < min)
        {
            min = b->accountDetails()->balance();
            re = b->accountDetails();
        }
    }
    std::cout << "Minimum Balanced Account is  : " << std::endl;
    return re;
}

float TotalBalanceInAccounts(Container &data)
{
    if (data.empty())
    {
        throw BankEmptyException("No Accounts in Bank!!!");
    }
    float total = 0.0f;

    for (std::shared_ptr<Bank> b : data)
    {
        total += b->accountDetails()->balance();
    }
    return total;
}

float AverageBalanceInAccounts(Container &data)
{
    if (data.empty())
    {
        throw BankEmptyException("No Accounts in Bank!!!");
    }
    float total = 0.0f;

    for (std::shared_ptr<Bank> b : data)
    {
        total += b->accountDetails()->balance();
    }
    return total/data.size();
}

void DepositMoney(Container &data, long accountno, float amount)
{
    if (data.empty())
    {
        throw BankEmptyException("No Accounts in Bank!!!");
    }
    bool flag=true;
    for(std::shared_ptr<Bank>b:data){
        if(b->accountDetails()->accountNumber()==accountno){
            b->accountDetails()->setBalance(amount);
            flag=false;
            std::cout<<"Amount Credited Successfull!!"<<std::endl;

        }
    }
    if(flag){
        throw AccountNotFoundException("Account Number not found!!");
    }
    
}

void WithdrawMoney(Container &data, long accountno, float amount)
{
    if (data.empty())
    {
        throw BankEmptyException("No Accounts in Bank!!!");
    }
    bool flag=true;
    for(std::shared_ptr<Bank>b:data){
        if(b->accountDetails()->accountNumber()==accountno){
            if(b->accountDetails()->balance()>=amount){
                b->accountDetails()->withdraw(amount);
            }
            else{
                throw LowBalanceException("Insufficient Balance!!!");
            }
            flag=false;
            std::cout<<"Amount Withdrawn Successfull!!"<<std::endl;
            std::cout<<"Remaining Balance is : " <<b->accountDetails()->balance()<<std::endl;
        }
    }
    if(flag){
        throw AccountNotFoundException("Account Number not found!!");
    }
}
