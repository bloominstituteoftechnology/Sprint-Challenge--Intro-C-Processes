1.  Process states can be running, ready and stopped.

* Running: Running on processor and executing instructions.
* Ready: Is waiting for OS to execute instruction.
* Stopeed: A process may have performed a command and is now waiting or letting for another to run.

2.  A zombie process can be when a child process executes before a parent and some information is kept in the kernel in case the parent may need it. To call on that information the parent calls wait() thus making the child left as a 'zombie'..

3.  In a compiled language need to only be compiled the once and can be run any number of times without the need of too much steps or machine resources in contrast to non-compiled languages where they need to be parsed, interpreted, and executed each run.
