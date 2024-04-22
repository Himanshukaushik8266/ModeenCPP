#include<iostream>
#include<functional>
void Magic(int &a,int b){
    ++a;
    std::cout<<a+b<<std::endl;
}

int main(){
    int local_variable=10;
    auto binded=std::bind(Magic,local_variable,90);

    binded();
    std::cout<<local_variable<<std::endl;
    return 0;

}