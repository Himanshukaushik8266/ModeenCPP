#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data[std::make_shared<CorporateEmployee>("M-101", "Shreya", 28, Gender::FEMALE, EmployeeType::MANAGER, 55000.0f)] = std::vector<EmployeePointer>{std::make_shared<CorporateEmployee>("E-102", "Himanshu", 20, Gender::MALE, EmployeeType::EMPLOYEE, 27000.0f), std::make_shared<CorporateEmployee>("E-103", "Kinshuk", 21, Gender::MALE, EmployeeType::EMPLOYEE, 20000.0f)};

    data[std::make_shared<CorporateEmployee>("M-104", "Nidhi", 22, Gender::FEMALE, EmployeeType::MANAGER, 45378.0f)] = std::vector<EmployeePointer>{std::make_shared<CorporateEmployee>("E-105", "Ayush", 19, Gender::MALE, EmployeeType::EMPLOYEE, 45322.0f), std::make_shared<CorporateEmployee>("E-106", "Vikash", 22, Gender::MALE, EmployeeType::EMPLOYEE, 36435.0f)};

    data[std::make_shared<GovernmentEmployee>(1, "Mitali", 28, Gender::FEMALE, EmployeeType::MANAGER, 55000.0f)] = std::vector<EmployeePointer>{std::make_shared<GovernmentEmployee>(2, "Mangesh", 20, Gender::MALE, EmployeeType::EMPLOYEE, 27000.0f), std::make_shared<GovernmentEmployee>(3, "RatanKumar", 21, Gender::MALE, EmployeeType::EMPLOYEE, 20000.0f)};

    data[std::make_shared<GovernmentEmployee>(4, "Muskan", 28, Gender::FEMALE, EmployeeType::MANAGER, 55000.0f)] = std::vector<EmployeePointer>{std::make_shared<GovernmentEmployee>(5, "Priyanka", 20, Gender::FEMALE, EmployeeType::EMPLOYEE, 54356.0f), std::make_shared<GovernmentEmployee>(6, "Muskan", 21, Gender::FEMALE, EmployeeType::EMPLOYEE, 643573.0f)};
}

float AverageofEmployeeUnderManager(Container &data, std::string name)
{
    Container::iterator itr = std::find_if(data.begin(), data.end(), [&](const std::pair<EmployeePointer, std::vector<EmployeePointer>> &row)
                                           { return row.first->name() == name; });
    std::vector<EmployeePointer> emp = (*itr).second;

    float total = std::accumulate(emp.begin(), emp.end(), 0.0f, [&](float upto_this_point, const EmployeePointer ptr)
                                  { return upto_this_point + ptr->salary(); });
    return total / float(emp.size());
}

std::string FindManagerUsingEmpid(Container &data, std::variant<std::string, int> id)
{
    std::string ans;
    if (id.index() == 0)
    {
        for (auto [k, v] : data)
        {
            for (EmployeePointer ptr : v)
            {
                if (std::dynamic_pointer_cast<CorporateEmployee>(ptr))
                {
                    CorporateEmployeePointer pt = std::dynamic_pointer_cast<CorporateEmployee>(ptr);
                    if (pt->id() == std::get<0>(id))
                    {
                        ans = k->name();
                        break;
                    }
                }
            }
        }
    }
    else if (id.index() == 1)
    {
        for (auto [k, v] : data)
        {
            for (EmployeePointer ptr : v)
            {
                if (std::dynamic_pointer_cast<GovernmentEmployee>(ptr))
                {
                    GovernmentEmployeePointer pt = std::dynamic_pointer_cast<GovernmentEmployee>(ptr);
                    if (pt->id() == std::get<1>(id))
                    {
                        ans = k->name();
                        break;
                    }
                }
            }
        }
    }
    return ans;
}
void DisplayObjects(Container &data)
{
    for (auto [k, v] : data)
    {
        if (std::dynamic_pointer_cast<CorporateEmployee>(k))
        {
            CorporateEmployeePointer ptr = std::dynamic_pointer_cast<CorporateEmployee>(k);
            std::cout << "The first manager name is " << ptr->name() << std::endl;
            std::cout << "Employees under this Manager are : \n";
            std::vector<EmployeePointer> hisEmployees = v;
            for (std::shared_ptr<Employee> pt : hisEmployees)
            {
                CorporateEmployeePointer ptr = std::dynamic_pointer_cast<CorporateEmployee>(pt);
                std::cout << *ptr << std::endl;
            }
        }
        else if (std::dynamic_pointer_cast<GovernmentEmployee>(k))
        {
            GovernmentEmployeePointer ptr = std::dynamic_pointer_cast<GovernmentEmployee>(k);;
            std::cout << "The first manager name is " << ptr->name() << std::endl;
            std::cout << "Employees under this Manager are : \n";
            std::vector<EmployeePointer> hisEmployees = v;
            for (std::shared_ptr<Employee> pt : hisEmployees)
            {
                GovernmentEmployeePointer ptr = std::dynamic_pointer_cast<GovernmentEmployee>(pt);
                std::cout << *ptr << std::endl;
            }
        }
    }
}

