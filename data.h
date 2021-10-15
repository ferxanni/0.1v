#pragma once
#include <string>
#include <vector>

struct data {
    std::string name;
    std::string surn;
    std::vector<int> marks = { 0 };
    int exam;
    float Total = 0;
};