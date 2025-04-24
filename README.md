# Simple Shell Team Project Holberton School :school:  C#26 
[![Blue-Futuristic-Technology-Linked-In-Background-Photo3.gif](https://i.postimg.cc/KYMRdqvX/Blue-Futuristic-Technology-Linked-In-Background-Photo3.gif)](https://postimg.cc/p9PWjBFk)
## :receipt: Description
This project is a simple UNIX command interpreter shell implementation in C. The shell is designed to mimic basic functionalities of the standard shell ``/bin/sh``, including command execution, handling arguments, and managing the environment.

## :computer: Requirements
- Allowed editors: ``vi``,``vim`` or ``emacs``
- All the files will be compiled on Ubuntu 20.04 LTS using gcc.
- Your code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl).
- You are not allowed to use global variables
- No more than 5 functions per file.
- The prototypes of all your functions should be included in your header file called ``main.h``

## :file_folder: Features
- Interactive prompt display (``$``)
- Executes commands with absolute paths (e.g., ``/bin/ls``)
- Handles ``Ctrl+D`` (EOF)
- Supports both interactive and non-interactive modes
- Built-in command: ``exit``

## :floppy_disk: Technical Skills
Creating and managing processes
Using system calls like ``execve``, ``fork``, ``wait``
Handling process IDs (PID and PPID)
Working with the PATH environment variable
Implementing basic shell features
Managing end-of-file (EOF) conditions

## :wrench: Allowed Functions and System Calls
- All standard functions from ``string.h``
- ``access``, ``chdir``, ``close``, ``execve``, ``exit``, ``_exit``, ``fflush``, ``fork``, ``free``, ``getcwd``, ``getline``, ``getpid``, ``isatty``, ``kill``, ``malloc``, ``open``, ``opendir``, ``perror``, ``printf``, ``fprintf``, ``read``, ``readdir``, ``signal``, ``stat``, ``strtok``, ``wait``, ``write``.

## :chart_with_downwards_trend: Flowchart
[![flowchart-drawio-2.png](https://i.postimg.cc/tCCsNyds/flowchart-drawio-2.png)](https://postimg.cc/nMgVnyPx)
## :writing_hand: Project Structure
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

## :construction: Code Style and Constraints
- Betty-compliant code
- No memory leaks
- Max 5 functions per file
- All files end with a new line
- Use system calls only when needed

 ## :gear: Compilation
- Compile the shell using this command:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o hsh
```
```bash
./hsh
```

## :closed_book: Usage
- ### Interactive Mode: :arrow_heading_down:
```bash
./hsh
($) ls
AUTHORS    hsh                 simple_execute_command.c  simple_search_path.c  simple_shell.h
README.md  man_1_simple_shell  simple_print_env.c        simple_shell.c        toto.txt
($) pwd
/home/seb/dev/holbertonschool-simple_shell
($) exit
```
- ### Not-Interactive Mode: :arrow_heading_down:
```bash
echo "ls" | ./hsh
AUTHORS    hsh                 simple_execute_command.c  simple_search_path.c  simple_shell.h
README.md  man_1_simple_shell  simple_print_env.c        simple_shell.c        toto.txt
```
## :broom: Memory Management
- This shell was tested with ``valgrind`` to ensure proper memory allocation and deallocation. No memory leaks were found during normal usage.
```bash
evgen@Zenbook:~/holbertonschool-simple_shell$ ./hsh
($) valgrind ./hsh
==534== Memcheck, a memory error detector
==534== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==534== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==534== Command: ./hsh
==534==
($) exit
==534==
==534== HEAP SUMMARY:
==534==     in use at exit: 0 bytes in 0 blocks
==534==   total heap usage: 3 allocs, 3 frees, 2,168 bytes allocated
==534==
==534== All heap blocks were freed -- no leaks are possible
==534==
==534== For lists of detected and suppressed errors, rerun with: -s
==534== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## :ledger: Manual
- Run the man page for this shell : 
```bash
man ./man_1_simple_shell
```
:arrow_double_down:
```man
SIMPLE_SHELL(1)                                         Genia888 Manual                                        SIMPLE_SHELL(1)

NAME
       simple_shell - a minimalistic UNIX command interpreter

SYNOPSIS
       simple_shell [interactive_mode]
       simple_shell [non-interactive_mode]

DESCRIPTION
       simple_shell  is a lightweight UNIX shell implementation supporting basic command execution, built-ins, and environment
       handling. It is designed for educational purposes and conforms to the Holberton School project requirements.

       Key features: - Basic command execution with arguments - PATH resolution -  Built-ins:  exit  and  env  -  Handles  EOF
       (Ctrl+D) and signals - No memory leaks (checked with Valgrind)

OPTIONS
       Interactive Mode
              Displays a prompt (e.g., #cisfun$ or :) ) and waits for user input.

       Non-Interactive Mode
              Reads commands from a file or pipe (e.g., echo ls | ./simple_shell ).

BUILT-IN COMMANDS
       exit   Exits the shell with status 0.

       env    Prints the current environment variables.

       help   Displays this help message (if implemented).
ENVIRONMENT
       simple_shell inherits the parent process environment and supports:

       PATH   For locating executables (e.g., /bin/ls ).

EXIT STATUS
       Returns: - 0 on successful execution - 1 on command not found - 2 on invalid arguments (if extended)

ERROR MESSAGES
       Prints errors to stderr in the format: ./simple_shell: 1: ls: not found

IMPLEMENTATION DETAILS
       -  Uses  execve  for  command  execution - Forks child processes via fork - Handles processes with wait - Complies with
       Betty style (80 chars/line, 40-line functions)

INSTALLING
       To install and run Simple Shell, follow these steps:
       1. Clone the repository using the following command:
       "git clone https://github.com/SebSa12000/holbertonschool-simple_shell.git"
       2. Compile the program by running the following command:
       "gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh"
       3. Run the program with the command in SYNOPSIS.

COMMANDS
       pwd    Print the path of the current working directory.  exit Exits the shell with status 0.

       env    Prints the current environment variables.

       ls     List the contents of the current directory.

AUTHOR
       Written by Mr Philips, Sebastien Salgues, Genia888 for Holberton School Project.

COPYRIGHT
       This is free software.

SEE ALSO
       bash

Simple Shell 1.0v                                         April 2025                                           SIMPLE_SHELL(1)
 Manual page man_1_simple_shell line 31/70 (END) (press h for help or q to quit)
```  
## :man_technologist: Authors
- [Mr Phillips](https://github.com/ddoudou7)     
- [Sebastien Salgues](https://github.com/SebSa12000)
- [Evgeni Khalepo](https://github.com/Genia888)
<p align="center">
  <strong>Students of </strong><br>
  <img src="https://i.postimg.cc/vTm5RRPM/1-540-logo-1.png" alt="Logo" width="150"><br>
</p>
