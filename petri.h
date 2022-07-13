#pragma once
#include "bacteri.cpp"

class petri {
private:
    std::vector<bacteri> list_{};
    int num_colonies{};
    int num_per_colony{};

public:
    petri(int num_per = 100, int num_colonies = 1);
    std::vector<bacteri> list();
    };