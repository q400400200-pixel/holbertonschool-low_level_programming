#include <stdlib.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @str: the string to duplicate
 *
 * Return: pointer to duplicated string (Success), NULL (Error)
 */
char *_strdup(char *str)
{
    char *dup;
    unsigned int i, len = 0;

    if (str == NULL)
        return (NULL);

    /* حساب طول النص */
    while (str[len] != '\0')
        len++;

    /* حجز مساحة في الذاكرة = طول النص + 1 للـ '\0' */
    dup = malloc(sizeof(char) * (len + 1));
    if (dup == NULL)
        return (NULL);

    /* نسخ النص */
    for (i = 0; i < len; i++)
        dup[i] = str[i];
    dup[len] = '\0';

    return (dup);
}
