#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.emplace(101, std::make_shared<Teacher>(1, "Himanshu", std::vector<VarType>{std::make_shared<OnlineStudents>(21, "Kinshuk", std::vector<int>{32, 67, 89, 34, 67}, Gender::MALE), std::make_shared<OfflineStudents>(32, "Muskan", std::vector<int>{34, 88, 32, 56, 44}, Gender::FEMALE)}));

    data.emplace(102, std::make_shared<Teacher>(2, "Soujnya", std::vector<VarType>{std::make_shared<OnlineStudents>(6, "Simran", std::vector<int>{32, 67, 89, 34, 67}, Gender::FEMALE), std::make_shared<OfflineStudents>(78, "Anjali", std::vector<int>{34, 88, 32, 56, 44}, Gender::FEMALE)}));

    data.emplace(103, std::make_shared<Teacher>(3, "Tiwari", std::vector<VarType>{std::make_shared<OnlineStudents>(76, "Vikas", std::vector<int>{32, 67, 89, 34, 67}, Gender::MALE), std::make_shared<OfflineStudents>(88, "Rohan", std::vector<int>{34, 88, 32, 56, 44}, Gender::MALE)}));
}

void Display(Container &data)
{
    std::for_each(data.begin(), data.end(), [](const std::pair<int, TeacherPointer> ptr)
                  { std::cout << *(ptr.second) << std::endl; });
}

bool AreAllStudentPass(Container &data)
{
    if(data.empty()){
        throw std::runtime_error("Data is empty!");
    }
    bool flag = true;
    std::for_each(data.begin(), data.end(), [&](const std::pair<int, TeacherPointer> ptr)
                  {
        for(VarType v:ptr.second->students()){
            std::visit([&](auto && val){
                if(!val->Ispass()){
                    flag= false;
                }
            },v);
        } });
    if (!flag)
    {
        return false;
    }
    return true;
}
