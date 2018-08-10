#include <stdio.h>
#include <dirent.h>

 */
int main(int argc, char **argv)
{
  // Parse command line
   // Open directory
   // Repeatly read and print entries
   // Close directory
   return 0;
} 
  DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  return(0);
}
