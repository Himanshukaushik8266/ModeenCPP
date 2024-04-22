#include <iostream>
#include <optional>
#include <functional>

using Function = std::function<std::optional<std::vector<int>>(std::vector<int> &)>;

Function F1 = [](std::vector<int> &data) -> std::optional<std::vector<int>>
{
    std::vector<int> result;
    for (int i : data)
    {
        if (i % 2 == 0)
        {
            result.push_back(i);
        }
    }
    if (result.empty())
    {
        return std::nullopt;
    }
    return result;
};

int main()
{

    std::vector<int> v{3, 2, 9, 5};

    std::optional<std::vector<int>> result = F1(v);
    if (result.has_value())
    {
        for (int i : result.value())
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "Nahi mila kuch" << std::endl;
    }

    return 0;
}