#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Teacher.h"
#include <unordered_map>
#include <algorithm>
#include <numeric>

using TeacherPointer = std::shared_ptr<Teacher>;
using Container = std::unordered_map<int, TeacherPointer>;

void CreateObjects(Container &data);
void Display(Container &data);
bool AreAllStudentPass(Container &data);

#endif // FUNCTIONALITIES_H
