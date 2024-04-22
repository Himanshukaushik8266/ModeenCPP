#include "Functionalities.h"

FnType function = [](const std::string s2,std::vector<int> vec, const std::string s1) -> void
{
    std::cout << "First string is : " << s1 << std::endl;
    std::cout << "Second string is : " << s2 << std::endl;
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
};

FnType bindedfunction = std::bind(function,std::placeholders::_1,std::placeholders::_2,"Waah");