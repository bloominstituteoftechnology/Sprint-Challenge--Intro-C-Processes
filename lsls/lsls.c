#include <stdio.h>
#include <dirent.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  
  char input[100];
  char isRunning = 1;

  printf("Enter a directory path or 'Q' to quit");
  scanf("%s", input);

  if (strcmp(input, "Q") == 0 || strcmp(input, "q") == 0) 
  {
    isRunning = 0;
  }

  while(isRunning)
  {
    DIR *folder;
    struct dirent *entry;
    folder = opendir(input);

    if (folder == NULL)
    {
        printf("Unable to read directory");
        return(1);
    }
    
    while ((entry=readdir(folder)))
    {
      printf("%s, entry->d_name");
    }

    closedir(folder);
  }

  return 0;
}