**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Start or create:
This state represents when the process is initially exectuted.
Ready:
A process at the ready state is ready to be assigned to a processor.
Running:
This state is arrived at when the readied processor is assigned to a processor and is actively being ran.
Waiting:
A process in the waiting state is waiting on a resource or user input to continue running.
Terminated or exit:
This state indicates that the process has finished running or was exited by the operating system.

**2. What is a zombie process?**

A process that completed it's execution, but still exists in the processes list.

**3. How does a zombie process get created? How does one get destroyed?**

A zombie process is created when the child process is executed and finishes before the parent process finishes. You can "destroy" a zombie process by stoping it in the task manager.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

A compiled programming language works directly with the computer's hardware giving notable performance gains. A non-compiled language has the extra step of having to be completely parsed every time it exectues.
