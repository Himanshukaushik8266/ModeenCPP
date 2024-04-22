#include<iostream>
#include<vector>
#include<memory>

class Demo
{
private:
    /* data */
    int _id{0};
    std::string _name{""};
public:
    Demo() =default;
    Demo(const Demo &)=delete;
    Demo (const Demo &&)=delete;
    Demo & operator=(const Demo &)=delete;
    Demo & operator=(const Demo &&)=delete;
    ~Demo() =default;


    Demo(int id,std::string name):_id{id},_name{name}{}

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    friend std::ostream &operator<<(std::ostream &os, const Demo &rhs);

    
};
inline std::ostream &operator<<(std::ostream &os, const Demo &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name;
    return os;
}
using DemoPointers=std::shared_ptr<Demo>;
int main(){

    std::vector<DemoPointers> data;

    data.push_back(std::make_shared<Demo>(10,"Himanshu"));
    data.push_back(std::make_shared<Demo>(11,"Piyush"));
    data.push_back(std::make_shared<Demo>(12,"Kushagra"));

    for(DemoPointers d:data){
        std::cout<<*d<<std::endl;
    }

    return 0;

}

