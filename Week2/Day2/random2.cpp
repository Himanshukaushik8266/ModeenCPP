#include<iostream>
#include<functional>
#include<vector>


void Adaptor(std::function<bool(int n)> fn,const std::vector<int> &data){
    for(int a:data){
        if(fn(a)){
            std::cout<<"yes"<<std::endl;
        }
        else{
            std::cout<<"no"<<std::endl;
        }
    }
}


int main(){

    // std::function<void(int)> fn=[](int number){std::cout<<number*number<<std::endl;};

    int n1=100;

    Adaptor(
        [&](int number){return number>n1;},
        std::vector<int>{0,101,2,4,-6}
    );

    return 0;

}