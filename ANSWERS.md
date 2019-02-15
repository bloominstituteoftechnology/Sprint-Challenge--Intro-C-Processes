**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- Start - When the initial state if first started
- Ready - When a process is waiting to be assigned to a processor
- Running - Processor executes its instructions
- Waiting - if a process needs to wait  for a resource such as user input
- Exit - waits to be removed from memory after it finishes its execution


**2. What is a zombie process?**

- Its a process that has finished its execution but it still has entry in the process table to report to its parent. A child always becomes a zombie before it is removed or reaped from the process table.


**3. How does a zombie process get created? How does one get destroyed?**

- if the parent process has a sleep it doesn't call wait and the child process' entry still exists in the process table. The process is destroyed once the parent reads the childs exit code and the child process entry is reaped from the process table

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

- A compiled language runs its source code through a compiler with results in code that can be run any number of time, resulting in really efficient code. So after the compilation, it only needs to be loaded and executed making a compiled language great for resource intensive material, where as a non-compiled language is great for UI or presentaional aspects of a program.