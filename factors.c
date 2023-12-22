#include "factors.h"
#include <stdlib.h>

/**
 * main - main function
 *
 * Return: void
 */
int main(int argc, char *argv[])
{
	FILE *fptr;
	size_t count;
	ssize_t line;
	char *buffer = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Error: Incorrect usage. Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((line = getline(&buffer, &count, fptr)) == -1)
	{
		fprintf(stderr, "Error: The file is empty\n");
		free(buffer);
		fclose(fptr);
		exit(EXIT_FAILURE);
	}
	do
	{
		factorize(buffer);
	}
	while((line = getline(&buffer, &count, fptr)) != -1);

	free(buffer);
	fclose(fptr);
	return (0);
}
