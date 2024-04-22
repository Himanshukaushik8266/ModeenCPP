#include <iostream>
 
class classA{
    public:
        virtual void Display(){
            std::cout<<"A display"<<std::endl;
        }
};
 
class classB : public classA{
    public:
        void Display(){
            std::cout<<"B Display"<<std::endl;
        }
};
 
 
int main(){
    classA *a = new classA();
    
    classB *c = dynamic_cast<classB*>(a);
    if(c==nullptr){
        std::cout<<"Hell"<<std::endl;
        return 0;
    }
    c->Display();
}