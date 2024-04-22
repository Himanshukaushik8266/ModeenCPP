#include <iostream>
#include <array>
#include <functional>
#include <thread>
#include<mutex>

std::mutex mt; //binary semaphore!

void Square(std::array<int, 5> &data)
{
    for (int i : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        /*
            ONLY 1 executing entity should be doing this at a time!
            Output stream buffer is shared between both the threads
        */
        mt.lock();
        std::cout << "Square of this number is :" << i * i << std::endl;
        mt.unlock();
    }
}
void Cube(std::array<int, 5> &data)
{
    for (int i : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        /*
            ONLY 1 executing entity should be doing this at a time!
        */
        mt.lock();
        std::cout << "Cube of this number is :" << i * i * i << std::endl;
        mt.unlock();
    }
}
int main()
{
    std::array<int, 5> a{65, 34, 22, 77, 97};
    std::thread t1(&Square, std::ref(a));
    std::thread t2(&Cube, std::ref(a));
    std::thread t3(std::move(t2));

    t2.~thread();

    t1.join();
    // t2.join();
    t3.join();

    std::cout << "Good bye \n";
    return 0;
}