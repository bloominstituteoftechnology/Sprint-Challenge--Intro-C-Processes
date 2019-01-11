**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Running - Process is running
Waiting - Process is waiting for something or another process to finish running
Stopped - The process has been stopped
Zombie - The process has terminated but is still lingering in the system because it was not properly cleaned up.


**2. What is a zombie process?**
A zombie process is when a process is termintated or dies but stays in the system because the parent process was not programmed properly to handle the death of it's child and ultimately prevents the child process from being cleaned up. The process' file descriptor stays in the system until it's manually cleaned up.


**3. How does a zombie process get created? How does one get destroyed?**
The zombie process gets created when a processes dies and all that's left in memory is its PID. The parent processes is supposed to get a signal to read the exit information from the child but it never happens so the zombie process is never cleaned up.
A zombie process cannot be killed like a normal process since it's already dead. To destroy it you can manually send a SIGCHLD signal to the parent process. If that doesn't work due to poor programming, the zombie process can be destroyed by killing the parent process.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

A compiled language gives the programmer more control over the program in terms of performance and memory management. More care has to be taken to make sure everything works but the programmer can control exactly how the memory is managed.
There is also a greater efficiency that comes with compiled languages. A non-compiled language, or an interpretted language, takes time to figure some things, e.g. type inference, so it takes longer to run the code.
Compiling the code into an assembly language allows the program to execute faster because there is very little guesswork and nothing needs to be interpretted. 

