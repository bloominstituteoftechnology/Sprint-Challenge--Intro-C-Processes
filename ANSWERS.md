**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

    Running:
        The process is active and functioning. Taking space in memory and using system resources.

    Waiting:
        The process is idling, still in memory and resources. It is waiting for a signal or communication from another process to continue or change state. 

    Stopped: 
        Process that is killed by a either a user signal or signal from another process. Will have an exit status. Has stopped using memory space and removed from process table

    Zombie:
        Processs that is stopped. Ususally a child process. But it is still occuying memory space but not actively using 
        system resources. The parent program needs it thats why it kept in the process table. 



**2. What is a zombie process?**
    Zombie process is a dead child process that sustains itself on the process table after it returns before the parent so, most often because the parent process has called wait(). 


**3. How does a zombie process get created? How does one get destroyed?**
    Zombie processes are a result of programs not managing child processes from forks correctly. 
    The parent does not call wait on the child making it return before the parent killing it prematurely and creating a zombie. 
    When the system calls wait to read the dead process’s exit status the parent process gets information from the dead process. After wait() is called, the zombie process is completely removed from memory and destroyed.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

    

