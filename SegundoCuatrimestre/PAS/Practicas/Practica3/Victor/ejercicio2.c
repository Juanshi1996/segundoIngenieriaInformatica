#include <stdlib.h>
#include <grp.h>
#include <getopt.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#define false  0
#define true   1
#define error -1
#define equal ==
#define and   &&
#define or    ||

static struct option long_options[] = {
  {"help",        no_argument,  0,  'h'},
  {"group", required_argument,  0,  'g'},
  {"english",     no_argument,  0,  'e'},
  {"spanish",     no_argument,  0,  's'},
  {0,                       0,  0,    0}
};

int main(int argc, char *argv[]) {
  int            character;
  int            hFlag        = false;
  char          *gValue       =  NULL;
  int            eFlag        = false;
  int            sFlag        = false;
  int            option_index = false;
  int            unknown      = false;
                 opterr       = false;
  struct group  *gr;

  while((character = getopt_long(argc, argv, "hg:es", long_options, &option_index)) != error) {
    switch(character) {
      case 'h': {
        hFlag     =  true;
        character = error;
        break;
      }
      case 'g': {
        gValue = optarg;
        break;
      }
      case 'e': {
        if(sFlag equal true) {
          character = error;
        }
        eFlag = true;
        break;
      }
      case 's': {
        if(eFlag equal true) {
          character = error;
        }
        sFlag = true;
        break;
      }
      case '?': {
        if(optopt equal 'g') {
          character = error;
        } else if(isprint(optopt)) {
          unknown   = optopt;
          hFlag     = true;
          character =  error;
        }
        break;
      }
      default: {
        abort();
      }
    }
  }
  if(eFlag equal false and sFlag equal false) {
    char *language = getenv("LANG");
    if(language[0] equal 'e' and language[1] equal 'n') {
      eFlag = true;
    }
    else if(language[0] equal 'e' and language[1] equal 's') {
      sFlag = true;
    }
  }
  if(hFlag or (eFlag and sFlag)) {
    if(eFlag) {
      if(unknown != false) {
        printf("Unknown option '%c'.\n", unknown);
      }
      printf("Use of the program: ejercicio2 [options]\n");
      printf("Options:\n");
      printf("-h, --help              Show this help\n");
      printf("-g, --group=GROUP       Group to analize\n");
      printf("-e, --english           Messages in English\n");
      printf("-s, --spanish           Messages in Spanish\n");
    }
    if(sFlag) {
      if(unknown != false) {
        printf("Opción desconocida '%c'.\n", unknown);
      }
      printf("Uso del programa: ejercicio2 [opciones]\n");
      printf("Opciones:\n");
      printf("-h, --help              Imprimir esta ayuda\n");
      printf("-g, --group=GRUPO       Grupo a analizar\n");
      printf("-e, --english           Mensajes en inglés\n");
      printf("-s, --spanish           Mensajes en castellano\n");
    }
    if(unknown != false) {
      exit(EXIT_FAILURE);
    } else {
      exit(EXIT_SUCCESS);
    }
  }
  if(gValue equal NULL) {
    gValue = getlogin();
    if(eFlag) {
      printf("Getting the primary group of the user %s...\n", gValue);
    } else if(sFlag) {
      printf("Obteniendo el grupo primario del usuario %s...\n", gValue);
    }
  }
  if((gr = getgrnam(gValue)) equal NULL) {
    if(sFlag equal true) {
      fprintf(stderr, "No ha sido posible obtener la información del usuario.\n");
    }
    else if(eFlag equal true) {
      fprintf(stderr, "Get of user information failed.\n");
    }
    exit(EXIT_FAILURE);
  }
  if(sFlag equal true){
    printf("Identificador del grupo: %i\n", gr->gr_gid);
    printf("Nombre del grupo: %s\n", gr->gr_name);
  }
  else if(eFlag equal true){
    printf("Group Identifier: %i\n", gr->gr_gid);
    printf("Group Name: %s\n", gr->gr_name);
  }
  exit(EXIT_SUCCESS);
}
