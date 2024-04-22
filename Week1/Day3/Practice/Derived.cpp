#include "Derived.h"
std::ostream &operator<<(std::ostream &os, const Derived &rhs) {
    os << "_dId: " << rhs._dId
       << " _dName: " << rhs._dName;
    return os;
}
Derived::Derived(int id, std::string name)
:_dId{id},_dName{name}{}
