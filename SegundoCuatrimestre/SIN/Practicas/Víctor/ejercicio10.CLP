(deftemplate alumno
	(slot apellidos
		(type STRING)
		(default ?NONE)
	)
	(slot nombre
		(type STRING)
		(default ?NONE)
	)
	(slot nota1
		(type FLOAT)
		(range 0.0 10.0)
	)
	(slot nota2
		(type FLOAT)
		(range 0.0 10.0)
	)
	(slot media
		(type FLOAT)
		(range 0.0 10.0)
	)
)
(deftemplate grupo
	(multislot miembros
		(type STRING)
		(cardinality 1 4)
	)
	(slot nota
		(type FLOAT)
		(range 0.0 10.0)
	)
)