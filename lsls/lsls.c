#include <stdio.h>
#include <dirent.h>

/*

  1. accept some user input that specifies a directory 
  2. `ls` / print the files/directories listed in the specified directory
  3. if the user does not specify a directory, `ls` their current directory `.`

  opendir() - opens a DIR stream corresponding to the DIR name
    * returns a pointer to the DIR stream
    * returns NULL if there is an error
  
  readdir() - read a directory 
    * returns a pointer to a `dirent` structure representing the next DIR entry in the provided DIR stream pointed to by `dirp`
    * retuns NULL upon reaching the end of the DIR stream or if an error was encountered 
  
  closedir() - close a directory
    * closes the DIR stream associated with `dirp`
    * also closes the underlying file descriptor associated with `dirp`
    * returns 0 on success
    * returns -1 on failure

*/
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}