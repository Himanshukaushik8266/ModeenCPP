#include <iostream>

void Display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << *(arr + i) << " ";
    }
    std::cout << "\n";
}
void Display(int **arr2, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << *(*(arr2 + i) + j) << " ";
        }
        std::cout << "\n";
    }
}
int main()
{

    int size = 5;

    // int arr1[col] {4,2,6,7};
    // int arr2[col]{6,7,3,6};
    // int arr3[col]{4,5,7,3};

    // int *arr[row]={arr1,arr2,arr3};

    int row = 3;
    int col = 4;

    int **a = (int **)malloc(row * sizeof(int *));

    for (int i = 0; i < row; i++)
    {
        *(a + i) = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++)
        {
            std::cin >> *(*(a + i) + j);
        }
    }

    Display(a, row, col);
}
