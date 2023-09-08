#ifndef __SHELL_H__
#define __SHELL_H__

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/* MACROS */
#define BUFSIZE 81
#define SHELL_PROMPT "($) "
#define UNUSED __attribute__((unused))

/* FUNCTIONS */
char *sh_readline(void);
void sh_loop(void);
pid_t sh_execute(char *cmd);

/* SPECIAL VARIABLES */
extern char *ERR_PROMPT;
extern char **environ;

char *ERR_PROMPT;
#endif	/* __SHELL_H__ */
