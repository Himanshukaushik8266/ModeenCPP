#include<iostream>
template<typename T>
T Multiply(T n1){
    return n1;
}

template<typename T, typename ...R>
T Multiply(T n1, R ...args){
    return n1*Multiply(args...);
}
int main(){

    std::cout<<Multiply<float>(8,2.77f,6,10)<<std::endl;
    
    return 0;

}