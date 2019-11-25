# Simple Shell

## Description

* Write your own simple UNIX command interpreter.
* This shell should produce an output according to a Ubuntu 14.04.6 LTS system
* This shell should work both interactively and non-interactively

## What our simple shell does

* Displays our prompt: `$` and waits for the user to type a command
* Takes in input from the command line and outputs the same results
as sh (/bin/sh)
* Displays the prompt each time a command has been executed
* Prints associated error messages

---

## Requirements:

* Create our own header file named
``` header.h ```
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
## Files Created

| Name of File | Description |
| --- | --- |
|[header.h](https://github.com/waffle52/simple_shell/blob/master/header.h) | Holds libraries and prototypes |
|[main.c](https://github.com/waffle52/simple_shell/blob/master/main.c) | main driving file|
|[our_env.c](https://github.com/waffle52/simple_shell/blob/master/our_env.c) | function that gets the environmental variable and parses through them|
|[showenv.c](https://github.com/waffle52/simple_shell/blob/master/showenv.c) | function that shows the environmental variable |
|[our_cd.c](https://github.com/waffle52/simple_shell/blob/master/our_cd.c) | function that implements the built in cd function along with multiple options| 
|[helper_functions.c](https://github.com/waffle52/simple_shell/blob/master/helper_funcs.c) | string manipulation along with free function |
|[static_path.c](https://github.com/waffle52/simple_shell/blob/master/static_path.c)| determines if user input is a valid command by searching all directories in PATH |

* Compile all created source code .c files in this repository along with the
header
```header.h```
file and launch the executable file to start your own shell

Use: ```./hsh```:
```
vagrant@vagrant-ubuntu-trusty-64:~/repos/simple_shell$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
vagrant@vagrant-ubuntu-trusty-64:~/repos/simple_shell$ ./hsh
$
```
---
## Available Commands


| Commands | Description |
--- | --- |
ls | lists all available files and directories in the current working directory
exit | exits the shell
env | prints the current environment
pwd | prints the present working directory
cd | changes the current directory of the process
^C | man the signal
\# | handles comments

---
```ls```:

Output:
```
$
$ ls
README.md  header.h  helper_funcs.c  hsh  main.c  our_cd.c  our_env.c  showenv.c  static_path.c
$
```
---
```ls -l ```:

```
$
$ ls -l
total 48
-rw-rw-r-- 1 vagrant vagrant  2973 Nov 24 21:02 README.md
-rw-rw-r-- 1 vagrant vagrant   820 Nov 24 21:25 header.h
-rw-rw-r-- 1 vagrant vagrant  1701 Nov 24 21:25 helper_funcs.c
-rwxrwxr-x 1 vagrant vagrant 14048 Nov 24 22:09 hsh
-rw-rw-r-- 1 vagrant vagrant  2046 Nov 24 22:09 main.c
-rw-rw-r-- 1 vagrant vagrant  1025 Nov 24 21:25 our_cd.c
-rw-rw-r-- 1 vagrant vagrant  1500 Nov 24 21:25 our_env.c
-rw-rw-r-- 1 vagrant vagrant   457 Nov 24 21:25 showenv.c
-rw-rw-r-- 1 vagrant vagrant  1592 Nov 24 21:25 static_path.c
$
```
---
```ls -l -a```:

```
$
$ ls -l -a
total 60
drwxrwxr-x  3 vagrant vagrant  4096 Nov 24 22:10 .
drwxrwxr-x 13 vagrant vagrant  4096 Nov 24 19:44 ..
drwxrwxr-x  8 vagrant vagrant  4096 Nov 24 21:25 .git
-rw-rw-r--  1 vagrant vagrant  2973 Nov 24 21:02 README.md
-rw-rw-r--  1 vagrant vagrant   820 Nov 24 21:25 header.h
-rw-rw-r--  1 vagrant vagrant  1701 Nov 24 21:25 helper_funcs.c
-rwxrwxr-x  1 vagrant vagrant 14048 Nov 24 22:09 hsh
-rw-rw-r--  1 vagrant vagrant  2046 Nov 24 22:09 main.c
-rw-rw-r--  1 vagrant vagrant  1025 Nov 24 21:25 our_cd.c
-rw-rw-r--  1 vagrant vagrant  1500 Nov 24 21:25 our_env.c
-rw-rw-r--  1 vagrant vagrant   457 Nov 24 21:25 showenv.c
-rw-rw-r--  1 vagrant vagrant  1592 Nov 24 21:25 static_path.c
$
```
---
```Ctrl + D```:

```
$
$ #User types in Ctrl + D here
$ # program exited
```
---

```exit```:

```
$
$ #User types in exit here
$ # program exited
$
```
---

```env```:

```
$
$ env
XDG_SESSION_ID=25
TERM=xterm-256color
SHELL=/bin/bash
SSH_CLIENT=10.0.2.2 52473 22
SSH_TTY=/dev/pts/2
USER=vagrant
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:
MAIL=/var/mail/vagrant
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
PWD=/home/vagrant/repos/simple_shell
LANG=en_US.UTF-8
SHLVL=1
HOME=/home/vagrant
LC_TERMINAL_VERSION=3.3.6
LOGNAME=vagrant
SSH_CONNECTION=10.0.2.2 52473 10.0.2.15 22
LESSOPEN=| /usr/bin/lesspipe %s
XDG_RUNTIME_DIR=/run/user/1000
LC_TERMINAL=iTerm2
LESSCLOSE=/usr/bin/lesspipe %s %s
_=./hsh
OLDPWD=/home/vagrant/repos
$
```
___

```pwd```:

```
$
$ pwd
/home/vagrant/repos/simple_shell
$
```
---
```cd ..```:

```
$
$ cd ..
$ pwd
/home/vagrant/repos
$
```
---

```cd```:

```
$
$ cd
$ pwd
/home/vagrant
$
```
---

```cd simple_shell```:

```
$
$ cd simple_shell
$ pwd
/home/vagrant/repos/simple_shell
$
```
---
```^C```:

```
$
$ ^C
$ ^C
$ ^C
$ ^C
$ ls
README.md  header.h  helper_funcs.c  hsh  main.c  our_cd.c  our_env.c  showenv.c  static_path.c
$
```
---
```#```:

```
$
$ ls # do you see this
README.md  header.h  helper_funcs.c  hsh  main.c  our_cd.c  our_env.c  showenv.c  static_path.c
$
```

---

## Authors

* **Anthony Louie** - [Alouie412](https://github.com/Alouie412)
* **Christine Pang** - [christinepang1](https://github.com/christinepang1)
* **Kyle Campbell** - [waffle52](https://github.com/waffle52)