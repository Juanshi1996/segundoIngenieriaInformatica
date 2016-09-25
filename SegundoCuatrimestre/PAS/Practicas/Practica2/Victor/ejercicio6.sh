#!/bin/bash
#===============================================================================
#
#         FILE: ejercicio6.sh
#
#        USAGE: ./ejercicio6.sh string
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
#      CREATED: 05.03.2015 - 09:49:59
#     REVISION:
#
#===============================================================================

if [ $# -eq 1 ]; then
  cat /etc/passwd | grep $1 | sed 's/::/: :/' > tmp
  while read x; do
    echo -n "=========="
    echo -e -n $x | sed -r -e 's/^([^:]+)[:]+([^:]+)[:]+([^:]+)[:]+([^:]+)[:]+([^:]+)[:]+([^:]+)[:]+([^:]+).*$/\
Logname: \1\
->UID: \3\
->Grupo: \4\
->GID: \4\
->gecos: \5\
->Home: \6\
->Shell por defecto: \7\
->Logueado: /'
  while read user; do
    if [ $(echo -e $x | sed -r -e 's/:.*$//') == $user ]; then
      echo 1
    else
      echo 0
    fi
  done < <(who | sed -r -e 's/ .*$//' | uniq)
done < tmp
rm tmp
else
  echo "Error de sintaxis: ./ejercicio6.sh cadena"
fi
