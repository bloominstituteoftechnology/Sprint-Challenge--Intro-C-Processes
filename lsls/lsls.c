#include <stdio.h>
#include <dirent.h>

#include <sys/stat.h>

// opendir()
// readdir()
// strcat()
// closedir()

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  struct stat buf;

  // Parse command line
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
      stat(entry->d_name, &buf); // Pulling file status
      
      if ((buf.st_mode & S_IFDIR) > 0)
      {
        printf("<DIR>  %s\n", entry->d_name); // print <DIR> & name
      }
      else
      {
        printf("%lld  %s\n", buf.st_size, entry->d_name); // print file size & name
      }
    }

    closedir(dir); // Close directory
  }
  return 0;
}
