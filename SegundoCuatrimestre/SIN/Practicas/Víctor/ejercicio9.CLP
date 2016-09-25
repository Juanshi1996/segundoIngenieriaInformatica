(deftemplate barco
	(slot letra
		(type SYMBOL)
		(allowed-symbols A B C D E F G H I J)
	)
	(slot numero
		(type INTEGER)
		(range 1 8)
	)
	(slot casillas
		(type INTEGER)
		(range 2 4)
		(default ?NONE)
	)
	(slot tipo
		(type SYMBOL)
		(allowed-symbols patrullera dragaminas fragata acorazado destructor portaaviones)
		(default ?NONE)
	)
	(slot estado
		(type SYMBOL)
		(allowed-symbols indemne tocado hundido)
		(default indemne)
	)
)