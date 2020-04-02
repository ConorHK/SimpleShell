#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define SHELL_NAME "spsh" // SimPle SHell (was going to go with ssh but decided against it for obious reasons)
#define VERSION 1.0

#define AUTHOR "ConorHK"
#define STUDENT_NUMBER 18398031
#define EMAIL_ADDRESS "conor.knowles@ucdconnect.ie"

#define BUFFER_SIZE 1024 //TODO: default according to google, may change

void prompt();
void execute(char **argv);
void split(char *line, char **argv);
void catch_interrupt(int signalNumber);
bool isChangeDirectory(char *command);
void changeDirectory(char **argv);
bool isRedirect(char **argv, int *position);
void redirect(char **argv, int position);
