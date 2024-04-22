#include<iostream>
#include "EmptyContainerException.h"
#include "NullPointerException.h"
#include "Functionalities.h"

int main(){

    MContainer data;
    CreateObjects(data);
    try{
        DisplayObjects(data);

        FindDiscountPrice(data);

        int taxableItems =FindTaxAmount(data);
        std::cout<<"Total Taxable items are : "<<taxableItems<<std::endl;

        bool check=CheckAllSameLicense(data);
        if(check){
            std::cout<<"All License type are equal"<<std::endl;
        }
        else{
            std::cout<<"Some of them are different"<<std::endl;
        }
    }
    catch(NullPointerException &e){
        std::cout<<e.what()<<std::endl;
    }
    catch(EmptyContainerException &e){
        std::cout<<e.what()<<std::endl;
    }
    
    return 0;

}