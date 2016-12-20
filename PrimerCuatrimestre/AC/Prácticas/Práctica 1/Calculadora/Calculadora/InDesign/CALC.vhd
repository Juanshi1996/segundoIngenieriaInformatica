LIBRARY IEEE;
USE IEEE.std_logic_1164.all;
ENTITY CONTROLADOR IS PORT (
	CLK : IN std_logic;
	W : OUT std_logic;
	R : OUT std_logic;
	C : OUT std_logic;
	Wa : OUT std_logic;
	Ra : OUT std_logic;
	Rbeta : OUT std_logic;
	RESET : IN std_logic;
	INICIO : IN std_logic;
	ALIM : IN std_logic;
	TIERRA : IN std_logic;
	Za : OUT std_logic;
	I : OUT std_logic;
	Z : OUT std_logic;
	Ralpha : OUT std_logic;
	Walpha : OUT std_logic;
	Wbeta : OUT std_logic
); END CONTROLADOR;



ARCHITECTURE STRUCTURE OF CONTROLADOR IS

-- COMPONENTS

COMPONENT \74LS74\
	PORT (
	D_A : IN std_logic;
	CLK_A : IN std_logic;
	Q_A : OUT std_logic;
	\Q\\_A\ : OUT std_logic;
	VCC : IN std_logic;
	PR_A : IN std_logic;
	GND : IN std_logic;
	CL_A : IN std_logic;
	D_B : IN std_logic;
	CLK_B : IN std_logic;
	Q_B : OUT std_logic;
	\Q\\_B\ : OUT std_logic;
	PR_B : IN std_logic;
	CL_B : IN std_logic
	); END COMPONENT;

COMPONENT \74LS32\
	PORT (
	I0_A : IN std_logic;
	I1_A : IN std_logic;
	O_A : OUT std_logic;
	VCC : IN std_logic;
	GND : IN std_logic;
	I0_B : IN std_logic;
	I1_B : IN std_logic;
	O_B : OUT std_logic;
	I0_C : IN std_logic;
	I1_C : IN std_logic;
	O_C : OUT std_logic;
	I0_D : IN std_logic;
	I1_D : IN std_logic;
	O_D : OUT std_logic
	); END COMPONENT;

-- SIGNALS

SIGNAL orcad_unused:std_logic;
SIGNAL D2 : std_logic;
SIGNAL N07316 : std_logic;
SIGNAL D4 : std_logic;
SIGNAL D3 : std_logic;
SIGNAL D5 : std_logic;
SIGNAL D1 : std_logic;
SIGNAL GND : std_logic;
SIGNAL N07383 : std_logic;
SIGNAL D7 : std_logic;
SIGNAL D6 : std_logic;
SIGNAL D8 : std_logic;
SIGNAL VCC : std_logic;

-- INSTANCE ATTRIBUTES




-- GATE INSTANCES

