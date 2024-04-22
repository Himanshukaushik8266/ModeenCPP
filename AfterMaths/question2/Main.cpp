#include <iostream>
#include "Datahandler.h"
#include <thread>
using ThreadContainer = std::array<std::thread, 4>;

int main()
{
    std::unique_ptr<Datahandler> &ptr = Datahandler::getInstance();

    ThreadContainer threads;
    threads[0] = std::thread(&Datahandler::TakeInput, ptr.get());
    threads[1] = std::thread(&Datahandler::AverageValue, ptr.get());
    threads[2] = std::thread(&Datahandler::ComputeSqaure, ptr.get());
    threads[3] = std::thread(&Datahandler::ComputeFactorial, ptr.get());

    for (int i = 0; i < 4; i++)
    {
        if (threads[i].joinable())
        {
            threads[i].join();
        }
    }
    ptr.release(); // Not mandatory in this case

    return 0;
}