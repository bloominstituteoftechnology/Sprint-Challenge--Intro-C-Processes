### Short answer responses below

1.  List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

    *   Created - is the "new" state
    *   Ready - process has been loaded into main memory and is awaiting execution on the CPU
    *   Running - process has been chosen for execution
    *   Blocked - process cannot carry on without state change
    *   terminated - process that has completed or has been completely killed

2.  What is a zombie process? How does one get created? How does one get destroyed?

    *   a process that has been completed but still has an entry in the process table.
    *   It can be created when a fork call is made and the child completes it's task and exit but the parent has not had the time to read and interpret the exit code.
    *   the process is destroyed once the parent can read the exit code. This is made possible via the wait system call.
