#include <stdio.h>
#include <dirent.h>

/**
  * Answers
  *
  1. 
  There are generally 5 states.
  Start - process has just been created
  Ready - process is waiting for the processor
  Running - processor is executing the processes' instructions
  Waiting - process is waiting for some event to occur
  Exit - process has finished its execution or has been terminated by the operating system

  2. A zombie process is a process that hasn't been properly removed after it's done being executed. It's created when the parent process does not call wait(). To properly remove the zombie process, one should call the `kill -s SIGCHILD pid command`; with the pid command line argument taking the value of the parent process's pid.
  
  3. There are benefits, such as having the compiler list out warnings that the programmer may not have been aware of. Interpretive languages only send error messages, in the case that the code is incorrectly written. With a compiler, the code can be technically parsable; however, there could be errors, such as logic errors, that the compiler warns about.
*/



/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  char *path;
  if(argv[1] != NULL){
    path = argv[1];
  }
  else{
    path = ".";
  }

  // Open directory

  DIR *directory = opendir(path);

  // Repeatly read and print entries

  if(directory == NULL){
    fprintf(stderr,"error opening directory\n");
    exit(1);
  }
  struct dirent *entry;
  while( (entry = readdir(directory)) != NULL){
    printf("%s\n",entry->d_name);
  }

  // Close directory

  closedir(directory);

  return 0;
}
