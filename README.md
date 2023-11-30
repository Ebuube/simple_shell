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
</br>
* Handled the `PATH`
</br>
* Implemented the `exit` built-in, that exits the shell
Usage: `exit [status]`
```
($) exit
```
Quits shell with last exit status.
</br>
* Implemented the `env` built-in, that prints the current environment.
</br>
* Implemented the `setenv` and `unsetenv` builtin commands
`setenv`
<div style="margin-left: 8px">	* Initialize a new environment variable, or modify an existing one
	* Syntax: `setenv VARIABLE VALUE`
</div>



### Missing features
* Ability to move cursor while in command line
