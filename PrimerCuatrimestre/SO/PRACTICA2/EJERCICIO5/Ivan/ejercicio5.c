#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void* cuentaLineas(void* nombreFichero){
  char* fichero = (char*) nombreFichero;
  char cadena[100];
  FILE* archivo;
  long cuenta = 0;
  archivo = fopen(fichero, "r");
  while(fgets(cadena, 100, archivo) != NULL){
    cuenta++;
  }
  fclose(archivo);
  pthread_exit((void*) cuenta);
}

int main(int argc, char** argv){
  if(argc < 2){
    printf("SINTAXIS: %s ARCHIVO1 ... ARCHIVON.\n", argv[0]);
    exit(-1);
  }
  int i, suma = 0;
  pthread_t hilos[argc-1];
  void* cuentas;
  for(i=0; i<argc-1; i++){
    pthread_create(hilos+i, NULL, (void*) cuentaLineas, (void*) argv[i+1]);
  }

  for(i=0; i<argc-1; i++){
    pthread_join(hilos[i], (void**) &cuentas);
    printf("HILO %d: Mi fichero tiene %d lineas.\n", (unsigned int) hilos, *((int*) cuentas));
    suma += *((int*) cuentas);
  }

  printf("HILO PRINCIPAL: La suma de las lineas de todos los archivos es %d.\n", suma);

}
