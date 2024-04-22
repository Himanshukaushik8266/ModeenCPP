#include<iostream>

class LambdaImplementation{
    private:
        int _num;   // To be discussed later!
    public:
        LambdaImplementation(){}
        ~LambdaImplementation(){}

        //functional call () operator [paren paren operator]
        void operator()(int number){
            std::cout << "Sqaure of " << number << " is : " << number * number << "\n"; 
        }
} l1;

int main(){
    l1(8); //operator is overload;
}

/*
    This is sort of the working of lambda function it is calling overloaded operator only by creating a temporary class
    , this class name is not known by the programmer hence we used auto (refernce to sample4.cpp)
*/