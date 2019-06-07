#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
/**
 * Main
 */



// int main(int argc, char **argv)
// {
//   // Parse command line
//   char dirName[1000];
//   char fileName[255];
//   char fullName[1000];
//   DIR* dir;
//   int files = 0;
//   struct dirent *entry;
  
  
//   printf("Enter directory:");
//   fgets(dirName, 1000, stdin);
//   dirName[strlen(dirName) - 1] = '\0';


//   // Open directory
//   if(strlen(dirName) == 0) {
//     dir = opendir(".");
//   } else {
//     dir = opendir(dirName);
//   }

//   if(dir == NULL) {
//     printf("Cant find that directory");
//   } 

//   // Repeatly read and print entries

//   while( (entry=readdir(dir)) )
//     {
//       files++;
//       struct stat buf;
//       strncpy(fileName, entry->d_name, 254);
//       stat(entry->d_name, &buf); 

//       printf("File Name: %s, File size: %lld\n", entry->d_name, buf.st_size);
//     }
  


//   // Close directory
//   closedir(dir);
//   return 0;
// }

int main(int argc, char **argv)
{	
  int i;
  DIR* dir;
  struct dirent *entry;
  struct stat buf;
  if (argv > 1) {
    dir = opendir(argv[1]);
  } else {
    dir = opendir(".");
  }

  while( (entry=readdir(dir)) )
    {
      struct stat buf;
      stat(entry->d_name, &buf);
       // file size of directory and name
      printf("File Name: %s, File size: %lld\n", entry->d_name, buf.st_size);
    }
}
