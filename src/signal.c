#include "shell.h"

void catch_interrupt(int signalNumber) {
  signal(signalNumber, catch_interrupt);
  printf("\n");
  prompt();
  fflush(stdout);
}
