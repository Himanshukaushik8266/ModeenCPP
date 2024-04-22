#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>

class SingletonClass
{
private:
    /* data */
    static std::shared_ptr<SingletonClass> _object;
    std::mutex mt;
    std::condition_variable cv;
    int _amount{0};
    bool flag=false;
    int _val{0};
    SingletonClass(int amount) : _amount{amount} {}

public:
    SingletonClass() = delete;
    SingletonClass(const SingletonClass &) = delete;
    SingletonClass(SingletonClass &&) = delete;
    SingletonClass &operator=(const SingletonClass &) = delete;
    SingletonClass &operator=(SingletonClass &&) = delete;
    ~SingletonClass() = default;

    void Add()
    {
        for (int i = 0; i < 100; i++)
        {
            std::lock_guard<std::mutex> lg(mt);
            _amount += 10;
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }
    }

    void Subtract()
    {
        for (int i = 0; i < 100; i++)
        {
            std::lock_guard<std::mutex> lg(mt);
            _amount -= 10;
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }
    }

    static std::shared_ptr<SingletonClass> getInstances(int amount)
    {
        if (_object)
        {
            return _object;
        }
        else
        {
            _object.reset(new SingletonClass(amount)); /// Point to remember
            return _object;
        }
    }

    void operation(){
        int *ptr = new int;
        std::unique_lock<std::mutex> ul(mt);
        cv.wait(ul,[&](){
            return flag;
        });
        *ptr = _val+500;
        std::cout<<*ptr<<std::endl;
    }

    void TakeInput()
    {
        std::lock_guard<std::mutex> lg(mt);
        std::cin>>_val;
        flag=true;
    }

    void notify()
    {
        cv.notify_one();
    }


    int amount() const { return _amount; }
};
std::shared_ptr<SingletonClass> SingletonClass::_object{nullptr};

int main()
{
    std::shared_ptr<SingletonClass> ptr = SingletonClass::getInstances(100000);

    // std::thread t1(&SingletonClass::Add, ptr);
    // std::thread t2(&SingletonClass::Subtract, ptr);

    std::shared_ptr<SingletonClass> ptr2 = SingletonClass::getInstances(5000);
    std::thread t3(&SingletonClass::operation, ptr);
    ptr->TakeInput();
    ptr->notify();


    // t1.join();
    // t2.join();
    t3.join();

    // std::cout << ptr->amount() << std::endl;
    // std::cout << ptr2->amount() << std::endl;

    return 0;
}