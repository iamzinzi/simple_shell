# simple_shell by Jinji Zhang and Bryan Leung


### Project Overview:
The shell will be compiled using this- `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
The program output must have the exact same output as `sh` (`/bin/sh`) as well as the exact same error output.
The only difference is when you print an error, the name of the program is `./hsh` instead of `sh`.

### Files
* AUTHORS - List of contributors to this repo  
* README.md - The README markdown file
* datatype_converter.c - converts data types  
    * string_to_int - converts a string to an integer  
    * counter_to_string - converts an int to a string  
* error_helper.c - handles the error messages that are written
* man_1_simple_shell - Custom manual page for the simple_shell  
* path_functions.c - helper functions that handle the PATH  
    * \_strstr - searches a pattern, if a substring is found in a string  
    * \_getenv - grabs the enviornment variable and returns it as a string  
    * add_node_end - adds a new node at the end of the list_t linked list  
    * build_linked_list - generates a linked list starting with the PATH  
    * free_list - frees the linked list of list_t  
* search_paths.c - iterates through the linked list (the PATH)  
    * print_env - prints the current env built-in  
    * search_path - loops through PATH to find the directory that contains the command    
* shell.h - header file used throughout each file  
* simple_shell.c - the main file   
* split_string.c - has many string helper functions and helps tokenize the input  
    * \_strlen - counts the length of the string  
    * word_count - counts how many command or arguments were inputted  
    * split_string - tokenizes the users standard input  
    * \_strcmp - compares two strings, returns 0 if matching  
    * str_concat - appends a '/' and the command to make a full path  
* string_dup.c - duplicates and copies a string for specific purposes  

### INSTALLATION AND USAGE EXAMPLES
In the terminal, enter `git clone https://github.com/iamzinzi/simple_shell.git`  
Then cd into the file via `cd simple_shell`  
Enter interactive mode with `./hsh`  
Enter the command `'s -l`  
Be happy!  
Exit with `exit` or Ctrl-D or Ctrl-C  
The shell can also be run in non-interactive mode like so,  
`echo "/bin/ls" | ./hsh`  

