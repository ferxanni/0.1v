
#include "funkcijos.h"





double mediana(std::vector<int> pazymiai) {
    int size = pazymiai.size();
    double tmedian;
    if (size % 2 == 0) {
        tmedian = (pazymiai[pazymiai.size() / 2 - 1] + pazymiai[pazymiai.size() / 2]) / 2;
    std::cout << " " << tmedian << '\n';
    }

    else
        tmedian = pazymiai[pazymiai.size() / 2];
    std::cout << " " << tmedian << '\n';
    return (tmedian);
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