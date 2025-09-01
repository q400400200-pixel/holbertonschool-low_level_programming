#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: input string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0, start, i;

	/* احسب طول النص */
	while (str[len] != '\0')
		len++;

	/* حدد نقطة البداية */
	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	/* اطبع من المنتصف إلى النهاية */
	for (i = start; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}