### Project Requirements:
* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be compiled on Ubuntu 14.04 LTS
* Your C programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall -Werror -Wextra` and `-pedantic`
* All your files should end with a new line
* A `README.md` file, at the root of the folder of the project is mandatory
* Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)

#### List of allowed functions and system calls:
`access` (man 2 access),  
`chdir` (man 2 chdir),  
`close` (man 2 close),  
`closedir` (man 3 closedir),  
`execve` (man 2 execve),  
`exit` (man 3 exit),  
`fork` (man 2 fork),  
`free` (man 3 free),  
`stat` (\__xstat) (man 2 stat),  
`lstat` (\__lxstat) (man 2 lstat),  
`fstat` (\__fxstat) (man 2 fstat),  
`getcwd` (man 3 getcwd),  
`getline` (man 3 getline),  
`kill` (man 2 kill),  
`malloc` (man 3 malloc),  
`open` (man 2 open),  
`opendir` (man 3 opendir),  
`perror` (man 3 perror),  
`read` (man 2 read),  
`readdir` (man 3 readdir),  
`signal` (man 2 signal),  
`strtok` (man 3 strtok),  
`wait` (man 2 wait),  
`waitpid` (man 2 waitpid),  
`wait3` (man 2 wait3),  
`wait4` (man 2 wait4),  
`write` (man 2 write),  
`_exit` (man 2 _exit),  
`isatty` (man 3 isatty),  
`fflush` (man 3 fflush),  

### Extra Trivia!
**Who designed and implemented the original Unix operating system?**
*The original AT&T Unix was created at Bell Labs by Ken Thompson (made Unix and B) and Dennis Ritchie (made Unix and C).*

**Who wrote the first version of the UNIX shell?**
*Ken Thompson. Crazy guy. He did much more which is included below*

**Who invented the B programming language (the direct predecessor to the C programming language)?**
*Ken Thompson.*

**Who is Ken Thompson?**
*Worked at Bell Labs with Dennis Ritchie. Worked at Google and helped co-invent Go. He has worked a lot on text iditors and regex. He worked on the UTF-8 encoding and chess machines..*

**How does a shell work?**
*A shell is a computer program and the interface to the Unix OS. A shell lives in the user space while the kernal lives in the kernel. Software in the kernel can execute special privleges such as manipulating hardware, we do not want any software doing this since the OS could be erased. The shell communicated to this kernel via system calls. This allows a user to open files and create processes. The Kernel double checks that the shell doesn't do anything dangerous. The shell uses system calls, I/O redirection, and piping to execute simple commands.*

**What is a pid and a ppid?**
*Process ID and Parent Process ID. In Linux, a exe is a program and a program is loaded into memory and if it is running, it is also a process. Processes have an ID which can be used as a target, eg. killing a process via PID. PPID is the parent process ID which also tells us which process started it.
PPID is important because sometimes ending a task doesn't fix a lagging issue. The process might run or use up resources even though it is dead (Zombie process). This is why killing the parent or end task tree(Windows task manager) is very effective.
Kill the parent if you want to end the children.*

**How to manipulate the environment of the current process?**
*Threading.*

**What is the difference between a function and a system call?**
*A system call is a specific function that uses a system service. System calls change hardware context and can enforce mutual exclusion.
The system call is also a subroutine built into the system while a function call is a call to a subroutine within the program. System calls access both kernal and user space so it adds extra time where as normal function aclls only access user address space.*

**How to create processes?**
*fork. That is a system call. It takes no arguments and returns a PID. The purpose is to create a child process for the caller. Should test the fork value to distinguished the parent from the child. If fork returned negative, error, if it returned 0, then it made a new child. If fork returned positive then that value is the child process to the parent.*

**What are the three prototypes of main?**
* int main(void)
* int main (int argc, char \*argv[])
* int main(int argc, char \*argv[], char \*envp[])

**How does the shell use the PATH to find the programs?**
*The job of a shell is to find and run commands. The shell identifies the command names then finds their files, or executables, to run. The first word is assumed to be the command name.
A few built-in commands are executed directly by the shell and are not searched for (echo, ed, pwd, kill, etc). These built in have no man pages, only help. If the command name is not a built-in, the shell tries to find the exe file. If there are no forward slashes, the shell looks in the PATH. Directories are separated by colons. Only one executable is run and if the file is not found we say the command is not found.*

**How to execute another program with the execve system call?**
*execve system call is used to execute a binary executable. On success it returns nothing but on error it returns -1. The first parameter is the path of a script or binary exe, the second parameter is an array of piointers and the last pointer must be NULL. The third and last parameter is an environment.
So an example may be:
 e = execve("/bin/ls", argv, envp);
   if (e == -1)
       fprintf(stderr, "Error: %s\n", strerror(errno));
The execve system call is how new processes are created in UNIX. A execve call replaces the current process image with a new one. The execve calln ever returns since the process that called it is usually replaced.*

**How to suspend the execution of a process until one of its children terminates?**
*wait(). executing a wait system call will suspend the parent process until any of its children processes terminates. The wait call then returns and the parent process can continue. The prototype is pid_t wait(int \*status);
The return value from wait is the PID of the child process that terminated. Ther parameter of wait is a pointer to a function that will recieve the child's exit status value. Exit call has no return and has some similarities to wait but that will not be covered here.
You can google this or the life cycle of a child process.*

**What is EOF / “end-of-file”??**
*End of File. It is a sign that the end of the file is reached and there is no more data. Ctrl-D is EOF for Linux and OS X and Ctrl-Z for Windows.*

## Authors
[Jinji Zhang](https://twitter.com/hizinzi)  
[Bryan Leung](https://twitter.com/BynLeung)
