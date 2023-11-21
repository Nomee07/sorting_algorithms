#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * write_array - Helper function to write an array to stdout
 * @array: Pointer to the array to be written
 * @size: Size of the array
 */
void write_array(int *array, size_t size)
{
	char buffer[20];
	size_t i;

	for (i = 0; i < size; i++)
	{
		snprintf(buffer, sizeof(buffer), "%d", array[i]);
		write(STDOUT_FILENO, buffer, strlen(buffer));

		if (i < size - 1)
			write(STDOUT_FILENO, ", ", 2);
	}
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: Pointer to the array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low - 1;
	size_t j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);
	write_array(array, size);
	return (i + 1);
}

/**
 * quicksort - Recursive function to perform quicksort
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */

void quicksort(int *array, size_t low, size_t high, size_t size)
{
	if (low < high)
	{
		size_t pivot_index = lomuto_partition(array, low, high, size);

		if (pivot_index > 0)
			quicksort(array, low, pivot_index - 1, size);
		quicksort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	quicksort(array, 0, size - 1, size);
}
