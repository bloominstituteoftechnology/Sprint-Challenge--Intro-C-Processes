#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

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
    
  getcwd() - get the pathname of the current working directory
    *

*/
int main(int argc, char **argv)
{
  DIR *directory; // dirp
  struct dirent *readDIR;
  char *cwd, cwdBuffer[314];

  // No DIR is specified. Print the current DIR.
  if (argc == 1)
  {
    cwd = getcwd(cwdBuffer, sizeof(cwdBuffer));
    directory = opendir(cwd);

    if (directory == NULL) printf("Failed to open the CWD: %s \n", cwd);

    else 
    {
      while ((readDIR = readdir(directory)) != NULL)
      {
        printf("%s \n", readDIR->d_name);
      }

      closedir(directory);
    }
  }

  // DIR has been specified. argc = 2. Specified DIR = argv[1].
  else
  {
    directory = opendir(argv[1]);

    if (directory == NULL) printf("Failed to open the specified directory: %s \n", argv[1]);

    else
    {
      while ((readDIR = readdir(directory)) != NULL)
      {
        printf("%s \n", readDIR->d_name);
      }

      closedir(directory);
    }
  }

  return 0;
}