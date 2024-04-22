#include<iostream>
#include<functional>
/*
    The actual data type of a lambda is unknown
    
    
    
    
    class Function_wrapper{
        //.....
        private:
            f <------------------lambda is saved to this member
            operator is overloaded for ();
    }




*/
void Magic(std::function<void(int number)> func){
    func(10);       //this will call lambda function
} 

int main(){

    auto f1=[](int number)->void{
        std::cout<<number*10<<std::endl;
    };

    Magic([](int number)->void{
        std::cout<<number*10<<std::endl;
    });
    f1(20);         //Overloaded () operators
    return 0;

}