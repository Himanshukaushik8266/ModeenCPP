#include<iostream>
class Dummy
{
private:
    /* data */
public:
    Dummy() noexcept{}

    void Display ()noexcept{
        std::cout<<"Hello\n";
        throw 1;
    }


    ~Dummy() {}
};

int main(){
    return 0;
}