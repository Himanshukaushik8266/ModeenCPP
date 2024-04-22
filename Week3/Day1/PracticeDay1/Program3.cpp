#include <iostream>
#include <thread>
#include <mutex>

int X = 0;
int Y = 0;
std::mutex m1;
std::mutex m2;

int FinalResult = 0;

void PerformOperation(int &XorY, std::mutex &m, std::string s)
{
    for (int i = 0; i < 5; i++)
    {
        m.lock();
        ++XorY;
        m.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void PerformBigOperation()
{
    int n = 6;
    while (n--)
    {
        if (std::try_lock(m1, m2) == -1)
        {
            FinalResult += (X + Y);
            X = 0;
            Y = 0;

            m1.unlock();
            m2.unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

int main()
{

    std::thread t1(PerformOperation, std::ref(X), std::ref(m1), "X : ");
    std::thread t2(PerformOperation, std::ref(Y), std::ref(m2), "Y : ");
    std::thread t3(PerformBigOperation);
    PerformBigOperation();

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Final result is : " << FinalResult << std::endl;
    return 0;
}