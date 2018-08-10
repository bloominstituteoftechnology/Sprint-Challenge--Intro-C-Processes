#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * Main
 */

int main(int argc, char **argv)
{
  char *directory_name;
  DIR *directory;
  struct dirent *ent;
  struct stat stat_buf;

  // Parse command line
  if (argc == 1)
  {
    directory_name = ".";
  }
  else if (argc == 2)
  {
    directory_name = argv[1];
  }
  else
  {
    fprintf(stderr, "Too many arguments. Usage: ./lsls [directory name]\n");
    exit(1);
  }

  // Open directory
  directory = opendir(directory_name);

  // check if directory is open
  if (directory == NULL)
  {
    fprintf(stderr, "Error opening directory");
  }

  // Repeatly read and print entries

  while ((ent = readdir(directory)) != NULL)
  {
      stat(ent->d_name, &stat_buf);
      if (stat_buf.st_mode & S_IFDIR)
      {
        printf("%10s %s\n", "<DIR>", ent->d_name);
      }
      else
      {
        printf("%10llu %s\n", stat_buf.st_size, ent->d_name);
      }
    }

    // Close directory
    closedir(directory);

    return 0;
  }