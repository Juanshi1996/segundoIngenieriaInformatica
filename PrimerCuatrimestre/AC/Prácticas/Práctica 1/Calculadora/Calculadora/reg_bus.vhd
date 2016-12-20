-- VHDL Test Bench Created from source file reg_bidireccional.vhd -- 18:30:00 17/10/2006
-- Author: Joaquín Olivares

library ieee;
use ieee.std_logic_1164.all;

 
-- registro 4 bit
entity reg is 
port(
     CLK:    in STD_LOGIC;
     RESET:  in STD_LOGIC;
     LOAD:      in STD_LOGIC; -- 1 Habilita la carga síncrona del registro. Precarga del registro antes de funcionamiento normal.
     WE:		 in STD_LOGIC; 	-- 1 habilita la escritura síncrona del registro
     RE:		 in STD_LOGIC; 	-- 1 habilita la lectura síncrona del registro si WE=0
     DATA: inout STD_LOGIC_VECTOR (3 downto 0)
);
end entity;
 
architecture arch of reg is   
	signal R: STD_LOGIC_VECTOR(3 downto 0);
	signal WE_SYNC, RE_SYNC, WR_FLAG, nWR_FLAG, WR_FLAG2: STD_LOGIC; 
begin
process (CLK, RESET, WR_FLAG2)
begin
	if RESET = '0' then
		R <= (others => '0');
		WE_SYNC <= '0';
		RE_SYNC <= '0';
		WR_FLAG <= '0';
	elsif WR_FLAG2 = '1' then
		R <= DATA;
		WR_FLAG <= '0';
	elsif CLK'event and CLK='1' then
		if WE = '1' OR LOAD = '1' then
			WR_FLAG <= '1' after 50 ns;
		end if;         
		WE_SYNC <= WE;
		RE_SYNC <= RE;
	end if;
end process;      

nWR_FLAG <= not WR_FLAG AFTER 5 ns;
WR_FLAG2 <= '0' WHEN RESET = '0' ELSE (WR_FLAG AND nWR_FLAG) ;

DATA <= R when RE_SYNC = '1' and WE_SYNC = '0' else (others => 'Z');			

end; 
