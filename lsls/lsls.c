#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}

// 1. Call `opendir()`.
// 2. Then repeatedly call `readdir()`--printing the filenames as you go--until it
//    lets you know there are no more directory entries by returning `NULL`.
// 3. Then call `closedir()`.