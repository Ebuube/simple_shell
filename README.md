# Simple Unix Command Interpreter

This program emulates a Unix shell and allows users to run linux commands directly in it.

## Compilation
To compile this program using the gcc compiler, run this command

`gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o hsh`

(assumption: the user is inside this repo)

## Usage
### Interactive
The interactive mode allows users to infinitely run Unix commands until a termination signal is sent to the program: `CTRL + C`. To use it interacitively, start the program thus:

`./hsh`

(assumption: the user is inside this repo)

### Non-interacitive
This simple unix command interpreter can equally be used non-interaactively by piping the output of a program into it. Example, to list all the files in the current working directory:

`echo "/bin/ls" | ./hsh`

(assumption: the user is inside this repo)
