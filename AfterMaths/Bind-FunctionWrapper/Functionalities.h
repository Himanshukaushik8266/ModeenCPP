#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<functional>
#include<vector>
#include<iostream>
using FnType=std::function<void(const std::string,std::vector<int>, const std::string )>;


extern FnType function;
extern FnType bindedfunction;





#endif // FUNCTIONALITIES_H

