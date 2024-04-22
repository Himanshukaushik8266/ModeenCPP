/*
    Objectives: 
    Design a consumer 
*/



#include<iostream>
#include<future>
int Consumer(std::future<int> &ft){
    int * ptr=(int *) malloc(40);
    auto f1=[](int number) {return number*number;};
    for(int i=1;i<=10;i++){
        ptr[i-1]=f1(i);
    }
    for(int i=1;i<=10;i++){
        std::cout<<ptr[i-1]<<"\n";
    }

    int n=ft.get(); //wait_fetch

    return (n*(n+1)/2); 
}

int main(){
    std::promise<int> pr;
    std::future<int> ft =pr.get_future();

    std::future<int> result=std::async(&Consumer,std::ref(ft));
    int value=0;
    std::cin>>value;
    pr.set_value(value);


    result.wait();

    std::cout<<"The answer is : "<<result.get()<<"\n";
    


    return 0;

}