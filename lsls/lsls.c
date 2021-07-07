#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
/**
 * Main
 */


int main(int argc, char **argv)
{
  // reads the command line arg
  for (int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]); 
  }
  // specify the directory that we would like to check
  char *dir_name;

  if (argc < 2) { 
    // if no second arg found then display the current directory
    dir_name = "."; 
  } else if (argc == 2) {
    // dir_name is now pointing to the second argument
    dir_name = argv[1];
  } else {
    // check if the directory is valid or not and exit 
    printf("Directory is invalid\n");
    exit(1);
  }
  // will open the directory of the value of our dir_name pointer
  DIR *dir_holder = opendir(dir_name);

  if (dir_holder == NULL) {
    fprintf(stderr, "invalid directory: %s\n", dir_name);
    exit(2);
  }


  // struct dirent gives us access to set methods such as d_name
  struct dirent *dir_ent;   

  while ( (dir_ent = readdir(dir_holder)) != NULL ) {  
    // system struct that gives us access to info about files such as the size of the file with st_size
    struct stat st;    

    // Array we will use to concat the path to the specified directory
    char full_file_path[500] = "";   
    strcat(full_file_path, dir_name); 
    strcat(full_file_path, "/"); 
    strcat(full_file_path, dir_ent->d_name);  

// stat() takes 2 args, the path that we would like to inquire, and the struct that hold the info about the path
    stat(full_file_path, &st);

    if(S_ISDIR(st.st_mode)){
      printf("%s %s\n", "<DIR>",dir_ent->d_name);
    } else if (S_ISREG(st.st_mode)) {
      printf("%ld %s\n", st.st_size,dir_ent->d_name);
    }
  }

  // Close directory
  closedir(dir_holder);


  return 0;
}
