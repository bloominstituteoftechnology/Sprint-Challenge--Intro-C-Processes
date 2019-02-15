**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- Created: When a process is initialized 
- Ready: A state in which it's occupying memory and able to accept an assignment to the respective processor.
- Waiting: The process is now waiting for a specific trigger/input in order to enter the running state.
- Running: The process is now executing its instructions as a result of receiving said input.
- Terminated: The process is killed either because it has reached the end of its execution or it's explicitly killed by some other trigger.


**2. What is a zombie process?**
A zombie process is a child process that's in the terminated state yet is still present in the process table.


**3. How does a zombie process get created? How does one get destroyed?**
A zombie process is generally created due to a failure of the parent process to call the `wait` command. This is important because that respective command is what triggers the child process to return its termination code, which in turn triggers the parent to remove the child process from the process table.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled languages are capable of optimizing the code when compiling, enabling improved performance at execution. In tandem with the strongly-typed nature of C, compiling can also more explicitly catch errors before execution.