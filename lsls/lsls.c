#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char commandline[1024];
  struct dirent *pDirent;
  DIR *pDir;

  // printf("Please enter a directory\n>>> ");
  // fgets(commandline, sizeof(commandline), stdin);
  // printf("COMMAND: %s\n", commandline); // <-- Debugging
  // if (commandline[0] == '\0')
  // {
  //   // sets the string to "./" if no directory is chosen
  //   commandline[0] = '.';
  //   commandline[1] = '/';
  //   commandline[2] = '\0';
  // }
  // parse arguments?
  if (argc < 2)
  {
    printf("Usage: lsls <dirname>\n");
    return 1;
  }
  // Open directory
  pDir = opendir(argv[1]);
  if (pDir == NULL)
  {
    printf("Can not open directory %s\n", commandline);
    return 1;
  }

  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL)
  {
    printf("%s\n", pDirent->d_name);
  }
  // Close directory
  closedir(pDir);

  return 0;
}