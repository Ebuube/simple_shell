#ifndef __GET_ENV_H__
#define __GET_ENV_H__

#include <stdio.h>
#include <string.h>

char *_getenv(const char *name);

extern char **environ;

#endif	/* __GET_ENV_H__ */
