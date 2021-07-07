1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.
    start - the intial state when a process is first started/created.
    ready - process is ready and waiting to be asssigned a processor.
    running - process executes its instructions.
    waiting - process changes to a waiting state if it needs to wait for a resource.
    terminated or exit - after a process finishes its execution, it is moved to the terminated state where it waits to be removed from the main memory.

2. What is a zombie process? How does one get created? How does one get destroyed?
    Is a process that has an exit status to report to it's parent process but does not get terminated.
    It is created because at times the parent process does not terminate it to ensure others don't get the same pid number.
    It can get desteroyed by sending a SIGCLD signal to the parent or by killing the parent process of the aombie.

3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?
    Faster execution and optimised for the target hardware.