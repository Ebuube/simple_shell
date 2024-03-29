#ifndef __SHELL_H__
#define __SHELL_H__

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

/* MACROS */
#define BUFSIZE 81
#define SHELL_PROMPT "ebube@~$ "
#define UNUSED __attribute__((unused))

/* FUNCTIONS */
char *sh_readline(void);
pid_t sh_loop(void);
pid_t sh_execute(char **cmd);
pid_t sh_run(char *line);
void sig_handler(int signo);
void free_str_safe(char **str);
char **add_path(char **args, bool *changed);
int run_builtin(const char *builtin, const char **args);
char *_change_dir(const char *path);
int find_chr(const char *str, const char c);

/* STRING HANDLERS */
char *trim(char **str);
char **tokenize(char *str, const char *delim);
int count_tok(const char *str, const char *delim);
int free_array(char **array);
char *strjoin(const char *str1, const char *sep, const char *str2);

/* SHELL BUILTINS */
pid_t _exit_shell(UNUSED const char **args);
pid_t _env_builtin(UNUSED const char **args);
pid_t _setenv_btn(UNUSED const char **args);
pid_t _unsetenv_btn(UNUSED const char **args);
pid_t _cd_btn(UNUSED const char **args);

/* SPECIAL VARIABLES */
extern char *ERR_PROMPT;
char *ERR_PROMPT;

extern char **environ;

/**
 * struct builtin_s - a builtin and its name coupled together
 * @opcode: name of builtin to be recognized by SHELL
 * @f: function to call
 */
typedef struct builtin_s
{
	char *opcode;
	pid_t (*f)(const char **);
	/* pid_t _exit_shell(void) */
} builtin_t;

/**
 * struct SH_POD_S - Packages some information concerning the running shell
 * @interactive: if shell is running interactively or not
 * @ERR_NO_BUILTIN: Code if builtin does not exist
 * @BUILTIN_SUCCESS: exit code if builtin executed well
 * @BUILTIN_FAILURE: Builtin did not execute properly
 * @FORK_EXEC_FAILURE: could not fork new process
 * @END_SUCCESS: Code to terminate shell successfully
 * @END_FAILURE: Code to termniate shell with failure
 * @LAST_EXIT_STATUS: Status of the last executed function
 * @END_SHELL: Signal to end the current shell session
 * @CMD_NOT_FOUND: Command does not exist
 */
typedef struct SH_POD_S
{
	bool interactive;
	int ERR_NO_BUILTIN;
	int BUILTIN_SUCCESS;
	int BUILTIN_FAILURE;
	int FORK_EXEC_FAILURE;
	int END_SUCCESS;
	int END_FAILURE;
	int LAST_EXIT_STATUS;
	int END_SHELL;
	int CMD_NOT_FOUND;
} SH_POD_T;
extern SH_POD_T SHELL;
SH_POD_T SHELL;

/* REMOVE WHEN STRUCTURES FOR SHELL_STATUS HAVE BEEN CREATED */
/*
 * extern int interactive;
 *int interactive;
 */
#endif	/* __SHELL_H__ */
