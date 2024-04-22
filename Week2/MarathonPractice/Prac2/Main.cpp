#include<iostream>
#include<functional>
class Main
{
private:
    /* data */
    int _id;
    std::string _name;
public:
    Main()=default;
    Main(const Main &)=delete;
    Main(const Main && )=delete;
    Main & operator=(const Main & )=delete;
    Main &operator=(const Main &&)=delete;
    ~Main()=default;

    Main(int id , std::string name):_id{id},_name{name}{}

    friend std::ostream &operator<<(std::ostream &os, const Main &rhs) {
        os << "_id: " << rhs._id
           << " _name: " << rhs._name;
        return os;
    }

};
class Demo
{
private:
    std::string _yeahBoy;
    // std::reference_wrapper<Main> _data;
    Main * _data{nullptr};
public:
    Demo()=default;
    Demo(const Demo &)=delete;
    Demo(const Demo && )=delete;
    Demo & operator=(const Demo & )=delete;
    Demo &operator=(const Demo &&)=delete;
    ~Demo()=default;
    // Demo(std::string yeahBoy , std::reference_wrapper<Main> data) :_yeahBoy{yeahBoy},_data{data}{}
    Demo(std::string yeahBoy , Main * data) :_yeahBoy{yeahBoy},_data{data}{}
    Demo(std::string yeahBoy) :_yeahBoy{yeahBoy}{}

    friend std::ostream &operator<<(std::ostream &os, const Demo &rhs) {
        os << "_yeahBoy: " << rhs._yeahBoy
           << " _data: " << *rhs._data;
        return os;
    }
};

int main(){
    
    std::vector<Demo *> DemoData;

    // std::vector<std::reference_wrapper<Main>> MainData;
    std::vector<Main *> MainData;

    Main *m1=new Main();
    Main *m2=new Main(2,"Vatan");

    MainData.push_back(m1);
    MainData.push_back(m2);

    DemoData.push_back(new Demo("Hellow"));
    DemoData.push_back(new Demo("Hilloo",m2));



    for(Demo * d:DemoData){
        std::cout<<*d<<std::endl;
    }

    for(Demo *d :DemoData){
        delete d;
    }


    return 0;

}