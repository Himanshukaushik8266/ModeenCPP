#include "License.h"
std::ostream &operator<<(std::ostream &os, const License &rhs) {
    std::string val="";
    if(rhs.licenseType()==LicenseType::OWNED){
        val="Owned";
    }
    else{
        val="Rented";
    }
    os << "_license_number: " << rhs._license_number
       << " _license_type: " << val;
    return os;
}

License::License(int id, LicenseType type)
:_license_number{id},_license_type{type}
{
}