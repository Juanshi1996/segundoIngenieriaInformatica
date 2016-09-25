#!/bin/bash
#===============================================================================
#
#         FILE: ejercicio2.sh
#
#        USAGE: ejercicio2.sh directory
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
#      CREATED: 11.03.2015 - 17:16:35
#     REVISION:
#
#===============================================================================

#==== FUNCTION =================================================================
#         NAME: list
#  DESCRIPTION:
#  PARAMETER 1:
#  PARAMETER 2:
#===============================================================================

function list() {
 echo "   <ul>" >> $(basename ${1}).html
 for x in $(find ${2} -maxdepth 1); do
   if [ $x != ${2} ]; then
     if [ -d $x ]; then
     echo "     <li><strong>$dir</strong></li>" >> $(basename ${1}).html
     list ${1} $x
     echo "   </ul>" >> $(basename ${1}).html
     else
     echo "     <li>$dir</li>" >> $(basename ${1}).html
     fi
   fi
 done
}   # ---------- end of function list ----------

if [ $# -eq 1 ] && [ -d ${1} ]; then
  echo "Generando el listado de la carpeta $(cd $1 && pwd && cd ..) sobre el \
fichero $(basename ${1}).html..."
  echo "<html>" > $(basename ${1}).html
  echo "  <head>" >> $(basename ${1}).html
  echo "    <title>Listado del directorio ${1}/</title>" >> \
$(basename ${1}).html
  echo "  </head>" >> $(basename ${1}).html
  echo "  <body>" >> $(basename ${1}).html
  echo "    <style type=\"text/css\">" >> $(basename ${1}).html
  echo "      body {font-family: sans-serif;}" >> $(basename ${1}).html
  echo "    </style>" >> $(basename ${1}).html
  echo "    <h1>Listado del directorio ./carpetaPrueba/</h1>" >> \
$(basename ${1}).html
  list ${1} ${1}
  echo "   <ul>" >> $(basename ${1}).html
  echo "  </body>" >> $(basename ${1}).html
  echo "</html>" >> $(basename ${1}).html
  echo -e "\E[32m¡Terminado!\e[0m"
elif [ $# -ne 1 ]; then
  echo -n -e "\E[31m\nSintaxis incorrecta: ./ejercicio2.sh \
<rutaDirectorio>\n\n\e[0m"
else
  echo -n -e "\E[31m\nEl argumento no es un directorio\n\n\e[0m"
fi
