**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Created - when a process is first created, it occupies the "created" or "new" state. The process awaits admission to the "ready" state.

Ready - or "waiting" process has been loaded into main memory and is awaiting execution on a CPU.

Running - a process moves into the running state when it is chosen for execution. A process can run in two modes: kernel mode or user mode.

Kernal Running - Processes in kernel mode can access both: kernel and user addresses.
Kernel mode allows unrestricted access to hardware including execution of privileged instructions.

User Running - Processes in user mode can access their own instructions and data but not kernel instructions and data. The system is in user mode when a computer system is executing on behalf of a user application.

Blocked - A process when it cannot carry on without an external change in state or event occurring.

Terminated - A process may be terminated, either from the "running" state by completing its execution or by explicitly being killed.

**2. What is a zombie process?**
A process that has completed its execution or has been killed and is awaiting exit status within the process table. It still has an entry in the process table.

**3. How does a zombie process get created? How does one get destroyed?**
A zombie process occurs when a process has completed execution but still has an entry in the process table. A zombie process gets destroyed when the parent process calls an exit status.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled languages are faster to execute than interpreted langauges because interpreted languages have to interpret and compile after every step of the code. Compiled languages are compiled then ran as an executable. Compiled code runs without further preparation and processing because the code is the native code for the CPU on the target machine.
