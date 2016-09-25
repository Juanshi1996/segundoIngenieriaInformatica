(deftemplate libro
	(multislot autores
		(type STRING)
	)
	(slot titulo
		(type STRING)
	)
	(slot editorial
		(type STRING)
	)
	(slot publicacion
		(type INTEGER)
		(range 1 2015)
	)
)
(deffacts bibliografia
	(libro
		(autores "Mira, J." "Delgado A. E." "Boticario, J. G." "Díez, F. J.")
		(titulo "Aspectos Básicos de la Inteligencia Artificial")
		(editorial "Editorial Sanz y Torres")
		(publicacion 1995)
	)
	(libro
		(autores "Galán, S. F." "Boticario, J. G." "Mira, J.")
		(titulo "Problemas Resueltos de Inteligencia Artificial Aplicada: Búsqueda y Representación")
		(editorial "Editorial Addison-Wesley Iberoamericana S. A.")
		(publicacion 1998)
	)
	(libro
		(autores "Rich, E." "Knight, K.")
		(titulo "Inteligencia Artificial")
		(editorial "2ª edición. McGraw-Hill Interamericana.")
		(publicacion 1994)
	)
)