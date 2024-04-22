#include<iostream>
#include<functional>


void Adaptor(std::function<void(void)> fn,int s1){
    fn();
}


int main(){

    Adaptor(
        [](){return true;},
        10
    );
    return 0;

}