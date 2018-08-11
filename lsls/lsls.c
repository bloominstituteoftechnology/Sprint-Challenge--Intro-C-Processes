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
    // how to run command: ./lsls ../examples or ./lsls ../
  }
  else
  {
    fprintf(stderr, "Too many arguments. Please provide only one directory name. Example: ./lsls <dir name>\n");
    exit(1);
  }
  // Open directory

  DIR *directory = opendir(dir_name); // directory is the handle to the directroy stream opened by opendir

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
    struct stat buf; // obtains information about the named file

    // Code below only works for current dir: per http://pubs.opengroup.org/onlinepubs/009695399/functions/realpath.html -> The realpath() function shall derive, from the pathname pointed to by file_name, an absolute pathname that names the same file, whose resolution does not involve '.', '..', or symbolic links.
    // char *fullpath = realpath(entry->d_name, NULL); /*resource used for realpath() ->
    // https://www.linuxquestions.org/questions/programming-9/how-to-get-the-full-path-of-a-file-in-c-841046/
    // post by member named Basel*/

    // alternatively, below works for all dirs:
    char fullpath[20000];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dir_name, entry->d_name);

    if(stat(fullpath, &buf) < 0)  // Returns -1 on error.  
        exit(1);

    /* checking to see if the file is a directory, 
    if yes then print<DIR> and name of dir, instead of size in bytes*/
    else if (buf.st_mode & S_IFDIR) { 
      printf("%10s %s\n", "<DIR>", entry->d_name); /* operator ( -> ) in C is used to access a member of a struct 
    which is referenced by the pointer in question */
    }

    /* if no, then print size in bytes and name of file*/
    else {
      printf("%10lld %s\n", buf.st_size, entry->d_name);
    }
  }
  
  // Close directory
  closedir(directory);

  return 0;
}