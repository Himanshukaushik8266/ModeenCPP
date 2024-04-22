#include<bits/stdc++.h>
using namespace std;
#include "EmptyContainerException.h"
#include "Functionalities.h"
int main(){
    Container data;
    try{
        
        CreateObjects(data);
        PrintObjects(data);
        DeleteObjects(data);

    }   
    catch(EmptyContainerException &s){
        cerr<<s.what()<<endl;
    }
    return 0;
}