#include <stdio.h>
#include <dirent.h>

#include <sys/stat.h>

// opendir()
// readdir()
// strcat()
// closedir()
// snprintf()

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  struct stat buf;

  // Parse command line
  // Optional: use ternary operator here
  if (argc == 1)
  {
    dir = opendir(".");
  }
  else
  {
    dir = opendir(argv[1]);
  }

  // Open directory
  if (dir == NULL)
  {
    printf(stderr, "Cannot open dir\n");
    exit(1);
  }

  // Repeatly read and print entries
  if (dir)
  {
    while ((entry = readdir(dir)) != NULL)
    {
      if (stat(entry->d_name, &buf) < 0) // Pulling file status
      {
        printf(stderr, "Reading stat of file failed.");
        exit(2);
      }

      if ((buf.st_mode & S_IFDIR) > 0) // make sure to use bitwise-operation
      {
        printf("%6s  %s\n", "<DIR>", entry->d_name); // print <DIR> & name
      }
      else
      {
        printf("%6lld  %s\n", buf.st_size, entry->d_name); // print file size & name
      }
    }

    closedir(dir); // Close directory
  }
  return 0;
}
