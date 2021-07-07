#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h> //for the stat() call
//http://www2.cs.uregina.ca/~hamilton/courses/330/notes/unix/lsl.html
/**
 * Main
 */
int main(int argc, char **argv)//argv to process commend-line arguments
//two predefined variables - the count of the command-line arguments in argc 
//and the individual arguments as character strings in the pointer array argv
{
  
  struct dirent *pDirent;//Reads the next directory entry from the DIR* returned by opendir()
  DIR *pDir;//way to use the opendir function
  struct stat sizebuf;
  // Parse command line
  if (argc < 2) {
    printf("Usage: ./lsls directory");
    exit(1);//using exit() function
  }

  // Open directory
  pDir = opendir(argv[1]);// opens the directory and returns a pointer to a variable of type DIR that will be used later. 
  if (pDir == NULL) { //If there is an error, opendir() returns NULL.
    printf("Cannot open directory '%s'\n", argv[1]);// The individual values of the parameters may be accessed with argv[1]
    exit(1); //using exit() function
  }
  // Repeatly read and print entries

  while ((pDirent = readdir(pDir)) != NULL) {
    stat(pDirent->d_name, &sizebuf);//getting size
    if ((sizebuf.st_mode & S_IFDIR) != 0) {
      printf("\t<DIR>  %s\n", pDirent->d_name);
    } else {
      printf("file size is %10ld  %s\n", sizebuf.st_size, pDirent->d_name);//use %10ld to print the size in a field of width 10
    }
  }

   // Close directory 
  closedir(pDir);//Close a directory (opened previously with opendir()) when done
  return 0;

 }