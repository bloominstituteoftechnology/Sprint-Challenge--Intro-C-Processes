#include <stdio.h>
#include <dirent.h> //includes DIR, struct dirent, opendir(), readdir(), and closedir()
#include <sys/stat.h> //includes stat(), st_size, st_mode

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // Open directory - opendir()
  // Repeatly read and print entries - readdir()
  // Close directory - closedir()

  DIR *dir;
  struct dirent *dirent;
  struct stat buffer;

  //Opens Dir
  if (argc > 2)
    {
      printf("Opening directory '%s'.\n", argv[1]);
      dir = opendir(argv[1]);
    }
  else if (argc < 2)
  {
    printf("A directory was not specified, printing content from '.' directory.\n");
    dir = opendir(".");
  }
  else
  {
    if (dir == NULL)
    {
      printf("Cannot open directory '%s'.\n", argv[1]);
      exit(1);
    }
  }

  //Reads & Prints Dir
  while ((dirent = readdir(dir)) != NULL)
  {
    stat(dirent->d_name, &buffer);

    if (buffer.st_mode & S_IFDIR)
    {
    printf("%10s %s\n", "<DIR>", dirent->d_name);
    }
    else if (buffer.st_mode & S_IFREG)
    {
    printf("%10lld %s\n", buffer.st_size, dirent->d_name);
    }
    else
    {
      printf("Stat failed!");
      exit(2);
    }
  }

  //Closes Dir
  closedir(dir);
  return 0;
}

