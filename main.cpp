#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include "input.h"
#include "output.h"

int main()
{
    int n;
    char temp;
    std::vector<data> sze;
    input(sze, &n);
    output(sze, n);
    system("start kursiokai.txt");
    return 0;
}
