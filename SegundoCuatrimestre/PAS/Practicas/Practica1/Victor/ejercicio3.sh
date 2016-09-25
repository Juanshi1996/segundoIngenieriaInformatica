#!/bin/bash
#===============================================================================
#
#         FILE: ejercicio3.sh
#
#        USAGE: ejercicio3.sh
#
#  DESCRIPTION:
#
#      OPTIONS: ---
# REQUIREMENTS: ---
#         BUGS: ---
#        NOTES: ---
#       AUTHOR: Víctor Monserrat Villatoro, victor1995mv@gmail.com
#      COMPANY: ---
#      VERSION: 1.0
#      CREATED: 12.03.2015 - 21:45:54
#     REVISION:
#
#===============================================================================

echo -e "El número de archivos en la carpeta actual es \E[32m$(find . \
-maxdepth 1 -type f | wc -l)\e[0m"
echo "$(who | cut -f 1 -d ' ' | sort | uniq)"
echo -e -n "\E[36m¿Qué carácter quieres contar? \e[0m"
if ! read -t5 caracter; then
  caracter='a'
  echo -e "\E[33ma (por defecto tras 5 segundos sin respuesta)\e[0m"
fi
echo -e "El carácter \E[32m$caracter\e[0m aparece \E[32m$(find . -name \
"*$caracter*" | wc -l)\e[0m veces en nombres de ficheros o carpetas contenidos \
en la carpeta actual"
