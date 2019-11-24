# Simple Shell

## Description

* Write your own simple UNIX command interpreter.
* This shell should produce an output according to a _______
* This shell should work both interactively and non-interactively

## What our simple shell does

* Displays our prompt: `$` and waits for the user to type a command
* Takes in input from the command line and outputs the same results
as sh (/bin/sh)
* Displays the prompt each time a command has been executed
* Prints associated error messagess
* * _----- wht else does the shell do

---

## Requirements:

* Create our own header file named
``` header.h ```.
* Specific compilation flag: gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

| List of authorized functions and system calls |
| --- |
| access (man 2 access)|
|chdir (man 2 chdir)|
|close (man 2 close)|
|closedir (man 3 closedir)|
|execve (man 2 execve)|
|exit (man 3 exit)|
|_exit (man 2 _exit)|
|fflush (man 3 fflush)|
|fork (man 2 fork)|
|free (man 3 free)|
|getcwd (man 3 getcwd)|
|getline (man 3 getline)|
|isatty (man 3 isatty)|
|kill (man 2 kill)|
|malloc (man 3 malloc)|
|open (man 2 open)|
|opendir (man 3 opendir)|
|perror (man 3 perror)|
|read (man 2 read)|
|readdir (man 3 readdir)|
|signal (man 2 signal)|
|stat (__xstat) (man 2 stat)|
|lstat (__lxstat) (man 2 lstat)|
|fstat (__fxstat) (man 2 fstat)|
|strtok (man 3 strtok)|
|wait (man 2 wait)|
|waitpid (man 2 waitpid)|
|wait3 (man 2 wait3)|
|wait4 (man 2 wait4)|
|write (man 2 write)|

---
## Directions

* Compile all created source code .c files in this repository along with the
header
```header.h```
file and launch the executable file to start your own shell

Example ```./hsh```:
```
$ ./hsh
$
$
```
---
## Available Commands


| Commands | Description |
--- | --- |
ls | lists all available files and directories in the current working directory
exit | exits the shell
env | prints the current environment
cd | changes the current directory of the process
^C | man the signal
\# | handles comments

---
```ls```:
```
insert picture or table of what happens here
```
Output:
```
$
$ Insert output of the command here
$
```
---

```ls```:
```
Insert typing in command here
```
Output:
```
$
$ Insert output of the command here
$
```
---

```exit```:
```
Insert typing in command here
```
Output:
```
$
$ Insert output of the command here
$
```

---

```env```:
```
Insert typing in command here
```
Output:
```
$
$ Insert output of the command here
$
```
___

```cd```:
```
Insert typing in command here
```
Output:
```
$
$ Insert output of the command here
$
```
---
```^C```:
```
Insert typing in command here
```
Output:
```
$
$ Insert output of the command here
$
```
---
```#```:
```
Insert typing in command here
```
Output:
```
$
$ Insert output of the command here
$
```

---

## Authors

* **Anthony Louie** - [Alouie412](https://github.com/Alouie412)
* **Christine Pang** - [christinepang1](https://github.com/christinepang1)
* **Kyle Campbell** - [waffle52](https://github.com/waffle52)