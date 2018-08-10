#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *directory;
  char *target; 
  struct dirent *directory_entry;
  struct stat buf;
  char path[30];

  // Parse command line

  //check to see if user entered a directory name
  if (argc < 2)
  {
    target = strdup("."); 
    printf("Usage: %s <directory>\n", argv[0]);
    printf("Listing current directory: \"%s\"\n", target);
  }
  else
  {
    target = strdup(argv[1]);
    printf("Listing directory: \"%s\"\n", target);
  }

  // Open directory

  directory = opendir(target);

  if(directory == NULL)
  {
    fprintf(stderr, "Can't open directory: %s\n", target);
    exit(128);
  }

  // Repeatly read and print entries
  while ((directory_entry = readdir(directory)) != NULL)
  {
    path[0]='\0';
    strcat(path,target);
    strcat(path,"/");
    strcat(path,directory_entry->d_name);
    
    stat(path, &buf);
    printf("%10ld %s\n", buf.st_size, directory_entry->d_name);
  }


  // Close directory

    closedir(directory);

  return 0;
}