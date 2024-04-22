#include "Functionalities.h"
#include "Demo.h"

void CreateObjects(Container &data)
{
    data.push_back(new Demo(1,"Himanshu"));
    data.push_back(new Demo (2,"Ayush"));
}

void PrintObjects(Container &data)
{
    for (Demo * p:data ){
        std::cout<<*p<<std::endl;
    }
}

void DeleteObjects(Container &data)
{
    if(data.empty()){
        char message[50]="Container is Empty";
        throw EmptyContainerException(message);
    }

    for(Demo * d: data ){
        delete d;
    }
    data.clear();
}
