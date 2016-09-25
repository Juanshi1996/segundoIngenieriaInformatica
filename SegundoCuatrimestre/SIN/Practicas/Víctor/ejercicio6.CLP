(deftemplate coche
	(slot unidades
		(type INTEGER)
	)
	(slot modelo
		(type SYMBOL)
	)
	(slot combustible
		(type SYMBOL)
		(allowed-symbols diesel gasolina)
	)
	(slot motor
		(type INTEGER)
	)
	(slot puertas
		(type INTEGER)
		(range 3 5)
	)
	(slot color
		(type SYMBOL)
	)
)
(deftemplate venta
	(slot vendedor
		(type STRING)
	)
	(slot modelo
		(type SYMBOL)
	)
	(slot fecha
		(type SYMBOL)
	)
	(slot cliente
		(type STRING)
	)
)
(deffacts coches
	(coche
		(unidades 1)
		(modelo clio)
		(combustible gasolina)
		(motor 1600)
		(puertas 3)
		(color azul)
	)
	(coche
		(unidades 1)
		(modelo clio)
		(combustible diesel)
		(motor 1800)
		(puertas 5)
		(color blanco)
	)
	(coche
		(unidades 1)
		(modelo megane)
		(combustible diesel)
		(motor 1800)
		(puertas 5)
		(color dorado)
	)
	(coche
		(unidades 2)
		(modelo megane)
		(combustible gasolina)
		(motor 1600)
		(puertas 5)
		(color gris)
	)
	(coche
		(unidades 1)
		(modelo laguna)
		(combustible gasolina)
		(motor 2000)
		(puertas 5)
		(color negro)
	)
)
(deffacts ventas
	(venta
		(vendedor "Juan Perez")
		(modelo megane)
		(fecha 10-10-2003)
		(cliente "Esteban Losada")
	)
	(venta
		(vendedor "Ana Ballester")
		(modelo laguna)
		(fecha 13-10-2003)
		(cliente "Juan Cano")
	)
)