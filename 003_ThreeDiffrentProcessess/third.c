#include "headers.h"

int main(int argc, char const *argv[])
{
  printf("Parent process started...\n");

  if (fork() == 0)
  {
      printf("Inside first child process\n");
      if (fork() == 0)
      {
        printf("Inside second child process\n");
        if (fork() == 0) {
          printf("Inside third child process\n");
        }
        printf("Second child process completed.\n");
      }
      printf("First child process completed.\n");
  }

  printf("Parent process ends.\n");

  return 0;
}