BEGIN
U1 : \74LS74\	PORT MAP(
	D_A => INICIO, 
	CLK_A => CLK, 
	Q_A => D1, 
	\Q\\_A\ => OPEN, 
	VCC => VCC, 
	PR_A => ALIM, 
	GND => GND, 
	CL_A => RESET, 
	D_B => D1, 
	CLK_B => CLK, 
	Q_B => D2, 
	\Q\\_B\ => OPEN, 
	PR_B => ALIM, 
	CL_B => RESET
);
U2 : \74LS74\	PORT MAP(
	D_A => D2, 
	CLK_A => CLK, 
	Q_A => D3, 
	\Q\\_A\ => OPEN, 
	VCC => VCC, 
	PR_A => ALIM, 
	GND => GND, 
	CL_A => RESET, 
	D_B => D3, 
	CLK_B => CLK, 
	Q_B => D4, 
	\Q\\_B\ => OPEN, 
	PR_B => ALIM, 
	CL_B => RESET
);
U3 : \74LS74\	PORT MAP(
	D_A => D4, 
	CLK_A => CLK, 
	Q_A => D5, 
	\Q\\_A\ => OPEN, 
	VCC => VCC, 
	PR_A => ALIM, 
	GND => GND, 
	CL_A => RESET, 
	D_B => D5, 
	CLK_B => CLK, 
	Q_B => D6, 
	\Q\\_B\ => OPEN, 
	PR_B => ALIM, 
	CL_B => RESET
);
U4 : \74LS74\	PORT MAP(
	D_A => D6, 
	CLK_A => CLK, 
	Q_A => D7, 
	\Q\\_A\ => OPEN, 
	VCC => VCC, 
	PR_A => ALIM, 
	GND => GND, 
	CL_A => RESET, 
	D_B => D7, 
	CLK_B => CLK, 
	Q_B => D8, 
	\Q\\_B\ => OPEN, 
	PR_B => ALIM, 
	CL_B => RESET
);
U6 : \74LS32\	PORT MAP(
	I0_A => D1, 
	I1_A => D4, 
	O_A => W, 
	VCC => VCC, 
	GND => GND, 
	I0_B => orcad_unused, 
	I1_B => orcad_unused, 
	O_B => OPEN, 
	I0_C => D8, 
	I1_C => D8, 
	O_C => RA, 
	I0_D => D2, 
	I1_D => D3, 
	O_D => N07316
);
U7 : \74LS32\	PORT MAP(
	I0_A => N07316, 
	I1_A => D7, 
	O_A => R, 
	VCC => VCC, 
	GND => GND, 
	I0_B => D1, 
	I1_B => D1, 
	O_B => ZA, 
	I0_C => TIERRA, 
	I1_C => TIERRA, 
	O_C => Z, 
	I0_D => D6, 
	I1_D => D6, 
	O_D => I
);
U8 : \74LS32\	PORT MAP(
	I0_A => D1, 
	I1_A => D1, 
	O_A => RALPHA, 
	VCC => VCC, 
	GND => GND, 
	I0_B => TIERRA, 
	I1_B => TIERRA, 
	O_B => WBETA, 
	I0_C => D5, 
	I1_C => D5, 
	O_C => C, 
	I0_D => D4, 
	I1_D => D4, 
	O_D => RBETA
);
U9 : \74LS32\	PORT MAP(
	I0_A => D2, 
	I1_A => D3, 
	O_A => N07383, 
	VCC => VCC, 
	GND => GND, 
	I0_B => N07383, 
	I1_B => D7, 
	O_B => WA, 
	I0_C => D8, 
	I1_C => D8, 
	O_C => WALPHA, 
	I0_D => orcad_unused, 
	I1_D => orcad_unused, 
	O_D => OPEN
);
END STRUCTURE;

LIBRARY IEEE;
USE IEEE.std_logic_1164.all;
ENTITY CALC IS PORT (
	DATOS : INOUT std_logic_vector(3 DOWNTO 0);
	TIERRA : IN std_logic;
	LOAD_beta : IN std_logic;
	INICIO : IN std_logic;
	LOAD_alpha : IN std_logic;
	RESET : IN std_logic;
	OVF : OUT std_logic;
	ALIM : IN std_logic;
	CLK : IN std_logic
); END CALC;



ARCHITECTURE STRUCTURE OF CALC IS

-- COMPONENTS

COMPONENT reg
	PORT (
	clk : IN std_logic;
	reset : IN std_logic;
	we : IN std_logic;
	re : IN std_logic;
	data : INOUT std_logic_vector(3 DOWNTO 0);
	load : IN std_logic
	); END COMPONENT;

COMPONENT acumulador
	PORT (
	clk : IN std_logic;
	reset : IN std_logic;
	we : IN std_logic;
	re : IN std_logic;
	z : IN std_logic;
	ov : OUT std_logic;
	data : IN std_logic_vector(3 DOWNTO 0);
	sum : INOUT std_logic_vector(3 DOWNTO 0)
	); END COMPONENT;

