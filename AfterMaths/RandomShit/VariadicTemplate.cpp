#include<iostream>

int Sum(int arg){
    return arg;
}

template<typename T,typename ...Args>
int Sum(T a,Args... args){
    return a+Sum(args...);
}

int main(){
    int k=Sum<int,int>(1,2,3,45,5);
    std::cout<<k<<"\n";
}
