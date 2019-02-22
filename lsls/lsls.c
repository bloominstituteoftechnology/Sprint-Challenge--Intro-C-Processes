#include <stdio.h>
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
  if (argv == 1)
  {
    dirname = ".";
  }
  else if (argv == 2)
  {
    dirname = argv[1];
  }
  else
  {
    fprintf(stderr, "usage: lsls [dirname]\n");
    exit(1);
  }

  // Open directory
  DIR *d = opendir(".");

  // Repeatly read and print entries
  struct dirent *de;

  // print directory results
  while ((de = readdir(d)) != NULL)
  {
    char *name = de->d_name;

    struct stat buf;

    stat(name, &buf);

    printf("%10lld %s\n", buf.st_size, name);
  }

  // Close directory
  closedir(d);
  return 0;
}