#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *ent;
  DIR *d;
  int count;
  int EXIT_SUCCESS;
  int EXIT_FAILURE;
  // Parse command line

  // Open directory
  ent = opendir(argv[0]);
  if (count == 0)
  {
    if (ent)
    {
      puts("Ok the folder is open");
    }
    else
    {
      return NULL;
    }
  }

  // Repeatly read and print entries
  ent = opendir(argv[0]);
  if (d != NULL)
  {
    for (;;)
    {
      ent = readdir(d);
      if (d == NULL)
        break;

      printf("%s\n", ent->d_name);
    }
    closedir(d);
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;

  // Close directory
  if ((ent = opendir("/")) == NULL)
  {
    perror("opendir() error");
  }
  else
  {
    count = 0;
    while ((ent = readdir(d)) != NULL)
    {
      printf("directory ent: %s\n", ++count, ent->d_name);
    }
    closedir(d);
  }

  return 0;
}