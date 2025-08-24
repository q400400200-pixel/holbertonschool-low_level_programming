#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints the alphabet in lowercase,
 * then in uppercase, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c;

	/* lowercase */
	for (c = 'a'; c <= 'z'; c++)
		putchar(c);

	/* uppercase */
	for (c = 'A'; c <= 'Z'; c++)
		putchar(c);

	/* newline */
	putchar('\n');

	return (0);
}
