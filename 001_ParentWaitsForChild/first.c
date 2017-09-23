#include "headers.h"

int main()
{
	int status, child_pid;
	pid_t pid;

	child_pid = fork();
	if(child_pid == 0)
	{
		printf("Before process creation\n");
		sleep(10);
		printf("Sleep complete\n");
	}
	else
	{
		printf("Inside Parent process\n");
		pid = waitpid(child_pid , &status, 0);
		printf("Child process having PID %d terminates with exit status %d\n",pid,status);
		printf("Execution of parent process completed\n");
	}

	return 0;
}
