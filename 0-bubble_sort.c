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
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swapped = 1;
				write_array(array, size);
			}
		}

		if (!swapped)
			break;
	}
}
