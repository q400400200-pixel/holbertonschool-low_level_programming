#include <stdio.h>

/**
 * main - prints the number of arguments passed into it
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	(void)argv; /* نتجاهل argv لأنه غير مستخدم */
	printf("%d\n", argc - 1);
	return (0);
}
