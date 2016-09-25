#!/bin/bash
#===============================================================================
#
#         FILE: ejercicio1.sh
#
#        USAGE: ejercicio1.sh directory [fileName.tar.gz]
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
#      CREATED: 10.03.2015 - 12:33:11
#     REVISION:
#
#===============================================================================

if [ $# -lt 1 ] || [ $# -gt 2 ]; then
  echo -n -e "\E[31m\nSintaxis incorrecta: ./ejercicio1.sh <rutaDirectorio> \
[<nombreArchivo>]\n\n\e[0m"                       #Error de sintaxis
elif [ -d ${1} ] && [ $# -eq 1 ]; then
  find ${1} -not -newermt '-20 seconds' -type f -printf '%p\0' | tar --null -v \
  -uf ${1}.tar.gz -T -
  echo -e "\E[32mArchivo ${1}.tar.gz creado correctamente\e[0m"
elif [ -d ${1} ] && [ $# -eq 2 ]; then
  find ${1} -not -newermt '-20 seconds' -type f -printf '%p\0' | tar --null -v \
  -uf ${2}.tar.gz -T -
  echo -e "\E[32mArchivo ${2}.tar.gz creado correctamente\e[0m"
else
  echo -n -e "\E[31m\nEl primer argumento no es un directorio\n\n\e[0m"
                                                  #El primer argumento no es un
                                                  #directorio
fi
