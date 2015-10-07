#include <iostream>
#include <fstream>

#include "parser.hpp"


using namespace std;

int main()
{
    Parser* p = new Parser("/Users/harbertt11/Documents/CodeBlocksProjects/TT_to_VHDL/","test.txt", "out.vhd");
    p->parse();
    p->generateVHDL("squarer");

    return 0;
}
