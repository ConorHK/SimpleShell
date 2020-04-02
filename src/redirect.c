#include "shell.h"

bool isRedirect(char **argv, int *position) {
  bool flag = false;
  for(int i = 0; i < BUFFER_SIZE; i++) {
    if(argv[i] == NULL){
      break; //breaks loop before string compare to avoid segmentation fault
    }
    if(strcmp(argv[i], ">") == 0){
      flag = true;
      *position = i;
      argv[i] = NULL; // removes '>' and anything after from command execution in execute.c
      break; // breaks loop to stop further iterations
    }
  }
  return flag;
}

void redirect(char **argv, int position) {
  char *newFile = argv[position+1];
  int file = open(newFile, O_CREAT | O_WRONLY | O_TRUNC,0666);
  if(file< 0) {
    fprintf(stderr,"open: %s: %s\n", strerror(errno), argv[position+1]);
    exit(1);
  }
  if(dup2(file,1) < 0) {
    fprintf(stderr,"dup2: %s\n", strerror(errno));
    exit(1);
  }
  close(file);
}
