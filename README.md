# Try_Shell

## Description
A UNIX Command interpreter written in C using linked lists.

## Compilation 

> gcc -Wall -Werror -Wextra -pedantic *.c -o try_shell

## Prompt

> $

## Files Of The Project

Name File | Description
------------- | -------------
[library.h](./src/library.h) | Interpreter prototypes.
[main.c](./src/main.c)    | Execute main function and print the prompt.
[linked_list.c](./src/linked_list.c) | Save all the path to execute the commands.
[getenv.c](./src/getenv.c) | Get enviroment.
[set_commands.c](./src/set_commands.c) | Tokenize the string and call the commands.
[utility.c](./src/utility.c) | Functions of own implementation of the standard library.
[create_error.c](./src/create_error.c)| Create a error message.

## Usage

# Non-Interactive
> echo "/bin/ls" | ./try_shell

> 2_utility.c  built_in_func.c  echo      library.h      linked_list.c  set_commands.c
a.out        create_error.c   getenv.c  library.h.gch  main.c         utility.c

# Interactive
>$
>
>$ env
>
>SHELL=/bin/bash
>
>WSL_DISTRO_NAME=Ubuntu
>
>NAME=LAPTOP-1CCJ17A1
>
>PWD=/home/andresdiaz111/Try_Shell/src
>
>LOGNAME=andresdiaz111
>
>MOTD_SHOWN=update-motd
>
>HOME=/home/andresdiaz111

## Authors
* Andres Diaz <andresdiaz50101@gmail.com>
