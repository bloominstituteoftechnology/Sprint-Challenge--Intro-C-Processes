#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h> // To get the size of entries, you'll need to use the `stat()` call in `<sys/stat.h>`.
/**
 * Main
 * 
 *TO_DO = figure out if code isn't working or test ----------
 */
int main(int argc, char **argv)
{
  //declarations
  DIR *dir;
  struct dirent *ent;
  struct stat buf; 
  char *directory;

  // Parse command line
   if (argc < 2 ) {
    directory = ".";
    printf("Directory: %s\n", directory);

  } else if(argc == 2) {
    directory = argv[1];
    printf("Directory: %s\n", directory);

  } else {
    printf("Cannot open directory\n");
    exit();
  }
  
  // Open directory 
  dir = opendir(directory);
  if (dir == NULL){
    printf("Cannot open '%s'\n", directory);
    exit();
  }
    
  // Repeatedly read and print entries 
  while ((ent = readdir(dir)) != NULL) {

    stat(ent->d_name, &buf); // d_name = file name, a string
    
    //print file name and file size req 
    printf("%s\n", ent->d_name);
    printf("file size is %10lld", buf.st_size); 
      
    return -1;
  }
    /* FILE SIZE REQ:
    // WHY SPECIFY FIELD WIDTH? Use `%10lld` to print the size in a field of width 10
    */
  
  // Close directory 
  closedir(dir);

  return 0;
}