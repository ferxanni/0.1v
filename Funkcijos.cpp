#include "Funkcijos.h"
#include "libraries.h"




void Studentu_grupes(vector <data>& sze)
{

  

    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    Rusiuojam_pagal_rezultatus(sze);
   

    vector <data>::iterator it = std::stable_partition(sze.begin(), sze.end(), skirstom);
    vector <data> silpni(it, sze.end());
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
    write2 << left << setfill(' ') << setw(num2) << "vidurkis";
    write2 << left << setfill(' ') << setw(num2) << "mediana" << endl;

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


    for (auto& i : silpni)
    {
        write2 << left << setfill(' ') << setw(num) << i.name;
        write2 << left << setfill(' ') << setw(num) << i.surn;
        write2 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.vidurkis();
        write2 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.mediana();
        write2 << endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo rusiavimas ir isvedimas i dvi grupes uztruko : " << diff.count() << " s\n";

    write1.close();
    write2.close();
}


void  Skaitom_faila(vector <data>& sze)
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

    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

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

void input(std::vector<data>& sze, int* sk)
{
    int counter = 0;
    int temp;
    std::ifstream fin;
    std::string buff;
    try {
        fin.open("studentai10000.txt");

        if (!fin.is_open())
            throw 0;

        getline(fin >> std::ws, buff);
        *sk = wordsinstring(buff) - 3;
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

            counter++;
        }

    }
    catch (int n)
    {
        std::cout << "Klaida!" << n << std::endl;

    }
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
            << " | " << std::setw(9) << sze[i].vidurkis()
            << " | " << std::setw(6) << sze[i].mediana()
            << " | " << std::endl;
    }
    fout << linija << std::endl;


}





void ranka_ivedimas(data sze[], int i)
{
    int temp;
    do {
        std::cout << "Iveskite egzamino rezultata:\n";
        std::cin >> sze[i].exam;
    } while (sze[i].exam < 0 || sze[i].exam > 10);
    std::cout << "Iveskite pazymius (kad baigti, iveskite -1:";
    int counter = 0;
    do {
        std::cin >> temp;
        sze[i].marks.push_back(temp);
        if (sze[i].marks.at(counter) != -1) { sze[i].Total = sze[i].Total + (float)sze[i].marks.at(counter); }
        counter++;
    } while (sze[i].marks.at(counter) != -1);
    counter--;
    
}




void stud_info(data sze[], int i)
{
    std::cout << "Iveskite " << i + 1 << " studento varda:\n";
    std::cin >> sze[i].name;

    std::cout << "Iveskite " << i + 1 << " studento pavarde:\n";
    std::cin >> sze[i].surn;

}




void isprintinam_data(data sze[], int studentu_sk)
{
    std::cout << "\n";
    std::cout << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Vidurkis/"
        << std::left << "Mediana\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentu_sk; i++)
    {
        std::cout << std::setw(20) << std::left << sze[i].name
            << std::setw(20) << std::left << sze[i].surn
            << std::setw(18) << std::left << sze[i].vidurkis()
            << sze[i].mediana()
            << endl;
    }

    std::cout << "Ivykdyta!" << std::endl;
}



void ivedimas()
{

    int stud_nr;
    char temp;
    do
    {
        std::cout << "Iveskite studentu kieki:\n";
        std::cin >> stud_nr;
    } while (int(stud_nr) < 0 || int(stud_nr) > 255);
    data sze[25];
  
    do
    {
        std::cout << "Spauskite 1, jeigu norite, kad studentu pazymiai butu sugeneruoti automatiskai\n";
        std::cout << "Spauskite 2, jeigu norite suvesti studentu pazymius pats\n";
        std::cin >> temp;
        if (temp != '1' && temp != '2') { std::cout << "Klaida\n"; }
    } while (temp != '1' && temp != '2');
    for (int i = 0; i < stud_nr; i++)
    {
        stud_info(sze, i);
        if (temp == '2') { ranka_ivedimas(sze, i); }
        else { auto_ivedimas(sze, i, 5); }
    }



    isprintinam_data(sze, stud_nr);



}