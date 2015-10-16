
// Tyler Harbert

#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <fstream>
#include "IO.hpp"

class Parser {
private:
    // parser variables
    std::ifstream _inputFile;
    std::ofstream _outputFile;
    std::string _outputFileName;
    std::string _rootPath;
    char _current;

    // vhdl variables
    IO* _vhdlInputs;
    IO* _vhdlOutputs;
    int _inputCount;
    int _possibleIO;
    int _outputCount;

public:
    Parser(std::string, std::string, std::string);
    Parser(std::string, std::string);
    void parse();
    void next();
    void generateVHDL(std::string);

};



#endif

