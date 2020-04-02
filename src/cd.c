#include "shell.h"

bool isChangeDirectory(char *command) {
  return (strcmp(command,"cd")==0);
}

void changeDirectory(char **argv){
  if(argv[1] == NULL){ // if no location is specified
    chdir(getenv("HOME"));
  }
  else {
    if(chdir(argv[1]) != 0) {
      fprintf(stderr,"cd: %s: %s\n", strerror(errno), argv[1]);
    }
  }
}
