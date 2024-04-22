#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
class Square
{
private:
    /* data */
    int _side;

public:
    Square() = default;
    Square(const Square &) = delete;
    Square(Square &&) = delete;
    Square &operator=(const Square &) = delete;
    Square &operator=(Square &&) = delete;
    ~Square() = default;

    Square(int s) : _side{s} {}

    void Area()
    {
        std::cout << _side * _side << std::endl;
    }

    int side() const { return _side; }
};

#endif // SQUARE_H
