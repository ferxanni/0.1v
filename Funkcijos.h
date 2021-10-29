#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "libraries.h"

struct data
{
    std::string name;
    std::string surn;
    int exam;
    vector <int> marks;
    double Total = 0;
    bool CorrectData = true;
    bool Group;


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

        std::sort(marks.begin(), marks.end());

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





void Rusiuojam_pagal_varda(vector <data>& sze);
void Rusiuojam_pagal_rezultatus(vector <data>& sze);
void Studentu_grupes(vector <data>& sze);
void Skaitom_faila(vector <data>& sze);
void Generuojam_Sarasa();
int GetLongestString(vector <data>& sze);

#endif
