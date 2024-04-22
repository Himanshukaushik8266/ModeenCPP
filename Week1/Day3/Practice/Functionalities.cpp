#include "Functionalities.h"

void CreateDerivedObjects(DContainer &data)
{
    for(int i=0;i<2;i++){
        data.push_back(new Derived(i,"Prerna"));
    }

    std::cout<<"Derived Data created successfully !!!"<<std::endl; 
}

void CreateBaseObjects(DContainer &derivedData, Container &data)
{
    for (int i=0;i<2;i++){
        data.push_back(new Base(i,"Himanshu",derivedData[i]));
    }
    std::cout<<"Base Data created successfully !!!"<<std::endl; 
}
void DeleteBaseObjects(Container &data)
{
    if(data.empty()){
        throw("Data is empty");
    }
    for(Base * b:data){
        delete b;
    }
    std::cout<<"Base Objects Deleted !!"<<std::endl;
}
void DeleteDerivedObjects(DContainer &data)
{
    if(data.empty()){
        throw("Data is empty");
    }
    for(Derived * d:data){
        delete d;
    }
    std::cout<<"Derived Objects Deleted !!"<<std::endl;
}

void ShowDerivedData(DContainer &data)
{
    for(int i=0;i<data.size();i++){
        std::cout<<*data[i]<<std::endl;
    }
    
}

void ShowBaseData(Container &data)
{
    for(int i=0;i<data.size();i++){
        std::cout<<*data[i]<<std::endl;
    }
}
