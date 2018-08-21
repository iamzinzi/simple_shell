# simple_shell

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
*A system call is a specific function that uses a system service. System calls change hardware context and can enforce mutual exclusion. The system call is also a subroutine built into the system while a function call is a call to a subroutine within the program. System calls access both kernal and user space so it adds extra time where as normal function aclls only access user address space.*  

**How to create processes?**  
*fork. That is a system call. It takes no arguments and returns a PID. The purpose is to create a child process for the caller. Should test the fork value to distinguished the parent from the child. If fork returned negative, error, if it returned 0, then it made a new child. If fork returned positive then that value is the child process to the parent.*  

**What are the three prototypes of main?**  
*int main(void)  
int main (int argc, char \*argv[])  
int main(int argc, char \*argv[], char \*envp[])  *  

**How does the shell use the PATH to find the programs?**  
*.*  

**How to execute another program with the execve system call?**  
*.*  

**How to suspend the execution of a process until one of its children terminates?**  
*.*  

**What is EOF / “end-of-file”??**  
*.*  
