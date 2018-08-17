#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

void ls_directory(const char *directory_name)
{
  /* DIR type is defined in <dirent.h> and represents an ordered sequence of all the directory entries in a directory */
  DIR *directory;
  struct dirent *entry;
  struct stat file_stat;

  /* Open directory: 
  opendir() returns a pointer to an object of type DIR if successful.
  if unsuccessful, opendir() returns a null pointer.
  */
  directory = opendir(directory_name);
  if (directory != NULL)
  {
    printf("\n***Start of ls call to %s***\n", directory_name);
    printf("\n%10s\t%10s\t%10s\t%10s\t%10s\t%s\n", "Size/Directory", "Links", "UserID", "GroupID", "Permissions", "Name");
    
      /* Repeatly read and print entries:
       readdir() returns a pointer to a structure representing the directory entry at the current position in the directory stream
       it returns a null pointer when it reaches the end of the directory entries */
    while ((entry = readdir(directory)) != NULL)
    {
      // create an array big enough to contain the full path
      char path[sizeof(directory_name) + sizeof(entry->d_name)];

      // sends formatted output to the string 'path'
      sprintf(path, "%s/%s", directory_name, entry->d_name);

      // stat needs a full path in order to access it
      // pass in the newly created path array
      if (stat(path, &file_stat) == -1)
      {
        fprintf(stderr, "%s\n", strerror(errno));
      }
      if ((S_ISDIR(file_stat.st_mode)))
      {
        printf("%10s\t%10u\t%10u\t%10u\t%10lo\t%s\n", "<DIR>", file_stat.st_nlink, file_stat.st_uid, file_stat.st_gid, (unsigned long) file_stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO), entry->d_name);
      }
      else
      {
        printf("%10lld\t%10u\t%10u\t%10u\t%10lo\t%s\n", file_stat.st_size, file_stat.st_nlink, file_stat.st_uid, file_stat.st_gid, (unsigned long) file_stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO), entry->d_name);
      }
    }
    printf("***End of ls call to %s***\n\n", directory_name);

  /* Close directory
  closedir closes the directory and returns 0 if the directory is successfully closed, if unsuccessful, -1 is returned
  The two ways in which closedir can fail are if the argument it is passed is not an open directory or if the function is interrupted by a signal */
    closedir(directory);
  }
  else
  {
    printf("Cannot open directory %s\n", directory_name);
    exit(1);
  }
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;
  i = 1;

  // the first argument in argv is always going to be the file name that takes every argument after as an argument to ls
  while (i < argc)
  {
    ls_directory(argv[i]);
    i++;
  }

  if (argc == 1)
  {
    ls_directory(".");
  }

  return 0;
}