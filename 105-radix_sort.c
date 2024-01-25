#include "sort.h"

/**
 * radix_sort - main fuction to sort the array
 * @array: the array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int exp, max = 0;
	int *tmp = NULL;

	if (array == NULL || size < 2)
		return;

	max = Max(array, size);
	tmp = malloc(size * sizeof(int));
	if (tmp == NULL)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		sort(array, size, exp, tmp);
		print_array(array, size);
	}

	free(tmp);
}

/**
 * sort - function to count array
 * @array: array to be sorted
 * @heap_size: size of array
 * @exp: exp is 10^i
 * @tmp: array to save temporary values
 */
void sort(int *array, size_t heap_size, int exp, int *tmp)
{
	int i, count[10] = {0};

	for (i = 0; i < (int)heap_size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = heap_size - 1; i >= 0; i--)
	{
		tmp[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
}

/**
* Max - A function to get maximum value in arr[]
* @array: array to be sorted
* @heap_size: size of the array
* Return: sorted array
*/
int Max(int *array, int heap_size)
{
	int i, max_value = array[0];

	for (i = 1; i < heap_size; i++)
		if (array[i] > max_value)
			max_value = array[i];
	return (max_value);
}
