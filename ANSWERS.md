**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
When a program is loaded into the memory and it becomes a process, it can be divided into four sections ─ stack, heap, text and data.
1. Stack

The process Stack contains the temporary data such as method/function parameters, return address and local variables.

2.Heap

This is dynamically allocated memory to a process during its run time.
3.Text

This includes the current activity represented by the value of Program Counter and the contents of the processor's registers.
4.
Data

This section contains the global and static variables.

When a process executes, it passes through different states. These stages may differ in different operating systems, and the names of these states are also not standardized.

In general, a process can have one of the following five states at a time.
Start

This is the initial state when a process is first started/created.
Ready

The process is waiting to be assigned to a processor. Ready processes are waiting to have the processor allocated to them by the operating system so that they can run. Process may come into this state after Start state or while running it by but interrupted by the scheduler to assign CPU to some other process.
Running

Once the process has been assigned to a processor by the OS scheduler, the process state is set to running and the processor executes its instructions.

Waiting

Process moves into the waiting state if it needs to wait for a resource, such as waiting for user input, or waiting for a file to become available.

Terminated or Exit

Once the process finishes its execution, or it is terminated by the operating system, it is moved to the terminated state where it waits to be removed from main memory.

Process States in UNIX and Linux
Running : The process is either running or it is ready to run .
Waiting : The process is waiting for an event or for a resource.
Stopped : The process has been stopped, usually by receiving a signal.
Zombie : The process is dead but have not been removed from the process table.



**2. What is a zombie process?**
Zombies are basically the leftover bits of dead processes that haven’t been cleaned up properly. A program that creates zombie processes isn’t programmed properly – programs aren’t supposed to let zombie processes stick around.If zombies are accumulating at a very quick rate  the entire pool of available PIDs ( Linux systems have a finite number of process IDs – 32767 by default on 32-bit systems.) will eventually become assigned to zombie processes, preventing other processes from launching.



**3. How does a zombie process get created? How does one get destroyed?**
When a process dies on Linux, it isn’t all removed from memory immediately — its process descriptor stays in memory. The process’s status becomes EXIT_ZOMBIE and the process’s parent is notified that its child process has died with the SIGCHLD signal. The parent process is then supposed to execute the wait() system call to read the dead process’s exit status and other information. This allows the parent process to get information from the dead process. After wait() is called, the zombie process is completely removed from memory.If a parent process isn’t programmed properly and never calls wait(), its zombie children will stick around in memory until they’re cleaned up.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
to compile or not to compile? - The main benefit of compile a block of code is to get all the errors in the world to fix them, ie to make necessary modifications to get it running. Running the source code through a compiler results in very efficient code that can be executed any number of times. The overhead for the translation is incurred just once, when the source is compiled; thereafter, it need only be loaded and executed.Interpreted languages, in contrast, must be parsed, interpreted, and executed each time the program is run, thereby greatly adding to the cost of running the program. For this reason, interpreted programs are usually less efficient than compiled programs.
It would make sense to use a compiled language for the intensive parts of an application (heavy resource usage), whereas interfaces (invoking the application) and less-intensive parts could be written in an interpreted language.