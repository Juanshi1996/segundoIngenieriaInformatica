#!/bin/bash
#===============================================================================
#
#         FILE: ejercicio3.sh
#
#        USAGE: ./ejercicio3.sh
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
#      CREATED: 27.03.2015 - 12:10:28
#     REVISION:
#
#===============================================================================

echo "*******"
echo "Lista de usuarios conectados, junto con el número de horas, minutos y segundos que llevan conectados:"
while read x; do
  t=$(echo -e $x | sed -r -e 's/^([^ ]+)[ ]([^ ]+)[ ]//' | sed -r -e 's/ \(.*$//')
  y=$(echo -e $t | sed -r -e 's/-.*$//')
  m=$(echo -e $t | sed -r -e 's/.....//' | sed -r -e 's/-.*$//')
  d=$(echo -e $t | sed -r -e 's/........//' | sed -r -e 's/ .*$//')
  h=$(echo -e $t | sed -r -e 's/^.* //' | sed -r -e 's/:..//')
  mnt=$(echo -e $t | sed -r -e 's/^.*://')
  date=$(echo -e $t | sed -r -e 's/ .*$//')
  x=$(echo $x | sed -e 's/ .*//')
  if [[ $printed != $x ]]; then
    cMnt=$(date +%M)
    cH=$(date +%H)
    cY=$(date +%Y)
    cM=$(date +%m)
    cD=$(date +%d)
    if [[ $cY -gt $y ]]; then
      cY=$(($cY-$y))
      cH=$(($cH+8766*$cY))
    fi
    if [[ $cM -gt $m ]]; then
     cM=$(($cM-$m))
     cH=$(($cH+730*$cM))
     cM=0
    fi
    if [[ $cD -gt $d ]]; then
     cD=$(($cD-$d))
     cH=$(($cH+24*$cD))
     cD=0
     echo $cY:$cM:$cD:$cH
    fi
    if [[ $cH -gt $h ]]; then
      cH=$(($cH-$h))
    else
      cH=$(($h-$cH))
    fi
    if [[ $cMnt -gt $mnt ]]; then
      cMnt=$(($cMnt-$mnt))
    else
      cH=$(($cH-1))
      cMnt=$((60-$mnt+$cMnt))
      if [ $cMnt -eq 60 ]; then
        cMnt=0
        cH=$(($cH-1))
      fi
    fi
    echo "El usuario $x lleva $cH horas, $cMnt minutos $(date +%S) segundos conectado"
  fi
  printed=$x
done < <(who)
