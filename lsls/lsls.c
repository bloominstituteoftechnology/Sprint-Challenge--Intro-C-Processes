#include <stdio.h>
#include <stdlib.h> // Holds exit() system call
#include <sys/stat.h> // Holds the stat() system call
#include <dirent.h> // Holds the declarations for DIR, struct dirent, and the system calls opendir(), readdir(), and closedir()

/**
 * Main
 */

int main(int argc, char **argv)
{
  // 1. PARSE COMMAND LINE
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

  // 2. OPEN DIRECTORY
  // opendir() opens the folder named in path or specified by the user.
  // DIR is a type
  DIR *directory = opendir(directory_name);

  // Check if directory is open
  if (directory == NULL)
  {
    fprintf(stderr, "Error in opening directory.");
    exit(2);
  }

  // 3. REPEATEDLY READ AND PRINT ENTRIES
  // Pointers are just references
  struct dirent *entry;

  // readdir() reads and prints the folder specified by the user
  while ((entry = readdir(directory)) != NULL)
  {
    // Allocate for arrap
    char path[10000];    
    // snprintf - formats and stores a series of characters and values in the array buffer
    // Path - the full path or buffer/temporary storage of data
    // Path, size of the path, and its format
    snprintf(path, sizeof(path), "%s/%s", directory_name, entry->d_name);
    // Stat the entry - store the entry/data about the file/folder in a structure
    struct stat stat_buf;

    // Address of the stat_buf
    if (stat(path, &stat_buf) < 0)
    {
      fprintf(stderr, "Failed to show the stats for %s.\n", path);
      exit(3);
    }

    // S_ISREG - macro for interpreting the values in the stat_buf
    if (S_ISREG(stat_buf.st_mode))
    {
      // Print the file name and its size in bytes
      printf("%20lld  %s\n", stat_buf.st_size, entry->d_name);
    }
  }

  // 4. CLOSE DIRECTORY
  closedir(directory);

  return 0;
}