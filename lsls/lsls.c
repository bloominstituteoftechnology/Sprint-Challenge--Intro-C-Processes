#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
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
    fprintf(stderr, "Usage: ./lsls [dirname]\n");
  }

  // Open directory
  DIR *d = opendir(dirname);

  // error check
  if (d == NULL)
  {
    fprintf(stderr, "lsls: cannot open directory %s\n", dirname);
  }

  struct dirent *ent;

  // Repeatly read and print entries
  while ((ent = readdir(d)) != NULL)
  {
    // This prints out the name of the file
    // printf("%s\n", ent->d_name);

    // we will print out the filesize
    char fullpath[10000];
    struct stat stat_buf;

    // get the full path
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dirname, ent->d_name);

    // stat the given file to find the number of bytes it contains
    if (stat(fullpath, &stat_buf) == -1)
    {
      fprintf(stderr, "Failed to stat file %s\n", fullpath);
      exit(3);
    }

    if (stat_buf.st_mode & S_IFREG)
    {
      // print the file name and its size in bytes
      printf("%10lld %s\n", stat_buf.st_size, ent->d_name);
    }
    else if (stat_buf.st_mode & S_IFDIR)
    {
      // we have a directory; mark it
      printf("%10s %s\n", "<DIR>", ent->d_name);
    }
    else
    {
      printf("%10s %s\n", "", ent->d_name);
    }
  }
  closedir(d);
  return 0;
}