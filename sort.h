#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* print_list */
void print_list(const listint_t *list);

/* print_array */
void print_array(const int *array, size_t size);

/* bubble_sort */
void bubble_sort(int *array, size_t size);

/* insertion_sort_list.c */
void insertion_sort_list(listint_t **list);

/* selction_sort.c */
void selection_sort(int *array, size_t size);

/* quick_sort.c */
void quick_sort(int *array, size_t size);
void swap(int *array, ssize_t item1, ssize_t item2);
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size);
void q_sort(int *array, ssize_t first, ssize_t last, int size);
#endif
