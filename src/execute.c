#include "shell.h"

void execute(char **argv) {
  pid_t pid;
  int status;
  int redirectPosition;

  if((pid = fork()) < 0) { // fork a child process
      fprintf(stderr, "Forking child process failed.\n");
      exit(1);
  }
  else if(pid == 0) { // child process
    if(isRedirect(argv, &redirectPosition)){
      redirect(argv, redirectPosition);
    }
    if(execvp(*argv,argv) < 0) { // execute command
      fprintf(stderr,"spsh: command not found: %s\n", *argv);
      exit(1);
    }
  }
  else {
    while(wait(&status) != pid);
  }
}
