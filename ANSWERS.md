**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

A Unix process can be in one of the following states: Running, Asleep, Zombie, or Stopped. A process starts running, goes to sleep while waiting for an event to complete, becomes a zombie and then becomes reaped by it's parent, which then stops it.

**2. What is a zombie process?**

A zombie process is a process that hasn't yet been reaped by a parent, but has finished executing.

**3. How does a zombie process get created? How does one get destroyed?**

They get created when a parent doesn't wait() on its child, generally.

They either get reaped by the parent, or they become an orphan and are eventually reaped by init.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiled languages always have faster performance after they are compiled because they are compiled directly into machine language. You can optimize with the machine language directly in mind.

Interpreted languages don't need to compile so there is (generally) a smaller space between writing the code and running the code. It's also generally easier to write and most useful for higher level languages that are further away from the machine code.
