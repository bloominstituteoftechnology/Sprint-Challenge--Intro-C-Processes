#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char **get_info(char *str) {
    struct dirent *ptr_dirent;

    printf("the directory is: %s\n", str);
    printf("argument count: %d\n", argc);
    
    DIR *ptr_dir;
    ptr_dir = opendir(str);

    if(ptr_dir == NULL) {
      printf("Cannot open directory %s\n", str);
    }

    while ((ptr_dirent = readdir(ptr_dir)) != NULL) {
      char *f_name = ptr_dirent->d_name;
      struct stat sizes;

      if (stat(f_name, &sizes) != -1) {
        printf("%-10s...\t[%ld]\n", f_name, sizes.st_size);
      }
    }

    closedir(ptr_dir);
  }

  if (argc < 1) {
    printf("There was an error");

  } else if (argc == 1) {
    char cwd[250];

    // get current working directory
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
      get_info(cwd);

    }
  } else if (argc == 2) {
    char *path_request = argv[1];

    get_info(path_request);
    printf("This is the path requested: %s\n", path_request);

  } else {
    printf("Formatting incorrect './lsls <path>'\n");

  }
  // char commands[1024];
  // char *args[100];

  // char **parse_commands(char *str, int *argc, char **args) {
    
  //   char *token;
  //   *argc = 0;

  //   token = strtok(str, " \t\n\r");

  //   while (token != NULL && *argc < 100) {
  //     args[(*argc)++] = token;

  //     token = strtok(NULL, " \t\n\r");
  //   }

  //   args[*argc] = NULL;

  //   return args;
  // }

  // while(1) {
  //   printf("lssh$ ");

  //   fgets(commands, sizeof(commands), stdin);

  //   parse_commands(commands, &argc, args);

  //   if(argc == 0) {
  //     continue;
  //   } else {
  //     printf("%d", argc);
  //   }


  // }
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}