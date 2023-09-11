#ifndef __SHELL_H__
#define __SHELL_H__

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/* MACROS */
#define BUFSIZE 81
#define SHELL_PROMPT "$ "
#define UNUSED __attribute__((unused))

/* FUNCTIONS */
char *sh_readline(void);
void sh_loop(void);
pid_t sh_execute(char *cmd);
void sig_handler(int signo);

/* STRING HANDLERS */
char *trim(char **str);

/* SPECIAL VARIABLES */
extern char *ERR_PROMPT;
char *ERR_PROMPT;

extern char **environ;

/* REMOVE WHEN STRUCTURES FOR SHELL_STATUS HAVE BEEN CREATED */
extern int interactive;
int interactive;
#endif	/* __SHELL_H__ */
