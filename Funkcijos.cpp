#include "Funkcijos.h"
#include "libraries.h"





void Studentu_grupes(vector <data>& sze)
{


    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    for (auto& i : sze)
    {
        if (i.vidurkis() >= 5) i.Group = true;
        else i.Group = false;
    }
   
    Rusiuojam_pagal_rezultatus(sze);

    std::ofstream write1("sarasas/kietiakai.txt");
    std::ofstream write2("sarasas/nuskriausti.txt");

    int num = 15;
    int num2 = 20;
    int num3 = 5;

    write1 << left << setfill(' ') << setw(num) << "Pavarde";
    write1 << left << setfill(' ') << setw(num) << "Vardas";
    write1 << left << setfill(' ') << setw(num2) << "vidurkis";
    write1 << left << setfill(' ') << setw(num2) << "mediana" << endl;

    write2 << left << setfill(' ') << setw(num) << "Pavarde";
    write2 << left << setfill(' ') << setw(num) << "Vardas";
    write2 << left << setfill(' ') << setw(num2) << "vidurkis";
    write2 << left << setfill(' ') << setw(num2) << "mediana" << endl;

    const std::string bruksnys(num * 4 + num3 * 5 + 14, '_');
    write1 << bruksnys << endl;
    write2 << bruksnys << endl;


    auto start1 = std::chrono::high_resolution_clock::now();
    auto st1 = start1;

   

    for (auto& i : sze)
    {
        
        if (i.Group == true)
        {


            write1 << left << setfill(' ') << setw(num) << i.name;
            write1 << left << setfill(' ') << setw(num) << i.surn;
            write1 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.vidurkis();
            write1 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.mediana();
            write1 << endl;



        }
   
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Failo isvedimas su  studentais i kietiakus uztruko : " << diff1.count() << " s\n";



    auto start2 = std::chrono::high_resolution_clock::now();
    auto st2 = start2;

    for (auto& i : sze)
    {
       
        if (i.Group == false)
        {


            write2 << left << setfill(' ') << setw(num) << i.name;
            write2 << left << setfill(' ') << setw(num) << i.surn;
            write2 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.vidurkis();
            write2 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.mediana();
            write2 << endl;


        }
   
    }


    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    std::cout << "Failo isvedimas su studentais i nuskriaustus uztruko : " << diff2.count() << " s\n";

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo rusiavimas i dvi grupes uztruko : " << diff.count() << " s\n";

    write1.close();
    write2.close();
}


void Skaitom_faila(vector <data>& sze)
{
    
    std::ifstream read("sarasas/Studentai.txt");

    if (!read)
    {
        cout << "Negalima atidaryti failo!" << endl;
    }

    read.ignore(std::numeric_limits<std::streamsize>::max(), read.widen('\n'));
    read.ignore(std::numeric_limits<std::streamsize>::max(), read.widen('\n'));

    int inputMarks;
    data z;

    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    while (!read.eof())
    {
       

        z.marks.clear();
        read >> z.name;
        read >> z.surn;

        for (int j = 1; j <= 5; j++)
        {
            read >> inputMarks;
            z.marks.push_back(inputMarks);
        }
        read >> z.exam;

        sze.push_back(z);

    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo su studentais nuskaitymas uztruko: " << diff.count() << endl;
    sze.pop_back();
    read.close();
}


void Generuojam_Sarasa()
{
    std::srand(std::time(NULL));
    
    int NR;
    std::cout << "iveskite, kiek studentu noretumete sugeneruoti(1000, 10 000, 100 000, 1 000 000, 10 000 000):" << std::endl;
    std::cin >> NR;

    std::ofstream write("sarasas/studentai.txt");
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    int num = 15; int num2 = 20; int num3 = 5;

    write << left << setfill(' ') << setw(num) << "Pavarde";
    write << left << setfill(' ') << setw(num) << "Vardas";
    write << left << setfill(' ') << setw(num3) << "ND1";
    write << left << setfill(' ') << setw(num3) << "ND2";
    write << left << setfill(' ') << setw(num3) << "ND3";
    write << left << setfill(' ') << setw(num3) << "ND4";
    write << left << setfill(' ') << setw(num3) << "ND5";
    write << left << setfill(' ') << setw(8) << "EGZ" << endl;

    const std::string line(num * 2 + num3 * 5 + 3.5, '_');
    write << line;

    for (int i = 0; i < NR; i++)
    {
        write << endl;
        std::string sk = std::to_string(i + 1);

        std::string vardas = "Vardas" + sk;
        std::string pavarde = "Pavarde" + sk;

        write << left << setfill(' ') << setw(num) << vardas;
        write << left << setfill(' ') << setw(num) << pavarde;

        for (int j = 0; j < 5; j++)
        {
            write << left << setfill(' ') << setw(num3) << rand() % 10 + 1;
        }

        write << std::fixed;
        write << left << setfill(' ') << setw(8) << rand() % 10 + 1;
    }
    write.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo su studentais kurimas uztruko: " << diff.count() << " s\n";
}






