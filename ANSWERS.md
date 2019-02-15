**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
-Created
The process is created and awaits approval from the scheduler to be in the ready state

-Ready
The process is in memory and is waiting to be passed through the cpu

-Running
The process is going through the cpu. Process is executed

-Blocked
When a process can not be run it will be blocked. This happens when it can not access a section of code or user input
is needed

-Terminated
When a process completes it's execution or exited within the code

**2. What is a zombie process?**
When a process is not using any memory at the moment but remains in the process table.

**3. How does a zombie process get created? How does one get destroyed?**
A zombie process is created when a process ends with an exit() call. You can destroy one by using the kill() command.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
A compiled language will run faster since it is compiled down into binary.