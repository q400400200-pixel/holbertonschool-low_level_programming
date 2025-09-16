#include <stdlib.h>
#include "main.h"

/**
* _calloc - allocates memory for an array and sets it to zero
* @nmemb: number of elements
* @size: size of each element in bytes
*
* Return: pointer to allocated memory
*         NULL if nmemb or size is 0, or if malloc fails
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
char *ptr;
unsigned int i, total;

if (nmemb == 0 || size == 0)
return (NULL);

total = nmemb * size;
ptr = malloc(total);
if (ptr == NULL)
return (NULL);

for (i = 0; i < total; i++)
ptr[i] = 0;

return (ptr);
}
