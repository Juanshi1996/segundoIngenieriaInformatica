#!/bin/bash
find /etc/rc?.d -name "S*" | while read f
do
  dir=$(dirname $f)
  file=$(basename $f)
  echo -e "Directorio: $dir -> Fichero: $file\n"
done | more
