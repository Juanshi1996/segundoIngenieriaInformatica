#!/bin/bash
#===============================================================================
#
#         FILE: ejercicio5.sh
#
#        USAGE: ./ejercicio5.sh
#
#  DESCRIPTION:
#
#      OPTIONS: see function 'usage' below
# REQUIREMENTS: ---
#         BUGS: ---
#        NOTES: ---
#       AUTHOR: Víctor Monserrat Villatoro, victor1995mv@gmail.com
#      COMPANY: ---
#      VERSION: 1.0
#      CREATED: 02.03.2015 - 08:54:48
#     REVISION:
#
#===============================================================================

echo -e "Descargando la web \E[34mhttps://twitter.com/GeoPortalMityc/...\e[0m"
wget https://twitter.com/GeoPortalMityc -O GeoPortalMityc 2> /dev/null
if [ $? -eq 0 ]; then
  echo -e "Listado de precios de GeoPortalMityc ordenados por precio del Combustible:"
  cat "GeoPortalMityc" | grep "EcoPrecio" | sed -r -e 's/^ .*EcoPrecio //' | sed -r -e 's/<\/p>//' | sed -r -e 's/&lt;//' | sed -r -e 's/&lt;//' | sort -k 5 > tmp
  while read x; do
    echo -n $x | sed -r -e 's/^.*es/Precio: \"/' | sed -r -e 's/€.*/\", /'
    echo -n $x | sed -r -e 's/ es.*$/, /' | sed -r -e 's/^.* A |^.* 95 /Ciudad: \"/'
    echo -n $x | sed -r -e 's/^([^ ]+)[ ]+([^ ]+)[ ]+([^ ]+).*$/Combustible: \"\1 \2\", /'
    echo $x | sed -r -e 's/^.*en/Dirección: \"/'
  done < "tmp"
  rm tmp GeoPortalMityc
else
  echo -e "\E[31mError de conexión.\e[0m"
fi
