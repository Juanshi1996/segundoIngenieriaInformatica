#!/bin/bash
#===============================================================================
#
#         FILE: ejercicio1.sh
#
#        USAGE: ./ejercicio1.sh
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
#      CREATED: 24.03.2015 - 08:54:48
#     REVISION:
#
#===============================================================================

echo -n -e "\E[36m*******\E[0m"
echo -n -e "\E[36m\n1) Líneas con la duración de las películas:\n\E[0m"
cat peliculas.txt | grep -E '[0-9]+ min\.'
echo -n -e "\E[36m*******\E[0m"
echo -n -e "\E[36m\n2) Líneas con el país de las películas:\n\E[0m"
cat peliculas.txt | grep -E '\[.+\]'
echo -n -e "\E[36m*******\E[0m"
echo -n -e "\E[36m\n3) Solo el país de las películas:\n\E[0m"
cat peliculas.txt | grep -E -o '\[.+\]' | grep -E -o '[a-z A-Z]+'
echo -n -e "\E[36m*******\E[0m"
echo -n -e "\E[36m\n4) Hay \E[0m$(cat peliculas.txt | grep -E -c '\(2014\)') "
echo -n -e "\E[36mpelículas del 2014 y \E[0m$(cat peliculas.txt | \
grep -E -c '\(2015\)') \E[36m"
echo -n -e "películas del 2015.\n\E[0m"
echo -n -e "\E[36m*******\E[0m"
echo -n -e "\E[36m\n5) Eliminar líneas vacías:\n\E[0m"
cat peliculas.txt | grep -E -v '^$'
echo -n -e "\E[36m*******\E[0m"
echo -n -e "\E[36m\n6) Líneas que empiezan por la letra C (con o sin espacios "
echo -n -e "antes):\n\E[0m"
cat peliculas.txt | grep -E '^ *C'
echo -n -e "\E[36m*******\E[0m"
echo -n -e "\E[36m\n7) Líneas que contienen d, l o t, una vocal y la misma "
echo -n -e "letra:\n\E[0m"
cat peliculas.txt | grep -E '([dlt])[aeiou]\1'
echo -n -e "\E[36m*******\E[0m"
echo -n -e "\E[36m\n8) Líneas que contienen ocho aes o más:\n\E[0m"
cat peliculas.txt | grep -E '([aA].*){8,}'
echo -n -e "\E[36m*******\E[0m"
echo -n -e "\E[36m\n9) Líneas que terminan con tres puntos y no "
echo -n -e "empiezan por espacio:\n\E[0m"
cat peliculas.txt | grep -E -v '^ ' | grep -E '\.\.\.$'
echo -n -e "\E[36m*******\E[0m"
echo -n -e "\E[36m\n10) Mostrar entre comillas las vocales con tilde:\n\E[0m"
cat peliculas.txt | sed -r -e 's/([ÁÉÍÓÚáéíóú])/"\1"/g'
