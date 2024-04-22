#include "Functionalities.h"

template<typename T, typename... Args>
T* relay(Args&&... args){
    return new T(std::forward<Args>(args)...);
}

template<typename T,typename... Args>
std::shared_ptr<T> relay2(Args&&... args){
    return std::make_shared<T>(std::forward<Args>(args)...);
}

int main(){
    Employee* e=relay<Employee>("Ramesh", 30000.0f, "Manager", 2);
    std::cout<<*e<<'\n';


    std::shared_ptr<Employee> e1=relay2<Employee>("vikas", 30000.0f, "trainer", 2);
    std::cout<<*e1<<'\n';

}