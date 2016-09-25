#!/bin/bash
df | sed -r -e 's/([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*/El dispositivo de bloques \1, montado en \6, tiene usados \3 bloques de un total de \2 (porcentaje de \5)./' | sed -n -e '1!p'
