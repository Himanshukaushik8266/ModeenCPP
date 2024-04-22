/*
    Variadic Templates 
*/

#include<iostream>
/*
    Add is a function that talkes two parameters of type int 
    It uses them as operands for binary  + operator and returns the result of  + operator applied on these operands 
*/
template<typename T>
T add(T n1){
    return n1;
}

template <typename T,typename ...Remaining>
T add(T n1,Remaining... args){
    return n1*add(args...);
}


int main(){

    std::cout<<add<int>(10,20,20,304,50)<<std::endl;
    std::cout<<add<float>(10.5f,9.6f)<<std::endl;
    return 0;

}
