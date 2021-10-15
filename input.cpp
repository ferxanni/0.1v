#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include "input.h"
#include "wordsinstring.h"

void input(std::vector<data>& sze, int* n)
{
    int k = 0;
    int temp;
    std::ifstream fin;
    std::string buffas;
    fin.open("studentai.txt");
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
            //std::cout << Eil.at(student_counter).Vard;
            sze.at(k).Total = sze.at(k).Total / *n;
            sze.at(k).Total = 0.6 * sze.at(k).exam + sze.at(k).Total * 0.4;
            k++;
        }
    }
    else { std::cout << "-\n"; }
}