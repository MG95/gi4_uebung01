#include  <stdio.h>
#include  <string.h>
#include <unistd.h>
#include  <sys/types.h>

int main(int argc, char* argv[], char* envp[])
{
	if (argc > 1) {
		char* progName = argv[1];
		char** newargs;
		for (int i = 2; i < argc; i++) {
			newargs[i - 2] = argv[i];
		}		
		pid_t pid = fork();
		printf("%d\n",pid);
		execv(progName, newargs);
		return 0;
	} else 
	return 1;
}