#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  char currentDir[1024];

  if (argc > 1)
  {
    sprintf(currentDir, "%s", argv[1]);
  }
  else
  {
    sprintf(currentDir, "%s", ".");
  }

  if (strcmp(currentDir, "help") == 0)
  {
    printf("\n---------------   LSLS HELP   --------------- \n\n"
           "To use this comandline program, type the following: \n\n  "
           " ./lsls directory\n\n"
           "contents of two folders higher than your current one:\n"
           " ./lsls ../../ \n\n "
           "If no directory is specified,  lsls will assume its current location as the target directory\n"
           " \n---------------   END  HELP   ---------------\n\n");
  }
  else if ((dir = opendir(currentDir)) == NULL)
  {
    perror("opendir error");
  }
  else if (strcmp(currentDir, "help") != 0)
  {
    while ((entry = readdir(dir)) != NULL)
    {
      struct stat buf;
      char type[1024];
      stat(entry->d_name, &buf);
      if (entry->d_type == DT_DIR)
      {
        sprintf(type, "%s", "<DIR>");
      }
      else
      {
        sprintf(type, "%ld", buf.st_size);
      }
      printf("  %12s  %s\n", type, entry->d_name);
    }
    closedir(dir);
  }

  return 0;
}