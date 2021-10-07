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
main.c    | execute main function
linked_list.c | save all the path to execute the commands
Get_commands.c | Funtions principals of the projects
Set_commands.c | Funtions for the Get_commands file
Utility.c | Some of string functions that utility of the project.
Exit_system.c | Exit process
Built.c | built-in command that prints environment variables

## Functions Of The Project

Name Function | Description
------------- | -------------
_strcat    | concatenates a string to another
_strcmp    | compares string to another
_strncmp   | compare two strings
_itoa.c    | convert int to string
_strcpy    | copies the string pointed to variable
_strcpy    | copies the string pointed to variable
_strdup    | Duplicate a string
