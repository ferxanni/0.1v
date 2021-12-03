#include "Funkcijos.h"
#include "libraries.h"

void Studentu_grupes1_list(list <data>& sze)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    list<data> nuskriausti;
    list <data> kietiakai;

    for (auto& l : sze)
    {
        if (l.vidurkis() >= 5) kietiakai.push_back(l);
        else if (l.vidurkis() < 5) nuskriausti.push_back(l);
    }

    nuskriausti.sort(Lyginam_pagal_rezultatus);
    kietiakai.sort(Lyginam_pagal_rezultatus);

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

    for (auto& u : kietiakai)
    {
        write1 << left << setfill(' ') << setw(num) << u.name;
        write1 << left << setfill(' ') << setw(num) << u.surn;
        write1 << left << setfill(' ') << setw(num2) << std::setprecision(2) << u.vidurkis();
        write1 << left << setfill(' ') << setw(num2) << std::setprecision(2) << u.mediana();
        write1 << endl;
    }


    for (auto& i : nuskriausti)
    {
        write2 << left << setfill(' ') << setw(num) << i.name;
        write2 << left << setfill(' ') << setw(num) << i.surn;
        write2 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.vidurkis();
        write2 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.mediana();
        write2 << endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo rusiavimas ir isvedimas i dvi grupes su (list) uztruko : " << diff.count() << " s\n";



    write1.close();
    write2.close();

    kietiakai.clear();
    nuskriausti.clear();

}


void Studentu_grupes2_list(list <data>& sze)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    sze.sort(Lyginam_pagal_rezultatus);

    list <data>::iterator it = std::stable_partition(sze.begin(), sze.end(), skirstom);
    list <data> nuskriausti(it, sze.end());
    sze.erase(it, sze.end());

    std::ofstream write1("sarasas/studentai.txt");
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
    write2 << left << setfill(' ') << setw(num2) << "Galutinis (Vid.)";
    write2 << left << setfill(' ') << setw(num2) << "Galutinis (Med.)" << endl;

    const std::string bruksnys(num * 4 + num3 * 5 + 14, '_');
    write1 << bruksnys << endl;
    write2 << bruksnys << endl;

    for (auto& u : sze)
    {
        write1 << left << setfill(' ') << setw(num) << u.name;
        write1 << left << setfill(' ') << setw(num) << u.surn;
        write1 << left << setfill(' ') << setw(num2) << std::setprecision(2) << u.vidurkis();
        write1 << left << setfill(' ') << setw(num2) << std::setprecision(2) << u.mediana();
        write1 << endl;
    }


    for (auto& i : nuskriausti)
    {
        write2 << left << setfill(' ') << setw(num) << i.name;
        write2 << left << setfill(' ') << setw(num) << i.surn;
        write2 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.vidurkis();
        write2 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.mediana();
        write2 << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo rusiavimas ir isvedimas i dvi grupes su (list) uztruko : " << diff.count() << " s\n";

    write1.close();
    write2.close();
}


void  Skaitom_faila2(list <data>& sze)
{
    std::ifstream read("sarasas/studentai.txt");

    if (!read)
    {
        cout << "Cannot open the File!" << endl;
    }

    read.ignore(std::numeric_limits<std::streamsize>::max(), read.widen('\n'));
    read.ignore(std::numeric_limits<std::streamsize>::max(), read.widen('\n'));

    int inputNd;
    data z;


    while (!read.eof())
    {
        z.marks.clear();
        read >> z.name;
        read >> z.surn;

        for (int j = 1; j <= 5; j++)
        {
            read >> inputNd;
            z.marks.push_back(inputNd);
        }
        read >> z.exam;

        sze.push_back(z);
    }


    sze.pop_back();
    read.close();
}

void Generuojam_Sarasa2()
{
    std::srand(std::time(NULL));

    int NR;
    std::cout << "iveskite, kiek studentu noretumete sugeneruoti(1000, 10 000, 100 000, 1 000 000, 10 000 000):" << std::endl;
    std::cin >> NR;

    std::ofstream write("sarasas/studentai.txt");

    int num = 15; int num2 = 20; int num3 = 5;

    write << left << setfill(' ') << setw(num) << "Pavarde";
    write << left << setfill(' ') << setw(num) << "Vardas";
    write << left << setfill(' ') << setw(num3) << "ND1";
    write << left << setfill(' ') << setw(num3) << "ND2";
    write << left << setfill(' ') << setw(num3) << "ND3";
    write << left << setfill(' ') << setw(num3) << "ND4";
    write << left << setfill(' ') << setw(num3) << "ND5";
    write << left << setfill(' ') << setw(8) << "EGZ" << endl;

    const std::string bruksnys(num * 2 + num3 * 5 + 3.5, '_');
    write << bruksnys;

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
}
