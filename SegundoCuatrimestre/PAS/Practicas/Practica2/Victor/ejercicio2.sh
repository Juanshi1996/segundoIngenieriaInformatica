#!/bin/bash
#===============================================================================
#
#         FILE: ejercicio2.sh
#
#        USAGE: ./ejercicio2.sh
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
#      CREATED: 25.03.2015 - 10:25:33
#     REVISION:
#
#===============================================================================

cat peliculas.txt | sed -e 's/\(.\{50,50\}\).*/\1.../' | sed -e 's/(\(.*\))/\1,/' | sed -e 's/\[\(.*\)\]/\1/'
