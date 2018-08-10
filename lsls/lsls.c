#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dirName = argv[1] == NULL ? "." : argv[1];
  struct dirent *ent;
  DIR *dirPointer;
  struct stat statBuffer;

  // Open directory
  if (!(dirPointer = opendir(dirName)))
  {
    fprintf(stderr, "Error: Could not open directory %s\n", dirName);
    return -1;
  }

  // Repeatly read and print entries
  while (ent = readdir(dirPointer))
  {
    char *pathName = strdup(dirName);

    strcat(pathName, "/");
    strcat(pathName, ent->d_name);

    stat(pathName, &statBuffer);

    if (statBuffer.st_mode & S_IFDIR)
    {
      printf("%10s %s\n", "<DIR>", ent->d_name);
    }
    else if (statBuffer.st_mode & S_IFREG)
    {
      printf("%10lld %s\n", statBuffer.st_size, ent->d_name);
    }
    else
    {
      printf("%10s %s\n", "<SPECIAL>", ent->d_name);
    }
  }
  // Close directory
  closedir(dirPointer);

  return 0;
}