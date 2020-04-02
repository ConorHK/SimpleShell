#include "shell.h"

int main(void){
  char input[BUFFER_SIZE]; // user input
  char* argv[100];

  signal(SIGINT, catch_interrupt);
  prompt();

  while(fgets(input,BUFFER_SIZE,stdin)) {
    strtok(input,"\n"); // removes \n from line read in by fgets as buffer limit is not reached.
    split(input,argv);

    if(isChangeDirectory(argv[0])) {
      changeDirectory(argv);
    }
    else {
      execute(argv);
    }
    prompt();
  }
}
