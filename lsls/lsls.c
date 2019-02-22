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
  // Parse command line
  (void)argc;
  (void)argv;
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