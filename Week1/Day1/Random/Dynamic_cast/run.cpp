#include <iostream>
#include <vector>
 
using namespace std;
 
class Shape {
public:
    virtual void area() {
        cout << "Shape area" << endl;
    }
    virtual ~Shape() {}
};
 
class Square : public Shape {
public:
    int _side;
    void area() override {
        std::cout << "Square area" << std::endl;
    }
    Square(int side) : _side{side} {}
    void print() {
        cout << "Side is : " << this->_side<<endl;
    }
    ~Square() {}
};
 
class Triangle : public Shape {
public:
    int _height, _base;
    void area() override {
        std::cout << "Triangle area" << std::endl;
    }
    Triangle(int height, int base) : _height{height}, _base{base} {}
    void print() {
        cout << "Height is : " << this->_height << " base is : " << this->_base << endl;
    }
    ~Triangle() {}
};
 
int main() {
 
    vector<Shape*> data;
 /*******************************************************************************************************************/
    // Square s(80);
    // Triangle t(78,67);
/*******************************************************************************************************************/
    for (int i = 0; i < 2; i++) {
        int enter;
        cout << "Enter 1 for Square and 2 for Triangle: ";
        cin >> enter;
        if (enter == 1) {
            int side;
            cout << "Enter Side of square: ";
            cin >> side;
            data.push_back(new Square(side));
        }
        else {
            int height, base;
            cout << "Enter height and base: ";
            cin >> height >> base;
            data.push_back(new Triangle(height, base));
        }
    }
 /*******************************************************************************************************************/
    // for (int i = 0; i < 2; i++) {
    //     if(i==0){
    //         data.push_back(&s);
    //     }
    //     else{
    //         data.push_back(&t);
    //     }
 
    // }
 /*******************************************************************************************************************/
 
    for (Shape* shape : data) {
        if(typeid(*shape)==typeid(Square)){
            Square * s=dynamic_cast<Square *>(shape);
            // cout<<typeid(s).name()<<endl;
            s->print();
            s->area();
        }
        else if(typeid(*shape)==typeid(Triangle)){
            Triangle * t=dynamic_cast<Triangle *>(shape);
            // cout<<typeid(t).name()<<endl;
            t->print();
            t->area();
        }
    }
 /*******************************************************************************************************************/
    // cout<<typeid(data[0]).name()<<endl;
    // cout<<typeid(data[1]).name()<<endl;
 /*******************************************************************************************************************/
    // for (auto it :data ) {
    //     if(typeid(*it)==typeid(Square)){
    //         Square * s=dynamic_cast<Square *>(it);
    //         s->print();
    //         s->area();
    //     }
    //     else if(typeid(*it)==typeid(Triangle)){
    //         Triangle * t=dynamic_cast<Triangle *>(it);
    //         t->print();
    //         t->area();
    //     }
    
    // }
    // for (Shape* shape : data) {
    //     cout<<typeid(shape).name()<<endl;;
    // }
 
 /*******************************************************************************************************************/
    // Clean up allocated memory
    for (Shape* shape : data) {
        delete shape;
    }
 /*******************************************************************************************************************/
 
    return 0;
}