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

  if(argc < 2) {
    filePath = opendir("."); 
  } else {
    filePath = opendir(argv[1]); 
  }
  // Open directory

  if(filePath == NULL) { // if no argv[1] --> invalid
     printf ("Cannot open directory --> '%s'\n", argv[1]);
     exit(1); 
  } 

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
