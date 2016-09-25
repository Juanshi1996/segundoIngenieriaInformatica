#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* cuentaLineas(void* fichero){
  FILE* file;
  char line[100];
  long i=0;

  if((file=fopen((char*)fichero, "r"))==NULL){
    printf("\nERROR de apertura: El fichero \"%s\" no existe o ha habido un problema al abrirlo.\n", (char*)fichero);
    pthread_exit(NULL);
  }
  while(fgets(line, 100, file)!=NULL){
    i++;
  }
  fclose(file);
  pthread_exit((void*)i);
}

int main(int argc, char* argv[]){
  if(argc < 2){
    printf("\nERROR de sintaxis: ./Ejercicio5 <fichero1> <fichero2> ... <ficheroN>\n\n");
    exit(EXIT_FAILURE);
  }

  int i;
  pthread_t hilos[argc-1];
  long lineas, sumatorioLineas=0;

  for(i=0; i<argc-1; i++){
    pthread_create(&hilos[i], NULL, cuentaLineas, (void*)argv[i+1]);
  }
  for(i=0; i<argc-1; i++){
    pthread_join(hilos[i], (void**)&lineas);
    sumatorioLineas = sumatorioLineas+lineas;
  }
  printf("\nLa suma total de líneas de los ficheros introducidos es: %ld.\n\n", sumatorioLineas);
}
