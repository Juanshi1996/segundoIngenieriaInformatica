#!/bin/bash
#===============================================================================
#
#         FILE: ejercicio6.sh
#
#        USAGE: ejercicio6.sh [directory1] [directory2] ... [directoryN]
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
#      CREATED: 15.03.2015 - 10:20:43
#     REVISION:
#
#===============================================================================

start=$(date +%s)
directories=0
executables=0
libraries=0
sources=0
headers=0

copy() {
  copied=0
  if [ -e "${2}" ];then
    read -p "El fichero ${2} existe. ¿Desea sobrescribirlo? (S/N): " overwrite
    if [ "$overwrite" == "S" ]; then
      cp "${1}" "${3}"
      copied=1
    fi
  else
    cp "${1}" "${3}"
    copied=1
  fi
  if [ $copied -eq 1 ]; then
    echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): Fichero ${1} copiado a ${2} \
" >> ejercicio6.log
    if [ "${4}" -eq "1" ]; then
      let "executables=executables+1"
    elif [ "$4" -eq "2" ]; then
      let "libraries=libraries+1"
    elif [ "$4" -eq "3" ]; then
      let "sources=sources+1"
    elif [ "$4" -eq "4" ]; then
      let "headers=headers+1"
    fi
  fi
}

if [ $# -ne 0 ]; then
  echo -e -n "\E[36mIntroduzca el directorio donde copiar los ejecutables: \
\e[0m"
  if ! read -t5 bin; then
    bin="$HOME/bin"
    echo -e "\E[33m$bin (por defecto tras 5 segundos sin respuesta)\e[0m"
  fi
  if [ -d $bin ]; then
    echo "El directorio $bin ya existía"
    echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): El directorio $bin ya existía" \
>> ejercicio6.log
  else
    mkdir "$bin" 2>> /dev/null
    if [ "$?" == "0" ]; then
      echo "Directorio $bin creado"
      echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): Directorio $bin creado" \
>> ejercicio6.log
    else
      echo "No se pudo crear el directorio $bin"
      echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): No se pudo crear el \
directorio $bin" >> ejercicio6.log
    fi
  fi
  echo -e -n "\E[36mIntroduzca el directorio donde copiar las librerías: \e[0m"
  if ! read -t5 lib; then
    lib="$HOME/lib"
    echo -e "\E[33m$lib (por defecto tras 5 segundos sin respuesta)\e[0m"
  fi
  if [ -d $lib ]; then
    echo "El directorio $lib ya existía"
    echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): El directorio $lib ya existía" \
>> ejercicio6.log
  else
    mkdir "$lib" 2>> /dev/null
    if [ "$?" == "0" ]; then
      echo "Directorio $lib creado"
      echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): Directorio $lib creado" \
>> ejercicio6.log
    else
      echo "No se pudo crear el directorio $lib"
      echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): No se pudo crear el \
directorio $lib" >> ejercicio6.log
    fi
  fi
  echo -e -n "\E[36mIntroduzca el directorio donde copiar los ficheros de \
fuente: \e[0m"
  if ! read -t5 src; then
    src="$HOME/src"
    echo -e "\E[33m$src (por defecto tras 5 segundos sin respuesta)\e[0m"
  fi
  if [ -d $src ]; then
    echo "El directorio $src ya existía"
    echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): El directorio $src ya existía" \
>> ejercicio6.log
  else
    mkdir "$src" 2>> /dev/null
    if [ "$?" == "0" ]; then
      echo "Directorio $src creado"
      echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): Directorio $src creado" \
>> ejercicio6.log
    else
      echo "No se pudo crear el directorio $src"
      echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): No se pudo crear el \
directorio $src" >> ejercicio6.log
    fi
  fi
  echo -e -n "\E[36mIntroduzca el directorio donde copiar las cabeceras: \e[0m"
  if ! read -t5 include; then
    include="$HOME/include"
    echo -e "\E[33m$include (por defecto tras 5 segundos sin respuesta)\e[0m"
  fi
  if [ -d $include ]; then
    echo "El directorio $include ya existía"
    echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): El directorio $include ya \
existía" >> ejercicio6.log
  else
    mkdir "$include" 2>> /dev/null
    if [ "$?" == "0" ]; then
      echo "Directorio $include creado"
      echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): Directorio $include creado" \
>> ejercicio6.log
    else
      echo "No se pudo crear el directorio $include"
      echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): No se pudo crear el \
directorio $include" >> ejercicio6.log
    fi
  fi
  echo "Utilizando los ficheros:"
  echo "$bin para almacenar los ficheros ejecutables"
  echo "$lib para almacenar las librerías"
  echo "$src para almacenar los ficheros de código fuente"
  echo "$include para almacenar los ficheros de cabeceras"
  for x in "$@"; do
    echo "Procesando directorio $x..."
    let "directories=directories+1"
    for y in $(find "$x" -type f); do
      if [ -x "$y" ]; then
        copy "$y" "$bin/$(basename "$y")" "$bin" 1
      elif [[ "$(basename "$y")" == lib* ]]; then
        copy "$y" "$lib/$(basename "$y")" "$lib" 2
      elif [[ "$(basename "$y")" == *.c* ]]; then
        copy "$y" "$src/$(basename "$y")" "$src" 3
        gcc "$y" -o "$(echo "$bin/$(basename "$y")" | tr '.c' '.out')" \
2>> /dev/null
        if [ "$?" -eq "0" ]; then
          let "executables=executables+1"
          echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): Compilado el fichero \
$y con gcc" >> ejercicio6.log
        else
          echo "Error al compilar el fichero $y con gcc"
          echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): No se pudo compilar \
el fichero $y con gcc" >> ejercicio6.log
        fi
      elif [[ "$(basename "$y")" == *.cpp* ]]; then
        copy "$y" "$src/$(basename "$y")" "$src" 3
        g++ "$y" -o "$(echo "$bin/$(basename "$y")" | tr '.cpp' \
'.out')" 2>> /dev/null
        if [ "$?" -eq "0" ]; then
          let "executables=executables+1"
          echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): Compilado el fichero \
$y con g++" >> ejercicio6.log
        else
          echo "Error al compilar el fichero $y con g++"
          echo "$(date +"%Y-%m-%d"):$(date +"%H-%M-%S"): No se pudo compilar \
el fichero $y con g++" >> ejercicio6.log
        fi
      elif [[ "$(basename "$y")" == *.h* ]]; then
        copy "$y" "$include/$(basename "$y")" "$include" 4
      fi
    done
  done
  echo "Número de directorios procesados: $directories"
  echo "Número de ficheros ejecutables: $executables"
  echo "Número de librerías: $libraries"
  echo "Número de ficheros de código fuente $sources"
  echo "Número de ficheros de cabecera: $headers"
  finish=$(date +%s)
  echo "Tiempo necesario: $((finish - start))"
fi
