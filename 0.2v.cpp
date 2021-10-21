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

unsigned int wordsinstring(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void input(std::vector<data>& sze, int* sk)
{
    int counter = 0;
    int temp;
    std::ifstream fin;
    std::string buffas;
    fin.open("studentai100.txt");
    if (fin.is_open())
    {
        getline(fin >> std::ws, buffas);
        *sk = wordsinstring(buffas) - 3;
        while (true)
        {

            sze.resize(sze.size() + 1);
            fin >> sze.at(counter).name;
            if (fin.eof()) { sze.pop_back(); break; }
            fin >> sze.at(counter).surn;
            for (int i = 0; i < *sk; i++)
            {
                fin >> temp;
                sze.at(counter).marks.push_back(temp);
            }
            fin >> sze.at(counter).exam;
            //std::cout << Eil.at(student_counter).Vard;
            sze.at(counter).Total = sze.at(counter).Total / *sk;
            sze.at(counter).Total = sze.at(counter).Total * 0.4 + 0.6 * sze.at(counter).exam;
            counter++;
        }
    }
    else { std::cout << "-\n"; }
}


void output(std::vector<data> sze, int sk) {

    std::string linija = "+-------------------+-------------------+-----------+--------+";
    std::string komentaras = "Studentu duomenis su isvestu vidurkiu bei mediana";
    std::ofstream fout;
    fout.open("kursiokai.txt");
    fout << komentaras << std::endl;
    fout << linija << std::endl;
    fout << "| Vardas            | Pavarde           | Vidurkis  | Mediana|" << std::endl;
    fout << linija << std::endl;
    for (int i = 0; i < sze.size(); i++)
    {
        fout << "| " << std::setw(17) << std::left << sze[i].name
            << " | " << std::setw(17) << std::left << sze[i].surn
            << " | " << std::setw(9) << sze[i].Total
            << " | " << std::setw(6) << mediana(sze[i].marks)
            << " |" << std::endl;
    }
    fout << linija << std::endl;
    fout << "\n\n";
}


int main()
{
    int sk;
    char temp;
    std::vector<data> sze;
    input(sze, &sk);
    output(sze, sk);
    system("start kursiokai.txt");
    return 0;
}
