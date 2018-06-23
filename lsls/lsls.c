#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  /*
  `DIR *opendir(char *path)`: This function opens the directory named in `path`
  (e.g. `.`) and returns a pointer to a variable of type `DIR` that will be used
  later. If there is an error, `opendir()` returns `NULL`.
  */
  DIR *filePath; 

  /*
  `struct dirent *readdir(DIR *d)`: Reads the next directory entry from the
  `DIR` returned by `opendir()`. Returns the result as a pointer to a `struct
  dirent` (see below). Returns `NULL` if there are no more directory entires.
  */
  struct dirent *ent;
//hello
  // char **errorCode; 
  /*
   If the user does not specify a directory print out the contents of the current directory,
    which is called `.`
  */
  if(argc < 2) {
    filePath = opendir("."); 
  } else { // provieded a directory as the first args 
    filePath = opendir(argv[1]); 
  }
  // Open directory

  if(filePath == NULL) { // if argv[1] --> invalid
     printf ("Cannot open directory --> '%s'\n", argv[1]);
     exit(1); 
  } 
/*
https://www.gnu.org/software/libc/manual/html_node/Opening-a-Directory.html

http://man7.org/linux/man-pages/man3/opendir.3.html

The opendir() and fdopendir() functions return a pointer to the
directory stream.  On error, NULL is returned, and errno is set
appropriately.



EACCES
Read permission is denied for the directory named by dirname.

EMFILE
The process has too many files open.

ENFILE
The entire system, or perhaps the file system which contains the directory, cannot support any additional open files at the moment. (This problem cannot happen on GNU/Hurd systems.)

ENOMEM
Not enough memory available.

  else if(opendir(filePath) == NULL) {
  fprintf("error code --> %s", errno); 
    switch(errno){
      case EACCES:
      case EMFILE:
      case ENFILE:
      case ENOMEM:
    }
  }
*/
  
  //test commit



  // Repeatly read and print entries
  while ((ent = readdir(filePath)) != NULL) { //Returns `NULL` if there are no more directory entires.
    printf ("[%s]\n", ent->d_name);

  }


  // Close directory
  closedir(filePath); 
  return 0;
}
// test
// ./lsls
//./lsls 'C:\Lambda\IntroToC\Sprint-Challenge--Intro-C-Processes\examples\'
