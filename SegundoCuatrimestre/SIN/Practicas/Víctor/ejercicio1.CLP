(deftemplate persona
	(slot nombre
		(type STRING)
	)
	(slot apellido
		(type STRING)
	)
	(slot color-ojos
		(type SYMBOL)
		(default marron)
	)
	(slot altura
		(type FLOAT)
		(default 180.0)
	)
	(slot edad
		(type INTEGER)
		(default 18)
	)
)