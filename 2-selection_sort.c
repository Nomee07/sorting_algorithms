#include "sort.h"

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
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			write_array(array, size);
		}
	}
}