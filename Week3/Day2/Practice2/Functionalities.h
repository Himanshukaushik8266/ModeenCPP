#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <iostream>
#include <variant>
#include <vector>
#include "Square.h"
#include "Triangle.h"
using VType = std::variant<Square *, Triangle *>;
using Container = std::vector<VType>;

void CreateObjects(Container &data)
{
    data.push_back(new Square(12));
    data.push_back(new Triangle(17.8f, 20.0f));
    data.push_back(new Triangle(23.8f, 20.0f));
    data.push_back(new Square(56));
    data.push_back(new Triangle(56.8f, 20.0f));
    data.push_back(new Triangle(75.8f, 20.0f));
    data.push_back(new Square(7));
    data.push_back(new Square(9));
}

void CommonFunction(Container &data)
{
    for (VType v : data)
    {
        std::visit([](auto &&val)
                   { val->Area(); },
                   v);
    }
}

void NotSoCommonFunction(Container &data)
{
    for (VType v : data)
    {
        if (std::holds_alternative<Square *>(v))
        {
            std::cout << "Square Found!" << std::endl;
            Square *temp = std::get<0>(v);
            std::cout << "Side of Square is : " << temp->side() << std::endl;
        }
        else if (std::holds_alternative<Triangle *>(v))
        {
            std::cout << "Triangle Found!" << std::endl;
            Triangle *temp = std::get<1>(v);
            std::cout << "Base of Triangle is : " << temp->base() << " Height of Triangle is : " << temp->height() << std::endl;
        }
    }
}

void DeleteObjects(Container &data)
{
    for (VType v : data)
    {
        std::visit([](auto &&val)
                   { delete val; },
                   v);
    }
}

#endif // FUNCTIONALITIES_H
