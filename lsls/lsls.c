#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>


//https://linux.die.net/man/3/opendir
  

     
/**
 * Main
 */
// Parse command line  

  // check the count of argc, 

  // `.` means current dir

  // argv[1] = dirname
int main(int argc, char **argv)
{
  char *dirname;//hold whatever arg passed
  // Parse command line
  if(argc == 1){//argc by default is 1 can not be 0 name of program is 1
    //set the directory that were going to be looking at tp "."
    dirname = ".";

  }else if (argc == 2){ //second arg
    dirname = argv[1];
  }else {
    //standard error message
    fprintf(stderr, "usage: lsls [dirname]\n ");
    //return 1; would work to end program
    exit(1);
  }
  //Open directory
  DIR *d;
  struct dirent * dir;
  d = opendir(dirname);

  // The DIR data type represents a directory stream. It's declared in the header `dirent.h`
  if (d ==NULL){
    fprint(stderr,"lsls: cannot open directory %s\n", dirname);
    exit(2);
  }

  // If find NULL, means no content in that dir
  //single directory entry
  //repeatly read and print entries
   struct dirent *entry;

  while ((entry = readdir(d)) !=NULL){
    //stat the entry
    char fullpath[8192];// 8192 bytes is size that for a buffer to read and write. Fa
    snprint(fullpath, sizeof(fullpath), "%s/%s", dirname, entry->d_name); //snprintf is essentially a function that redirects the output of printf to a buffer.
    struct stat stat_buf;

     if(stat(fullpath, &stat_buf) < 0) {

       fprintf(stderr,"lsls: failed to stat file %s\n", fullpath);

       exit(3);
     }
     if (S_ISREG(stat_buf.st_mode)){
       
       printf("10%lld %s\n", stat_buf.st_size, entry->d_name);
      }else if (S_ISDIR(stat_buf.st_mode)){
        printf("%10s %s\n","DIR", entry->d_name);
      }else{

        printf("%10s %s\n", "", entry->d_name); 


      }

  }
  //10 will give it ten spaces make it more prettier
  // while (1) {
  //   entry = readdir(d);
  //   if(entry == NULL) {
  //     break;
  //   }
  //   printf();
  // }
   //close directory
//asigned interger types off_t
   closedir(d);

  return 0;
}

