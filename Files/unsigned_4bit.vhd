LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY unsigned_squarer_4bit_entity IS
PORT (a : IN std_logic;
b : IN std_logic;
c : IN std_logic;
d : IN std_logic;
b0 : OUT std_logic;
b1 : OUT std_logic;
b2 : OUT std_logic;
b3 : OUT std_logic;
b4 : OUT std_logic;
b5 : OUT std_logic;
b6 : OUT std_logic;
b7 : OUT std_logic);
END unsigned_squarer_4bit_entity;

ARCHITECTURE unsigned_squarer_4bit_arch OF unsigned_squarer_4bit_entity IS
BEGIN
b0 <= ( not a and not b and not c and d ) or ( not a and not b and c and d ) or ( not a and b and not c and d ) or ( not a and b and c and d ) or ( a and not b and not c and d ) or ( a and not b and c and d ) or ( a and b and not c and d ) or ( a and b and c and d );
b1 <= '0';
b2 <= ( not a and not b and c and not d ) or ( not a and b and c and not d ) or ( a and not b and c and not d ) or ( a and b and c and not d );
b3 <= ( not a and not b and c and d ) or ( not a and b and not c and d ) or ( a and not b and c and d ) or ( a and b and not c and d );
b4 <= ( not a and b and not c and not d ) or ( not a and b and not c and d ) or ( not a and b and c and d ) or ( a and not b and not c and d ) or ( a and not b and c and d ) or ( a and b and not c and not d );
b5 <= ( not a and b and c and not d ) or ( not a and b and c and d ) or ( a and not b and c and not d ) or ( a and not b and c and d ) or ( a and b and not c and d ) or ( a and b and c and d );
b6 <= ( a and not b and not c and not d ) or ( a and not b and not c and d ) or ( a and not b and c and not d ) or ( a and not b and c and d ) or ( a and b and c and not d ) or ( a and b and c and d );
b7 <= ( a and b and not c and not d ) or ( a and b and not c and d ) or ( a and b and c and not d ) or ( a and b and c and d );
END unsigned_squarer_4bit_arch;