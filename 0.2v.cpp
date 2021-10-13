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
    float Total = 0;
};


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

void output(std::vector<data> sze, int n)
{
    std::string failas;
    std::string komentaras;
    std::ofstream fout;
    fout.open(failas);

    fout.open("kursiokai.txt");



    //string linija(51, '-');
    std::string linija = "+-------------------+-------------------+-----------+--------+";

    fout << komentaras << std::endl;
    fout << linija << std::endl;
    fout << "| Vardas            | Pavarde           | Vidurkis  | Mediana|" << std::endl;
    fout << linija << std::endl;
    for (int i = 0; i < n; i++)
    {
        fout << "| " << std::setw(17) << std::left << sze[i].name
            << " | " << std::setw(17) << std::left << sze[i].surn
            << " | " << std::setw(9) << sze[i].Total
            << " | " << std::setw(6) << mediana(sze[i].marks)
            << " |" << std::endl;
    }
    fout << linija << std::endl;

    fout.close();
}

unsigned int wordsinstring(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void input(std::vector<data>& sze, int* n)
{
    int k = 0;
    int temp;
    std::ifstream fin;
    std::string buffas;
    fin.open("studentai10000.txt");
    if (fin.is_open())
    {
        getline(fin >> std::ws, buffas);
        *n = wordsinstring(buffas) - 3;
        while (true)
        {

            sze.resize(sze.size() + 1);
            fin >> sze.at(k).name;
            if (fin.eof()) { sze.pop_back(); break; }
            fin >> sze.at(k).surn;
            for (int i = 0; i < *n; i++)
            {
                fin >> temp;
                sze.at(k).marks.push_back(temp);
            }
            fin >> sze.at(k).exam;
            
            sze.at(k).Total = sze.at(k).Total / *n;
            sze.at(k).Total = 0.6 * sze.at(k).exam + sze.at(k).Total * 0.4;
            k++;
        }
    }
    else { std::cout << "-\n"; }
}

int main()
{
    int n;
    char temp;
    std::vector<data> sze;
    input(sze, &n);
    output(sze, n);
    system("start kursiokai.txt");
    return 0;
}
