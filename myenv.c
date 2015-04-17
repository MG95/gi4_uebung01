#include <stdio.h>

int main(int argc, char* argv[], char* envp[]) 
{

	// Ausgabe aller Umgebungsvariablen

	int i = 0;
	
	while (envp[i])
	{
		printf("%s", envp[i]);
		i++;
	}
	
	// Ausgabe der Anzahl aller Umgebungsvariablen
	
	printf("Anzahl Umgebungsvariablen: %d", i);


  return 0;
}
