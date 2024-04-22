#ifndef CAR_H
#define CAR_H

#include <iostream>
class Car
{
private:
    std::string _car_name;
    int _wheels;
public:
    Car()=default;
    Car(const Car &)=delete;
    Car(Car && )=delete;
    Car & operator=(const Car & )=delete;
    Car &operator=(Car &&)=delete;
    ~Car()=default;
    Car(std::string bike_type, int wheels);

    std::string carName() const { return _car_name; }
    void setCarName(const std::string &car_name) { _car_name = car_name; }

    int wheels() const { return _wheels; }
    void setWheels(int wheels) { _wheels = wheels; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
