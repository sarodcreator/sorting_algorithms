#include "sort.h"
#include "swap.h"

/**
 * heap_sort - Sorts an array using the Heap Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	/**
	 * Start from bottommost and rightmost internal mode and heapify all
     * internal modes in bottom up way
	 */
	if (array == NULL || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		maxHeap(array, size, i, size);

	for (i = (size - 1); i > 0; --i)
	{
		_swap(&array[0], &array[i]);
		print_array(array, size);

		maxHeap(array, size, 0, i);
	}
}

/**
 * maxHeap - The function to maintain the max property
 * @array: array to be modified
 * @size: size of the array for print
 * @index: index of the current node
 * @heap_size: size of the heap
 */
void maxHeap(int *array, size_t size, int index, size_t heap_size)
{
	int largest = index;		 /* Initialize largest as root*/
	int left = 2 * index + 1;	 /* left = (index << 1) + 1*/
	int right = 2 * index + 2; /* right = (index + 1) << 1*/

	if (left < (int)heap_size && array[left] > array[largest])
		largest = left;

	if (right < (int)heap_size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		_swap(&array[index], &array[largest]);
		print_array(array, size);
		maxHeap(array, size, largest, heap_size);
	}
}
