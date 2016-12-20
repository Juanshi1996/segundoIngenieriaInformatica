-- VHDL source file acumulador.vhd -- 20:08:00 17/10/2006
-- Author: Joaquín Olivares

library ieee;
use ieee.std_logic_1164.all;    
use ieee.numeric_std.all;
use ieee.std_logic_arith.all;

-- use IEEE.STD_LOGIC_UNSIGNED.ALL; 
 
-- acumulador de 4+1 bits
entity acumulador is 
port(
     CLK:		in STD_LOGIC;
     RESET:  	in STD_LOGIC;    
     WE: 		in STD_LOGIC; -- si WE = 1 se acumula el dato de entrada 
     RE: 		in STD_LOGIC; -- si RE = 1 se habilita el bus de salida, sino queda en alta impedancia
     Z: 			in STD_LOGIC; -- si Z = 1, puesta a Cero sincrona
     OV: 		out STD_LOGIC; -- overflow
     DATA: 		in STD_LOGIC_VECTOR (3 downto 0);		-- dato de entrada
     SUM: 		inout STD_LOGIC_VECTOR (3 downto 0)		-- dato de salida
);
end entity;
 
architecture arch of acumulador is   
	signal R: STD_LOGIC_VECTOR(4 downto 0);
	signal WE_SYNC, RE_SYNC, WR_FLAG, nWR_FLAG, WR_FLAG2: STD_LOGIC; 
begin
process (CLK, RESET, WR_FLAG2)
	variable op1, op2: unsigned (4 downto 0);
begin
	if RESET = '0' then
		R <= (others => '0');
		WE_SYNC <= '0';
		RE_SYNC <= '0';
		WR_FLAG <= '0';
	elsif WR_FLAG2 = '1' then
		op1 := resize(unsigned(DATA),5);
		op2 := unsigned(R);			
		R <= std_logic_vector(op1 + op2) ;
		WR_FLAG <= '0';
	elsif CLK'event and CLK='1' then
		if WE = '1' then
			WR_FLAG <= '1' AFTER 50 ns;
		elsif Z = '1' then
			WR_FLAG <= '0';
			R <= (others => '0');
		end if;         
		WE_SYNC <= WE;
		RE_SYNC <= RE;
	end if;
end process;      

--op1 <= DATA after 12 ns when CLK'event and CLK='1' and WE ='1';
--R <= '0'&op1 + R after 13 ns when CLK'event and CLK='1' and WE = '1';

nWR_FLAG <= not WR_FLAG AFTER 5 ns;
WR_FLAG2 <= '0' WHEN RESET = '0' ELSE (WR_FLAG AND nWR_FLAG) ;

SUM <= R(3 downto 0) when RE_SYNC = '1' and WE_SYNC = '0' else (others => 'Z');			
OV <= R(4);

end; 
