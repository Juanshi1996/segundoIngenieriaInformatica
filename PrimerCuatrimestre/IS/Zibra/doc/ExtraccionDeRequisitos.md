#Extracción de requisitos
###PARTES INTERESADAS:

1. __Dentista__
2. __Pacientes__
3. __Administrativo/a__ (será el actor principal)

###DATOS:

- Almacenaremos información del paciente: DNI, nombre y apellidos, teléfonos, correo electrónico, dirección/es postal/es, anotaciones, favorito, más usados, redes sociales (nombre + URL ó usuario)

##REQUISITOS

###FUNCIONALES:

- Realizar un programa informático para gestionar una agenda de una clínica dental
- Buscar un contacto en la agenda
- Ordenar los contactos de la agenda alfabéticamente por sus apellidos
- Insertar, modificar y borrar contactos de la agenda
- Marcar un contacto como favorito
- Hacer copias de seguridad de nuestra agenda (opción de guardar y cargar copia de seguridad)
- Imprimir la agenda (esto se realizará por orden alfabético con respecto a los apellidos)

###NO FUNCIONALES:

- El lenguaje de programación a utilizar será C++
- La interfaz será en modo texto
- Se delegará la protección a la propia seguridad del S.O.
- Se ejecutará en entornos Linux
- Deberá estar preparado para albergar 200 contactos
- El almacenamiento será en ficheros de texto binario
- No es necesaria la relación entre contactos
- Las copias de seguridad se realizarán en un fichero binario
- La impresión de la agenda será en formato HTML

###PRIORIDADES:

Las funcionalidades necesarias ordenadas por prioridad son las siguientes:

1. Búsqueda por apellido, por ello se sustituye el formato en papel.
2. Realizar una copia de seguridad de los contactos.
3. Insertar un nuevo contacto en la agenda.
