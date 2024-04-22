#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "ICECar.h"
#include "EVCar.h"
#include<unordered_set>
#include<algorithm>
#include<numeric>
#include "EmptyContainerException.h"
#include "NullPointerException.h"
#include <variant>
#include <vector>
#include <memory>

using ICECarPointer = std::shared_ptr<ICECar>;
using EVCarPointer = std::shared_ptr<EVCar>;
using VariantType = std::variant<ICECarPointer, EVCarPointer>;
using Container = std::vector<VariantType>;

void CreateObjects(Container &data);
Container InstancesWithPriceBelow600000(Container &data);
float AveragePriceOFEVCar(Container &data);
int CountEVCarMatchingEngineType(Container &data,EPowerType type);
std::string BrandNameWithMatchingID(Container &data ,std::string id);
std::unordered_set<BatteryType> UniqueBatteryTypes(Container &data);
bool AtLeastOneAbove600000(Container &data);



#endif // FUNCTIONALITIES_H
