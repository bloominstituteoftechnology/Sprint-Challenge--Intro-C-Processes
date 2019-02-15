#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h> // To get the size of entries, you'll need to use the `stat()` call in `<sys/stat.h>`.
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line --- pass any parameters to opendir() --- more info here: [commandline.c](examples/commandline.c).

  // Open directory ---  Call `opendir()`

  // Repeatly read and print entries --- repeatedly call `readdir()`
    
    /* RETURNS FROM `readdir()` 
    struct dirent *ent;
    //some code here 
    ent = readdir(d);
    printf("%s\n", ent->d_name);// d_name = file name, a string
    */
      
    /* FILE SIZE REQ:
      struct stat buf;
      stat("./lsls.c", &buf);
      printf("file size is %lld\n", buf.st_size);
       
      // To get the size of entries, you'll need to use the `stat()
      // Use `%10lld` to print the size in a field of width 10
    */

  // Close directory --- call `closedir()`

  return 0;
}