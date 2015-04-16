#include <stdio.h>

int main(int argc, char* argv[], char* envp[]) 
{

	// Ausgabe aller Paramater, auf die argv zeigt

	for (int i = 1; i < argc; i++)
	{
		printf("Parameter Nr. %d: %s", i, argv[i]);
	}


  return 0;
}
