#!/bin/bash
#===============================================================================
#
#         FILE: ejercicio5.sh
#
#        USAGE: ejercicio5.sh directory [string]
#
#  DESCRIPTION: Compress those files whose age is greater than 20 seconds of a
#               directory on a .tar.gz file with the same name of the directory
#               or as the second argument if it is given.
#
#      OPTIONS: see function 'usage' below
# REQUIREMENTS: ---
#         BUGS: ---
#        NOTES: ---
#       AUTHOR: Víctor Monserrat Villatoro, victor1995mv@gmail.com
#      COMPANY: ---
#      VERSION: 1.0
#      CREATED: 14.03.2015 - 18:43:19
#     REVISION:
#
#===============================================================================

if [ $# -lt 1 ] || [ $# -gt 2 ]; then
  echo -n -e "\E[31m\nSintaxis incorrecta: ./ejercicio5.sh <directorio> \
<cadena>\n\n\e[0m"
elif [ ! -d ${1} ]; then
  echo -n -e "\E[31m\nEl primer argumento no es un fichero\n\n\e[0m"
else
  echo -e "\E[33mRuta;\E[32mTamaño;\E[36mReferenciasInodo;\E[34mPermisos;\
\E[35mEjecutable\e[0m"
  if [ $# == 1 ]; then
    files=$(find "$1" -type f | xargs ls -li | sort -n -k 6) #Lista los ficheros
                                                             #con la opción -li
                                                             #ordenados por la 6
                                                             #columna
  else
    files=$(find "$1" -type f -name "*$2*" | xargs ls -li | sort -n -k 6)
                                                             #Lista los ficheros
                                                             #en cuyo nombre
                                                             #está contenido el
                                                             #segundo argumetno
                                                             #con la opción -li
                                                             #ordenados por la 6
                                                             #columna
  fi
  for x in $(echo "$files" | awk -F ' ' '{ print $10 }'); do #Coloca en filas de
                                                             #10 columnas con el
                                                             #carácter ' ' de
                                                             #separación
    if [ -x "$x" ]; then
      echo -e "\E[33m$x;\E[32m$(stat -c %s "$x");\E[36m$(ls -l "$x" | cut -f 2 \
-d ' ')\E[34m$(stat -c %A "$x");\E[35m1\e[0m"
    else
      echo -e "\E[33m$x;\E[32m$(stat -c %s "$x");\E[36m$(ls -l "$x" | cut -f 2 \
-d ' ');\E[34m$(stat -c %A "$x");\E[35m0\e[0m"
    fi
  done
fi
