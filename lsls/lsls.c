#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  struct dirent *ent;
  // Open directory
  DIR *dir;
  if (argc == 1)
  { 
    dir = opendir(".");
  }
  else if (argc == 2)
  {
    dir = opendir(argv[1]);
  }
  else 
  {
    printf("Could not open current directory");
    return 0;
  }
  
  if (dir == NULL )
  {
    printf("Could not open current directory");
    return 0;
  }

  // Repeatedly read and print entries
  struct dirent * entry;
  const char * d_name;

  while ((entry = readdir (dir)))
  {
    printf("   %s\n", entry->d_name);
  }

  closedir(dir);

  return 0;
}