#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "libraries.h"

struct data
{
    std::string name;
    std::string surn;
    int exam;
    vector <int> marks;
    bool CorrectData = true;
    double Vidurkis;
    double Mediana;

    double vidurkis() const
    {
        double s = 0;
        for (int i = 0; i < marks.size(); i++)
        {
            s = s + marks[i];
        }
        double avr = s / marks.size();
        return 0.4 * avr + 0.6 * exam;
    }

    double mediana()
    {

        std::sort(marks.begin(), marks.end());  //sorting an array in ascending order

        double s = 0;
        if (marks.size() % 2 == 0)
        {
            s = (double)((marks[marks.size() / 2] + marks[marks.size() / 2]) / 2);
        }
        else
        {
            s = (double)marks[marks.size() / 2];
        }
        return 0.4 * s + 0.6 * exam;
    }

};

bool Lyginam_pagal_rezultatus(const data& a, const data& b);
bool Lyginam_pagal_varda(const data& a, const data& b);
//void Sort_by_FirstName(list <student> &A);
//void Sort_by_Results(list <student> &A);

void  Skaitom_faila(vector <data>& sze);
bool skirstom(const data& a);
void Rusiuojam_pagal_rezultatus(vector <data>& sze);
void Generuojam_Sarasa();
int GetLongestString(vector <data>& sze);
void Studentu_grupes(vector <data>& sze);



#endif
