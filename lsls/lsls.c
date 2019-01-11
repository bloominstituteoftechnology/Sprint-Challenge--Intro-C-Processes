#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // initialize dir as a the DIR data type with a pointer.
  DIR *dir = opendir(argv[1]);

  // this is the struct which refers to the DIR entry and allows certain methods on it like d_name
  struct dirent *pDir;

  // if there is less than 2 in the argument count then there has not been a path specified, so show the current directory contents.
  if (argc < 2)
  {
    // show current if no args
    dir = opendir(".");
  }
  else
  {
    // if the path is not valid then show an error in the command line.
    if(dir == NULL)
    {
      // invalid directory
      printf("Unable to open directory: %s\n", argv[1]);
      // exit

  return 0;
  }
}

 // loop through 
  while((pDir = readdir(dir)) != NULL)
  {
    // print off the name of the entry via d_name method
    printf("%s\n", pDir->d_name);
  }

  // close directory
  closedir(dir);

  return 0;
}