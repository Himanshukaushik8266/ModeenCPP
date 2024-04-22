#include <iostream>
#include "Functionalities.h"

int main()
{

    FunctionContainer functions;
    ThreadsContainer threads;
    VariantContainer variants;

    CreateObjects(variants);
    CreateFunctionalConatiner(functions);

    CreateThreads(functions, threads, variants);
    JoinThreads(threads);
    // F1(variants);
    // F2(variants);
    return 0;
}