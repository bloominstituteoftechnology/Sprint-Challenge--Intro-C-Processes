#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path;
  // Check for empty command line
  if (argc > 1)
  {
    path = argv[1];
  }
  else
  {
    path = ".";
  }

  // Open directory
  DIR *directory = opendir(path);
  // Check if directory could not be opened.
  if (directory == NULL)
  {
    printf("Directory could not be opened: %s\n", path);
    exit(1);
  }

  // Repeatly read and print entries
  struct dirent *ent;
  struct stat buf;
  char *fp;

  while ((ent = readdir(directory)) != NULL)
  {
    fp = malloc(strlen(path) + strlen(ent->d_name) + 1);

    if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
    {
      sprintf(fp, "%s/%s", path, ent->d_name);
    }
    else
    {
      sprintf(fp, "%s", ent->d_name);
    }

    stat(fp, &buf);

    printf("%10ld %s\n", buf.st_size, ent->d_name);
    free(fp);
  }

  // Close directory

  return 0;
}