#include "Engine.h"

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "_horsepower: " << rhs._horsepower
       << " _torque: " << rhs._torque;
    return os;
}

Engine::Engine(int horsepower, float torque)
:   _horsepower{horsepower},_torque{torque}{}
