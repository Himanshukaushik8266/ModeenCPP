
#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <memory>
#include <array>
#include <iostream>
#include <functional>
#include <algorithm>
#include <numeric>
#include <condition_variable>
#include <mutex>
class Datahandler
{
private:
    /* data */
    std::array<int, 5> _data;
    std::array<int, 5> _sqaure_result;
    std::array<int, 5> _factorial_result;
    std::mutex mt;
    static std::unique_ptr<Datahandler> _object;
    std::condition_variable cv;
    bool checker = false;
    Datahandler() = default;

public:
    Datahandler(const Datahandler &) = delete;
    Datahandler(Datahandler &&) = delete;
    Datahandler &operator=(const Datahandler &) = default;
    Datahandler &operator=(Datahandler &&) = delete;
    ~Datahandler() = default;

    static std::unique_ptr<Datahandler> &getInstance();
    void TakeInput();
    void ComputeSqaure();
    void ComputeFactorial();
    void AverageValue();

    std::array<int, 5> sqaureResult() const { return _sqaure_result; }
};

#endif // DATAHANDLER_H
