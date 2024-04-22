#include <iostream>
#include <functional>
#include <memory>
#include <array>
#include <vector>
#include <queue>
/*********************************************************/
class Base
{
private:
    /* data */
public:
    Base(/* args */) {}
    virtual ~Base() {}

    void operator[](int i)
    {
        std::cout << 10 << std::endl;
    }
};
/*************************************************************/
class Madam : virtual public Base
{
private:
    std::string _name;

public:
    Madam()
    {
        std::cout << "Constructor called!!" << std::endl;
    };
    Madam(const Madam &) = delete;
    Madam(Madam &&) = delete;
    Madam &operator=(const Madam &) = delete;
    Madam &operator=(Madam &&) = delete;
    ~Madam() = default;

    Madam(std::string name) : _name{name} {}
    std::string name() const { return _name; }
    /***********ostream operator overload*****************************************/
    friend std::ostream &operator<<(std::ostream &os, const Madam &rhs)
    {
        os << "_name: " << rhs._name;
        return os;
    }
    /*******************New Operator Overload**************************************/
    static void *operator new(size_t s)
    {
        std::cout << "Hamare wala" << std::endl;
        return (void *)malloc(s);
    }
    /******************Delete Operator Overload************************************/
    static void operator delete(void *pp)
    {
        std::cout << "Yeh mera delete" << std::endl;
        free(pp);
    }
    /**********************Subscript Operator Overload******************************/

    void operator[](int i)
    {

        std::cout << i << std::endl;
    }
    /************************Functor Overload***************************************/

    void operator()()
    {
        std::cout << "This is function calling" << std::endl;
    }
};
/************************************************************************************/

using MeraMap = std::unordered_map<int, std::shared_ptr<Madam>>;

auto Comparator = [](const std::pair<int, std::shared_ptr<Madam>> p1, const std::pair<int, std::shared_ptr<Madam>> p2)
{
    return p1.second->name() > p2.second->name();
};
int main()
{
        
    Base *mm = new Madam();
    Madam *ptr = dynamic_cast<Madam *>(mm);
    (*ptr)();

    std::cout << &mm << " " << &ptr << std::endl;
    delete (ptr);

    return 0;
}