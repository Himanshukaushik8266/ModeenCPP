#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

class Home
{
private:
    /* data */
    std::string _name{""};

public:
    Home() = default;
    Home(const Home &) = delete;
    Home(Home &&) = delete;
    Home &operator=(const Home &) = delete;
    Home &operator=(Home &&) = delete;
    ~Home() = default;

    Home(std::string name) : _name{name} {}

    friend std::ostream &operator<<(std::ostream &os, const Home &rhs)
    {
        os << "_name: " << rhs._name;
        return os;
    }
};
using Array = std::array<Home *, 3>;

void CreateObjects(Array &data)
{
    data[0] = new Home("Himanshu");
    data[1] = new Home("Shrestha");
    data[2] = new Home("Priyanshu");
}

void DeleteObjects(Array &data){
    for(int i=0;i<3;i++){
        delete data[i];
    }
}

int main()
{
    Array data;
    CreateObjects(data);

    for (int i = 0; i < 3; i++)
    {
        std::cout << *data[i] << "\t";
    }
    std::cout << "\n";

    DeleteObjects(data);
    
    return 0;
}