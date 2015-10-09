LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY unsigned_squarer_5bit_entity IS
PORT (a : IN std_logic;
b : IN std_logic;
c : IN std_logic;
d : IN std_logic;
e : IN std_logic;
b0 : OUT std_logic;
b1 : OUT std_logic;
b2 : OUT std_logic;
b3 : OUT std_logic;
b4 : OUT std_logic;
b5 : OUT std_logic;
b6 : OUT std_logic;
b7 : OUT std_logic;
b8 : OUT std_logic;
b9 : OUT std_logic);
END unsigned_squarer_5bit_entity;

ARCHITECTURE unsigned_squarer_5bit_arch OF unsigned_squarer_5bit_entity IS
BEGIN
b0 <= ( not a and not b and not c and not d and e ) or ( not a and not b and not c and d and e ) or ( not a and not b and c and not d and e ) or ( not a and not b and c and d and e ) or ( not a and b and not c and not d and e ) or ( not a and b and not c and d and e ) or ( not a and b and c and not d and e ) or ( not a and b and c and d and e ) or ( a and not b and not c and not d and e ) or ( a and not b and not c and d and e ) or ( a and not b and c and not d and e ) or ( a and not b and c and d and e ) or ( a and b and not c and not d and e ) or ( a and b and not c and d and e ) or ( a and b and c and not d and e ) or ( a and b and c and d and e );
b1 <= '0';
b2 <= ( not a and not b and not c and d and not e ) or ( not a and not b and c and d and not e ) or ( not a and b and not c and d and not e ) or ( not a and b and c and d and not e ) or ( a and not b and not c and d and not e ) or ( a and not b and c and d and not e ) or ( a and b and not c and d and not e ) or ( a and b and c and d and not e );
b3 <= ( not a and not b and not c and d and e ) or ( not a and not b and c and not d and e ) or ( not a and b and not c and d and e ) or ( not a and b and c and not d and e ) or ( a and not b and not c and d and e ) or ( a and not b and c and not d and e ) or ( a and b and not c and d and e ) or ( a and b and c and not d and e );
b4 <= ( not a and not b and c and not d and not e ) or ( not a and not b and c and not d and e ) or ( not a and not b and c and d and e ) or ( not a and b and not c and not d and e ) or ( not a and b and not c and d and e ) or ( not a and b and c and not d and not e ) or ( a and not b and c and not d and not e ) or ( a and not b and c and not d and e ) or ( a and not b and c and d and e ) or ( a and b and not c and not d and e ) or ( a and b and not c and d and e ) or ( a and b and c and not d and not e );
b5 <= ( not a and not b and c and d and not e ) or ( not a and not b and c and d and e ) or ( not a and b and not c and d and not e ) or ( not a and b and not c and d and e ) or ( not a and b and c and not d and e ) or ( not a and b and c and d and e ) or ( a and not b and not c and not d and e ) or ( a and not b and not c and d and e ) or ( a and not b and c and not d and e ) or ( a and not b and c and d and not e ) or ( a and b and not c and not d and e ) or ( a and b and not c and d and not e );
b6 <= ( not a and b and not c and not d and not e ) or ( not a and b and not c and not d and e ) or ( not a and b and not c and d and not e ) or ( not a and b and not c and d and e ) or ( not a and b and c and d and not e ) or ( not a and b and c and d and e ) or ( a and not b and not c and d and not e ) or ( a and not b and not c and d and e ) or ( a and not b and c and d and not e ) or ( a and b and not c and not d and not e ) or ( a and b and not c and not d and e ) or ( a and b and not c and d and e ) or ( a and b and c and not d and e ) or ( a and b and c and d and e );
b7 <= ( not a and b and c and not d and not e ) or ( not a and b and c and not d and e ) or ( not a and b and c and d and not e ) or ( not a and b and c and d and e ) or ( a and not b and c and not d and not e ) or ( a and not b and c and not d and e ) or ( a and not b and c and d and not e ) or ( a and b and not c and d and not e ) or ( a and b and not c and d and e ) or ( a and b and c and d and not e ) or ( a and b and c and d and e );
b8 <= ( a and not b and not c and not d and not e ) or ( a and not b and not c and not d and e ) or ( a and not b and not c and d and not e ) or ( a and not b and not c and d and e ) or ( a and not b and c and not d and not e ) or ( a and not b and c and not d and e ) or ( a and not b and c and d and not e ) or ( a and b and c and not d and not e ) or ( a and b and c and not d and e ) or ( a and b and c and d and not e ) or ( a and b and c and d and e );
b9 <= ( a and not b and c and d and e ) or ( a and b and not c and not d and not e ) or ( a and b and not c and not d and e ) or ( a and b and not c and d and not e ) or ( a and b and not c and d and e ) or ( a and b and c and not d and not e ) or ( a and b and c and not d and e ) or ( a and b and c and d and not e ) or ( a and b and c and d and e );
END unsigned_squarer_5bit_arch;