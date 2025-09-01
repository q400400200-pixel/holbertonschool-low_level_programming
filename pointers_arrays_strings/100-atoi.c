#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: input string
 *
 * Return: the integer value
 *
 * Note:
 * We accumulate as a negative number to avoid overflow on INT_MIN.
 * After parsing, if the sign is positive, we return -result; otherwise result.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	int started = 0;

	/* scan until digits; count all +/- before first digit */
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			if (!started)
				sign = -sign;
		}
		else if (s[i] == '+')
		{
			/* do nothing; only relevant before digits */
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			int digit = s[i] - '0';

			started = 1;
			/* accumulate as negative to stay in range even at INT_MIN */
			result = result * 10 - digit;
		}
		else if (started)
		{
			/* first non-digit after number -> stop */
			break;
		}
		i++;
	}

	/* if no digits were found, result is 0 -> returns 0 */
	if (sign > 0)
	{
		/* return the positive value without multiplying -1 during parse */
		/* Beware: negating INT_MIN would overflow, but here result == INT_MIN
		 * only when the digits exceeded INT_MAX; standard atoi is UB then.
		 * Given project tests, this path avoids the sanitizer issues seen.
		 */
		return (-result);
	}
	return (result);
}
