### Short Answer Questions

Add your answers inline, below, with your pull request.


1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

    *States of a process*
        
        1. Start - initial state the process is created

        2. Ready - Process is waiting to be assigned.

        3. Running - Process has been assigned to a processor.

        4. Waiting - Process moves into a waiting state.

        5. Terminated - Process finished its execution.

---

2. What is a zombie process? How does one get created? How does one get destroyed?


    On Unix and Unix-like computer operating systems, a zombie process or *defunct process* is a process that has completed execution (via the exit system call) but still has an entry in the process table: it is a process in the "Terminated state". To destroy it you can send a SIGCHLD signal to the parent 
    ```kill -s SIGCHLD <ppid>```. This will cause well-behaving parents to reap their zombie children.
---

3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

    Compiled Languages are compiled to machine code and then executed. Non-compiled languages also known as interperted languages are just executed.