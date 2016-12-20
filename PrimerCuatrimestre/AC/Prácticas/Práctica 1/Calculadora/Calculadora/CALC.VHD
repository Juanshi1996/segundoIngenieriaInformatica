LIBRARY IEEE;
USE IEEE.std_logic_1164.all;

ENTITY SENALES_CONTROL IS PORT (
	S1 : IN std_logic;
	S2 : IN std_logic;
	S3 : IN std_logic;
	S4 : IN std_logic;
	S5 : IN std_logic;
	Za : OUT std_logic;
	Ralpha : OUT std_logic;
	W : OUT std_logic;
	R : OUT std_logic;
	Wa : OUT std_logic;
	Rbeta : OUT std_logic;
	Ra : OUT std_logic;
	Walpha : OUT std_logic;
	S0 : IN std_logic
); END SENALES_CONTROL;



ARCHITECTURE STRUCTURE OF SENALES_CONTROL IS

-- COMPONENTS

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
SIGNAL GND : std_logic;
SIGNAL VCC : std_logic;

-- GATE INSTANCES

BEGIN
U1 : \74LS32\	PORT MAP(
	I0_A => orcad_unused, 
	I1_A => orcad_unused, 
	O_A => OPEN, 
	VCC => OPEN, 
	GND => OPEN, 
	I0_B => S0, 
	I1_B => S0, 
	O_B => ZA, 
	I0_C => S1, 
	I1_C => S1, 
	O_C => RALPHA, 
	I0_D => S1, 
	I1_D => S3, 
	O_D => W
);
U5 : \74LS32\	PORT MAP(
	I0_A => S4, 
	I1_A => S2, 
	O_A => R, 
	VCC => VCC, 
	GND => GND, 
	I0_B => S2, 
	I1_B => S4, 
	O_B => WA, 
	I0_C => S3, 
	I1_C => S3, 
	O_C => RBETA, 
	I0_D => S5, 
	I1_D => S5, 
	O_D => RA
);
U6 : \74LS32\	PORT MAP(
	I0_A => S5, 
	I1_A => S5, 
	O_A => WALPHA, 
	VCC => VCC, 
	GND => GND, 
	I0_B => orcad_unused, 
	I1_B => orcad_unused, 
	O_B => OPEN, 
	I0_C => orcad_unused, 
	I1_C => orcad_unused, 
	O_C => OPEN, 
	I0_D => orcad_unused, 
	I1_D => orcad_unused, 
	O_D => OPEN
);
END STRUCTURE;

LIBRARY IEEE;
USE IEEE.std_logic_1164.all;

ENTITY PUESTA_CERO IS PORT (
	CERO : IN std_logic;
	I : OUT std_logic;
	C : OUT std_logic;
	Z : OUT std_logic;
	Wbeta : OUT std_logic
); END PUESTA_CERO;



ARCHITECTURE STRUCTURE OF PUESTA_CERO IS

-- COMPONENTS

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
SIGNAL GND : std_logic;
SIGNAL VCC : std_logic;

-- GATE INSTANCES

BEGIN
U7 : \74LS32\	PORT MAP(
	I0_A => CERO, 
	I1_A => CERO, 
	O_A => I, 
	VCC => VCC, 
	GND => GND, 
	I0_B => CERO, 
	I1_B => CERO, 
	O_B => C, 
	I0_C => CERO, 
	I1_C => CERO, 
	O_C => Z, 
	I0_D => CERO, 
	I1_D => CERO, 
	O_D => WBETA
);
END STRUCTURE;

LIBRARY IEEE;
USE IEEE.std_logic_1164.all;

