#ifndef MINOR_H
#define MINOR_H
#include<iostream>
class Minor
{
private:
    /* data */
public:
    Minor()=default;
    ~Minor()=default;

    void Sum(int n1,int n2){
        std::cout<<"Sum is : "<<n1+n2<<std::endl;
    }
    void Subtract(int n1,int n2){
        std::cout<<"Absolute difference is : "<<abs(n1-n2)<<std::endl;
    }
    void Multiply(int n1,int n2){
        std::cout<<"Multiplication is : "<<n1*n2<<std::endl;
    }

};

#endif // MINOR_H
