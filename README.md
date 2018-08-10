# Sprint-Challenge: Intro to C and Processes

Complete both tasks below.

_The code for the second task needs a Unix-like environment to work! That includes
Linux, macos, Cygwin, WSL, BSD, etc._

If you want to test if your environment is set up for it, compile and run the
[testdir.c](examples/testdir.c) program in the `examples/` directory. (You can
type `make` in the `examples/` directory.) It should print `Testing: PASS`.

## Task 1

### Short Answer Questions

Add your answers inline, below, with your pull request.

> 1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

* **Start**: Initial state when a process is created.
* **Ready**: Waiting to be selected and run by the processor. This is essentially `Start`, but may be in this state if the process was running before but was paused before it was finished.
* **Running**: Process is running and the CPU is executing process' instructions. 
* **Waiting**: Continuation of the process is contingent on the resolution of something else, like result of an I/O operation. While similar to `Start`/`Ready`, this expresses that the process needs to wait for something before it can continue running, while the other states express that the process is ready to run but waiting to be executed.
* **Terminated**: Process that has ended. State suggests it is ready to be cleaned up by OS or other processes. 

> 2. What is a zombie process? How does one get created? How does one get destroyed?

A zombie process is a *child* process which has terminated but the parent process has not yet cleaned up (*e.g. `wait()`-ed upon*).  Because of this, the child process still has a PID and is clogging up the list of processes, even though the process itself has terminated and is not using resources.

A zombie process is generally and is supposed to be destroyed by the parent. Generally, the parent `wait()`-s for the child process to terminate. Once the child process is terminated, the parent `wait()` resolves and the process is removed from the list of processes. If done correctly, zombie processes happen all the time but are taken cared of immediately. The problem arises when they are not.

Now, a small amount of zombie processes hanging around is not bad, and is probably normal. (*Remember, the zombie processes have been terminated and are no longer using resources*). However, if there's too many, usually because a parent process is not correctly handling its children, the computer might run out of PID's to give to new processes, effectively making the system unable to run new processes. This is obviously not a desired outcome.

> 3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

A program from a compiled language (*CL*) will run faster than a program from a non-compiled language (*NCL*). Before I explain why, it is worth noting that the computer does not understand source code, the code that humans type in. That code needs to be translated into machine code the computer *does* understand in order for it to be executed.

The performance difference between *CL* program and an *NCL* program arises from when this translation happens. In an *NCL* program, the translation happens generally when the program is executed. The interpreter/engine/what-have-you reads the source code and generally translates it there and then. This is slower because it takes some time to convert source code into machine code, and there are times that there are decisions that need to be made during translation that the what-have-you needs to determine, further slowing things down.

In contrast, the translation and any extra work related to that is done ahead of time in a *CL* language. This means you can not run the program dynamically, because all of the source code needs to be translated up-front. However, after everything has been translated and put into an executable file, the execution is faster because now the computer is now just concerned with executing code it understands. That is, there is no need for extra overhead to translate and arrange things during run-time.

## Task 2

Write a program in C, `lsls.c`, that prints out a directory listing for the
directory the user specifies on the command line. If the user does not specify a
directory, print out the contents of the current directory, which is called `.`.

### Example runs:

```
$ ./lsls
.
..
lsls.c
lsls

$ ./lsls /home/exampleuser
.
..
.config
.vim
.yarnrc
.bashrc
foo.c
.vscode
Downloads
.gitconfig
.bash_history
.viminfo
src
```

**Hint**: Start by just printing out the contents of the current directory `.`,
and then add the command line parsing later after you have it working.

### General approach

_You are expected to use Google to find examples of how to use these functions.
Also see [Details](#details), below._

1. Call `opendir()`.
2. Then repeatedly call `readdir()`--printing the filenames as you go--until it
   lets you know there are no more directory entries by returning `NULL`.
3. Then call `closedir()`.

You don't have to write the three functions, above. They're _system calls_ built
into the OS.

### Details

You will be using functionality included in `<dirent.h>`. This header file holds
the declarations for `DIR`, `struct dirent`, `opendir()`, `readdir()`, and
`closedir()`, below.

* `DIR *opendir(char *path)`: This function opens the directory named in `path`
  (e.g. `.`) and returns a pointer to a variable of type `DIR` that will be used
  later. If there is an error, `opendir()` returns `NULL`.
  
  _You should check for errors. If there is one, print an error message and exit
  (using the `exit()` function)._

* `struct dirent *readdir(DIR *d)`: Reads the next directory entry from the
  `DIR` returned by `opendir()`. Returns the result as a pointer to a `struct
  dirent` (see below). Returns `NULL` if there are no more directory entires.

* `closedir(DIR *d)`: Close a directory (opened previously with `opendir()`)
  when you're done with it.

The `struct dirent *` returned by `readdir()` has the following fields in it:

```c
struct dirent {
  ino_t  d_ino       // file serial number
  char   d_name[]    // file name, a string
};
```

(You don't need to declare this `struct dirent` type. It's already included in
`<dirent.h>`.)

For output, you should print the field `d_name` from your `struct dirent *`
variable, e.g.

```c
struct dirent *ent;

// ... some of your code ...

ent = readdir(d);

printf("%s\n", ent->d_name);
```

To parse the command line, you'll have to look at `argc` and `argv` specified in
your `int main(int argc, char **argv)` function. Example code to print all
command line arguments can be found in [commandline.c](examples/commandline.c).
Modify that example to look at the command line parameters, if any, and pass
those to `opendir()`.

### Stretch Goal: Print file size in bytes

Modify the program to print out the file size in bytes as well as the name.

Example output (suggestion: use `%10lld` to print the size in a field of width
10):

```
$ ./lsls
    224  .
    992  ..
   1722  lsls.c
   8952  lsls
```

You'll need to use the `stat()` call in `<sys/stat.h>`.

* `int stat(char *fullpath, struct stat *buf)`: For a given full path to a file
  (i.e. the path passed to `opendir()` following by a `/` followed by the name
  of the file in `d_name`), fill the fields of a `struct stat` that you've
  pointed to. Returns `-1` on error.

  ```c
  // Example stat() usage

  struct stat buf;

  stat("./lsls.c", &buf);

  printf("file size is %lld\n", buf.st_size);
  ```

### Stretch Goal: Mark Directories

Instead of a size in bytes for a directory (which is marginally useful), replace
the number with the string `<DIR>`.

Example output:

```
$ ./lsls
     <DIR>  .
     <DIR>  ..
      1717  lsls.c
      8952  lsls
```

The `st_mode` field in the `struct stat` buffer holds information about the file
permissions and type of file.

If you bitwise-AND the value with `S_IFDIR` and get a non-zero result, the file
is a directory.

(If you bitwise-AND the value with `S_IFREG` and get a non-zero result, the file
is a regular file, as opposed to a device node, symbolic link, hard link,
directory, named pipe, etc.)
