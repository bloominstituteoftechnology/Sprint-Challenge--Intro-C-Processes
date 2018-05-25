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

1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

States are `created`, `ready`, `running`, `blocked`, and `terminated`. 

`Created`: this is when the process first starts, it is created, also called 'new state'. Then it enters
the `ready`state. 

`Ready`: also called 'waiting' is the process when the main memory is awaiting to
execute to the `CPU`, done by the dispatch or short term scheduler. There can be multiple processes at one point. 

`Running`: when the process is chosen to execute, then it goes into the running state. It will execute
processing instructions by one of the `CPU`'s of the system. Within the `running` state there are two modes,
the `kernel mode`, and `user mode`. 

`Blocked`: is the state where there may occur a block, where the process can't carry on without an external change in state. One example can be a block call on to an I/O device like a fax machine, it may be unavailable. Lastly, we have the state 

`Terminated`: this process can be terminated from the running state by finishing up the execution or by being stuck where it is not executing, leaving it in a process table where it is waiting for execution. 

2. What is a zombie process? How does one get created? How does one get destroyed? 

`Zombie process`: it is the process that has been completed but it is the 'process table', it is the the final state, called the terminated state. The child is waiting for entry from the parent to read the child's exit status. It can get destroyed or exited by the `wait` system call.

3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code? 

With a compiled language you the code can be faster compared to the those translated at run time, because theres a translation process. It is more of a one to one with the code and the hardware operations being performed by machine code, making it easier for the programmers to control the use of the CPU and memory with better detail. 




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
