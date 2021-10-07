# Try_Shell

## Description
Command interpreter written in C using linked lists to store the path.

## Compilation 

> gcc -Wall -Werror -Wextra -pedantic *.c -o try_shell

## Prompt

> $

## Files Of The Project

Name File | Description
------------- | -------------
[library.h](./src/library.h) | interpreter prototypes
[main.c](./src/main.c)    | execute main function
[linked_list.c](./src/linked_list.c) | save all the path to execute the commands
[getenv.c](./src/getenv.c) | get enviroment
[set_commands.c](./src/set_commands.c) | tokenize the string to call the commands
[utility.c](./src/utility.c) | functions of own implementation of the standard library
[create_error.c](./src/create_error.c)| create a message of error
