#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // // Parse command line

  // for (int i = 1; i < argc; i++)
  // {
  //   printf("%s", argv[i]);
  //   return 0;
  // }

  // // Open directory
  // DIR *dir;
  // struct dirent *sd;

  // dir = opendir(".");

  // if (dir == NULL)
  // {
  //   printf("Error! Unable to open directory.\n");
  //   exit(1);
  // }

  // // Repeatly read and print entries
  // while ((sd = readdir(dir)) != NULL)
  // {
  //   printf(">> %s\n", sd->d_name);
  // }

  // // Close directory
  // closedir(dir);

  // return 0;

  // ------- Instructor Solution ---------

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
    fprintf(stderr, "useage: ./lsls [dirname]\n");
    exit(1);
  }

  // Open directory
  DIR *d = opendir(dirname);

  // error check
  if (d == NULL)
  {
    fprintf(stderr, "lsls: cannot open directory %s\n", dirname);
    exit(2);
  }

  struct dirent *ent;

  // Repeatedly read and print entries
  while ((ent = readdir(d)) != NULL)
  {
    // printf("%s\n", ent->d_name);
    char fullpath[8192];
    struct stat stat_buf;

    // get the full path
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dirname, ent->d_name);
    //stat the given file to find the number of bytes it contains
    if (stat(fullpath, &stat_buf) == -1)
    {
      fprintf(stderr, "failed to stat file %s\n", fullpath);
      exit(3);
    }

    if (stat_buf.st_mode & S_IFREG)
    {
      // Print the name of the file and its size
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