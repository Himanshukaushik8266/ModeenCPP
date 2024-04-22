#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <vector>
#include "Major.h"
#include "Minor.h"
#include <iostream>
#include <functional>
#include <memory>

using MajorContainer = std::vector<std::shared_ptr<Major>>;

void CreateObjects(MajorContainer &data)
{
    std::shared_ptr minorData = std::make_shared<Minor>();
    data.push_back(std::make_shared<Major>(*minorData));
    data.push_back(std::make_shared<Major>(*minorData));
    data.push_back(std::make_shared<Major>(*minorData));
    data.push_back(std::make_shared<Major>(*minorData));
    data.push_back(std::make_shared<Major>(*minorData));
}

void FindVal(MajorContainer &data, int input1, int input2)
{
    int i = 1;
    for (std::shared_ptr<Major> m : data)
    {
        if (i % 2 == 0)
        {
            // m->Operations([&](int n1,int n2){m->minor().get().Sum(n1,n2);},input1,input2);     //This is absolute beauty!!
            // m->Operations(&Minor::Sum,input1,input2); //This type missmatch due to the Minor * to the function sum

            m->Operations(std::bind(&Minor::Sum, m->minor().get(), std::placeholders::_1, std::placeholders::_2), input1, input2);

            /*
                We can do it using these two ways either using the lambda function or by using the bind by creating
                a callable object
            */
        }
        else
        {
            m->Operations([&](int n1, int n2)
                          { m->minor().get().Multiply(n1, n2); },
                          input1 + 3, input2 + 7);
        }
        i++;
    }
}

#endif // FUNCTIONALITIES_H
