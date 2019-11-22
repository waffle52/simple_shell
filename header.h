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
int _strcmp(char *s1, char *s2);
/*
void handler(int sig_num);
*/
char *_strcat(char *dest, char *src);
char *_getenv(char *name);
char *static_path(char *user_command, char *env_string);
char *cmd_cpy(char *dest, char *src, char *usr_cmd);
int our_cd(char *path);
char *handledotdot(char *path);
void showenv(char **envp);
#endif /* HEADER_H */
