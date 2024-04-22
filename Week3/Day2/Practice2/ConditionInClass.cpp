#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
class ConditionInClass
{
private:
    static ConditionInClass *_object;
    int _value{0};
    std::mutex mt;
    std::condition_variable cv;
    bool flag{false};
    int *ptr;
    ConditionInClass() = default;

public:
    ConditionInClass(const ConditionInClass &) = delete;
    ConditionInClass(ConditionInClass &&) = delete;
    ConditionInClass &operator=(const ConditionInClass &) = delete;
    ConditionInClass &operator=(ConditionInClass &&) = delete;
    ~ConditionInClass()
    {
        delete ptr;
    }

    static ConditionInClass *getInstance()
    {
        if (_object)
        {
            return _object;
        }
        else
        {
            _object = new ConditionInClass();
            return _object;
        }
    }
    void Operation()
    {
        ptr = new int;
        std::unique_lock<std::mutex> ul(mt);
        cv.wait(ul, [&]()
                { return flag; });
        *ptr = _value * _value * _value;
        std::cout << "Cube of the  " << _value << " is : " << *ptr << std::endl;
    }

    void TakeInput()
    {
        std::lock_guard<std::mutex> lg(mt);
        int input = 0;
        std::cin >> input;
        setValue(input);
    }
    void Notify()
    {
        cv.notify_one();
    }
    void setValue(int value) { _value = value; }

    void setFlag(bool flag_) { flag = flag_; }
};

ConditionInClass *ConditionInClass::_object{nullptr};

int main()
{

    ConditionInClass *cd = ConditionInClass::getInstance();

    std::thread t1(&ConditionInClass::Operation, cd);

    cd->TakeInput();

    cd->setFlag(true);

    cd->Notify();

    t1.join();

    return 0;
}