#include <iostream>
#include <map>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <future>

std::mutex mt;
std::condition_variable cv;
bool flag = false;
std::promise<int> pr;
std::future<int> promised_future = pr.get_future();

using Container = std::map<int, std::string>;
using FunType = std::function<void(Container &)>;

FunType CreateObjects = [](Container &data)
{
    std::lock_guard<std::mutex> lg(mt);
    data.insert(std::make_pair<int, std::string>(1, "Himanshu"));
    data.insert(std::make_pair<int, std::string>(2, "Manthan"));
    data.insert(std::make_pair<int, std::string>(3, "Saurav"));
    data.insert(std::make_pair<int, std::string>(4, "Priyanshu"));
    flag = true;
    cv.notify_all();
};

FunType FindKeyForGivenName = [](Container &data)
{
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, []()
            { return flag; });

    // int keyChecker = promised_future.get();

    int keyChecker = 3;
    for (auto &[key, value] : data)
    {
        if (key == keyChecker)
        {
            std::cout << "The name corresponding to the given name is : " << value << std::endl;
            break;
        }
    }
};

// void takeInput()
// {
//     std::lock_guard<std::mutex> lg(mt);
//     std::cout << "Enter key to find the name of the student : ";
//     int a;
//     std::cin >> a;
//     pr.set_value(a);
// }

int main()
{
    Container dataMap;

    // std::thread t1(CreateObjects, std::ref(dataMap));
    // std::thread t2(FindKeyForGivenName, std::ref(dataMap));

    std::future<void> t1=std::async(CreateObjects, std::ref(dataMap));
    std::future<void> t2=std::async(FindKeyForGivenName, std::ref(dataMap));

    t1.get();
    t2.get();

    class Name{
        private:
            int a;
        public:
            Name()=default;
            ~Name()=default;
            void Display(){
                std::cout<<"The Value of a is  : "<<a<<std::endl;
            }
            void setName(int a){this->a=a;};
    };

    Name* n=new Name();

    n->setName(15);

    n->Display();

    delete n;

    // std::thread t3(&takeInput);

    // t1.join();
    // t2.join();
    // t3.join();
    return 0;
}