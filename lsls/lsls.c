#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dirid;
  // Parse command line
  if (argc == 1)
  {
    dirid = '.';
  }
  else if (argc == 2)
  {
    dirid = argv[1];
  }
  else
  {
    printf("Please input a correct directory name.\n");
    printf("Syntax: lsls [directory]");
    exit(2); //exit because of inappropriate arguments
  }

  // Open directory
  DIR *dirpoint = opendir(dirid);
  if (dirpoint == NULL) // checking if directory exists based on DIR return
  {
    printf("This directiory cannot be found or opened: %s\n", dirpoint);
    exit(1); // exit if directory name not found 
  }

  // Repeatly read and print entries
  struct dirent *entrypoint;
  while (entrypoint = readdir(dirpoint))
  {
    puts(entrypoint->d_name);
  }
  // Close directory
  closedir(dirpoint);

  return 0;
}