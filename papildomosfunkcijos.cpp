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

unsigned int wordsinstring(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}


int randomMark()
{
    srand(time(0));


    for (int i = 0; i < 10; i++)
        return (rand() % 10) + 1;
}

void auto_ivedimas(data sze[], int i, int n)
{
    sze[i].exam = randomMark();
    for (int x = 0; x < n; x++)
    {
        sze[i].marks.push_back(randomMark());
    }
    sze[i].Total = sze[i].Total / n;
    sze[i].Total = sze[i].Total * 0.4 + 0.6 * sze[i].exam;
}