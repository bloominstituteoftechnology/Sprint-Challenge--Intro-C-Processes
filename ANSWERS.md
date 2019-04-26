**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Main Unix states are: 
  Running or in the queue to run
  Sleeping (uninterruptible or interruptible--waiting for an event to end)
  Zombie/Defunct
  Stopped/Traced: a pause in the system for debugging purposes

Below is a list of processes and system calls that can happen when a program is running. 

# Initializing a Process:

- Allocation of working memory.
- Entry is added to the operating system's processing list.
- OS's scheduling algorithm schedules the newly-initialized process.

# System Calls
- A request to the OS to perform a privileged operation on its behalf.
- Uses requests and response (similar to API calls)
- File subsystem system calls: open(), close(), read(), write(), chmod(), and chown()
- Process control system calls: fork(), exec(), exit(), wait(), brk(), and signal()
Diagram of a System Call
          Request
        -------->         ---------->
Processes     OS (Gatekeeper)     Hardware
        <--------         <---------
          Response

Diagram of Parent Child Relationship
      P1                                    P2
x (executed)                          x  (value carried over)
y (executed)                          y  (value carried over)
z (executed)                          z  (value carried over)

fork()  =>  creates a forked copy     fork () (carried over)*

wait() & waitpid() (optional)**         

Parent code                           Child Code Examples:
  Open()                                Open()
  Read()                                Read()
  Write()                               Write()
  Close()                               Close()
  getpid()                              getpid()
  sleep()***                            exit()
  Execute Own Functions                 Executes own functions

*if P2 also executes the fork it is a problem referred to as a fork bomb.

** wait(), waitpid(), if the timing is right sleep(), can force the parent to wait to executes its remaining code until this child has completed its tasks. 
  - Wait() cleans ups the child's resources by the parent alerting the OS to reclaiming child's address space by passing the child's PID.


**2. What is a zombie process?**

Zombie Process: When the child does not call exit() and/or the parent does not have a wait() call, then the OS is not notified by the parent that it needs to clean up after the child. So the child's address is not immediately cleaned.

Orphan Process: It is when a parent process has exited without the child process reaching completion. Orphan processes get adopted. The progenitor of all processes is init, which can adopt the orphaned child.

**3. How does a zombie process get created? How does one get destroyed?**

Omitting an exit() from the child, can create a zombie process().
Omitting the wait() call creates a zombie process. Since the OS is never alerted by the parent that the OS can reclaim the child's address space.

Special processes are in place to run occasionally to slay the zombie by cleaning up these processes that were never officially exited from but are not actively running either.

A zombie process can be killed by using the parent process's id when calling:  ```kill -s SIGCHLD pid```
This allows the parent to remove the child processes that are completed.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiling code allows a developer to fix all errors that the compiler has read and it allows the developer to read all warnings like unused variable etc. so that the code is as clean as possible.
