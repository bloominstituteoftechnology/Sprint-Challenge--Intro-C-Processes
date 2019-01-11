#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  
  int count;
  for (count=0; count<argc; count++)
  {
    puts (argv[count]);
  }
      
  // Open directory
  struct dirent *de;
  DIR *dr = opendir (".");
  
 if (count > 1) {
    dr = opendir(argv[1]);
 }

 if (dr == NULL){
    printf("Could not open directory: %s\n", argv[1]);
    return 0;
 }

  // Repeatly read and print entries
  struct stat buf;
  while ((de = readdir(dr)) != NULL) {
            stat(argv[1], &buf);
            printf("file size is %ld", buf.st_size);
            printf ("%s\n", de->d_name);
  }

  // Close directory
  closedir (dr);
  return 0;
}