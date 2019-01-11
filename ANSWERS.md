

**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
    --Created(New) | The first/initial state, process is created 
    --Ready | Process loaded into memory and awaiting execution on CPU
    --Running |  Process assigned to processor and code is ran in either Kernel or User mode
    --Blocked | Get pushed to waiting stage - cannot continue without an external change
    --Waiting | Waiting for an change to see if more code needs to be executed
    --Terminated | Process has either finished running or explicitly killed. No longer executing but remains in the process table as a zombie process until parent process calls wait system to read it's exit status.


**2. What is a zombie process?**
    --A zombie process or defunct process is a process that has completed execution but still has an entry in the process table: it is a process in the "Terminated state". It is basically awaiting confirmation of completion.


**3. How does a zombie process get created? How does one get destroyed?**
    --A zombie process is created in the terminated state once a process has finished executing. Zombie processes can be destroyed with the kill command or upon reboot.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
    --Faster performance as we apply several configurations at the compile so it doesn't have to do it at runtime. Also, it is closer to computer language so we really get a feel for what the computer is doing as opposed to the other abstract languages which translate "too much".
