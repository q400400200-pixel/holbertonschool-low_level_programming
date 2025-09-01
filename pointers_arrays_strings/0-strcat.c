#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string (will be modified)
 * @src: source string (to append)
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	/* ابحث عن نهاية dest */
	while (dest[i] != '\0')
		i++;

	/* انسخ src في نهاية dest */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* أضف null terminator */
	dest[i] = '\0';

	return (dest);
}
