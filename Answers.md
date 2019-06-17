List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.
Create- Creates occupies created or a new state waiting for the ready state.

ready/waiting- The process has been loaded into memory and is awaiting execution from the cpu.

Running- The process changes into a running state when it is picked for execution.

Blocked- Cannot carry on without external change in state or event occurring.

Destroy -   The process is terminated and removed from running state. Although, the process has been terminated, it still remains in a zombie state. It remains in the process table waiting for it's parents to call the wait system call to read its exit status.

What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?
Compilers generate native machine code(not that it maters) can also create optimizations during the compile stage.

Interpreters- are easy to implement and do not require a compile stage since most of it is already created under the hood.