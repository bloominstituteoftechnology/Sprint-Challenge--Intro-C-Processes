#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
// int main(int argc, char **argv)
// {
//   char *dirr;
//   // Parse command line
//   if (argc == 1)
//   {
//     dirr = ".";
//   }
//   else
//   {
//     dirr = argv[1];
//   }
//   // Open directory
//   DIR *dirp = opendir(dirr);
//   if (dirp == NULL)
//   {
//     printf("Can't open that");
//   }
//   // Repeatly read and print entries
//   struct dirent *dent;
//   struct stat fstats;
//   dent = readdir(dirp);
//   while(dent != NULL)
//   {
//     stat(dent->d_name, &fstats);
//     printf("%d ----- %s", fstats.st_size, dent->d_name);
//   }
//   // Close directory
//   closedir(dirp);
//   return 0;
// }

int main(int argc, char **argv)
{
  char *dirname;
  // Parse command line
  if (argc >= 2)
  {
    dirname = argv[1];
  }
  else
  {
    dirname = ".";
  }
  // Open directory
  DIR *d = opendir(dirname);
  
  // Repeatly read and print entries
  struct dirent *de;  
  while((de = readdir(d)) != NULL)
  {    
    struct stat buf;
    char fullpath[8000];
    sprintf(fullpath, "%s/%s", dirname, de->d_name);
    
    if (stat(fullpath, &buf) == -1)
    {
      printf("%s\n", de->d_name);
    }
    printf("%10lld %s\n", buf.st_size, de->d_name);
  }
  // Close directory
  closedir(d);
  return 0;
}