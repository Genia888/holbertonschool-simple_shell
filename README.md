# Simple Shell Team Project Holberton School C#25 :school:
[![Blue-Futuristic-Technology-Linked-In-Background-Photo3.gif](https://i.postimg.cc/KYMRdqvX/Blue-Futuristic-Technology-Linked-In-Background-Photo3.gif)](https://postimg.cc/p9PWjBFk)
## Description
This project is a simple UNIX command interpreter shell implementation in C. The shell is designed to mimic basic functionalities of the standard shell ``/bin/sh``, including command execution, handling arguments, and managing the environment.

## Allowed Functions and System Calls
- All standard functions from ``string.h``
- ``access``, ``chdir``, ``close``, ``execve``, ``exit``, ``_exit``, ``fflush``, ``fork``, ``free``, ``getcwd``, ``getline``, ``getpid``, ``isatty``, ``kill``, ``malloc``, ``open``, ``opendir``, ``perror``, ``printf``, ``fprintf``, ``read``, ``readdir``, ``signal``, ``stat``, ``strtok``, ``wait``, ``write``.

## Requirements
- Allowed editors: ``vi``,``vim`` or ``emacs``
- All the files will be compiled on Ubuntu 20.04 LTS using gcc.
- Your code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl).
- You are not allowed to use global variables
- No more than 5 functions per file.
- The prototypes of all your functions should be included in your header file called ``main.h``
- 
## Manual
Run the man page for this shell : 
``man ./man_1_simple_shell``

  [![Capture-d-cran-man-simple-shell.jpg](https://i.postimg.cc/wvCzg1nq/Capture-d-cran-man-simple-shell.jpg)](https://postimg.cc/XGkmgYVm)

## Features
- First check if the command is interactive or not 
- => not interactive is 'echo "ls" | ./hsh' 
- => interactive is launch by './hsh' in terminal and display a prompt '($)' and wait for command
- Executes commands using full path or from $PATH
- Displays error message and return code 127 when command not found
- No use of getenv, system or printf
- Forks only when needed
  
## Compilation

Compile the shell using this command:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o hsh
./hsh
```
  
## Project Structure
| FILE  |DESCRIPTION|
| :--------------------: | :--------------------------: |
|``AUTHORS``|list of project contributors|
|``README``| describes and launches a project|
|`man_1_simple_shell` |man page of the imple shell program|
|``simple_execute_command.c``|contains the functions that are mandatory for the shell to work|
|``simple_print_env.c``|built-in command to print environment variables|
|``simple_search_path.c``|function to search for executables using the ``PATH`` environment variable|
|``simple_shell.c``|main entry point and core shell loop|
|``simple_shell.h``|header file containing function prototypes and includes|


## Authors👷‍♂
- [Mr Phillips](https://github.com/ddoudou7)
- [Sebastien Salgues](https://github.com/SebSa12000)
- [Evgeni Khalepo](https://github.com/Genia888)
