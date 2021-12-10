#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H
#include "libraries.h"

struct data
{
    std::string name;
    std::string surn;
    int exam;
    vector <int> marks;
    bool CorrectData = true;
    bool Group;
    double Total = 0;
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


void  Skaitom_faila1(vector <data>& szee);
void  Skaitom_faila2(list <data>& sze);
bool skirstom(const data& a);
void Rusiuojam_pagal_rezultatus(vector <data>& sze);
void Generuojam_Sarasa();
int GetLongestString(vector <data>& sze);
void Studentu_grupes1_list(list <data>& sze);
void Studentu_grupes2_list(list <data>& sze);
void Studentu_grupes1(vector <data>& szee);
void Studentu_grupes2(vector <data>& szee);
unsigned int wordsinstring(std::string const& str);
int randomMark();
void auto_ivedimas(data sze[], int i, int n);
void input(std::vector<data>& sze, int* sk);
void output(std::vector<data> sze, int sk);
void ranka_ivedimas(data sze[], int i);
void stud_info(data sze[], int i);
void isprintinam_data(data sze[], int studentu_sk);
void ivedimas();


#endif
