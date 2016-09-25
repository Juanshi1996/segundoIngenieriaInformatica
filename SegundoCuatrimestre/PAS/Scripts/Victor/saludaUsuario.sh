#!/bin/bash
echo -n "Introduzca su nombre de usuario: "
read name
if [ "$name" == "$USER" ]
  then
  echo "Bienvenido \"$name\""
else
  echo "Eso es mentira!"
fi
