# Makefile for compiling the shell project in C


# C compiler to use
CC = gcc

# Source files
SRC = $(wildcard *.c)

# Object files
OBJ = $(SRC:.c=.o)

# Name of executable
NAME = hsh

# Remove program to use
# RM = rm -f
# Not allowed to set the RM variable

# Flags for C compiler
CFLAGS := -Wall -Werror -Wextra -pedantic -std=gnu89

# Vim temporary files
VIM_TMP = $(wildcard *.swp)

# Emacs temporary files
EMACS_TMP = $(wildcard *~)

# Dependencies
DEPS := "$(wildcard main.h)"


# Rules

ifneq ($(strip $(DEPS)), "") # ensure dependencies are present

all: $(SRC) # recompile only the updated source files
	$(CC) $? -o $(NAME)


.PHONY: clean fclean oclean re

clean: # delete all emacs and vim temporary files along with the executable
	$(RM) $(EMACS_TMP) $(VIM_TMP) $(NAME)

oclean: # delete all object files
	$(RM) $(OBJ)

fclean: clean oclean # delete all emacs and vim temporary files, the executable \
	and the object files

re: fclean all # force recompilation of all source files

endif
