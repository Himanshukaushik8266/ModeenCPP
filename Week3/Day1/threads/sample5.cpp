#include <iostream>
#include <thread>
#include <mutex>
int amount = 1000;
std::mutex mt;
void withdraw()
{
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::lock_guard<std::mutex> lk(mt);
        amount -= 10;
    }
}
void deposit()
{
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::lock_guard<std::mutex> lk(mt);
        amount += 10;
    }
}

int main()
{

    std::thread t1(&withdraw);
    std::thread t2(&deposit);

    t1.join();
    t2.join();

    std::cout << "Final amount is : " << amount << std::endl;

    return 0;
}