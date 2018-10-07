#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>



int main(int argc, char **argv)
{
  // dirent is the directory entry 
  struct dirent *ent;
  DIR *dir;
  // parse the command line parameters
  if (argc > 2) {
    // if too many args, print error and exit
    printf("Error! Too many arguments!");
    exit(1);
  } else if (argc < 2) {
    // if no args passed in by user, assign "." value to dir
    dir = opendir(".");
  } else {
    // otherwise, assign the directory the user provides
    dir = opendir(argv[1]);
  }

  if (dir == NULL) {
    printf("Directory not found!\n");
    exit(1);
  }

  while((ent = readdir(dir))!= NULL)
  {
    if(argc < 2)
    {
      printf("./%s\n", ent->d_name);
    }
    else
    {
      printf("%s\n", ent->d_name);
    }
  }
  // Close directory
  closedir(dir);

  return 0;
}