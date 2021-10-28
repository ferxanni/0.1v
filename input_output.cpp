
#include "input_output.h"




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

            sze.at(counter).Total = sze.at(counter).Total / *sk;
            sze.at(counter).Total = sze.at(counter).Total * 0.4 + 0.6 * sze.at(counter).exam;
            

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
            << " | " << std::setw(9) << sze[i].Total
            << " | " << std::setw(6) << mediana(sze[i].marks)
            << " | " << std::endl;
    }
    fout << linija << std::endl;  

    
}





void ranka_ivedimas(data sze[], int i)
{
    int temp;
    do {
        std::cout << "Áveskite egzamino rezultatà:\n";
        std::cin >> sze[i].exam;
    } while (sze[i].exam < 0 || sze[i].exam > 10);
    std::cout << "Iveskite pazymius (kad baigti, áveskite -1:";
    int counter = 0;
    do {
        std::cin >> temp;
        sze[i].marks.push_back(temp);
        if (sze[i].marks.at(counter) != -1) { sze[i].Total = sze[i].Total + (float)sze[i].marks.at(counter); }
        counter++;
    } while (sze[i].marks.at(counter) != -1);
    counter--;
    sze[i].Total = sze[i].Total / counter;
    sze[i].Total = 0.6 * sze[i].exam + sze[i].Total * 0.4;
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
            << std::setw(18) << std::left << sze[i].Total;
        mediana(sze[i].marks);
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
    //std::vector<duomenys> Eil_vect;
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