ENTITY CONTROLADOR IS PORT (
	CLK : IN std_logic;
	W : OUT std_logic;
	R : OUT std_logic;
	I : OUT std_logic;
	C : OUT std_logic;
	Z : OUT std_logic;
	Wa : OUT std_logic;
	Ra : OUT std_logic;
	Walpha : OUT std_logic;
	Ralpha : OUT std_logic;
	Wbeta : OUT std_logic;
	Rbeta : OUT std_logic;
	RESET : IN std_logic;
	INICIO : IN std_logic;
	ALIM : IN std_logic;
	TIERRA : IN std_logic;
	Za : OUT std_logic
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

COMPONENT SENALES_CONTROL	 PORT (
	S1 : IN std_logic;
	S2 : IN std_logic;
	S3 : IN std_logic;
	S4 : IN std_logic;
	S5 : IN std_logic;
	Za : OUT std_logic;
	Ralpha : OUT std_logic;
	W : OUT std_logic;
	R : OUT std_logic;
	Wa : OUT std_logic;
	Rbeta : OUT std_logic;
	Ra : OUT std_logic;
	Walpha : OUT std_logic;
	S0 : IN std_logic
); END COMPONENT;

COMPONENT PUESTA_CERO	 PORT (
	CERO : IN std_logic;
	I : OUT std_logic;
	C : OUT std_logic;
	Z : OUT std_logic;
	Wbeta : OUT std_logic
); END COMPONENT;

-- SIGNALS

SIGNAL orcad_unused:std_logic;
SIGNAL VCC : std_logic;
SIGNAL GND : std_logic;
SIGNAL S2 : std_logic;
SIGNAL S1 : std_logic;
SIGNAL S4 : std_logic;
SIGNAL S3 : std_logic;
SIGNAL S5 : std_logic;
SIGNAL S0 : std_logic;

-- GATE INSTANCES

BEGIN
U2 : \74LS74\	PORT MAP(
	D_A => INICIO, 
	CLK_A => CLK, 
	Q_A => S0, 
	\Q\\_A\ => OPEN, 
	VCC => VCC, 
	PR_A => RESET, 
	GND => GND, 
	CL_A => ALIM, 
	D_B => S0, 
	CLK_B => CLK, 
	Q_B => S1, 
	\Q\\_B\ => OPEN, 
	PR_B => RESET, 
	CL_B => ALIM
);
U3 : \74LS74\	PORT MAP(
	D_A => S1, 
	CLK_A => CLK, 
	Q_A => S2, 
	\Q\\_A\ => OPEN, 
	VCC => VCC, 
	PR_A => RESET, 
	GND => GND, 
	CL_A => ALIM, 
	D_B => S2, 
	CLK_B => CLK, 
	Q_B => S3, 
	\Q\\_B\ => OPEN, 
	PR_B => RESET, 
	CL_B => ALIM
);
U4 : \74LS74\	PORT MAP(
	D_A => S3, 
	CLK_A => CLK, 
	Q_A => S4, 
	\Q\\_A\ => OPEN, 
	VCC => VCC, 
	PR_A => RESET, 
	GND => GND, 
	CL_A => ALIM, 
	D_B => S4, 
	CLK_B => CLK, 
	Q_B => S5, 
	\Q\\_B\ => OPEN, 
	PR_B => RESET, 
	CL_B => ALIM
);
SEGCTRL : SENALES_CONTROL	PORT MAP(
	S1 => S1, 
	S2 => S2, 
	S3 => S3, 
	S4 => S4, 
	S5 => S5, 
	Za => ZA, 
	Ralpha => RALPHA, 
	W => W, 
	R => R, 
	Wa => WA, 
	Rbeta => RBETA, 
	Ra => RA, 
	Walpha => WALPHA, 
	S0 => S0
);
CEROS : PUESTA_CERO	PORT MAP(
	CERO => TIERRA, 
	I => I, 
	C => C, 
	Z => Z, 
	Wbeta => WBETA
);
END STRUCTURE;

LIBRARY IEEE;
USE IEEE.std_logic_1164.all;

ENTITY CALC IS PORT (
	DATOS : INOUT std_logic_vector(3 DOWNTO 0);
	TIERRA : IN std_logic;
	INICIO : IN std_logic;
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
	data : INOUT std_logic_vector(3 DOWNTO 0)
	); END COMPONENT;

COMPONENT acumulador
	PORT (
	clk : IN std_logic;
	reset : IN std_logic;
	we : IN std_logic;
	re : IN std_logic;
	z : IN std_logic;
	ov : OUT std_logic;
	data : INOUT std_logic_vector(3 DOWNTO 0);
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
	d_in : IN std_logic_vector(3 DOWNTO 0);
	d_out : INOUT std_logic_vector(3 DOWNTO 0)
	); END COMPONENT;

COMPONENT CONTROLADOR	 PORT (
	CLK : IN std_logic;
	W : OUT std_logic;
	R : OUT std_logic;
	I : OUT std_logic;
	C : OUT std_logic;
	Z : OUT std_logic;
	Wa : OUT std_logic;
	Ra : OUT std_logic;
	Walpha : OUT std_logic;
	Ralpha : OUT std_logic;
	Wbeta : OUT std_logic;
	Rbeta : OUT std_logic;
	RESET : IN std_logic;
	INICIO : IN std_logic;
	ALIM : IN std_logic;
	TIERRA : IN std_logic;
	Za : OUT std_logic
); END COMPONENT;

-- SIGNALS

SIGNAL orcad_unused:std_logic;
SIGNAL RA : std_logic;
SIGNAL I : std_logic;
SIGNAL C : std_logic;
SIGNAL R : std_logic;
SIGNAL W : std_logic;
SIGNAL Z : std_logic;
SIGNAL RALPHA : std_logic;
SIGNAL WALPHA : std_logic;
SIGNAL WBETA : std_logic;
SIGNAL RBETA : std_logic;
SIGNAL WA : std_logic;
SIGNAL ZA : std_logic;
SIGNAL DAT : std_logic_vector(3 DOWNTO 0);

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
	data(0) => DATOS(0)
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
	data(0) => DATOS(0)
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
	d_out(0) => DAT(0)
);
CONTROL : CONTROLADOR	PORT MAP(
	CLK => CLK, 
	W => W, 
	R => R, 
	I => I, 
	C => C, 
	Z => Z, 
	Wa => WA, 
	Ra => RA, 
	Walpha => WALPHA, 
	Ralpha => RALPHA, 
	Wbeta => WBETA, 
	Rbeta => RBETA, 
	RESET => RESET, 
	INICIO => INICIO, 
	ALIM => ALIM, 
	TIERRA => TIERRA, 
	Za => ZA
);
END STRUCTURE;

