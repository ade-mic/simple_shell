#ifndef MAIN_H
#define MAIN_H

extern char **environ;
/** Libraries **/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/** Prototype Declaration **/
void interactive_mode(void);
void non_interactive_mode(void);
char *_strcpy(char *dest, char *src);
size_t _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *str1, char *str2);
char *_strchr(const char *s, int c);
int execute_args(char **args);
int execmd(char **argv);
char *readline();
char *readstream();
char **process_line(char *lineptr);

/** BUiltin **/
int own_ext(char **args);
int own_cd(char **args);
#endif /* SHELL_H */
