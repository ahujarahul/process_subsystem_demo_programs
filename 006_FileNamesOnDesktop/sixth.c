#include "headers.h"

int main(int argc, char const *argv[])
{
  char *directory = "/Users/rahulahuja/Desktop";
  int ret;
  DIR *dir;
  struct dirent *entry;
  int fd;
  struct stat fileStat;

  char dirName[100];
  char fileName[100];
  int maxSizeFile;

  if (fork() == 0)
  {
      printf("Inside first child process\n");
      ret = chdir (directory);
      if (ret == 0)
      {
        printf("cwd is Desktop\n");

        if ((dir = opendir(".")) == NULL)
          perror("opendir() error\n");
        else {
          printf("contents of Desktop\n");
          printf("---------------------------------------------------------------------------\n");
          while ((entry = readdir(dir)) != NULL){
            printf("FILE NAME : %s\n", entry->d_name);
          }
       }
     }else if(ret == -1){
       printf("change of cwd failed..\n");
     }
   }
  return 0;
}
