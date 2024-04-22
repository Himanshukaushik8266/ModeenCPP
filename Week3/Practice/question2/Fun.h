#ifndef FUN_H
#define FUN_H

#include "Developer.h"
#include "Tester.h"
#include<vector>
#include<variant>
#include<optional>
#include<memory>

using DevPtr = std::shared_ptr<Developer>;
using TestPtr = std::shared_ptr<Tester>;
using Container = std::vector<std::variant<DevPtr, TestPtr>>;

void CreateObjects(Container& data);
std::optional<Container> InstancesAbove5(Container& data);
std::optional<float> CalAverageSal(Container& data);
#endif // FUN_H
