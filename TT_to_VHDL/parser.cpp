// Tyler Harbert

#include <iostream>
#include <fstream>
#include <cmath>

#include "parser.hpp"

// This constructor reads in the whole file and sets the lookahead to the first non-white space
Parser::Parser(std::string rootPath, std::string inputFile) {
    this->_rootPath = rootPath;
    this->_outputFileName = "output.vhd";
    this->_inputFile.open(rootPath + inputFile);

    if (this->_inputFile.is_open()){
        std::cout << "\nfile " << rootPath << inputFile << " opened successfully\n";
    }else {
        std::cout << "\nfile " << rootPath << inputFile << " failed to open\n";
    }
}

// This constructor does the same thing and also sets the output file name
Parser::Parser(std::string rootPath, std::string inputFile, std::string outputFile) {
    this->_rootPath = rootPath;
    this->_outputFileName = outputFile;
    this->_inputFile.open(rootPath + inputFile);

    if (this->_inputFile.is_open()){
        std::cout << "\nfile " << rootPath << inputFile << " opened successfully\n";
    }else {
        std::cout << "\nfile " << rootPath << inputFile << " failed to open\n";
    }
}

// this gets the next non-whitespace char
void Parser::next() {
    do {
        this->_current = this->_inputFile.get();
    } while (isspace(this->_current));
}

// this generates the vhdl
void Parser::generateVHDL(std::string name) {
    std::cout << "running VHDL generator:\n";
    this->_outputFile.open(this->_rootPath + this->_outputFileName);

    if (this->_outputFile.is_open()){
        std::cout << "\nfile " << this->_rootPath << this->_outputFile << " opened successfully\n";
    }else {
        std::cout << "\nfile " << this->_rootPath << this->_outputFile << " failed to open\n";
    }

    // add library info
    this->_outputFile << "LIBRARY ieee;\nUSE ieee.std_logic_1164.all;\n\n";

    // add entity
    this->_outputFile << "ENTITY " << name << "_entity IS\nPORT (";
    for (int i=0; i<this->_inputCount; i++){
        this->_outputFile << this->_vhdlInputs[i].name << " : IN std_logic;\n";
    }
    for (int j=0; j<this->_outputCount; j++){
        this->_outputFile << this->_vhdlOutputs[j].name << " : OUT std_logic";
        if (j != this->_outputCount-1)
            this->_outputFile << ";\n";
    }
    this->_outputFile << ");\nEND " << name << "_entity;\n\n";

    //add architecture
    this->_outputFile << "ARCHITECTURE " << name << "_arch OF " << name << "_entity IS\nBEGIN\n";
    // each output
    for (int k=0; k<this->_outputCount; k++){
        this->_outputFile << this->_vhdlOutputs[k].name << " <= ";

        // loop through all posible io for 1s count
        int onesTot = 0;
        for (int l=0; l < this->_possibleIO; l++){
            // output is a 1
            if (this->_vhdlOutputs[k].values[l])
                onesTot++;
        }
        // if all 0, make the output expicitly 0
        if (onesTot <= 0)
            this->_outputFile << "'0';\n";
        // if all 1, make output explicitly 1
        else if (onesTot == this->_possibleIO)
            this->_outputFile << "'1';\n";
        // if a combination, process truth table
        else {

            // loop through all posible io
            int onesCount = 0;
            for (int l=0; l < this->_possibleIO; l++){
                // if an output is 1
                if (this->_vhdlOutputs[k].values[l]){
                    onesCount++;
                    this->_outputFile << "( ";
                    // all inputs at that index
                    for (int m = 0; m<this->_inputCount; m++){
                        if (!this->_vhdlInputs[m].values[l])
                            this->_outputFile << "not ";
                        this->_outputFile << this->_vhdlInputs[m].name;
                        if (m != this->_inputCount-1)
                            this->_outputFile << " and ";
                    }
                    this->_outputFile << " )";
                    if (onesCount != onesTot)
                        this->_outputFile << " or ";
                    else
                        this->_outputFile << ";\n";
                }
            }
        }
    }
    this->_outputFile << "END " << name << "_arch;";

    this->_outputFile.close();
    std::cout << "VHDL generation complete to " << this->_rootPath << this->_outputFileName << "\n";
}

// This function creates the parsed file
void Parser::parse() {
    std::cout << "running parser:\n";
    this->next();

    // parse number of inputs
    std::string inputs_str = "";
    if (this->_current == '#')
        this->next();
    if (this->_current == 'i')
        this->next();
    if (this->_current == ':')
        this->next();

    while (isdigit(this->_current)) {
        inputs_str = inputs_str + this->_current;
        this->next();
    }
    this->_inputCount = stoi(inputs_str);
    this->_possibleIO = (int)pow(2,this->_inputCount);

    // allocate input array
    this->_vhdlInputs = new IO[this->_inputCount];

    // loop through all inputs
    int i = 0;
    while (this->_current != '#'){

        // parse variable name
        std::string name = "";
        while (this->_current != ':') {
            name = name + this->_current;
            this->next();
        }
        this->next();

        // set input name
        this->_vhdlInputs[i].name = name;
        this->_vhdlInputs[i].values = new bool[this->_possibleIO];

        // parse variable values
        int j = 0;
        while (this->_current == '0' || this->_current == '1') {
            if (this->_current == '0'){
                this->_vhdlInputs[i].values[j] = false;
            }else{
                this->_vhdlInputs[i].values[j] = true;
            }
            this->next();
            j++;
        }

        std::cout << "successfully parsed input " << name << "\n";
        i++;
    }
    this->next();

    // parse number of outputs
    std::string outputs_str = "";
    if (this->_current == 'o')
        this->next();
    if (this->_current == ':')
        this->next();

    while (isdigit(this->_current)) {
        outputs_str = outputs_str + this->_current;
        this->next();
    }
    this->_outputCount = stoi(outputs_str);

    // allocate input array
    this->_vhdlOutputs = new IO[this->_outputCount];

    // loop through all outputs
    int k = 0;
    while(!this->_inputFile.eof()){

        // parse variable name
        std::string name = "";
        while (this->_current != ':') {
            name = name + this->_current;
            this->next();
        }
        this->next();

        // set input name
        this->_vhdlOutputs[k].name = name;
        this->_vhdlOutputs[k].values = new bool[this->_possibleIO];

        // parse variable values
        int l = 0;
        while (this->_current == '0' || this->_current == '1') {
            if (this->_current == '0'){
                this->_vhdlOutputs[k].values[l] = false;
            }else{
                this->_vhdlOutputs[k].values[l] = true;
            }
            this->next();
            l++;
        }

        std::cout << "successfully parsed output " << name << "\n";
        k++;
    }

    this->_inputFile.close();
    std::cout << "parsing complete\n";
}
