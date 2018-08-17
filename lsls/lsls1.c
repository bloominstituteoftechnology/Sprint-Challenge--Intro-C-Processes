#include <stdio.h>

#include <dirent.h>

#include <stdlib.h>

#include <sys/stat.h>



/**

 * Main

 */

int main(int argc, char **argv)

{

  DIR *dir;//holds whatever arg passed
//To define a structure, you must use the struct statement. The struct statement defines a new data type,
  struct dirent *pDirent;

  struct stat buf;



  // Parse command line

  if (argc < 2) // Default current dir

  {

    dir = opendir(".");

    argv[1] = ".";

  }

  else

  {

    dir = opendir(argv[1]); // dir path

  }

  // Open directory

  if (dir == NULL)

  {

    printf("The directory is empty! :(\n"); // test ./lsls x

    exit(1);

  }

  // Repeatly read and print entries

  else

  {

    while ((pDirent = readdir(dir)) != NULL) // read while dir not empty

    {

      stat((*pDirent).d_name, &buf);

      printf("%ld\t %s\n", buf.st_size, (*pDirent).d_name);

    }

  }



  // Close directory

  closedir(dir);



  return 0;

}