**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

There are 5 potential states a process can be in:
1. New
    * New state is the initial state, when a process is starting / being created.
2. Ready
    * Ready state is when the process is waiting for assignment to a particular processor - this is usually prior to the running state.
3. Waiting
    * This state is when the process is waiting for some particular event to occur before entering the Running state. It might wait on things like user input, or for another process to complete.
4. Running
    * A process is considered running when the processor is executing it's instructions.
5. Terminated
    * A terminated state for a process means it has completed execution and isn't in any other states.

**2. What is a zombie process?**
  A zombie process is a child process that has entered the terminated state (completed execution) and can still be seen in the process table.



**3. How does a zombie process get created? How does one get destroyed?**
You can create a zombie process by forgetting or refusing to call the `wait` system command from the parent process. When you call the `wait` command on a child process from the parent process, the child process returns it's exit code to the parent. When the parent observes the exit status of the child (from `wait`), the operating system will remove the zombies entry from the process table, also known as being "reaped" or destroyed.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
There are numerous benefits to compiled languages.  When we are capable of compiling our code prior to execution, the compiler can make optimizations to our code so it will run faster at execution. Additionally, a compiler will catch some bugs prior to fully compiling, leading to less outright errors in our program. 