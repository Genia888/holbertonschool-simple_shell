# 0x16. C - Simple Shell

This project is a simple UNIX command line interpreter written in C.

## Features
- First check if the command is interactive or not 
- => not interactive is 'echo "ls" | ./hsh' 
- => interactive is launch by './hsh' in terminal and display a prompt '($)' and wait for command
- Executes commands using full path or from $PATH
- Displays error message and return code 127 when command not found
- No use of getenv, system or printf
- Forks only when needed

## Team
- Mr Philips (ddoudou7)
- @SebSa12000
- Evgeni
