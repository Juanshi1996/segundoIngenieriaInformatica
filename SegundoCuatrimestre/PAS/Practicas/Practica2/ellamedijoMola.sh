echo "Ella me dijo mola" | grep --color 'ola'
echo "Ella me dijo mola" | grep --color '.la' # '.' lo interpreta como cualquier cosa.
#sed sólamente modifica una vez por línea. Para que no haga eso, mirar la opción -g
echo "Octubre Octubre" | grep --color 'O'
echo "Octubre Octubre" | grep --color '^O'
echo "Octubre Octubre" | grep --color 'e'
echo "Octubre Octubre" | grep --color 'e$'
echo "Octubre Octubre" | grep --color 'e$'
echo "Holaaaaaaaaaaaaaaaaaaaaaaaaaaaaaas" | grep --color 'ola*s'
echo "Hols" | grep --color 'ola*s'
echo "Olas emocionantes" | grep --color 'a.*e'
echo "holaaaaaaaaaaaaaa" | grep --color -o 'a'
echo "holaaaaaaaaaa" | grep --color 'a*'
echo "holaaaaaaaaaaaa" | grep -o --color 'a*'
echo "holaaaaaaaaaaaaa" | grep -o -E --color 'a{0,1}a'
#echo "holaaaaaaaaaaaaa" | grep -o -E 'a{0,}'
echo "holaaaaaaaaaaaaa" | grep -o -E --color '(hola|ola)'


df | sed -r -e 's/([^ ]*)[ ]*.*/El dispositivo de bloques \1.../'
