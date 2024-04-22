#ifndef CAR_H
#define CAR_H
#include<iostream>
class Car
{
private:
    std::string _name   {""};
    int _acceleration{0};
    int _topSpeed{0};
    float _exShowroomPrice{0.0f};
public:
    //default constructor enable
    Car()=default;
    Car (const Car &) =delete;                  //(delete -> disabled copy constructor )
    Car(Car &&)=delete;                         //brand new
    Car &operator=(const Car&)=delete;          //deleted copy assignment
    Car &operator=(Car&&)=delete;               //brand new(deleted move assignement )
    virtual ~Car()=default;


    Car(std::string name,int acceleration,int top_speed,float price);

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int acceleration() const { return _acceleration; }
    void setAcceleration(int acceleration) { _acceleration = acceleration; }

    int topSpeed() const { return _topSpeed; }
    void setTopSpeed(int topSpeed) { _topSpeed = topSpeed; }

    float exShowroomPrice() const { return _exShowroomPrice; }
    void setExShowroomPrice(float exShowroomPrice) { _exShowroomPrice = exShowroomPrice; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    virtual float drive()=0;
};


#endif // CAR_H
