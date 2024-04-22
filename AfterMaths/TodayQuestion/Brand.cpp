#include "Brand.h"
std::ostream &operator<<(std::ostream &os, const Brand &rhs) {
    os << "_name: " << rhs._name;
    for(std::reference_wrapper<Car> c:rhs._cars){
        std::cout<<c.get()<<std::endl;
    }
    return os;
}

Brand::Brand(std::string name, std::vector<std::reference_wrapper<Car>> car)
:_name{name},_cars{car}
{
}