#include <stdio.h>

#include <dirent.h> //let's us open directory

#include <stdlib.h>

#include <sys/stat.h>

//https://linux.die.net/man/3/opendir

/**
 * Main
 */
// Parse command line

// check the count of argc,

// `.` means current dir

// argv[1] = dirname
int main(int argc, char **argv)
{
  char *dirname; //hold whatever arg passed
  // Parse command line

  if (argc == 1)
  {
    //argc by default is 1 can not be 0 name of program is 1
    //set the directory that were going to be looking at tp "."
    dirname = ".";
  }
  else if (argc == 2)
  {
    //second arg
    dirname = argv[1];
  }
  else
  {
    //standard error message
    fprintf(stderr, "usage: lsls [dirname]\n ");
    //return 1; would work to end program
    exit(1);
  }
  //Open directory
  // DIR *d;
  // struct dirent *dir;
  // d = opendir(dirname);

  DIR *d = opendir(dirname);

  // The DIR data type represents a directory stream. It's declared in the header `dirent.h`
  if (d == NULL)
  {
    fprintf(stderr, "lsls: cannot open directory %s\n", dirname);
    
    exit(2);
  }

  // If find NULL, means no content in that dir
  //single directory entry
  //repeatly read and print entries
  //To define a structure, you must use the struct statement. The struct statement defines a new data type,
  struct dirent *entry;

  while ((entry = readdir(d)) != NULL)
  {
    //stat the entry
    char fullpath[8192];     
    // 8192 bytes is size that for a buffer to read and write. 
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dirname, entry->d_name); //snprintf is essentially a function that redirects the output of printf to a buffer.
   
    struct stat stat_buf;

    if (stat(fullpath, &stat_buf) < 0)
    {

      fprintf(stderr, "lsls: failed to stat file %s\n", fullpath);

      exit(3);
    }

      // stat_buf->st_size == (*stat_buf).st_size;
    
     
      printf("%lld %s\n", stat_buf.st_size, entry->d_name);
  }

   
   closedir(d);

  return 0;
}
