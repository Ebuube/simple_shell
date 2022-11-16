#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE 81
#define ERR_PROMPT "hsh"
#define SHELL_PROMPT "#cisfun$ "
#define UNUSED __attribute__((unused))

void hsh_loop(UNUSED int argc, UNUSED char *argv[], UNUSED char *const envp[]);
char *hsh_readline(void);
pid_t hsh_execute(UNUSED int argc, UNUSED const char *command,
		UNUSED char *const *args, UNUSED char *const envp[]);

#endif	/* _MAIN_H */
