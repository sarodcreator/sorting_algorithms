#include "sort.h"
/**
 * bubble_sort - sort array lements from min to max value
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t n, position;
	int tmp = 0;

	if (size < 2)
		return;

	for (n = 0; n < size; n++)
	{
		for (position = 0; position < size - n - 1; position++)
		{
			if (array[position] > array[position + 1])
			{
			tmp = array[position];
			array[position] = array[position + 1];
			array[position + 1] = tmp;
			print_array(array, size);
			}
		}
	}
}
