**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Created- The process enters a new state and waits for the ready state via the system scheduler.
Ready- This is where the process is loaded into memory and is awaiting to be executed from the CPU
Running- The process has been executed and is being ran by one of the cores on the CPU
Blocked- The process must require user input, or the device that the process is trying to access is not available
Terminated- The process is finished executing or is killed by the user

**2. What is a zombie process?**

It's a process that has been fully executed and terminated but still remains in the process table. It remains in the process table until the parent finishes reading its exit code to notify the system that the child process has completed.

**3. How does a zombie process get created? How does one get destroyed?**

A zombie process gets created by being terminated first, but it still shows up in the process table because it has to wait on its parent process to read its exit code. This process gets destroyed once the child's process exit code is read by the parent and is automatically removed from the process table.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

The benefits from working in a compiled language versus a non-compiled language is less exposure to errors. With C, you are more prone to errors since you have more free reign to do what you want and not exactly following a rule set. However, with a language like JavaScript, there are certain syntax rules that you have to abide by before even running or compliling the program.
