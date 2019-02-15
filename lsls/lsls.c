#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line & open directory
  DIR *d = opendir(argv[1] ? argv[1] : ".");

  // Repeatly read and print entries
  struct dirent *entry;
  while ((entry = readdir(d)) != NULL)
  {
    char *name = entry->d_name;

    struct stat buf;
    stat(name, &buf);

    printf("%10ld %s\n", buf.st_size, name);
  }

  // Close directory
  closedir(d);

  return 0;
}