#include <stdio.h>
#include <dirent.h>



void directoryListing(const char *directoryName)
{
  DIR *directory;
  struct dirent *entry;


// opening the directory
  directory = opendir(directoryName);
  if (directory != NULL)
  {
      // read and print entries in the loop
    while ((entry = readdir(directory)) != NULL)
    {
      printf("%s\n", entry->d_name);
    }
// Closing out the directory
    closedir(directory);
  }
  else
  {
// printing directory name
    printf("Can't open %s\n", directoryName);
    exit(1);
  }
}


// Main ->

int main(int argc, char **argv)
{
  // Parsing the command line
    int i;
    i = 1;

  while (i < argc)
  {
    directoryListing(argv[i]);
    i++;
  }
//checking to see if the user doesn't enter a directory and if so 
// the . should become the directory
    if (argc == 1)
  {
    directoryListing(".");
  }

  return 0;
}