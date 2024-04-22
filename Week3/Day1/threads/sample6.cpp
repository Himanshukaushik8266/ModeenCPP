/*
    RAII :
*/
/*
    One object of this class will be responsible for one connection mechanism
*/
#include <ostream>
#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
class BankingOperations
{
private:
    /* data */
    int _amount{0};
    std::mutex mt;
    static BankingOperations *_soloHeroObject;
    BankingOperations(int amount) : _amount{amount} {}

public:
    BankingOperations() = delete;
    BankingOperations(const BankingOperations &) = delete;
    BankingOperations(BankingOperations &&) = delete;
    BankingOperations &operator=(const BankingOperations &) = delete;
    BankingOperations &operator=(BankingOperations &&) = delete;
    ~BankingOperations() = default;

    void withdraw()
    {
        for (int i = 0; i < 100; i++)
        {

            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::lock_guard<std::mutex> lk(mt);
            _amount -= 10;
        }
    }
    void deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::lock_guard<std::mutex> lk(mt);
            _amount += 10;
        }
    }

    int amount() const { return _amount; }

    static BankingOperations *getFirstInstance(int amount)
    {
        if (_soloHeroObject)
        {
            return _soloHeroObject;
        }
        else
        {
            _soloHeroObject = new BankingOperations(amount);
            return _soloHeroObject;
        }
    }
};

BankingOperations *BankingOperations::_soloHeroObject{nullptr};
int main()
{

    BankingOperations *b1 = BankingOperations::getFirstInstance(1000); // Value initialisation

    std::vector<std::thread> arr;

    arr.push_back(std::thread(&BankingOperations::withdraw, b1));
    arr.push_back(std::thread(&BankingOperations::deposit, b1));

    for (std::thread &t : arr)
    {
        /*
            Before joining the thread please check whether it is joinable or not
            joining same thread more than once it will show undefined behaviour
        */
        if (t.joinable())
        { // true, still wait means it is joinable
            t.join();
        }
        else
        {
            throw std::runtime_error("Thread is not joinable");
        }
    }

    std::cout << b1->amount() << std::endl;

    return 0;
}