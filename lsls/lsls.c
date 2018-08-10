#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define RED "\x1b[1;31m"
#define BLUE "\x1b[1;34m"
#define GRAY "\x1b[1;30m"

void Usage() {
    fprintf(stderr, "\nUsage: exec [OPTION]... [DIR]...\n");
    fprintf(stderr, "List DIR's (directory) contents\n");
    fprintf(stderr, "\nOptions\n-R\tlist subdirectories recursively\n");
    return;
}

void RecDir(char * path, int flag) {
    DIR * dp = opendir(path);
    if(!dp) {
        perror(path);
        return;
    }
    struct dirent * ep;
    char newdir[512];
    printf(BLUE "\n%s :\n" GRAY, path);
    while((ep = readdir(dp)))
        if(strncmp(ep->d_name, ".", 1))
            printf(RED "\t%s\n" GRAY, ep->d_name);
    closedir(dp);
    dp = opendir(path);
    while((ep = readdir(dp))) if(strncmp(ep->d_name, ".", 1)) {
        if(flag && ep->d_type == 4) {
            sprintf(newdir, "%s/%s", path, ep->d_name);
            RecDir(newdir, 1);
        }
    }
    closedir(dp);
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory
      switch(argc) {
    case 2:
        if(strcmp(argv[1], "-R") == 0) Usage();
        else RecDir(argv[1], 0);
        break;
    case 3:
        if(strcmp(argv[1], "-R") == 0) RecDir(argv[2], 1);
        else Usage();
        break;
    default: Usage();
    }

  return 0;
}