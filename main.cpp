#include "Funkcijos.h"
#include "libraries.h"


int main()

{



    int sk;

    list<data> sze;
    vector <data> szee;


    std::cout << "Pasirinkite!" << std::endl;

    std::cout << "1. Noriu ikelti studentu duomenis is failo" << std::endl;

    std::cout << "2. Noriu ivesti studentu duomenis pats" << std::endl;
    std::cout << "3. Noriu generuoti studentu faila automatiskai" << std::endl;
    std::cout << "4. Noriu spartos analizes" << std::endl;
    std::cout << "Jusu pasirinkimas:\n" << std::endl;


    std::string choice;
    std::cin >> choice;

    do

    {

        if (choice == "1")

        {
            vector <data> sze;
            input(sze, &sk);
            output(sze, sk);


        }

        else if (choice == "2")

        {

            ivedimas();

        }

        else if (choice == "3")
        {

            char repeat;
            do {


                Generuojam_Sarasa();
               
                Skaitom_faila2(sze);
                Studentu_grupes1_list(sze); //list 
                
                


                cout << "Jeigu norite generuoti nauja sarasa spauskite N \n";
                std::cin >> repeat;
            } while (repeat == 'N');


        }
        else if (choice == "4")
        {
           
            char repeat;
            do {

                Generuojam_Sarasa();
                {




                    Skaitom_faila1(szee);
                    Skaitom_faila2(sze);
                    std::cout << " LIST:" << std::endl;
                    Studentu_grupes1_list(sze); //list                        
                    Studentu_grupes2_list(sze); //list
                    std::cout << "VECTOR:" << std::endl;
                    Studentu_grupes1(szee); //vector
                    Studentu_grupes2(szee); //vetor
                    


                }
                       
                cout << "Jeigu norite sugeneruoti nauja sarasa spauskite N \n";
                std::cin >> repeat;
                  
            } while (repeat == 'N');



               
             
            

        }
    } while (choice != "1" && choice != "2" && choice != "3");


    return 0;
}
