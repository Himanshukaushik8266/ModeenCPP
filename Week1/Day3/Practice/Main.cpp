#include<iostream>
#include "Functionalities.h"

int main(){

    Container data;
    DContainer derivedData;

    CreateDerivedObjects(derivedData);
    CreateBaseObjects(derivedData,data);

    DeleteBaseObjects(data);



    ShowDerivedData(derivedData);

    DeleteDerivedObjects(derivedData);

}