#include<iostream>
#include<optional>
#include<list>


class Demo
{
private:
    /* data */
    int _id;
    std::string _name;
public:
    Demo(/* args */) {}
    ~Demo() {}
    Demo(int id,std::string name):_id{id},_name{name}{}

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    friend std::ostream &operator<<(std::ostream &os, const Demo &rhs) {
        os << "_id: " << rhs._id
           << " _name: " << rhs._name;
        return os;
    }
};

std::optional<std::list<Demo>> FunctionAcheWala(std::list<Demo> &data){
    std::list<Demo> result;
    for(Demo i:data){
        if(i.id()>1){
            result.push_back(i);
        }
    }
    if(result.empty()){
        return std::nullopt;
    }

    return result;
}
int main(){

    std::list<Demo> li;

    li.push_back(Demo(1,"himanshu"));
    li.push_back(Demo(2,"satyam"));
    li.push_back(Demo(3,"Vikas"));

    std::optional<std::list<Demo>> result=FunctionAcheWala(li);

    if(result.has_value()){
        for(Demo i:result.value()){
            std::cout<<i<<std::endl;
        }
        std::cout<<std::endl;
    }
    else{
        std::cout<<"Null signal Encountered"<<std::endl;
    }

    return 0;
}