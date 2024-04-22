#ifndef TRAININGBATCH_H
#define TRAININGBATCH_H
#include "Id.h"
#include "Employee.h"
class TrainingBatch
{
private:
    /* data */
    Id _id;
    int _strength;
    Employee _trainer;
    Employee _pmtCoordinator;

public:
    TrainingBatch(/* args */) {}
    ~TrainingBatch() {}
};

#endif // TRAININGBATCH_H
