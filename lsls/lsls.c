#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h> // To get the size of entries, you'll need to use the `stat()` call in `<sys/stat.h>`.
/**
 * Main
 */
int main(int argc, char **argv)
{
  //declarations
  DIR *dir;
  struct dirent *ent;
  struct stat buf; 
 

  // Parse command line --- pass any parameters to opendir() --- more info here: [commandline.c](examples/commandline.c).

  // Open directory 
  dir = opendir(argv[1]);
  if (dir == NULL) {
    printf("Cannot open '%s'\n", argv[1]);
    return 1;
  }

  // Repeatedly read and print entries 
  if ((ent = readdir(dir)) != NULL) {
    stat(ent->d_name, &buf); // d_name = file name, a string
    if (strcmp(ent->d_name, argv[1]) != 0) { // used string compare (strcmp) to test for correct file
      printf("%s\n", ent->d_name);
      printf("file size is %lld\n", buf.st_size); //print file size req 
      return -1;
    }
    /* FILE SIZE REQ:
    // WHY SPECIFY FIELD WIDTH? Use `%10lld` to print the size in a field of width 10
    */
  }

  // Close directory 
  closedir(dir);

  return 0;
}