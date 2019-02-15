#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir;

  if (argc == 2)
  {
    dir = argv[1];
  }
  else if (argc < 2)
  {
    dir = ".";
  }
  else if (argc > 2)
  {
    printf("Input Error: check path syntax\n");
    exit(1);
  }
  // Open directory
  DIR *d = opendir(dir);

  if (d == NULL)
  {
    printf("Error\n");
    exit(1);
  }
  // Repeatly read and print entries
  struct dirent *entry;
  struct stat buf;
  char pathName[100];

  while ((entry = readdir(d)) != NULL)
  {
    strcpy(pathName, dir);
    strcat(pathName, "/");
    strcat(pathName, entry->d_name);

    stat(pathName, &buf);
    printf("%10ld %s\n", buf.st_size, entry->d_name);
  }

  // Close directory
  closedir(d);

  return 0;
}