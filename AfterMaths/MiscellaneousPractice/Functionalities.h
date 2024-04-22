#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<iostream>
#include<optional>
#include "MeriClass.h"
using Container = int **;

std::optional<Container> Function1(){
    
    Container data=new int*[3];
    for(int i=0;i<3;i++){
        data[i]=new int[4];
        for(int j=0;j<4;j++){
            std::cin>>data[i][j];
        }
    }

    if(data==nullptr){
        return std::nullopt;
    }

    return data;
};

#endif // FUNCTIONALITIES_H
