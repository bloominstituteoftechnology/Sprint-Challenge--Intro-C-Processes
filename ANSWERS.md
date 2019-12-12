**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

a. R/Running/runnable: the process can be run and is simply waiting on the CPU to begin processing.

b. S/Interruptible Sleep: the process is waiting for some sort of event to complete. An example of this would be something like the following:

printf("Please provide an integer:\n");
scanf(%d, input_var);

After prompting the user for input, the process will be in an S state while waiting for the input it is supposed to scan.

c. D/Uninterruptible Sleep: the process cannot be killed or interrupted with any sort of action or user input. This usually requires a more drastic solution such as a reboot and is similar to a zombie process in that it cannot be killed. Linux introduced a TASK_KILLABLE feature to allow these processes to be killed (but not interrupted) in the event an issue arises.

d. Z/Zombie: the process has been terminated and is waiting to have its status collected. It cannot be killed in this state. This happens due to programming errors; if wait() is never called, for example, the zombie process never has its information retrieved so it is not removed from memory. It will then remain in memory until it is manually freed up in some way.

e. T/Stopped: the process has been suspended or interrupted in some way via a STOP signal, most commonly a user entering ^z in the terminal. Until it receives a CONT signal the process will not do anything including termination. Upon receiving CONT, the process will continue from the point at which it had stopped.

**2. What is a zombie process?**

As described above, a zombie process is a process that has been terminated but has not been removed from memory after returning. The process cannot be killed although it is no longer doing anything useful. This is not supposed to happen and forces a user to manually close the program to remove it from memory.


**3. How does a zombie process get created? How does one get destroyed?**

A zombie process is created through a programming oversight such as the exclusion of a wait() within a code block. Since Linux has a finite number of PID numbers available, zombie processes can add up in extreme cases and prevent other processes from being able to launch. They can be destroyed by passing a SIGCHLD signal to the parent process, which executes a wait() system call to clean up zombie child processes. It is worth mentioning again that a zombie process cannot be killed in the same manner as a standard one.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

The general difference between compiled and interpreted languages is that a compiled language expresses itself (once compiled) as direct machine instructions whereas an interpreted language is read and executed by some other program that is generally written in the language of the machine. The extra time compiling allows for faster performance because the compiled code is native to the machine, which also allows for the compiler to make optimizations to the code. Interpreted languages feature the ability to run code on the fly without taking time to compile, so development is generally faster. Every time it is executed the code must be interpreted so it is slower to execute.

A massive and not entirely accurate generalization to get the gist of this is that compiled languages are slower to develop and faster to run, and vice versa for interpreted languages.
