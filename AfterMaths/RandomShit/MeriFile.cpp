#include <iostream>
#include <unordered_map>
#include <queue>
#include <functional>
#include <list>
#include <array>
#include <variant>
#include <optional>

using VarType = std::variant<int, std::string>;
using Container = std::list<VarType>;
using PriorityConatiner = std::priority_queue<VarType, std::vector<VarType>, std::function<bool(const VarType &, const VarType &)>>;

PriorityConatiner Adaptor(Container &data, std::optional<std::function<bool(const VarType &, const VarType &)>> fn)
{

    if (fn.has_value())
    {
        PriorityConatiner temp(data.begin(), data.end(), fn.value());
        return temp;
    }
    else
    {
        std::cout << "Please provide a fucntion to perform operation !" << std::endl;
        return PriorityConatiner{};
    }
}
void DisplayPriorityQueue(PriorityConatiner temp)
{
    while (!temp.empty())
    {
        std::visit([](auto &&val)
                   { std::cout << val << std::endl; },
                   temp.top());
        temp.pop();
    }
}

int main()
{

    Container c{3, "Himanshu", "Tushar", 6, 4, "Kinshuk"};

    PriorityConatiner meriQueue = Adaptor(c, [](const VarType &v1, const VarType &v2)
                                          {
        if(std::holds_alternative<int>(v1) && std::holds_alternative<int>(v2))
        {
            int val1 = std::get<int>(v1);
            int val2 = std::get<int>(v2);
            return val1<val2;
        }
        else if(std::holds_alternative<std::string>(v1) && std::holds_alternative<std::string>(v2))
        {
            std::string val1 = std::get<std::string>(v1);
            std::string val2 = std::get<std::string>(v2);
            return val1>val2;
        } 

        return true;    
    });

    DisplayPriorityQueue(meriQueue);

    return 0;
}