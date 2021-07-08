**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Created/New - process is created and awaiting admission to the "ready/waiting" state by a scheduler

Ready/Waiting - process is loaded into main memory and waiting to be executed by the CPU

Running - process is chosen for execution. Its instructions are executed by the CPU

Blocked - process is stopped for various reasons (waiting on user input/other processes, require acess to other processes)

Terminated - process is done. Exeuction is completed or the process is killed. Stays as zombie process until the wait system calls acknowledges it and removes it from process table. Will cause resource leak if not dealt with.

**2. What is a zombie process?**
Process that has been been terminated (completley executed or killed) but hasn't been removed from the process table.

**3. How does a zombie process get created? How does one get destroyed?**
A process turns to zombie once it's been "killed" but not "reaped": all its instructions have been executed, but it's parent process hasn't read its exit status to get its entry off the process table. 
It gets destroyed once its parent process reads its exit status through the wait system call.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
I asked Beej this question :D The major benefit is better performance. Compiled languages use less memory and are faster because no resources are used on interpreting. You just run them directly. No translation overheads.

