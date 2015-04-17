#include  <stdio.h>
#include  <string.h>
#include <stdlib.h>
#include <unistd.h>
#include  <sys/types.h>
#include <editline/readline.h>

int main(int argc, char* argv[], char* envp[])
{
	char* line;
	int memory_read;    
	size_t nbytes = 1024; 
	printf("\n");
	pid_t curPid =0;
   int res = 0;
   		int* status;

	do {
		
		if (curPid != 0) 
			waitpid(curPid, status, WNOHANG );
		printf("\n>> ");
		printf("\n>> ");
		
		line = (char *) malloc (nbytes + 1);    
		memory_read = getline (&line, &nbytes, stdin); 
		if (memory_read == -1) 
		{
			continue;
		}
		line[strcspn(line, "\r\n")] = 0;

		res = strcmp("exit", line);
		if (res == 0)
			break;
		char args[10][nbytes];
		int argsc = 0, p = 0;
		char* curArg = (char*) malloc((nbytes) + 1);
		int more = 0;
		for (int i = 0;line[i] != '\0'; i++) {
			if (line[i] == ' ') {
				more = 1;
				strcpy(args[argsc],curArg);

				
				free(curArg);
				if (line[i] == ' ')
					curArg = (char *) malloc((nbytes*10) + 1);
				argsc++;
				i++;
				p = 0;
			} else {
				curArg[p] = line[i];
				p++;

			}
		}
		if (more ==0) {
			strcpy(args[0],curArg);
			free(curArg);
			argsc++;
		}
		char* prog;
		if (argsc == 1) {
			pid_t pid = fork();
			prog = args[0];
			if (pid == 0) {
				int er = execv(prog, 0);
				return 0;
			} else {
				curPid = pid;
				continue;
			}
			
		} else if (argsc > 1) {

			char * argpass[argsc];
			for (int w = 1; w < argsc; w++) {
				argpass[w] = args[w];
			}
			pid_t pid = fork();
			prog = args[0];
			if (pid == 0) {
				int er = execv(prog, 0);
				return 0;
			} else {
				curPid = pid;
				continue;
			}
			
		}

		free(line);
	} while(1);

	return 0;
}