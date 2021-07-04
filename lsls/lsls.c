#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if (argc < 2) {
    printf("Usage: %s <directory name>\n", argv[0]);
    return 0;
  }

  // Open directory
  DIR *directory;
  struct dirent *entry;

  if((directory = opendir(argv[1])) == NULL)
  {
    perror("opendir");
    return 0;
  }

  // Repeatly read and print entries
  int i = 0;
  while ((entry = readdir(directory)) != NULL) 
  {
    i++;
    printf("\n%s", entry -> d_name );
  }
  // Close directory
  if (closedir(directory) == -1) 
  {
    perror("closedir");
    return 0;
  }

  return 0;
}