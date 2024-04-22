// fold expressions
#include<iostream>

/*
accept infinite parameters 
add 1 parametet with remainig
*/

template <typename... T>
auto add(T... n1){
    return (n1 + ...); // right associative operation 
}

template<typename ... A>
void subtract(A... args){
    std::cout<<(args - ...)<<"\n";
    std::cout<<(... - args)<<"\n";
}


int main(int argc, char const *argv[])
{
    subtract(1,2,3,4,5,5);

    return 0;
}
