#include "Demo.h"
std::ostream &operator<<(std::ostream &os, const Demo &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name;
    return os;
}
Demo::Demo(int id, std::string name):_id{id},_name{name}{}
