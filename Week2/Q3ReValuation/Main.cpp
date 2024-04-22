#include <iostream>
#include "Bill.h"
#include <memory>
using BillPointer = std::shared_ptr<Bill>;
using BillContainer = std::vector<BillPointer>;
using InvoiceConatiner=std::vector<Invoice>;

void CreateObjects(BillContainer &data , InvoiceConatiner &data2)
{
    //First Entry
    data2.push_back(Invoice(101));
    data.push_back(std::make_shared<Bill>(1000.0f,data2[0]));
}

int main()
{

    BillContainer data;
    InvoiceConatiner data2;

    CreateObjects(data,data2);



    for(BillPointer b:data){
        std::cout<<*b<<std::endl;
    }

    return 0;
}