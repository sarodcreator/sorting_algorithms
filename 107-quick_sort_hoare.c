#include  "sort.h"
#include "swap.h"
/**
 *hoare_partition - hoare partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}
/**
 *q_s - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void q_s(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		q_s(array, first, position - 1, size);
		q_s(array, position, last, size);
	}
}
/**
 *quick_sort_hoare - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_s(array, 0, size - 1, size);
}
