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
  // char *dir_path;
  // printf("There are %d command line argument(s):\n", argc);
  int i;
  for (i = 0; i < argc; i++)
  {
    printf("   %s\n", argv[i]);
  }

  // file size of directory
  struct stat buf;
  if (argc > 1)
  {
    stat(argv[1], &buf);
  }
  else
  {
    stat(".", &buf);
  }
  printf(" %ld\n", buf.st_size);

  DIR *d;
  struct dirent *dir;
  // Open directory
  d = (argc > 1) ? opendir(argv[1]) : opendir(".");
  if (d)
  {
    char filepath[] = "./";
    // Repeatly read and print entries
    while ((dir = readdir(d)) != NULL)
    {
      char *pathcpy = strdup(filepath);
      strcat(pathcpy, dir->d_name);
      stat(pathcpy, &buf);
      printf("%11ld %s\n", buf.st_size, dir->d_name);
    }
    // Close directory
    if (closedir(d) == -1)
    {
      perror("closedir");
      return 0;
    }
  }
  return (0);
}
