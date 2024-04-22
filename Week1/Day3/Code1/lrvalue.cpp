/*
    4 Tokens 
    int //data type
    n1 //identifier name given by the programmer
    = // assignment
    10 // integer value has no address(no storage location in ram)
*/

/*
    any form of data that is not preserved in a fixed location 
    in memory will disappear at the end of the expression (full expression)
    where it originated
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    10; //temporary (rvalue);
    "harshit";
    std::vector<int> {1,2,3};
    // int *ptr=&n1; // lvalue asking the os that it persists here ptr is lvalue;
    return 0;

}