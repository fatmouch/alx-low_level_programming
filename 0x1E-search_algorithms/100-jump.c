#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Function searches for the value in an array using Jump Search.
 * @array: The array to search.
 * @size: The size of the Array.
 * @value: The value to search for.
 *
 * Return: -1 if not found, i otherwise
 */
int jump_search(int *array, size_t size, int value)
{
size_t jump, start, limit;

if (!array || size == 0)
return (-1);
jump = (size_t) sqrt(size);
start = limit = 0;
while ((limit < size) && (array[limit] < value))
{
printf("Value checked array[%lu] = [%d]\n", limit, array[limit]);
start = limit;
limit += jump;
}
printf("Value found between indexes [%lu] and [%lu]\n", start, limit);
limit = limit < size - 1 ? limit : size - 1;
while ((array[start] < value) && (start < limit))
{
printf("Value checked array[%lu] = [%d]\n", start, array[start]);
start++;
}
printf("Value checked array[%lu] = [%d]\n", start, array[start]);
return (array[start] == value ? (int) start : -1);
}
