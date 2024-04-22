#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
class Triangle
{
private:
    /* data */
    float _base;
    float _height;

public:
    Triangle() = default;
    Triangle(const Triangle &) = delete;
    Triangle(Triangle &&) = delete;
    Triangle &operator=(const Triangle &) = delete;
    Triangle &operator=(Triangle &&) = delete;
    ~Triangle() = default;

    Triangle(float ba, float he) : _base{ba}, _height{he} {}

    void Area()
    {
        std::cout << 0.5f * _base * _height << std::endl;
    }

    float base() const { return _base; }

    float height() const { return _height; }
};

#endif // TRIANGLE_H
