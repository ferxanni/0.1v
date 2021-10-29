#include "Funkcijos.h"
#include "libraries.h"







int main()

{
    


    int sk;

    std::vector<data> sze;
    
    char repeat;
    do {
        Generuojam_Sarasa();
        Skaitom_faila(sze);
        Studentu_grupes(sze);

        cout << "Jeigu norite generuoti nauja sarasa spauskite N \n";
        std::cin >> repeat;
    }
        while (repeat == 'N');

  

    return 0;
}