COMPONENT reg_ci
	PORT (
	clk : IN std_logic;
	reset : IN std_logic;
	we : IN std_logic;
	re : IN std_logic;
	c : IN std_logic;
	z : IN std_logic;
	i : IN std_logic;
	d_in : INOUT std_logic_vector(3 DOWNTO 0);
	d_out : OUT std_logic_vector(3 DOWNTO 0);
	BS : OUT std_logic
	); END COMPONENT;

COMPONENT CONTROLADOR	 PORT (
	CLK : IN std_logic;
	W : OUT std_logic;
	R : OUT std_logic;
	C : OUT std_logic;
	Wa : OUT std_logic;
	Ra : OUT std_logic;
	Rbeta : OUT std_logic;
	RESET : IN std_logic;
	INICIO : IN std_logic;
	ALIM : IN std_logic;
	TIERRA : IN std_logic;
	Za : OUT std_logic;
	I : OUT std_logic;
	Z : OUT std_logic;
	Ralpha : OUT std_logic;
	Walpha : OUT std_logic;
	Wbeta : OUT std_logic
); END COMPONENT;

-- SIGNALS

SIGNAL orcad_unused:std_logic;
SIGNAL C : std_logic;
SIGNAL WALPHA : std_logic;
SIGNAL RBETA : std_logic;
SIGNAL WBETA : std_logic;
SIGNAL ZA : std_logic;
SIGNAL Z : std_logic;
SIGNAL WA : std_logic;
SIGNAL RA : std_logic;
SIGNAL R : std_logic;
SIGNAL RALPHA : std_logic;
SIGNAL W : std_logic;
SIGNAL I : std_logic;
SIGNAL DAT : std_logic_vector(3 DOWNTO 0);

-- INSTANCE ATTRIBUTES




-- GATE INSTANCES

BEGIN
REG_BETA : reg	PORT MAP(
	clk => CLK, 
	reset => RESET, 
	we => WBETA, 
	re => RBETA, 
	data(3) => DATOS(3), 
	data(2) => DATOS(2), 
	data(1) => DATOS(1), 
	data(0) => DATOS(0), 
	load => LOAD_BETA
);
ACC : acumulador	PORT MAP(
	clk => CLK, 
	reset => RESET, 
	we => WA, 
	re => RA, 
	z => ZA, 
	ov => OVF, 
	data(3) => DAT(3), 
	data(2) => DAT(2), 
	data(1) => DAT(1), 
	data(0) => DAT(0), 
	sum(3) => DATOS(3), 
	sum(2) => DATOS(2), 
	sum(1) => DATOS(1), 
	sum(0) => DATOS(0)
);
REG_ALPHA : reg	PORT MAP(
	clk => CLK, 
	reset => RESET, 
	we => WALPHA, 
	re => RALPHA, 
	data(3) => DATOS(3), 
	data(2) => DATOS(2), 
	data(1) => DATOS(1), 
	data(0) => DATOS(0), 
	load => LOAD_ALPHA
);
CI : reg_ci	PORT MAP(
	clk => CLK, 
	reset => RESET, 
	we => W, 
	re => R, 
	c => C, 
	z => Z, 
	i => I, 
	d_in(3) => DATOS(3), 
	d_in(2) => DATOS(2), 
	d_in(1) => DATOS(1), 
	d_in(0) => DATOS(0), 
	d_out(3) => DAT(3), 
	d_out(2) => DAT(2), 
	d_out(1) => DAT(1), 
	d_out(0) => DAT(0), 
	BS => OPEN
);
CONTROL : CONTROLADOR	PORT MAP(
	CLK => CLK, 
	W => W, 
	R => R, 
	C => C, 
	Wa => WA, 
	Ra => RA, 
	Rbeta => RBETA, 
	RESET => RESET, 
	INICIO => INICIO, 
	ALIM => ALIM, 
	TIERRA => TIERRA, 
	Za => ZA, 
	I => I, 
	Z => Z, 
	Ralpha => RALPHA, 
	Walpha => WALPHA, 
	Wbeta => WBETA
);
END STRUCTURE;

