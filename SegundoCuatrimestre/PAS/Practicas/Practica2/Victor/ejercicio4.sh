#!/bin/bash
#===============================================================================
#
#         FILE: ejercicio4.sh
#
#        USAGE: ./ejercicio4.sh file integer
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
#      CREATED: 28.03.2015 - 20:28:33
#     REVISION:
#
#===============================================================================
if [ $# -eq 2 ]; then
  while read ip; do
    t=$(ping -c 1 -W $2 $ip)
    if [ ! $? -ne 0 ]; then
      t=$(echo -e "$t" | cut -d " " -f 7 | sort -h | tail -1 | tr -d "time=")
      echo "La IP $ip respondió en $t milisegundos"
    else
      echo "La IP $ip no respondió tras $2 segundos"
    fi
  done < $1 | sort -k 6
else
  echo "Error de sintaxis: ./ejercicio4.sh fichero entero"
fi
