#include "headers.h"

int main()
{
	int status;
	pid_t pid, p2id;

	printf("Parent process started...\n");

	if(fork() == 0)
	{
		printf("First child created.\n");
		sleep(10);
		printf("Sleep for first child completes.\n");
	}
	else
	{
		pid = wait(&status);
		printf("First child process having PID %d terminates with exit status %d\n",pid,status);
	}

	if(fork() == 0)
	{
		printf("Second child created.\n");
		sleep(5);
		printf("Sleep for second child completes.\n");
	}
	else
	{
		p2id = wait(&status);
		printf("Second child process having PID %d terminates with exit status %d\n",p2id,status);
	}

	printf("Parent process completed.\n");
	return 0;
}
