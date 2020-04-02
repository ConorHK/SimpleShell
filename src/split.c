#include "shell.h"

void split(char *input, char **argv){
  while (*input != '\0') {
    while (*input == '\t' || *input == '\n' || *input == ' ') { // removes whitespace
      *input++ = '\0';
    }
    *argv++ = input; // current argv element is set to current input then iterated.
    while (*input != '\0' && *input != ' ' && *input != '\t' && *input != '\n')  { //iterates through characters
      input++;
     }
  }
  *argv = '\0';
}
