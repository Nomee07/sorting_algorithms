#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */

void selection_sort(int *array, size_t size)
{
	int aux = 0;
	size_t i = 0, j = 0, pos = 0;

	if (array == NULL || size == 0)
		return;

	for (; i < size - 1; i++)
	{
		pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pos])
				pos = j;
		}
		if (pos != i)
		{
			aux = array[i];
			array[i] = array[pos];
			array[pos] = aux;
			print_array(array, size);
		}
	}
}
