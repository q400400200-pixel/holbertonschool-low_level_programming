#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: input string
 *
 * Return: pointer to s
 */
char *cap_string(char *s)
{
	int i = 0, j;
	char sep[] = " \t\n,;.!?\"(){}";

	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (i == 0)
			{
				s[i] -= 32;
			}
			else
			{
				for (j = 0; sep[j] != '\0'; j++)
				{
					if (s[i - 1] == sep[j])
					{
						s[i] -= 32;
						break;
					}
				}
			}
		}
		i++;
	}
	return (s);
}
