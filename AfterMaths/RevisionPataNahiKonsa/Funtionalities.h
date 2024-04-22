#ifndef FUNTIONALITIES_H
#define FUNTIONALITIES_H
#include<functional>
#include<iostream>
using FnType=std::function<void(int, int )>;

void Adaptor(FnType &fn,int a, int b);

extern FnType Square;
extern FnType Cube;




#endif // FUNTIONALITIES_H
