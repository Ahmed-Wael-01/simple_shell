#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

void non_inter(void);
char **splice(char *str);
int word_len(char *str);
int word_cnt(char *str);
char *_getenv(const char *name);
char **psplice(char *path);
int pword(char *str);
int plen(char *str);
int _strlen(char *s);
char **line_breaker(char *str);
int line_count(char *str);
int path_search(char **str);
int execute(char *cmd, char **av);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void envprint(void);
void shfree(char **str);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
void exitf(char **str, char **path);

#endif
