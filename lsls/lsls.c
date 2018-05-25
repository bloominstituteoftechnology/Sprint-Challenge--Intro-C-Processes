#include <stdio.h>
#include <dirent.h>

// `gcc -Wall -Wextra -o lsls lsls.c`
// `./lsls`
// Got code from: https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1046380353&id=1044780608

/**
 * Main
 */
// int argc, char **argv
int main(void)
{
  DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  return (0);
}