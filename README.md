[![Generic badge](https://img.shields.io/badge/Made%20with%20C-green.svg)](https://en.wikipedia.org/wiki/C_(programming_language)) [![Generic badge](https://img.shields.io/badge/Memory%20leak%20free-blue.svg)](https://valgrind.org/) [![Generic badge](https://img.shields.io/badge/Made%20with%20threads-orange.svg)](https://www.geeksforgeeks.org/multithreading-in-c/)

# Simple Unix Command Interpreter

This program emulates a Unix shell and allows users to run linux commands directly in it.

## Compilation
To compile this program using the gcc compiler, run this command

* **Manually**

`$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o hsh`

* **Using make**
This feature enables easy compilation of the program. Simply run this command.
`$ make`

## Usage
### Interactive
The interactive mode allows users to infinitely run Unix commands until a termination signal is sent to the program: `CTRL + C`. To use it interacitively, start the program thus:

`$ ./hsh`

### Sample
You can run a command with or without argumeents. Example, the `ls`

```
($) ls /
bin   etc   lib32   lost+found  myproject  root  snap  tmp      var
boot  home  lib64   media       opt        run   srv   usr
dev   lib   libx32  mnt         proc       sbin  sys   vagrant


($) touch play_1 play_2 play_3
($) ls
play_1 play_2 play_3
```

### Non-interacitive
This simple unix command interpreter can equally be used non-interaactively by piping the output of a program into it. Example, to list all the files in the current working directory:

`$ echo "ls" | ./hsh`


### General features
* Can handle command lines with arguments
* Handled the `PATH`
* Implemented the `exit` built-in, that exits the shell
Usage: `exit [status]`
```
($) exit
```
Quits shell with last exit status.
* Implemented the `env` built-in, that prints the current environment.
* Implemented the `setenv` and `unsetenv` builtin commands
`setenv`: Initialize a new environment variable, or modify an existing one. Syntax: `setenv VARIABLE VALUE`. Should print something on failure.
`unsetenv`: Remove an environment variable. Syntax: `unsetenv VARIABLE`. Should print something on failure.
* Implemented the `cd` builtin command. Changes the current directory of the process. Syntax: `cd [DIRECTORY]`. If no argument is given to the command, it takes the uesr to **HOME** directory. To change to the previous command `cd -`.
* Multiple commands can be entered on the command line, separated by a semi-colon `;`. Eg.
```
($) ls /var; ls /hbtn ; ls /var
``` 
* Comments: Everything after a hash `#` is considered a comment and not part of the command to be executed. e.g
```
($) ls /var # I am a simple comment :)
```


### Missing features
* Ability to move cursor while in command line
* Aliases
* File input
* Shell variables: E.g. `$?`, `$$`.
* Logical operators: E.g. `&&`, `||`.
