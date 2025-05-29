#include "sys/wait.h"
#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "../includes/get_next_line.h"
#include "../includes/memory_allocator.h"

int main()
{
	int status;
	int pid;
	int fd[2];
	char string[1024] = {0};
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		sleep(2);

		close(fd[0]);
		int test = write(fd[1], "Hello World", 11);
		printf ("sa%d\n", test);

		// read(fd[0], string, 20);
		// printf("%s\n", string);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);

		// write("Hello World")
		// printf("%s\n", string);
		// pause();
	}
	waitpid(0, &status, 0);
	// printf("%d\n", status);
	while (wait(NULL) > 0)
		;
}
