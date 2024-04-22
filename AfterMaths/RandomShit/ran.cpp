#include <iostream>
#include <array>
#include <vector>
#include <functional>
#include <memory>
class Home
{
private:
    /* data */
    int _a{0};
 
public:
    Home() = default;
    Home(const Home &) = delete;
    Home(Home &&) = delete;
    Home &operator=(const Home &) = delete;
    Home &operator=(Home &&) = delete;
    ~Home() = default;
 
    Home(int a) : _a{a} {}
 
    friend std::ostream &operator<<(std::ostream &os, const Home &rhs)
    {
        os << "_a: " << rhs._a;
        return os;
    }
};
using Vector = std::vector<std::shared_ptr<Home>>;
using Container = std::array<std::reference_wrapper<Vector>, 3>;
 
void CreateObjects(Container &data, Vector &vec1, Vector &vec2, Vector &vec3)
{
    // data1
 
    vec1.push_back(std::make_shared<Home>(10));
    vec1.push_back(std::make_shared<Home>(30));
    vec1.push_back(std::make_shared<Home>(20));
    data[0] = std::ref(vec1);
 
    // data2
 
    vec2.push_back(std::make_shared<Home>(600));
    vec2.push_back(std::make_shared<Home>(6435));
    vec2.push_back(std::make_shared<Home>(3466));
    data[1] = std::ref(vec2);
 
    // data3
 
    vec3.push_back(std::make_shared<Home>(65346));
    vec3.push_back(std::make_shared<Home>(56456));
    vec3.push_back(std::make_shared<Home>(54352));
    data[2] = std::ref(vec3);
}
int main()
{
    Vector vec1, vec2, vec3;
    Container data{std::ref(vec1), std::ref(vec2), std::ref(vec3)};
 
    CreateObjects(data, vec1, vec2, vec3);
 
    for (int i = 0; i < 3; i++)
    {
        Vector temp = data[i].get();
 
        for (std::shared_ptr<Home> ptr : temp)
        {
            std::cout << *ptr << " ";
        }
        std::cout << "\n";
    }
}
