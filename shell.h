#ifndef __SHELL_H__
#define __SHELL_H__

/* HEADERS */

/* SYSTEM HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/* USER DEFINED HEADERS */
#include "path_list.h"

/* MACROS */
#define BUFSIZE 81
#define SHELL_PROMPT "$ "
#define UNUSED __attribute__((unused))
#define FILE_DELIM "/"

/* FUNCTIONS */

/* EXECUTION HANDLERS */
char *sh_readline(void);
void sh_loop(void);
void sig_handler(int signo);
pid_t sh_execute(char *cmd);

/* STRING HANDLERS */
char *trim(char **str);
char **tokenize(char *str, const char *DELIM);
/* char **get_args(char *cmd); */
char **get_args(char *cmd, bool *found_path);
int count_tok(const char *str, const char *delim);
void free_str_safe(char **str);

/* SPECIAL VARIABLES */
extern char *ERR_PROMPT;
char *ERR_PROMPT;

extern char **environ;

/* REMOVE WHEN STRUCTURES FOR SHELL_STATUS HAVE BEEN CREATED */
extern int interactive;
int interactive;
#endif	/* __SHELL_H__ */
