#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t i, tmp, position;
	int swap;
	
	for (i = 0; i < size; i++)
	{
		tmp = i;
		for (position = i + 1; position < size; position++)
		{
			if (array[tmp] > array[position])
				tmp = position;
		}
		if (tmp != i)
		{
			swap = array[i];
			array[i] = array[tmp];
			array[tmp] = swap;
			print_array(array, size);
		}
	}
}
