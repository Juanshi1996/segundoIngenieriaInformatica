#!/bin/bash
#===============================================================================
#
#         FILE: ejercicio4.sh
#
#        USAGE: ejercicio4.sh file pattern
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
#      CREATED: 13.03.2015 - 19:11:26
#     REVISION:
#
#===============================================================================

if [ $# -ne 2 ]; then
  echo -n -e "\E[31m\nSintaxis incorrecta: ./ejercicio4.sh <fichero> \
<patrón>\n\n\e[0m"
elif [ ! -f ${1} ]; then
  echo -n -e "\E[31m\nEl primer argumento no es un fichero\n\n\e[0m"
else
  i=1
  for x in $(grep -n ${2} ${1} | cut -f1 -d ':'); do
    echo "---------------------------"
    echo -e "Emparejamiento número: \E[32m$i\e[0m"
    if [ $(wc -l $1 | cut -f 1 -d ' ') -lt $((x+1)) ]; then
      echo "$(head -n $((x+1)) $1 | tail -n 2)"
    else
      echo "$(head -n $((x+1)) $1 | tail -n 3)"
    fi
    ((i++))
  done
fi
