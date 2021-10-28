
#include "funkcijos.h"
#include "input_output.h"





int main()

{

    std::cout << "Pasirinkite!" << std::endl;

    std::cout << "1. Noriu ikelti studentu duomenis is failo" << std::endl;

    std::cout << "2. Noriu ivesti studentu duomenis pats" << std::endl;
    std::cout << "Jusu pasirinkimas:\n" << std::endl;
   

    int sk;

    std::vector<data> sze;

    std::string choice;
    std::cin >> choice;

    do

    {

        if (choice == "1")

        {

            input(sze, &sk);
            output(sze, sk);
            

        }

        else if (choice == "2")

        {

            ivedimas();

        }
    } while (choice != "1" && choice != "2");

   
        return 0;
    }
