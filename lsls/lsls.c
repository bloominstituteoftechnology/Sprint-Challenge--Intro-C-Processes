#include <stdio.h>
// dirent.h contains the declarations for the opendir(), readdir(), and closedir() system calls.
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
    fprintf(stderr, "You've inputed too many arguments. Correct input: ./index2 [your_directory_name]\n");
    exit(1);
  }


  // OPEN DIRECTORY
  DIR *directory = opendir(directory_name);

  // Check if directory is open
  if (directory = NULL)
  {
    fprintf(stderr, "Error in opening directory.\n");
  }

  // REPEATEDLY READ AND PRINT ENTRIES
  struct dirent *ent;

  while ((ent = readdir(directory)) != NULL)
  {
    char path[20000];
    struct stat stat_buf;

    // We need the full path
    snprintf(path, sizeof(path), "%s/%s", directory_name, ent->d_name);

    if (stat(path, &stat_buf) == -1)
    {
      fprintf(stderr, "Failed to show the stats for %s.\n", path);
      exit(2);
    }

    if (stat_buf.st_mode & S_IFREG)
    {
      // Print the file name and its size in bytes
      printf("%20lld %s\n", stat_buf.st_size, ent->d_name);
    }

    else if (stat_buf.st_mode & S_IFDIR)
    {
      // Directory name
      printf("%20lld %s\n", "<DIR>", ent->d_name);
    }

    else
    {
      printf("%10s %s \n", " ", ent->d_name);
    }
  }

  // Close directory
  closedir(directory);

  return 0;
}