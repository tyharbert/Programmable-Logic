LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY signed_squarer_3bit_entity IS
PORT (a : IN std_logic;
b : IN std_logic;
c : IN std_logic;
b0 : OUT std_logic;
b1 : OUT std_logic;
b2 : OUT std_logic;
b3 : OUT std_logic;
b4 : OUT std_logic);
END signed_squarer_3bit_entity;

ARCHITECTURE signed_squarer_3bit_arch OF signed_squarer_3bit_entity IS
BEGIN
b0 <= ( not a and not b and c ) or ( not a and b and c ) or ( a and not b and c ) or ( a and b and c );
b1 <= ( a and not b and c ) or ( a and b and c );
b2 <= ( not a and b and not c ) or ( a and not b and c ) or ( a and b and not c ) or ( a and b and c );
b3 <= ( not a and b and c ) or ( a and b and not c ) or ( a and b and c );
b4 <= ( a and not b and not c ) or ( a and not b and c ) or ( a and b and not c ) or ( a and b and c );
END signed_squarer_3bit_arch;