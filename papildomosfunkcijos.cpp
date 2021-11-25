#include "Funkcijos.h"
#include "libraries.h"



bool Lyginam_pagal_varda(const data& a, const data& b)
{
    return a.name < b.name;
}

bool Lyginam_pagal_rezultatus(const data& a, const data& b)
{
    return a.vidurkis() > b.vidurkis();
}

void Rusiuojam_pagal_rezultatus(vector <data>& sze)
{
    std::sort(sze.begin(), sze.end(), Lyginam_pagal_rezultatus);
}

bool skirstom(const data& a)
{
    return (a.vidurkis() >= 5);
}

int GetLongestString(list <data>& sze)
{
    int ln = 0, max = 0;
    for (auto& i : sze)
    {
        ln = i.name.size();
        if (ln > max) max = ln;
    }
    for (auto& i : sze)
    {
        ln = i.surn.size();
        if (ln > max) max = ln;
    }
    return max;
}
