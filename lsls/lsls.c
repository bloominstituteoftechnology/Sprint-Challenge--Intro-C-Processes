#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv)
{
  // Parse command line & open directory
  struct dirent *dir_entry;
  char *dirName;

  if (argc == 1)
  {
    dirName = "."; // sets default if no arg provided
  }
  else if (argc == 2)
  {
    dirName = argv[1]; 
  }
  else
  {
    fprintf(stderr, "Please provide a valid directory name\n");
  }

  DIR *dir = opendir(dirName);

  // Repeatly read and print entries

  while ((dir_entry = readdir(dir)) != NULL)
  {
    printf("%s\n", dir_entry->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}