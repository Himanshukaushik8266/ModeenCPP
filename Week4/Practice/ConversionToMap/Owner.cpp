#include "Owner.h"

Owner::Owner(std::string name)
:_registered_name{name}
{
}
std::ostream &operator<<(std::ostream &os, const Owner &rhs) {
    os << "_registered_name: " << rhs._registered_name;
    return os;
}
