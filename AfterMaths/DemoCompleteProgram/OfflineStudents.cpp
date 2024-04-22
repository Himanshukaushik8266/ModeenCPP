#include "OfflineStudents.h"

OfflineStudents::OfflineStudents(int studId, std::string name, std::vector<int> marks, Gender gender)
    : _studId{studId}, _name{name}, _marks{marks}, _gender{gender}
{
}

bool OfflineStudents::Ispass()
{
    float total{0};
    for(int i :_marks){
        total+=i;
    }

    float percentage=(total/5);

    if(percentage >55){
        return true;
    }
    return false;
}
std::ostream &operator<<(std::ostream &os, const OfflineStudents &rhs)
{
    os << "_studId: " << rhs._studId
       << " _name: " << rhs._name
       << " Marks are : ";
    for (int a : rhs._marks)
    {
        std::cout << a << " ";
    }

    std::string val = "";

    if (rhs._gender == Gender::MALE)
    {
        val = "Male";
    }
    else
    {
        val = "Female";
    }
    os << " _gender: " << val;
    return os;
}
