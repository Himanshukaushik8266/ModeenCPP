/*
    trigger app
    f1----------->f2(2 interger will be created )
                    |
                    |
                    |
                    |
                    pedicate to filter the data
*/

#include<iostream>
#include<functional>

std::function<int()> f2(int n1,int n2){
    /*
        A lambda can capture data from its enclosing function without explicit passing 
        Here comes Capture clause in picture just put an empercent there 
        [  &  ]----->capture by reference
        [  =  ]------>capture by value
        
    */
    auto lambda_fn=[&](){int val=99; return n1+n2+10+20+val;};
    lambda_fn();
    return lambda_fn;
}
void f1(){
    int n1=10;
    int n2=20;
    std::function<int()> modifed_function=f2(n1,n2);

    std::cout<<modifed_function()<<std::endl;

}

int main(){
    f1();
    return 0;
}