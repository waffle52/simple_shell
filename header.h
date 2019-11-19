#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _atoi(char *s);
/* void sigintHandler(int sig_num); */

#endif /* HEADER_H */
