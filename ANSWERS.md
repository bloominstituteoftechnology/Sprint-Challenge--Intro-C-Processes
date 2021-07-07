**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

* `Started/Created` - The initial state where a process has first been created, but is not ready to run yet.
* `Ready` - The process has reached a point where it is ready to run and is waiting to be assigned to a processor by the OS.
* `Running` - The process is running/the processsor is executing its instructions.
* `Waiting` - The process is waiting for something like a resource or user input.
* `Terminated` - The process has stopped. It could have finished its instructions or been terminated by the OS.
* `Zombie` - The process has been terminated but has not been removed from the process table yet.

**2. What is a zombie process?**

* A `zombie process` is a process that has been terminated but still has an entry in the process table.

**3. How does a zombie process get created? How does one get destroyed?**

* A zombie process gets `created` when when its parent fails to call the wait system call to read its exit status. It gets `destroyed` when its parent process calls wait to read its exit status, thereby removing its entry from the process table, at which point it is "reaped".

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

* A program written in a compiled language will be `compiled` into native machine code. This results in very efficient code which tends towards faster performance. The overhead for the translation into machine language is incurred only once, when the program is compiled. Afterwards, it only needs to be loaded and executed. This is in contrast to interpreted languages, which must be parsed, interpreted, and executed every time they run a program.
