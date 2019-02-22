#include <stdio.h>
#include <string.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char commands[1024];
  char *args[100];

  char **parse_commands(char *str, int *argc, char **args) {
    
    char *token;
    *argc = 0;

    token = strtok(str, " \t\n\r");

    while (token != NULL && *argc < 100) {
      args[(*argc)++] = token;

      token = strtok(NULL, " \t\n\r");
    }

    args[*argc] = NULL;

    return args;
  }

  while(1) {
    printf("lssh$ ");

    fgets(commands, sizeof(commands), stdin);

    parse_commands(commands, &argc, args);

    if(argc == 0) {
      continue;
    } else {
      printf("%d", argc);
    }


  }
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}