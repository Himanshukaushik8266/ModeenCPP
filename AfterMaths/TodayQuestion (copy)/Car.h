#ifndef CAR_H
#define CAR_H
#include<iostream>
class Car
{
private:
    /* data */
    int _seatcount;
    std::string _model;
    float _price;
 
public:
    Car()=default;
    Car(const Car &)=delete;
    Car(Car && )=default;
    Car & operator=(const Car & )=delete;
    Car &operator=(Car &&)=default;
    ~Car()=default;

    Car(int seat, std::string model, float price);

    int seatcount() const { return _seatcount; }

    std::string model() const { return _model; }

    float price() const { return _price; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    
};

#endif // CAR_H