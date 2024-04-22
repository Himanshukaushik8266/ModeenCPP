#include "Functionalities.h"
#include <algorithm>
#include <numeric>

void CreateObjects(MContainer &data)
{

    data.emplace(1, std::make_shared<Device>("D-1983", "Lg-1087", 35000.0f, 1.8f, DeviceType::WORKSTATION, std::make_shared<License>(101, LicenseType::OWNED), std::make_shared<Owner>("Himanshu")));
    data.emplace(2, std::make_shared<Device>("D-3455", "Note20 Ultra", 105000.0f, 1.8f, DeviceType::MOBILE, std::make_shared<License>(102, LicenseType::OWNED), std::make_shared<Owner>("Vatan")));
    data.emplace(3, std::make_shared<Device>("D-7644", "Pixel 7 pro", 85000.0f, 2.8f, DeviceType::MOBILE, std::make_shared<License>(103, LicenseType::RENTED), std::make_shared<Owner>("Navidha")));
    data.emplace(4, std::make_shared<Device>("D-5435", "Oneplus Buds Nord", 2500.0f, 3.7f, DeviceType::ACCESSORY, std::make_shared<License>(104, LicenseType::OWNED), std::make_shared<Owner>("Priyanshu")));
}
/*Finding Discount price for all items */

void FindDiscountPrice(MContainer &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Conatiner is Empty!");
    }
    std::cout << "Discounted prices are  : " << std::endl;
    std::for_each(data.begin(), data.end(), [](const std::pair<int, DevicePointer> &d)
                  {
                      if (d.second)
                      {
                          if (d.second->type() == DeviceType::MOBILE || d.second->type() == DeviceType::WORKSTATION)
                          {
                              std::cout << d.first << " : " << (2 * d.second->price()) / 100 << std::endl;
                          }
                          else if (d.second->type() == DeviceType::ACCESSORY)
                          {
                              std::cout << d.first << " : " << (5 * d.second->price()) / 100 << std::endl;
                          }
                      }
                      else
                      {
                          throw NullPointerException("Null Pointer Encountered");
                      }
                  });
}
/* Finding all the taxable items */

int FindTaxAmount(MContainer &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Conatiner is Empty!");
    }

    int taxableItem = std::count_if(data.begin(), data.end(), [](const std::pair<int, DevicePointer> &row)
                                    { return row.second->sarValue() >= 1.0f && row.second->sarValue() <= 1.5f && row.second->license()->licenseType() == LicenseType::OWNED || row.second->license()->licenseType() == LicenseType::OWNED && row.second->sarValue() >= 1.5f && row.second->sarValue() <= 2.0f; });

    return taxableItem;
}
/* Check Whether they have same licence type */

bool CheckAllSameLicense(MContainer &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Conatiner is Empty!");
    }
    LicenseType checker = (*data.begin()).second->license()->licenseType();

    return std::all_of(data.begin(), data.end(), [&](const std::pair<int, DevicePointer> &row)
                       { return row.second->license()->licenseType() == checker; });
}
/*  Displaying all items  */

void DisplayObjects(MContainer &data)
{
    if (data.empty())
    {
        throw EmptyContainerException("Conatiner is Empty!");
    }

    std::for_each(data.begin(), data.end(), [](const std::pair<int, DevicePointer> &p)
                  {
        if(p.second) std::cout<<"Key: "<<p.first<<" Values: "<<*p.second<<std::endl;
        else throw NullPointerException("Null pointer exception"); });
}