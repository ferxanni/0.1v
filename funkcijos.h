#pragma once
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>





struct data {
    std::string name;
    std::string surn;
    std::vector<int> marks = { 0 };
    int exam;
    double Total=0;



   
};


double mediana(std::vector<int> pazymiai);
unsigned int wordsinstring(std::string const& str);
int randomMark();
void auto_ivedimas(data sze[], int i, int n);