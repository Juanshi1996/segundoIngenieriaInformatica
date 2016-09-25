(deftemplate puente-aereo
	(slot origen
		(type SYMBOL)
	)
	(multislot destinos
		(type SYMBOL)
	)
)
(deffacts grafo
	(puente-aereo
		(origen Lisboa)
		(destinos Paris Madrid)
	)
	(puente-aereo
		(origen Madrid)
	)
	(puente-aereo
		(origen Roma)
		(destinos Lisboa Madrid Frankfurt)
	)
	(puente-aereo
		(origen Paris)
		(destinos Roma)
	)
	(puente-aereo
		(origen Estocolmo)
		(destinos Paris)
	)
	(puente-aereo
		(origen Frankfurt)
		(destinos Roma Estocolmo)
	)
)