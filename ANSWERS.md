**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

*new state:* initial user request process
*Running state:* when the process is being executed by the CPU 
*waiting state:* when the process is stored out of memory and will only be retrieved when needed.
*Ready State:* When the process is ready in memory but is waiting for CPU to execute it. Ready to be executed.
*Terminated State:* After the process is completed


**2. What is a zombie process?**
A process that has executed but has not exit.



**3. How does a zombie process get created? How does one get destroyed?**
When there is  children processes that finished but still has to send an exit status to its parent.
Won’t get destroyed until the parent function receives and acknowledges the state of the child process. 



**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

higher performance in terms of execution and better optimization for specific hardware.

