#ifndef __PATH_LIST_H__
#define __PATH_LIST_H__

/* FUNCTION HEADERS */
#include <stdlib.h>
#include <string.h>
#include "_getenv.h"
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>

/* DATA STRUCTURE */

/**
 * struct dir_list_s - a linked list for directories
 * @dir: directory name
 * @next: pointer to next node in the list
 */
typedef struct dir_list_s
{
	char *dir;
	struct dir_list_s *next;
} dir_list_t;

/*  FUNCTIONS */

/* SYSTEM FILE HANDLERS */
char *resolve_path(const char *prg);
char *search_dir(const char *dir_name, const char *filename);

/* DATA STRUCTURES */
dir_list_t *path_list(void);
dir_list_t *add_dir_list_node(dir_list_t **head, const char *dir_name);
void free_dir_list(dir_list_t **head);

/* STRING HANDLERS */
char **tokenize(char *str, const char *DELIM);
int count_tok(const char *str, const char *delim);

extern char **environ;

#endif	/* __PATH_LIST_H__ */
