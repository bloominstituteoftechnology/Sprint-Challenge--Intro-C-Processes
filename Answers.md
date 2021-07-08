## Task 1

### Short Answer Questions

Add your answers inline, below, with your pull request.

1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

Ready - process is ready to be assigned to a processor, Running - process is running, Waiting - process is waiting, Exit - process is done

2. What is a zombie process? How does one get created? How does one get destroyed?

A zombie process is one which has finished its execution but is still present in the process table. For instance, a child process that has completed its execution but is not removed. A zombie process gets created when fork() is called and the child process completes before the parent process. It can be destroyed by having the parent process call wait().

3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

Compiled languages are faster than non-compiled languages. Also complied languages are prone to less error.