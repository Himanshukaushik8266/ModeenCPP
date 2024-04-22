#include <iostream>
#include <vector>

std::vector<int> FindOddNumbers(std::vector<int> &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }

    std::vector<int> record;
    for (int i : data)
    {
        if (i % 2 != 0)
        {
            record.push_back(i);
        }
    }
    return record;
}
int main()
{
    std::vector<int> data{4, 6, 8, 10, 12};
    try
    {
        if (std::vector<int> v = FindOddNumbers(data); !v.empty())
        {
            std::cout << v[0] << std::endl;
        }
        else
        {
            std::cout << "Data is empty" << std::endl;
        }
    }
    catch (std::runtime_error &ex)
    {
        std::cout <<"Yeh wala : "<< ex.what() << std::endl;
    }

    return 0;
}
