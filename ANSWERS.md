**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
- Running: process is running or ready to run
- Waiting: process is waiting for an event or resource
- Stopped: process has been stopped
- Zombie: process is dead but has not been removed from the         process table

**2. What is a zombie process?**
The process is dead but has not been removed from the         process table. It is a process that has completed execution (via the exit system call) but still has an entry in the process table: it is a process in the "Terminated state".

**3. How does a zombie process get created? How does one get destroyed?**
It is created when the a child process's entry in the process table is still needed to allow the parent process to read the child's exit status. A child process always first becomes a zombie before being removed from the resource table. Usually the zombie process is killed when the parent process's wait function is called, but it can also be called by some other manual kill function call.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Working in a compiled language results in efficient code that can be executed any number of times. The overhead for the translation is incurred only once, when the source is compiled; thereafter, it need only be loaded and executed.

Interpreted languages must be parsed, interpreted, and executed each time the program is run, which adds to the cost of running the program. Therefore, interpreted programs are usually less efficient than compiled programs.