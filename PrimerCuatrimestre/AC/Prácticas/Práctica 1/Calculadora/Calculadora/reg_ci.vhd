-- VHDL Test Bench Created from source file reg_bidireccional.vhd -- 18:30:00 17/10/2006
-- Author: Joaquín Olivares

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
-- use IEEE.STD_LOGIC_UNSIGNED.ALL;


-- registro 4 bits 
-- Prioridades:
-- 1.- WE
-- 2.- C
-- 3.- Z 
-- 4.- I
-- RE sin prioridad, se activa independientemente del valor del resto de señales de control

entity reg_ci is 
port(
	CLK:    	in STD_LOGIC;
	RESET:  	in STD_LOGIC; 
	WE:  		in STD_LOGIC; -- Si 1 Carga síncrona de datos
	RE:  		in STD_LOGIC; -- Si 1 Salida síncrona de datos, sino alta impedancia
	C: 			in STD_LOGIC; -- Si 1 Complemento a 1 del valor almacenado en el registro
	Z: 			in STD_LOGIC; -- Si 1 Puesta a cero síncrona
	I: 			in STD_LOGIC; -- Si 1 incremento del valor almacenado en el registro
	D_IN:		inout STD_LOGIC_VECTOR (3 downto 0);
	BS:		out STD_LOGIC; -- Bit de signo del valor almacenado
	D_OUT: 	out STD_LOGIC_VECTOR (3 downto 0)
);
end entity;
 
architecture arch of reg_ci is   
	signal R, REG_AUX: STD_LOGIC_VECTOR(3 downto 0);
	signal RE_SYNC, WR_FLAG, nWR_FLAG, WR_FLAG2: STD_LOGIC; 

begin
process (CLK, RESET, WR_FLAG2)
	variable valor: unsigned (3 downto 0);
begin
	if RESET = '0' then
		R <= (others => '0');
		RE_SYNC <= '0';
		WR_FLAG <= '0';
	elsif WR_FLAG2 = '1' then
			R <= D_IN;
			WR_FLAG <= '0';
	elsif CLK'event and CLK='1' then
		if WE = '1' then
			WR_FLAG <= '1' AFTER 50 ns; 
		elsif Z = '1' then
			WR_FLAG <= '0';
			R <= (others => '0') AFTER 5 ns;
		elsif C = '1' then
				WR_FLAG <= '0';
				R <= not R AFTER 5 ns;	
		elsif I = '1' then
			WR_FLAG <= '0';
			valor := unsigned(R);
			R <= std_logic_vector( valor + "1") AFTER 5 ns;
		end if;
		RE_SYNC <= RE;
	end if;         	
	
end process;      

nWR_FLAG <= not WR_FLAG AFTER 5 ns;
WR_FLAG2 <= '0' WHEN RESET = '0' ELSE (WR_FLAG AND nWR_FLAG) ;

D_OUT <= R when RE_SYNC = '1' else (others => 'Z');
BS <= R(3);

end; 
