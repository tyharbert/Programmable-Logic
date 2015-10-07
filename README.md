Truth Table to VHDL
--------

This program can create a VHDL from a truth table.  The format of the truth table can be found in *test.txt* within the project’s root directory.  You can pass the root directory, the input file name and the output file name to the parser constructor.  The name that you want your VHDL entity and architecture to be based off of must be passed to the parser’s generateVHDL() function. See the example main function below:
```````````
Parser* p = new Parser("/Users/harbertt11/Documents/CodeBlocksProjects/TT_to_VHDL/","test.txt", "out.vhd");
p->parse();
p->generateVHDL("squarer");
```````````

