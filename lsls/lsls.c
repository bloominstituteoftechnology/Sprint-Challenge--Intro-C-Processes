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
  /*
  char *filename;

  if (argc == 1)
  {
    filename = "index.c";
    printf("We passed in no arguments.\n");
  }

  else if (argc == 2)
  {
    filename = argv[1];
    printf("We passed in the file %s \n", filename);
  }

  else
  {
    fprintf(stderr, "You have entered more than one directory name. Enter only one. Sample: ./lsls [your_file_name]\n");
    exit(1);
  }
  */

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
  /*
  DIR *directory = opendir(".");
  char *result = directory == NULL ? "Did not open" : "Successful!";
  printf("Testing opening a directory: %s\n", result);
  closedir(directory);
  */

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
    printf("%s\n", entry->d_name);
  }

  // CLOSE DIRECTORY
  closedir(directory);

  /*
  struct stat file_stat;

  while (argc-- > 1)
  {
    if (lstat(argv[argc], &file_stat) == -1)
    {
      fprintf(stderr, "%s\n", strerror(errno));
    }
    else
    {
      fprintf(stdout, "Links\tUid\tGid\tSize\tName\n");
      fprintf(stdout, "%u\t%u\t%u\t%u\t%s\n", file_stat.st_nlink,
              file_stat.st_uid, file_stat.st_gid, file_stat.st_size,
              argv[argc]);
    }
  }
  */

  return 0;
}