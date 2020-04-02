#include "shell.h"

void prompt() {
  char buffer[100];
  time_t currentTime = time(0);
  strftime(buffer,100,"%d/\%m/\%y | %X", localtime(&currentTime));
  printf("[%s] # ", buffer);
}
