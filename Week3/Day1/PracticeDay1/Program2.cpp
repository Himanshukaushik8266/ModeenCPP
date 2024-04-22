#include <iostream>
#include <thread>
#include <mutex>

class Demo
{
private:
    /* data */

    int _amount{1000};
    std::mutex mt;
    Demo(int amount) : _amount{amount} {}
    static Demo *_onlyObject;

public:
    Demo() = delete;
    Demo(const Demo &) = delete;
    Demo(Demo &&) = delete;
    Demo &operator=(const Demo &) = delete;
    Demo &operator=(Demo &&) = delete;
    ~Demo() = default;

    static Demo *CreateObject(int amount)
    {
        if (_onlyObject)
        {
            return _onlyObject;
        }
        else
        {
            _onlyObject = new Demo(amount);
            return _onlyObject;
        }
    }

    void withdraw()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::lock_guard<std::mutex> lk(mt);
            _amount -= 100;
            // std::cout<<_amount<<std::endl;
        }
    }
    void deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::lock_guard<std::mutex> lk(mt);
            _amount += 100;
            // std::cout<<_amount<<std::endl;
        }
    }

    int amount() const { return _amount; }
};

Demo *Demo::_onlyObject{nullptr};

int main()
{

    Demo *d=Demo::CreateObject(9000);

    std::thread t1(&Demo::deposit,d);
    std::thread t2(&Demo::withdraw,d);

    t1.join();
    t2.join();

    std::cout<<d->amount()<<std::endl;


    return 0;
}