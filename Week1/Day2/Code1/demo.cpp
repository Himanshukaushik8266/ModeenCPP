#include<bits/stdc++.h>
using namespace std;
enum class Rank {
    FIRST,
    SECOND,
    THIRD
};


enum class Gear{
    FIRST,
    SECOND,
    THIRD
};

enum class Position{
    FIRST,
    SECOND,
    THIRD
};

void Magic(int number){
    std::cout<<"number*number"<<std::endl;
}
int main(){
    //We cannot force the user to use enum name as a prefix
    
    enum Rank r1=Rank::FIRST;
    enum Gear g1=Gear::FIRST;

    //Compiler shpuld block comparison of enums of different types
    
    // if(r1==g1){
    //     std::cout<<"OOPS!!!!"<<endl;
    // }


    //Implicit conversion must not be done by compiler
    // Magic(r1);
    
    return 0;

}