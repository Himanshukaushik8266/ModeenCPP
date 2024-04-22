#include <iostream>
#include <functional>
#include <optional>
using FnType = std::function<void(int **, int, int)>;

FnType Display = [](int **arr2, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << *(*(arr2 + i) + j) << " ";
        }
        std::cout << "\n";
    }
};

FnType maxrow = [](int **a, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int maxele = *(*(a + i) + 0);
        for (int j = 0; j < col; j++)
        {
            if (maxele < (*(*(a + i) + j)))
            {
                maxele = *(*(a + i) + j);
            }
        }
        std::cout << "max of row " << i + 1 << " is " << maxele << "\n";
    }
};

void Adaptor(FnType &fn, int **a, int row, int col, std::optional<FnType> UserNeDiaKya)
{
    if (UserNeDiaKya.has_value())
    {
        UserNeDiaKya.value()(a, row, col);
    }
    else
    {
        fn(a, row, col);
    }
}

int main()
{
    int row = 3;
    int col = 4;
    int **a = new int *[row];
    for (int i = 0; i < row; i++)
    {
        *(a + i) = new int[col];
kw
        for (int j = 0; j < col; j++)
        {
            std::cin >> *(*(a + i) + j);
        }
    }

    // maxrow(a, row, col);

    Adaptor(Display, a, row, col, [](int **a, int row, int col)
            {   std::cout<<"First Element is : ";
                std::cout << *(*(a + 0) + 0) << std::endl; });
}