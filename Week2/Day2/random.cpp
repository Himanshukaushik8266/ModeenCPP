#include<iostream>
#include<list>
class Demo
{
private:
    /* data */
    std::string _name;
    int _l;
public:
    Demo(std::string name,int l):_name{name},_l{l}{}

    friend std::ostream &operator<<(std::ostream &os, const Demo &rhs) {
        os << "_name: " << rhs._name
           << " _l: " << rhs._l;
        return os;
    }
};


int main(){
    int n=4;
    std::list<Demo *> l;
    std::list<int> li;
    int enter;
    std::string name;
    while (n--){
        std::cout<<"Enter integer : ";
        std::cin>>enter;
        li.push_back(enter);

        std::cout<<"Enter name of the Demo : ";
        std::cin>>name;
        

        l.push_back(new Demo(name,*li.end()));

        std::cin.ignore(1,'\n');
        std::cin.clear();


    }

    for(Demo *d:l){
        std::cout<<*d<<std::endl;
    }

    return 0;

}