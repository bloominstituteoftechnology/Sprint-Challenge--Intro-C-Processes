#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define MAX_TOKENS 2

char **parse_commandline(char *str, int *argc, char **args)
{
  char *token;
  *argc = 0;
  token = strtok(str, " \t\n\r");

  while (token != NULL && *argc < MAX_TOKENS)
  {
    args[(*argc)++] = token;
    token = strtok(NULL, " \t\n\r");
  }
  args[*argc] = NULL;
  return args;
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  char commandline[1024];
  struct dirent *pDirent;
  DIR *pDir;

  if (argc < 2)
  {
    // Parse command line
    printf("Please enter a directory\n>>> ");
    fgets(commandline, sizeof(commandline), stdin);
    printf("COMMAND: %s\n", commandline); // <-- Debugging
    if (commandline[0] == '\0')
    {
      // sets the string to "./" if no directory is chosen
      // TODO: currently not working
      commandline[0] = '.';
      commandline[1] = '/';
      commandline[2] = '\0';
    }
    char **clargs = parse_commandline(commandline, &argc, argv);
    pDir = opendir(clargs[0]);
  }
  else
  {
    // parse arguments?
    pDir = opendir(argv[1]);
  }
  // Open directory
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