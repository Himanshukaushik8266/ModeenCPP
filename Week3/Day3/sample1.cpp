#include<iostream>
#include<future>


/*
    One number from the user, find the factorial and store the result.
*/



void Factorial(std::future<int> &promised_variable_future){
    int * ptr=(int *)malloc(4);     // can be executed before the operation
    ////wait for the event////
    
    int n=promised_variable_future.get();
    int result=1;
    for(int i=1;i<=n;i++){
        result*=i;
    }
    *ptr=result;
    std::cout<<"Factorial is : "<<*ptr<<std::endl;

}

int main(){

    std::promise<int> promised_variable;
    std::future<int> promised_variable_future=promised_variable.get_future(); 

    std::future<void> result= std::async(&Factorial,std::ref(promised_variable_future));

    // std::thread t1(&Factorial,std::move( promised_variable_future));
    int number=0;
    std::cin>>number;
    promised_variable.set_value(number);

    result.wait();

    std::cout<<"GoodBye"<<std::endl;

    // t1.join();
    
    return 0;

}