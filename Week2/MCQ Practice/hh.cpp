#include<iostream>
#include<functional>
void Magic(int &a){


    ++a;
    std::cout<<a<<std::endl;
    
}

int main(){

    int local_variable=0;
    auto fn=std::bind(&Magic,std::ref(local_variable));

    fn();
    fn();

    std::cout<<local_variable<<std::endl;
    
    return 0;

}