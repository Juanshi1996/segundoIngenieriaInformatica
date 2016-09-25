#include <unistd.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <grp.h>
#include <ctype.h>

#define true  1
#define false 0
#define and   &&
#define or    ||
#define equal ==

int main(int argc, char *argv[]) {
  int            character;
  char          *nValue     = NULL;
  int            uValue     = 0;
  int            gFlag      = 0;
  int            eFlag      = 0;
  int            sFlag      = 0;
  struct passwd *pw;

  opterr = false;
  while((character = getopt(argc, argv, "n:u:ges")) != -1) {
    switch(character) {
      case 'n': {
        if(uValue != false) {
          fprintf(stderr, "UID and user name should not be used at the same time\n");
          exit(EXIT_FAILURE);
        }
        nValue = optarg;
        break;
      }
      case 'u': {
        if(nValue != NULL) {
          fprintf(stderr, "UID and user name should not be used at the same time\n");
          exit(EXIT_FAILURE);
        }
        uValue = atoi(optarg);
        break;
      }
      case 'g': {
        gFlag = true;
        break;
      }
      case 'e': {
        if(sFlag equal true) {
          fprintf(stderr, "No se puede activar dos idiomas al mismo tiempo\n");
          fprintf(stderr, "Two languages cannot be used at same time\n");
          exit(EXIT_FAILURE);
        }
        eFlag = true;
        break;
      }
      case 's': {
        if(eFlag equal true) {
          fprintf(stderr, "Two languages cannot be used at same time\n");
          fprintf(stderr, "No se puede activar dos idiomas al mismo tiempo\n");
          exit(EXIT_FAILURE);
        }
        sFlag = true;
        break;
      }
      case '?': {
        if(optopt equal 'n' or optopt equal 'u') {
          fprintf(stderr, "Option -%c requires an argument\n", optopt);
        } else if(isprint(optopt)) {
          fprintf(stderr, "Option -%c not valid\n", optopt);
        } else {
          fprintf(stderr, "Unknow %x character\n", optopt);
        }
        exit(EXIT_FAILURE);
      }
      default: {
        abort();
      }
    }
  }
  if(nValue != NULL) {
    if((pw = getpwnam(nValue)) equal NULL) {
      fprintf(stderr, "Get of user %s information failed\n", nValue);
      exit(EXIT_FAILURE);
    }
  } else if(uValue != false) {
    if((pw = getpwuid(uValue)) equal NULL) {
      fprintf(stderr, "Get of user %i information failed\n", uValue);
      exit(EXIT_FAILURE);
    }
  } else {
    if((pw = getpwnam(getlogin())) equal NULL){
      fprintf(stderr, "Get of user information failed\n");
      exit(EXIT_FAILURE);
    }
  }
  if(!eFlag and !sFlag) {
    if(strcmp(getenv("LANG"), "en_EN") equal 0) {
      eFlag = true;
    } else if(strcmp(getenv("LANG"), "es_ES.UTF-8") equal 0) {
      sFlag = true;
    }
  }
  if(eFlag) {
    printf("User name: %s\n", pw->pw_gecos);
    printf("User ID: %d\n", pw->pw_uid);
    printf("Password: %s\n", pw->pw_passwd);
    printf("Home: %s\n", pw->pw_dir);
    printf("Default shell: %s\n", pw->pw_shell);
    if(gFlag) {
      printf("Main Group Number: %i\n", pw->pw_gid);
      printf("Main Group Name: %s\n", getgrgid(pw->pw_gid)->gr_name);
    }
  }
  else if(sFlag) {
    printf("Nombre de usuario: %s\n", pw->pw_gecos);
    printf("Identificador de usuario: %d\n", pw->pw_uid);
    printf("Contraseña: %s\n", pw->pw_passwd);
    printf("Carpeta inicio: %s\n", pw->pw_dir);
    printf("Intérprete por defecto: %s\n", pw->pw_shell);
    if(gFlag) {
      printf("Número del Grupo Principal: %i\n", pw->pw_gid);
      printf("Nombre del Grupo Principal: %s\n", getgrgid(pw->pw_gid)->gr_name);
    }
  }
  return(EXIT_SUCCESS);
}
