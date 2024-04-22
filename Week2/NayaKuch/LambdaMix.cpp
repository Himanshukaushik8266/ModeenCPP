#include<iostream>
#include<vector>
#include<functional>
using FunctionalConatiner=std::vector<std::function<int(int,int)>>;

auto Multiply=[](int n1,int n2){return n1*n2;};
auto Sum=[](int n1,int n2){return n1+n2;};


int main(){

    int n1=90,n2=100;

    //1.

        Multiply(n1,n2);
    //2.
        Sum(n1,n2);

    
    return 0;

}