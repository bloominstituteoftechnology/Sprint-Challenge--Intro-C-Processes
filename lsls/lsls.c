#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>




/**
 * Main
 */
void parse_command(int argc, char **argv)
{
    int i;

    printf("There are %d command line argument(s):\n", argc);

    for (i = 0; i < argc; i++) {
        printf("   %s\n", argv[i]);
    }  
}


int main(int argc, char **argv)
{
//  parse_command(argc, argv);
  // Parse command line
  char * path = argc > 1 ? argv[1] : "."; 

  // Open directory
  DIR * d = opendir(path);
  if (d == NULL) {
    printf("Error opening directory '%s'\n", path);
    exit(1);
  }
  struct dirent *ent;

  char full_path[500];
  // Repeatly read and print entries
  while (ent = readdir(d))
  {
    struct stat buf;
    sprintf(full_path, "%s/%s", path, ent->d_name);
    int rc = stat(full_path, &buf);

    char info[16];
    if (rc == 0)
    {
        switch (buf.st_mode & __S_IFMT) {
          case __S_IFDIR:
          strcpy(info, "<DIR>");
          break;
          case __S_IFREG:
          sprintf(info, "%ld", buf.st_size);
          break;
          default:
          break;
          
        }
           
        // if (buf.st_mode & __S_IFDIR != 0 )
        //   strcpy(info, "<DIR>");
        // else { //if (buf.st_mode & __S_IFREG != 0)
        //   sprintf(info, "%ld", buf.st_size);
        //   if (S_IFREG(buf.st_mode) != 0)
        //     printf("regular");
        // }
    }
    else
    {
      strcpy(info,  "?");
    }
      

    printf("%15s  %s\n", info, ent->d_name);    
  }
  // Close directory
  closedir(d);

  return 0;
}