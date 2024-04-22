#include<iostream>
#include<functional>
#include<list>
/*
    Function Wrapper
*/

void Adaptor(std::function<void(void)> fn,const std::list<int> &data){
    for(int d:data){
        fn();
    }
}

int main(){

    Adaptor(
        [](void){std::cout<<8 *76<<"\n";},
        std::list<int>{10,90,80,65}
    ); 

    return 0;

}