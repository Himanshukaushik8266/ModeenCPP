#include <iostream>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <future>
#include <functional>
std::mutex mt;
std::condition_variable cv;
bool flag = false;
int **arr;
std::function<void(void)> takeInput = [](void) -> void
{
    arr = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        arr[i] = new int[3];
    }
    std::lock_guard<std::mutex> lg(mt);

    std::cout << "Enter integer in 2D array : " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> arr[i][j];
        }
    }
    flag = true;
    cv.notify_one();
};
std::function<void(void)> display = [](void) -> void
{
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&]()
            { return flag; });
    std::cout << "2D Array is  : ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{

    std::future<void> f1 = std::async(takeInput);
    std::future<void> f2=std::async(display);
 
    f1.wait();
    f2.wait();

    for (int i = 0; i < 3; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}