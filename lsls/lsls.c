#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  
  printf("\n----Following Are The Command Line Arguments Passed----");
      printf("%s\n",argv[1]);
  // Parse command line
  char* path =  argv[1];
  // DIR *opendir(char *path);


  struct dirent *ent;;  // Pointer for directory entry
 
    // opendir() returns a pointer of DIR type. 
    DIR *dr = opendir(path);
 
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }
 
    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    // for readdir()
    while ((ent = readdir(dr)) != NULL)
            printf("%s\n", ent->d_name);;
 
    closedir(dr);    
    return 0;

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}