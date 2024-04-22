#include <iostream>
#include <memory>
#include <vector>
using FloatPointer = std::shared_ptr<float>;
using Container = std::vector<FloatPointer>;

int main()
{
    Container data;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        float enter;
        std::cin >> enter;

        FloatPointer temp = std::make_shared<float>(enter);

        data.push_back(temp);
    }
    std::cout << "Your values are : " << std::endl;

    for (FloatPointer f : data)
    {
        std::cout << *f << std::endl;
    }

    return 0;
}