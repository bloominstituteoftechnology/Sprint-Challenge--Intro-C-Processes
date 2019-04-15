#### 1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

- New: the process is just created.
- Ready: the process waits for permission to run.
- Running: the process is executed by CPU.
- Waiting: the process is paused and waits for more resources 

#### 2. What is a zombie process? How does one get created? How does one get destroyed?

- Zombie process is the process has been run and completed, but has not yet been removed completely
- A child process should be cleaned up from process table after execution. If a child process, during Terminate state, 's exit status unexists or has not read by system, it will become zombie process. 

#### 3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

- Compiled code can be executed any number of times because it is only translated once.