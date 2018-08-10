#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */

int main(int argc, char **argv)
{
  // PARSE COMMAND LINE
  char *directory_name;

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
    fprintf(stderr, "You have entered more than one directory name. Enter only one. Sample: ./lsls [your_directory_name]\n");
    exit(1);
  }

  // OPEN DIRECTORY
  DIR *directory = opendir(directory_name);

  // Check if directory is open
  if (directory == NULL)
  {
    fprintf(stderr, "Error in opening directory.");
    exit(1);
  }

  // REPEATEDLY READ AND PRINT ENTRIES
  struct dirent *entry;

  while ((entry = readdir(directory)) != NULL)
  {
    char path[20000];
    struct stat stat_buf;

    // We need the full path
    snprintf(path, sizeof(path), "%s/%s", directory_name, entry->d_name);

    if (stat(path, &stat_buf) == -1)
    {
      fprintf(stderr, "Failed to show the stats for %s.\n", path);
      exit(2);
    }

    if (stat_buf.st_mode & S_IFREG)
    {
      // Print the file name and its size in bytes
      printf("%20lld %s\n", stat_buf.st_size, entry->d_name);
    }

    else if (stat_buf.st_mode & S_IFDIR)
    {
      // Directory name
      printf("%20lld %s\n", "<DIR>", entry->d_name);
    }
    else
    {
      printf("%10s %s\n", " ", entry->d_name);
    }
  }

  // CLOSE DIRECTORY
  closedir(directory);

  return 0;
}