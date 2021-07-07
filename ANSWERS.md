**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Start - Initial state when a process is created
Ready - Process waiting to be assigned to a processor. Waiting to have processor allocated to them by the OS.
Running - The process has been assigned to a processor by the OS shedular, state is set to running and executes its programs.
Waiting - Process moves into waiting state if it needs to wait for a resource, user input, or for a file to become available.
Terminated - Once the process finish its execution, or is terminated by OS, move to terminated state to be removed from main memory

**2. What is a zombie process?**
A child process which has finished the execution but still has entry in the process table to report to its parent process


**3. How does a zombie process get created? How does one get destroyed?**
 Until the parent function receives and acknowledges the message, the child function remains in a “zombie” state, meaning it has executed but not exited.
 Use wait() to ensure child has finish and allows you to obtaibn the childs exit status

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled programs generally run faster than interpreted
