#include<iostream>
#include<future>
#include<functional>


int Consumer(std::future<int> &pr){

    int *ptr=(int *)malloc(sizeof(int));

    int answer=pr.get();

    *ptr=answer*answer;

    // std::cout<<"Answer is : "<<*ptr<<std::endl;

    return *ptr;
}

int main(){
    std::promise<int> promisedVariable;
    std::future<int> promisedVariableFuture=promisedVariable.get_future();

    std::future<int> ft=std::async(&Consumer,std::ref(promisedVariableFuture));


    int value{0};
    std::cin>>value;

    promisedVariable.set_value(value);

    // ft.wait();

    std::cout<<ft.get()<<std::endl;


    return 0;

}