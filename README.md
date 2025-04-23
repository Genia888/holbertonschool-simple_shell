# Simple Shell Team Project Holberton School C#25 :school:
[![Blue-Futuristic-Technology-Linked-In-Background-Photo3.gif](https://i.postimg.cc/KYMRdqvX/Blue-Futuristic-Technology-Linked-In-Background-Photo3.gif)](https://postimg.cc/p9PWjBFk)
## Description
This project is a simple UNIX command interpreter shell implementation in C. The shell is designed to mimic basic functionalities of the standard shell ``/bin/sh``, including command execution, handling arguments, and managing the environment.

## Learning Objectives

By completing this project, you will understand:
# General Concepts
The history of UNIX and its creators
How a shell works internally
Process management in UNIX systems
The difference between functions and system calls
Environment manipulation
Program execution mechanisms

# Technical Skills
Creating and managing processes
Using system calls like ``execve``, ``fork``, ``wait``
Handling process IDs (PID and PPID)
Working with the PATH environment variable
Implementing basic shell features
Managing end-of-file (EOF) conditions

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
 
## Manual
Run the man page for this shell : 
```bash
man ./man_1_simple_shell
```
  [![Capture-d-cran-man-simple-shell.jpg](https://i.postimg.cc/wvCzg1nq/Capture-d-cran-man-simple-shell.jpg)](https://postimg.cc/XGkmgYVm)

## Code Style and Constraints
- Betty-compliant code
- No memory leaks
- Max 5 functions per file
- All files end with a new line
- Use system calls only when needed

## Features
- Interactive prompt display (``$``)
- Executes commands with absolute paths (e.g., ``/bin/ls``)
- Handles ``Ctrl+D`` (EOF)
- Supports both interactive and non-interactive modes
- Built-in command: ``exit``
  
## Usage
Interactive Mode:
```bash
./hsh
($) ls
AUTHORS    hsh                 simple_execute_command.c  simple_search_path.c  simple_shell.h
README.md  man_1_simple_shell  simple_print_env.c        simple_shell.c        toto.txt
($) pwd
/home/seb/dev/holbertonschool-simple_shell
($) exit
```
Non-Interactive Mode:
```bash
echo "ls" | ./hsh
AUTHORS    hsh                 simple_execute_command.c  simple_search_path.c  simple_shell.h
README.md  man_1_simple_shell  simple_print_env.c        simple_shell.c        toto.txt
```

## Compilation
Compile the shell using this command:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o hsh
```
```bash
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


## Authors
- [Mr Phillips](https://github.com/ddoudou7)
- [Sebastien Salgues](https://github.com/SebSa12000)
- [Evgeni Khalepo](https://github.com/Genia888)
  
