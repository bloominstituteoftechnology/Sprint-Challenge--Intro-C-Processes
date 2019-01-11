#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir_path;
  printf("There are %d command line argument(s):\n", argc);
  

  if (argc < 2) { 
    dir_path = ".";
  } else if (argc == 2) {
    dir_path = argv[1];
    printf("Directory path: %s\n", dir_path);
  } else {
    printf("Directory is invalid\n");
    return 0;
  }

  // Open directory
  DIR *dir;
  struct dirent *dp;

  if ((dir = opendir(dir_path)) == NULL) {
        perror ("Cannot open .");
        return 0;
    }

  // Repeatly read and print entries

  // create stat to read file size
  struct stat buf;
  while ((dp = readdir(dir)) != NULL) 
  {
    // allocate size for file_name and give it empty string in order to concatenate
    // won't work if not give a value for some reason
    char file_name[100] = "";

    // tried combining dir_path and / before hand but does not work that way...reads wrong values
    strcat(file_name, dir_path);
    strcat(file_name, "/");
    strcat(file_name, dp->d_name);

    stat(file_name, &buf);
    printf("\n%10lld %s\n", buf.st_size, dp->d_name );
  }

  // Close directory
  if (closedir(dir) == -1) 
  {
    perror("closedir");
    return 0;
  }


  return 0;
}