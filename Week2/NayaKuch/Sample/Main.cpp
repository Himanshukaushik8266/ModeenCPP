#include <iostream>
#include "Functionalities.h"

int main()
{
    std::vector<int> v1{10,20,676,35,776};
    try
    {
        Adaptor(lfn1, v1);
        Adaptor(lfn2, v1);
        Adaptor(lfn3, v1);

        binded_wrapper(10);
    }
    catch (std::runtime_error &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}