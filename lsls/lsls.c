#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char input[5];
  char isRunning = 1;

  do {
    DIR *folder;
    struct dirent *entry;
    folder = opendir(input);
    struct stat buf;
    char *path;

    if (argc < 2)
    {
      path = ".";
    }
    else if (argc > 2)
    {
      exit(1);
    }
    else
    {
      path = strtok(argv[1], "\t\n\r");
    }

    folder = opendir(path);

    if (folder == NULL)
    {
        printf("Unable to find directory");
        exit(1);
    }
    
    while ((entry=readdir(folder)))
    {
      printf("%s, entry->d_name");
      printf("%s, buf.st_size");
    }

    closedir(folder);

    printf("Press Q to quit or anything else to repeat.");
    scanf("%s", input);

    if (strcmp(input, "Q") == 0 || strcmp(input, "q") == 0) 
    {
      isRunning = 0;
    }

  } while (isRunning)

    
  return 0;
}