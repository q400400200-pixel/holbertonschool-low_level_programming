#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: input string
 *
 * Return: the integer value
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, result = 0;
	int found_digit = 0;

	/* تخطى أي شيء قبل الأرقام */
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			sign *= 1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found_digit = 1;
			result = result * 10 + (s[i] - '0');
		}
		else if (found_digit)
			break;
		i++;
	}
	return (result * sign);
}
