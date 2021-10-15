#include <iostream>
#include "mediana.h"

using namespace std;

float mediana(std::vector<int> pazymiai) {
    int size = pazymiai.size();
    int tmedian;
    if (size % 2 == 0) {
        tmedian = (pazymiai[pazymiai.size() / 2 - 1] + pazymiai[pazymiai.size() / 2]) / 2;
    std::cout << " " << tmedian << '\n';
    }

    else
        tmedian = pazymiai[pazymiai.size() / 2];
    std::cout << " " << tmedian << '\n';
    return (tmedian);
}