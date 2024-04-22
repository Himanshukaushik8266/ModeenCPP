/*
    Objectives: Create an adaptor which takes
    1) A callable of the followinf signature
        Input:  int and int
        Output: void 
    2) interger number n1;
    3) interger numbre n2;

    The adaptor must apply/ map the callable on the 2) and 3) intergers
*/
#include<iostream>
#include<functional>

void Operator(std::function<void (int ,int )> fn, int data1,int data2){           
    // such functions that allows you to map multiple logic is called map functions
    fn(data1,data2);
}

int main(){

    Operator([](int n1,int n2)->void{std::cout<<n1+(n2*2)<<std::endl;},20,30);

    Operator([](int n1,int n2)->void{std::cout<<n1+(n2*6)<<std::endl;},20,30);
    return 0;

}