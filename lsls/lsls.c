#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */

/*The opendir() function opens a directory stream corresponding to the directory name, 
and returns a pointer to the directory stream. The stream is positioned at the first 
entry in the directory.*/

int main(int argc, char **argv)
{
  // Parse command line  
  // check the count of argc, 
  // `.` means current dir
  // argv[1] = dirname

  char *dirname;

  if (argc == 1)
  {
    dirname = ".";
  }
  else if (argc == 2)
  {
    dirname = argv[1];
  }
  else
  {
    fprintf(stderr, "./lsls [dirname]\n");
    exit(1); // can return 1 too 
  }

  // Open directory
  // The DIR data type represents a directory stream. It's declared in the header `dirent.h`
  DIR *d;
  struct dirent *dir;
  d = opendir(dirname); 
  
  // if error, `opendir()` returns NULL
  if (d == NULL)
  {
    fprintf(stderr, "./lsls: cannot open directory %s\n", dirname);
    exit(1); // from solution, should be exit(2) because it's different exit from above.
  }
  // Repeatly read and print entries
  // If find NULL, means no content in that dir
  while((dir = readdir(d)) != NULL)
  {
    printf("%s\n", dir->d_name);
  }

  // stretch
  /*
  while((dir = readdir(d)) != NULL)
  {
    // stat the entry
    char fullpath[8192];  // 8192 bytes is size that for a buffer to read and write. Fairly arbitary.
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dirname, entry->d_name);
    struct stat stat_buf;

    if (stat(fullpath, &stat_buf) < 0)
    {
      fprintf(stderr, "lsls: failed to stat file %s\n", fullpath);
      exit(3);
    }

    if (S_ISREG(stat_buf.st_mode))
    {
      printf("%10lld %s\n", stat_buf.st_size, entry->d_name);
    }
    else if (S_ISDIR(stat_buf.st_mode))
    {
      printf("%10s %s\n", "<DIR>", entry->d_name);
    }
    else
    {
      printf("%10s %s\n", "", entry->d_name);
    }
  }
  */

  // Close directory
  closedir(d);
  
  return 0;
}