#include <stdio.h>

int main(int argc, char* argv[], char* envp[]) 
{

	// PrŸfe, ob Umgebungsvariable gesetzt ist und gib entsprechende Ausgabe aus
	
	if (argc >= 3 && *(getenv(argv[1])) && strcmp(argv[2], "-v")
	{
		printf("%s", getenv(argv[1]));
		return 0;
	}


	if (argc > 2 && *(getenv(argv[1])))
	{
		return 0;
	}
	
	return 1;
}
