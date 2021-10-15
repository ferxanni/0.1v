#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include "output.h"
#include "mediana.h"

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

