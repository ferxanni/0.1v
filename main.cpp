#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>


struct data {
    std::string name;
    std::string surn;
    std::vector<int> marks = { 0 };
    double exam;
    float Total = 0;
};



int randomMark() 
{
    srand(time(0));  

    
    for (int i = 0; i < 10; i++)
        return (rand() % 10) + 1;
}

void auto_ivedimas(data sze[], int i, int n) 
{
    sze[i].exam = randomMark();
    for (int x = 0; x < n; x++)
    {
        sze[i].marks.push_back(randomMark());
    }
    sze[i].Total = sze[i].Total / n;
    sze[i].Total = sze[i].Total * 0.4 + 0.6 * sze[i].exam;
}

void ranka_ivedimas(data sze[], int i) 
{
   int temp;
    do {
        std::cout << "Įveskite egzamino rezultatą:\n";
        std::cin >> sze[i].exam;
    } while (sze[i].exam < 0 || sze[i].exam > 10);
    std::cout << "Įveskite pažymius (kad baigti, įveskite -1:";
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
        std::cout << "Įveskite " << i + 1 << " studento vardą:\n";
        std::cin >> sze[i].name;
    
        std::cout << "Įveskite " << i + 1 << " studento pavardę:\n";
        std::cin >> sze[i].surn;

    }



int mediana(const std::vector<int> marks) {
    int size = marks.size();
    double tmedian;
    if (size % 2 == 0) { 
        tmedian = (marks[marks.size() / 2 - 1] + marks[marks.size() / 2]) / 2;
        std::cout << " " << tmedian << '\n';
    }

    else
        tmedian = marks[marks.size() / 2];
    std::cout << " " << tmedian << '\n';
    return (tmedian);
}






void isprintinam_data(data sze[], int studentu_sk)
{
    std::cout << "\n";
    std::cout << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavardė"
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
    std::cout << "\n";
}

int main()
{
    
    int stud_nr;
    std::string temp;
    do
    {
        std::cout << "Įveskite, kiek studentų norite įvertinti:\n";
        std::cin >> stud_nr;
    } while (int(stud_nr) < 0 || int(stud_nr) > 100);
    data sze[25];
    
    std::vector<data> sze_vect;
    do
    {
        std::cout << "Kad duomenis būtų sugeneruoti automatiškai, įrašykite 'auto', kitu atveju spauskite 1 ir enter \n";
        std::cin >> temp;
        if (temp != "auto" && temp != "1") { std::cout << "netinkama komanda"; }
    } while (temp != "auto" && temp != "1");
    for (int i = 0; i < stud_nr; i++)
    {
        stud_info(sze, i);
        if (temp == "1") { ranka_ivedimas(sze, i); }
        else { auto_ivedimas(sze, i, 5); }
    }
    isprintinam_data(sze, stud_nr);
    
    return 0;
}