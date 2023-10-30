#ifndef __STRTOK_H__
#define __STRTOK_H__

/* HEADER FILES */

#include <stdlib.h>
#include <string.h>
#include <strings.h>

/* FUNCTION PROTOTYPES */

char **_strtok(char *str, const char *delim);
int counttok(const char *str, const char *delim);

#endif	/* __STRTOK_H__ */
