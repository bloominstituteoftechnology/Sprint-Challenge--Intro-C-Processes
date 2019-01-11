#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{  
  // Checking how argv will work here

  for (int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]); // --> Interprets command line arg
  }

  printf("hello world\n"); // --> test for sanity check

  // Getting started / Interpret CL arguments

  char *dir_name; // --> lets use this to be able to specify which directory we want to check

  if (argc < 2) { // --> It'd look like `ls .` or `ls` ( Base Case )
    dir_name = "."; // --> Meaning to check just the directory you're currently in
  } else if (argc == 2) {
    dir_name = argv[1]; // --> `ls some_dir_name` || dir_name = some_dir_name
  } else {
    printf("Directory is invalid\n");
    exit(1);
  }

  DIR *dir_holder = opendir(dir_name); // --> Open directory of whatever the dir_name is assigned to

  if (dir_holder == NULL) {
    fprintf(stderr, "invalid directory: %s\n", dir_name);
    exit(2);
  }


  // Repeatly read and print entries --> Use the struct dirent
  struct dirent *dir_ent;   

  while ( (dir_ent = readdir(dir_holder)) != NULL ) {  
    struct stat st;    

    char full_file_path[500] = ""; // --> Use an array to concatenate path passed in + / + dir_ent->d_name    
    strcat(full_file_path, dir_name); // --> concatenate 1
    strcat(full_file_path, "/"); // --> concatenate 2
    strcat(full_file_path, dir_ent->d_name); // --> concatenate 3    

    stat(full_file_path, &st); // --> Now we can use stat(our full path name, address/pointer to the st struct)
    
    printf("%lld %s\n", st.st_size,dir_ent->d_name);
  }

  // Close directory
  closedir(dir_holder);

  return 0;
}