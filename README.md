# Sprint-Challenge: Intro To C - File Directories

This challenge allows you to practice the concepts and techniques learned over the past week and apply them in a concrete project. This Sprint explored introductory C programming concepts. During this Sprint, you studied C syntax, a computer's memory model, structs, and system calls. In your challenge this week, you will demonstrate proficiency of these concepts by creating an application that prints out a directory listing for the directory the user specifies on the command line.

## Instructions

**Read these instructions carefully. Understand exactly what is expected _before_ starting this Sprint Challenge.**

This is an individual assessment. All work must be your own. Your challenge score is a measure of your ability to work independently using the material covered through this sprint. You need to demonstrate proficiency in the concepts and objectives introduced and practiced in preceding days.

You are not allowed to collaborate during the Sprint Challenge. However, you are encouraged to follow the twenty-minute rule and seek support from your PM and Instructor in your cohort help channel on Slack. Your work reflects your proficiency introductory C programming and your command of the concepts and techniques in the system calls module.

You have three hours to complete this challenge. Plan your time accordingly.

## Commits

Commit your code regularly and meaningfully. This helps both you (in case you ever need to return to old code for any number of reasons and your project manager.

## Description

In this challenge, you will write a program in C, `lsls.c`, that prints out a directory listing for the
directory the user specifies on the command line. The directory listing will include both file names and sizes. If the user does not specify a
directory, print out the contents of the current directory, which is called `.` 

### Example runs:  

```
$ ./lsls
     224  .
     992  ..
    1722  lsls.c
    8952  lsls
```

```
$ ./lsls ../../../../Documents
       512  .
       832  ..
 412867798  part2.mov
 412079176  part1.mov
      8196  .DS_Store
     20094  screenshot.png
         0  .localized
   8166430  report.pdf
       512  GitHub
       448  Zoom
```


In meeting the minimum viable product (MVP) specifications listed below, your application will be able to display all files and folders in the specified directory as demonstrated in the above snippet. 

## Self-Study/Essay Questions

Demonstrate your understanding of this week's concepts by answering the following free-form questions. Edit the `Answers.md` document to include your answers after each question. Make sure to leave a blank line above and below your answer so it is clear and easy to read by your project manager.

1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

2. What is a zombie process? 

3. How does a zombie process get created? How does one get destroyed?

4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

You are expected to be able to answer all these questions. Your responses contribute to your Sprint Challenge grade. Skipping this section *will* prevent you from passing this challenge.

## Project Set Up

***_The code for the coding task needs a Unix-like environment to work! That includes
Linux, macos, Cygwin, WSL, BSD, etc._***

If you want to test if your environment is set up correctly, compile and run the
[testdir.c](examples/testdir.c) program in the `examples/` directory. (You can
type `make` in the `examples/` directory.) It should print `Testing: PASS`.

### Follow the general approach outlined below to get started on your project:

1. Call `opendir()`.
2. Then repeatedly call `readdir()`--printing the filenames as you go--until it
   lets you know there are no more directory entries by returning `NULL`.
3. Then call `closedir()`.

  You don't have to write the three functions, above. They're _system calls_ built into the OS.

>**Hint** _You are expected to use Google to find examples of how to use these functions._

### Accessing Directories

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

### File Sizes

For each entry in a directory, your program should print its size in bytes. 

To get the size of entries, you'll need to use the `stat()` call in `<sys/stat.h>`.
  - `int stat(char *fullpath, struct stat *buf)`: For a given full path to a file
  (i.e. the path passed to `opendir()` following by a `/` followed by the name
  of the file in `d_name`), fill the fields of a `struct stat` that you've
  pointed to. Returns `-1` on error.

  >**Hint**: Use `%10lld` to print the size in a field of width 10

  ```c
  // Example stat() usage

  struct stat buf;

  stat("./lsls.c", &buf);

  printf("file size is %lld\n", buf.st_size);
  ```

 > Note: The specification for the `stat` system call does not specify exactly how directories should be treated. This means you might see weird behavior when your `lsls` prints out the sizes of directories, such all their sizes being 0 or all their sizes being 512, or some other such strange behaviors. This is not a mistake on your part, it was simply just not specified how this should work as part of the spec.

## Minimum Viable Product

Your finished project must include all of the following requirements:

- Thoughtful, complete answers to the questions in the Self-Study/Essay section
- Program that allows the user to specify the target directory on the command line and prints out the:
  - names of all entries in that directory
  - size of each entry in bytes

In your solution, it is essential that you follow best practices and produce clean and professional results. Schedule time to review, refine, and assess your work and perform basic professional polishing including spell-checking and grammar-checking on your work. It is better to submit a challenge that meets MVP than one that attempts to much and does not.

Validate your work through testing and ensure that your code operates as designed.

## Stretch Problems

After finishing your required elements, you can push your work further. These goals may or may not be things you have learned in this module but they build on the material you just studied. Time allowing, stretch your limits and see if you can deliver on the following optional goals:

- **Mark Directories**

    Instead of a size in bytes for a directory (which is marginally useful), replace
    the number with the string `<DIR>`.

    Example output:

    ```
    $ ./lsls ../../../../Documents
        <DIR>  .
        <DIR>  ..
    412867798  part2.mov
    412079176  part1.mov
          8196  .DS_Store
        20094  screenshot.png
            0  .localized
      8166430  report.pdf
        <DIR>  GitHub
        <DIR>  Zoom
    ```

    The `st_mode` field in the `struct stat` buffer holds information about the file permissions and type of file.

    If you bitwise-AND the value with `S_IFDIR` and get a non-zero result, the file is a directory.

    (If you bitwise-AND the value with `S_IFREG` and get a non-zero result, the file is a regular file, as opposed to a device node, symbolic link, hard link, directory, named pipe, etc.)

- **Expand the Hierarchy**

    Sometimes it can be helpful to see multiple levels of the file system simultaneously. Expand your program so that it prints entries in two levels of the file system - both the directory specified by the user AND all entries one level below that directory. Essentially, print out all items in the folder specified AND, for any folders in that location, also print out their contents. Use whitespace to clearly differentiate between the different levels.

    Example output:
```
    $ ./lsls ../../../../Documents
        <DIR>  .
                <DIR>  .
                <DIR>  ..
            412867798  part2.mov
            412079176  part1.mov
                  8196  .DS_Store
                20094  screenshot.png
                    0  .localized
              8166430  report.pdf
                <DIR>  GitHub
                <DIR>  Zoom
        <DIR>  ..
                <DIR>  .
                <DIR>  ..
                <DIR>  Pictures
                <DIR>  Desktop
                <DIR>  Applications
                <DIR>  Documents
                <DIR>  Downloads
    412867798  part2.mov
    412079176  part1.mov
          8196  .DS_Store
        20094  screenshot.png
            0  .localized
      8166430  report.pdf
        <DIR>  GitHub
                <DIR>  Intro-Python
                <DIR>  DS-Algorithms
                <DIR>  Graphs
                <DIR>  Intro-to-C
        <DIR>  Zoom
                10244  .DS_Store
                <DIR>  2018-6-09 18.05.23 Ashton Kutcher's Zoom Meeting 683704137
                <DIR>  2018-7-13 18.43.13 Nat Friedman's Zoom Meeting 917598981
                <DIR>  2018-8-19 18.12.21 Stewart Butterfield's Zoom Meeting 157190585
                <DIR>  2018-11-26 18.01.33 Austen Allred's Zoom Meeting 870798944
```
