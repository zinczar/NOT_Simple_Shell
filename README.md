# Simple Shell
In this repo we create a simple shell.

# Motivation
This is our end of end of semester and second partner project for Holberton School.  Over the last three months we have been learning C basics. In this repo we bring everything we have learned together and create a simple shell.

# Environment
Our Simple Shell is built and tested in Ubuntu 14.04 LTS and compiled with GCC 4.8.4

# How to Use?
Launch the shell with ./hsh and enter a command.<br/>
Example output:<br/>
```
vagrant@vagrant-ubuntu-trusty-64:$ ./hsh
$ pwd
/home/vagrant/simple_shell
$ ls
pathfinder.c  README.md  hsh  shell.h  shell_helpers.c  simple_shell.c
```

# How to Complie:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

# Respository Contents
Simple Shell files:

| **File** | **Description** |
|----------|-----------------|
| shell.h | Header file that contains function prototypes and standard C library header files |
| simple_shell.c | Contains the int main(void) function - entry point |
| pathfinder.c | Contains function that returns executable path using strtok and access |
| shell_helpers.c | Contains helper functions: _strlen, _strnpy, _strcat, _strncmp,_strdup |
| more_shell_helpers.c | Contains more helper functions: _strcmp |
| built_ins.c | Contains built in functions: _getenv and _printenv |

# Contributers
* [**Brendan Eliason**](https://github.com/zinczar) - follow on twitter @zinczar<br/>
* [**Andrew Cox**](https://github.com/AndrewC7) - follow on twitter @AndrewC795
