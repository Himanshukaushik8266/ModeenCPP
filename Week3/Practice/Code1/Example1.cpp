#include<iostream>
#include <memory>
class Demo
{
private:
    int _id;
    std::string _name;
public:
    Demo() {}
    Demo(int id,std::string name):_id{id},_name{name}{}
    ~Demo() {}
};

void Dummy(){
    // Demo *ex1=new Demo(10,"Harshit");

    // std::shared_ptr<Demo> sptr{new Demo(10,"Harshit")};
    std::shared_ptr<Demo> sptr{std::make_shared<Demo>(10,"Harshit")};//Preferred way to allocate in heap

    int n1{0};
    try{
        std::cin>>n1;
    std::cout<<10/n1;
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
    }
    // delete ex1;
}
int main(){

    Dummy();
    return 0;

}


/*
    Dummy()

    ex1 ----------------------------------> Heap [10   |     Harshit]
    [0x100H]                                 0x100H   
    <---8bytes--->
    0x11H           0X18H

    n1
    [   0    ]
    <----4bytes---->
    0x45H       0x48H

*/


/*
    data : pointer ex1
    function which is guarantee to execute each time an object destroyed:destructor

    action before data(ex1) is destroyed  :  Heap deallocation using delete ex1



    smart pointers in modern cpp

        ->  std::unique_pointer
        ->  std::shared_pointer
        ->  std::weak_pointer (token which can convert to shared ptr)

*/