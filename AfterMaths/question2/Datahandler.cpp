#include "Datahandler.h"
std::unique_ptr<Datahandler> Datahandler::_object{nullptr};
std::unique_ptr<Datahandler> &Datahandler::getInstance()
{
    if (!_object)
    {
        _object = std::unique_ptr<Datahandler>(new Datahandler());
    }
    return _object;
}

void Datahandler::TakeInput()
{
    std::lock_guard<std::mutex> lg(mt);

    while (true)
    {
        bool flag = true;
        std::cout << "Enter Five integer : ";
        for (int i = 0; i < 5; i++)
        {
            std::cin >> _data[i];
            if (_data[i] < 1 || _data[i] > 10)
            {
                std::cout << "Invalid input! Try again" << std::endl;
                flag = false;
                std::cin.ignore(1, '\n');
                std::cin.clear();
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }

    checker = true;
    cv.notify_one();
}

void Datahandler::ComputeSqaure()
{
    std::lock_guard<std::mutex> lg(mt);
    _sqaure_result[0] = 3 * 3;
    _sqaure_result[1] = 9 * 9;
    _sqaure_result[2] = 15 * 15;
    _sqaure_result[3] = 21 * 21;
    _sqaure_result[4] = 27 * 27;

    std::cout << "Squares are:: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << _sqaure_result[i] << " ";
    }
    std::cout << std::endl;
}

void Datahandler::ComputeFactorial()
{
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&]()
            { return checker; });

    for (int i = 0; i < 5; i++)
    {
        int fac = 1;
        for (int j = 1; j <= _data[i]; j++)
        {
            fac *= j;
        }
        _factorial_result[i] = fac;
    }
    std::cout << "Factorials are:: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << _factorial_result[i] << " ";
    }
    std::cout << std::endl;
}

void Datahandler::AverageValue()
{
    std::lock_guard<std::mutex> lg(mt);
    std::array<int, 5> primes{2, 3, 5, 7, 11};
    float total = 0;
    total = std::accumulate(primes.begin(), primes.end(), 0.0f, [](int upto_this, int a)
                            { return upto_this + a; });

    std::cout << "Average of first 5 primes is : " << total / 5.0 << std::endl;
}
