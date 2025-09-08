#include <stdio.h>

/**
 * main - prints the program name
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	(void)argc; /* to avoid unused variable warning */
	printf("%s\n", argv[0]);
	return (0);
}
