#include <iostream>
#include <fstream>

#include "parser.hpp"


using namespace std;

int main()
{
    Parser* p = new Parser("/Users/harbertt11/Documents/CodeBlocksProjects/TT_to_VHDL/Files/","unsigned_3bit.txt", "unsigned_3bit.vhd");
    p->parse();
    p->generateVHDL("unsigned_squarer_3bit");

    Parser* p1 = new Parser("/Users/harbertt11/Documents/CodeBlocksProjects/TT_to_VHDL/Files/","signed_3bit.txt", "signed_3bit.vhd");
    p1->parse();
    p1->generateVHDL("signed_squarer_3bit");

    Parser* p2 = new Parser("/Users/harbertt11/Documents/CodeBlocksProjects/TT_to_VHDL/Files/","unsigned_4bit.txt", "unsigned_4bit.vhd");
    p2->parse();
    p2->generateVHDL("unsigned_squarer_4bit");

    Parser* p3 = new Parser("/Users/harbertt11/Documents/CodeBlocksProjects/TT_to_VHDL/Files/","signed_4bit.txt", "signed_4bit.vhd");
    p3->parse();
    p3->generateVHDL("signed_squarer_4bit");

    return 0;
}
