#include "Fun.h"
#include "EmptyContainerException.h"
#include<iostream>
#include<optional>

void CreateObjects(Container &data)
{
    data.push_back(std::make_shared<Developer>("12", "Kshitij", 1550.0f, 13, Skills::CODING));
    data.push_back(std::make_shared<Developer>("13", "Prateek", 1550.0f, 13, Skills::CODE_REVIEW));
    data.push_back(std::make_shared<Developer>("14", "Abhijeet", 1900.0f, 10, Skills::CODING));
    data.push_back(std::make_shared<Tester>("12", "Harshit", 1300.0f, 43, Skills::INTEGRATION_TESTING));
    data.push_back(std::make_shared<Tester>("12", "Kinshuk", 2500.0f, 353, Skills::UNIT_TESTTING));
    data.push_back(std::make_shared<Tester>("12", "amalalala", 1000.0f, 4245, Skills::UNIT_TESTTING));
}

std::optional<Container> InstancesAbove5(Container &data)
{
    Container c;
    if(!data.empty()){
        for(std::variant<DevPtr,TestPtr> v : data){
            std::visit([&](auto&& val){if(val->experienceYears() < 5){
                c.push_back(val);
            }},
            v);
        }
    }else{
        throw EmptyContainerException("Container is empty");
    }
    
    if(c.empty() ){
        return std::nullopt;
    }
    return (c);
}

std::optional<float> CalAverageSal(Container &data)
{
    float averagesal = 0.0f;
    if (!data.empty()) {
        for (std::variant<DevPtr, TestPtr> v : data) {
            std::visit([&](auto&& val) { averagesal += val->salary(); }, v);
        }
        std::cout << "Total Salary: " << averagesal << "\n";
    }
    if((averagesal / data.size())==0 ){
        return std::nullopt;
    }
    return averagesal/data.size();
}
