/*
    Functional Programming
        - map : applying a logic (function) on all items in data collection (one by one)
        - filter : extracting items that satisfy a condition from the data collection
        - reduce : collecting/summarizing/gathering/converting multiple items into a single item
                    based on a binary operation

        e.g. 10,20,30,40,65
            -reduce 5 numbers into 1 number by summation aggregation
            -reduce 5 numbers into 1 by product aggregation
*/

#include "Employee.h"
#include "Functionalities.h"
#include <algorithm>
#include <numeric>

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateEmployees(data1);
    CreateEmployeesPointer(data2);
    CreateEmployeesSmartPointer(data3);
    /*
        rule 1 : default operation is binary +
    */
    float totalSalary=std::accumulate(data1.begin(), data1.end(), 0.0f, [](float answer_upto_current_point, const Employee &emp)
                                   { return answer_upto_current_point + emp.salary(); });

    std::cout << totalSalary << std::endl;
}


/*
    ["Satyam" | 80000 | "Trainee" | 10]
    ["Ayush" | 88000 | "IT" | 10]
    ["Himanshu" | 80000 | "HR" | 10]
    ["Ksritij" | 80000 | "CEO" | 10]
 
 
    AUCV - answer upto current value
 
    init/AUCV
    0.0f        80000           88000       80000           70000  
    |           |               |           |               |
    |           |               |           |               |
    -------------               |           |               |
        |                       |           |               |
        |                       |           |               |
        80000 [AUCV]            |           |               |
        |                       |           |               |
        |                       |           |               |
        -------------------------           |               |
                    |                       |               |
                    |                       |               |
                    168000                  80000           |
                    |                       |               |
                    -------------------------               |
                                |                           |
                                248000                      |
                                |                           |
                                -----------------------------
                                                |
                                                |
                                                318000

*/