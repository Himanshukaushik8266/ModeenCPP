#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
std::mutex mt;
bool flag = false;
std::condition_variable cv;

int value = 0;
void Consumer()
{
    int count = 0;
    int *arr = (int *)malloc(sizeof(int[10]));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (i + 1) * 2;
    }

    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&]()
            { return flag; });

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] < value)
        {
            count++;
        }
    }

    std::cout << "Consumer 1 : Count of number less than value : " << count << std::endl;
}
void Consumer2()
{
    int count1 = 0;
    int *arr = (int *)malloc(sizeof(int[10]));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (i + 1) * 3;
    }

    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&]()
            { return flag; });

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] < value)
        {
            count1++;
        }
    }

    std::cout << "Consumer 2 : Count of number less than value : " << count1 << std::endl;
}

int main()
{

    std::thread t1(&Consumer);
    std::thread t2(&Consumer2);
    mt.lock();
    // std::cin>>value;
    value = 5;
    flag = true;
    mt.unlock();

    cv.notify_all();

    t1.join();
    t2.join();

    return 0;
}