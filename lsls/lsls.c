#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if (argc < 2)
	{
		// Print current dir entries
    void *dir = opendir(".");

    if (dir == NULL)
    {
      printf("%d\n", errno);
      exit(1);
    }
	}
  else
  {
    // Print argv[1] entries

  }
  
  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}