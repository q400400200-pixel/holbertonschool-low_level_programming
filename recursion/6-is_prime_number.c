#include "main.h"

/**
 * check_prime - helper to check if n is divisible
 * @n: number to check
 * @i: current divisor
 *
 * Return: 1 if prime, 0 otherwise
 */
int check_prime(int n, int i)
{
	if (i * i > n)     /* لو وصلنا لأكبر من الجذر */
		return (1);
	if (n % i == 0)    /* لو n يقبل القسمة على i */
		return (0);
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - returns 1 if n is prime, 0 otherwise
 * @n: number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (check_prime(n, 2));
}
