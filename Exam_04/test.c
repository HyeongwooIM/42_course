#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd[2];
	int fd_temp;
	int temp;
	int file;

	temp = dup(0);
	pipe(fd);
	file = open("ccc", O_RDONLY);
	dup2(file, 0);
	fd_temp = dup(0);
	printf("%d, %d, %d", fd_temp, file, temp);
	
	sleep(5);
}
