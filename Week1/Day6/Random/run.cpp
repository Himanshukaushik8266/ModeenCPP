#include<iostream>
#include<stdexcept>
void Magic(int a) noexcept{
    int n1{0};
    std::cin>>n1;
    std::cout<<a/n1<<std::endl;
}
int main(){

    Magic(10);
    return 0;

}