#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
 
class MeriClass
{
private:
    /* data */
    std::mutex mt;
    std::condition_variable conVar;
    bool flag = false;
    int fac{1};
    int N{0};
 
    static MeriClass m;
 
    MeriClass() {}
 
public:
    MeriClass(const MeriClass &) = delete;
    MeriClass(MeriClass &&) = delete;
    MeriClass &operator=(const MeriClass &) = delete;
    MeriClass &operator=(MeriClass &&) = delete;
    ~MeriClass() = default;
 
    static MeriClass& getInstance();
 
    void takeInput()
    {
        std::lock_guard<std::mutex> lg(mt);
        std::cout << "Enter Input for N : ";
        std::cin >> N;
 
        flag = true;
        conVar.notify_one();
    }
 
    void ComputeFactorial()
    {
        std::unique_lock<std::mutex> ul(mt);
        std::cout << "Waiting here ... " << std::endl;
        conVar.wait(ul, [&]()
                    { return flag; });
 
        for (int i = 1; i <= N; i++)
        {
            fac *= i;
        }
 
        std::cout << "The factorial of the number is  : " << fac << std::endl;
    }
};
 
MeriClass MeriClass::m;
MeriClass &MeriClass::getInstance()
{
    return m;
}
 
int main()
{
 
    std::unique_ptr<MeriClass> up(&MeriClass::getInstance());
    
 
    std::thread t1(&MeriClass::takeInput, up.get());
    std::thread t2(&MeriClass::ComputeFactorial, up.get());
 
    t1.join();
    t2.join();
 
    up.release();
 
    return 0;
}
 