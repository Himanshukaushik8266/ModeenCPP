#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"
#include "Car.h"
#include <algorithm>
#include <numeric>
#include <future>

void CreateObjects(Container &data)
{

    data.emplace("c101", std::make_shared<Car>("c101", 800000.0f, "Dzire", std::make_shared<Engine>(300, 110.0f), CarType::SEDAN));
    data.emplace("c102", std::make_shared<Car>("c102", 1779000.0f, "Nexon", std::make_shared<Engine>(300, 34500.0f), CarType::SEDAN));
    data.emplace("c103", std::make_shared<Car>("c103", 7579000.0f, "Creta", std::make_shared<Engine>(9800, 7890.0f), CarType::SUV));
}

int TotalHorsepower(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException(std::future_errc::no_state, "Data is Empty");
    }
    int total = std::accumulate(data.begin(), data.end(), 0, [](float answer_upto_current_point, const std::pair<std::string, CarPointer> &row)
                                { return answer_upto_current_point + row.second->engine()->horsepower(); });
    return total;
}

bool IsContainerAllCarAbover7l(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException(std::future_errc::no_state, "Data is Empty");
    }
    return std::all_of(data.begin(), data.end(), [](const std::pair<std::string, CarPointer> &row)
                       { return row.second->price() > 700000.0f; });
}
EnginePointer EnginePointerToMinPriceCar(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException(std::future_errc::broken_promise, "Data is Empty");
    }
    // asssume the first data value as your min
    auto itr = std::min_element(
        data.begin(),
        data.end(),
        [](const std::pair<std::string, CarPointer> &row1, const std::pair<std::string, CarPointer> &row2)
        {
            return row1.second->price() < row2.second->price();
        });

    return (*itr).second->engine(); // agar Engine* hoga return type then return (*itr).second->engine().get();
}

float AverageEngineTorque(const Container &data)
{
    if (data.empty())
    {
        throw EmptyContainerException(std::future_errc::broken_promise, "Data is Empty");
    }
    int total = 0;
    int count = 0;
    total = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float answer_upto_current_pointer, const std::pair<std::string, CarPointer> &row)
        {
            if (row.second->engine())
            {
                count++;
                return answer_upto_current_pointer + row.second->engine()->torque();
            }
            else
            {
                return answer_upto_current_pointer;
            }
        });
    return total / count;
}

std::string FindCarModelByID(const Container &data, std::string carId)
{
    if (data.empty())
    {
        throw EmptyContainerException(std::future_errc::no_state, "Data is Empty");
    }

    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](const std::pair<std::string, CarPointer> &row)
        {
            return row.first.compare(carId) == 0;
        });
    if (itr == data.end())
    {
        throw IdNotFoundException("Id not Found for this Car ID!!");
    }
    return (*itr).second->model();
}
