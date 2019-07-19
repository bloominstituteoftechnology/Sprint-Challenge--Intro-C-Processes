1.  Created: occupying the new state

    Ready: loaded into memory and awaiting execution.

    Running: instructions begin to run after being executed
    Kernel mode: unrestricted access (privileged)
    User mode: can only access user-level instructions and data

    Blocked: the process is blocked and cannot continue

    Terminated: a process finishes, either by being killed or finishing

2.  A zombie process is when a process continues to live on the process
    table after it has been terminated. This may happen within a child
    process if the parent needs to hold on to it's data.

3.  Simply put, compiled code runs faster. Additionally, being compile
    usually means that it is optimised for the target hardware
