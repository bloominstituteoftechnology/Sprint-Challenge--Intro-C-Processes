#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  
  struct dirent *ent;
  DIR *dir;
  // Parse command line
  if (argc==2) { // if 2 arguments passed in
    // Open directory
    if ((dir=opendir(argv[1]))!=NULL) { // if the user specified a directory name that opens a dir
      while ((ent=readdir(dir))!=NULL){
        struct stat buf;
        char subdir[1028] = "";
        strcat(subdir, argv[1]); // here we need to construct a file path from the argument passed in by user
        if (argv[1][strlen(argv[1])-1]!='/') { // add a slash at the end if not there already
          strcat(subdir,"/");
        }
        strcat(subdir, ent->d_name);
        strcat(subdir,"\0"); // make sure to end the string with a null character
        stat(subdir, &buf);
        // Repeatly read and print entries
        if ((buf.st_mode & S_IFDIR)!=0) {
          printf("<DIR> %s\n",ent->d_name); // print <DIR> instead of byte size if it's a directory
        } else {
          printf("%lld %s\n", buf.st_size,ent->d_name); // print byte size if it's a file
        }
    }
    // Close directory
    closedir(dir);
    } else {
      printf("Program has error.");
      exit(-1);
  }
  // if one argument is given open current directory:
  } else if (argc==1) {
    if ((dir=opendir("./"))!=NULL) { // is current directory not null?
      while ((ent=readdir(dir))!=NULL){
        struct stat buf;
        char subdir[1028] = "";
        strcat(subdir, "./");
        strcat(subdir, ent->d_name);
        strcat(subdir,"\0");
        stat(subdir, &buf);
        if ((buf.st_mode & S_IFDIR)!=0) {
          printf("<DIR> %s\n",ent->d_name);
        } else {
          printf("%lld %s\n", buf.st_size,ent->d_name);
        }
    }
    closedir(dir);
    } else {
      printf("Program has error.");
      exit(-1);
    }
  }


  
  return 0;
}