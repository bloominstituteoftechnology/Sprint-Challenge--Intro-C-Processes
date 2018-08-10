#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dir_name;
  // Parse command line
  if (argc == 1)
  {
    dir_name = ".";
  }
  else if (argc == 2)
  {
    dir_name = argv[1];
    // how to run command: ./lsls ../examples
  }
  else
  {
    fprintf(stderr, "Too many arguments. Please provide only one directory name. Example: ./lsls <dir name>\n");
    exit(1);
  }
  // Open directory

  DIR *directory = opendir(dir_name);

  if (directory == NULL) // If there is an error, opendir() returns NULL
  {
    printf("Error incurred while opening directory.");
    exit(1);
  }

  // Repeatedly read and print entries
  struct dirent *entry;

  /* readdir() returns the result as a pointer to a struct dirent.
  Returns NULL if there are no more directory entires.*/
  while ((entry = readdir(directory)) != NULL) 

  {
    struct stat buf;
    
    char *fullpath = realpath(entry->d_name, NULL); /*resource used for realpath() ->
    https://www.linuxquestions.org/questions/programming-9/how-to-get-the-full-path-of-a-file-in-c-841046/
    post by member named Basel*/

     if(stat(fullpath, &buf) < 0)  // Returns -1 on error.  
        exit(1);

     printf("file/dir name: %s  size: %lld\n", entry->d_name, buf.st_size); /* operator ( -> ) in C is used to access a member of a struct 
     which is referenced by the pointer in question */
    //  printf("file size is %10lld\n", fileStat.st_size);
  }
  
  // Close directory
  closedir(directory);

  return 0;
}