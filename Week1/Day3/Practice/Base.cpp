#include "Base.h"

Base::Base(int id, std::string name,Derived *d)
:_id{id},_name{name},_data{d}{}

std::ostream &operator<<(std::ostream &os, const Base &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _data: " << *rhs._data;
    return os;
}
