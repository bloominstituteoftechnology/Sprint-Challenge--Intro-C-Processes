#include <stdio.h>    //Enables the use of input and output functions
#include <stdlib.h>   // Enables the use of several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <dirent.h>   // Enables format library for Directory entries.
#include <sys/stat.h> // Enables data returned by the stat() function

void ls_dir(const char *dir_name) //Creatings a void function that accepts a char array of characters(Directory path)
{
  DIR *directory;
  struct dirent *entry;

  directory = opendir(dir_name); // Open directory
  if (directory != NULL)         //If the directory isnt emtpy
  {
    while ((entry = readdir(directory)) != NULL) //Loop through the directory and read each entry until you get to a null point/end of the directory
    {
      struct stat file_name;
      stat(entry->d_name, &file_name);

      //If you a have a regular file print size
      if (file_name.st_mode & S_IFREG)
      {
        printf("%s %lld\n", entry->d_name, file_name.st_size);
      }
      //Else if you have a directory print <DIR>
      else if (file_name.st_mode & S_IFDIR)
      {
        printf("%s %s\n", "<DIR>", entry->d_name);
      }
      //Else it failed, print the list of files
      else
      {
        printf("%s\n", entry->d_name);
      }
    }

    closedir(directory); //Closes the directory
  }
  else
  {
    printf("Directory doesnt exist. %s\n", dir_name); //Failed to open directory name or path was incorrect
    exit(1);
  }
}

/**
 * Main
 */

int main(int argc, char **argv)
{
  // Parse command line
  int x;

  x = 1;
  while (x < argc)
  {
    ls_dir(argv[x]);
    x++;
  }

  if (argc == 1)
  {
    ls_dir(".");
  }

  return 0;
}

// You'll need to use the `stat()` call in `<sys/stat.h>`.

// * `int stat(char *fullpath, struct stat *buf)`: For a given full path to a file
//   (i.e. the path passed to `opendir()` following by a `/` followed by the name
//   of the file in `d_name`), fill the fields of a `struct stat` that you've
//   pointed to. Returns `-1` on error.

//   ```c
//   // Example stat() usage

//   struct stat buf;

//   stat("./lsls.c", &buf);

//   printf("file size is %lld\n", buf.st_size);
//   ```
