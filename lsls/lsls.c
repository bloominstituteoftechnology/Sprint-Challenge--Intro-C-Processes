#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/*******
* Main *
*******/

// function to print current working directory

// function to execute command

int main(int argc, char **argv)
// figure out  what to do with argc and argv
{
  char *dirname;

  // Parse command line
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
    fprintf(stderr, "usage: lsls [dirname]\n");
    exit(1);
  }

  // Open directory
  DIR *d = opendir(dirname);

  // Repeatly read and print entries
  struct dirent *de;

  while ((de = readdir(d)) != NULL)
  {
    char *name = de->d_name;

    char fullpath[8192];

    sprintf(fullpath, "%s/%s", dirname, name);

    struct stat buf;

    if (stat(fullpath, &buf) == -1)
    {
      perror("stat");
    }

    stat(name, &buf);

    printf("%10lld %s\n", buf.st_size, name);
  }

  // Close directory
  closedir(d);
  return 0;
}