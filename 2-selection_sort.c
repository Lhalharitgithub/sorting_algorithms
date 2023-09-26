#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - A custom function that sorts an array in
 * ascending order with selection sort algorithm.
 * @array: Arguement of the function containing array that is to
 * be sorted by the custom function.
 * @size: Argument of the function with length of the array.
 * Return: The function returns nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t unk_arg21;
	size_t unk_argv4;
	size_t unk_arg;
	int var_al;

	for (unk_argv4 = 0; unk_argv4 < size - 1; unk_argv4++)
	{
		unk_arg = unk_argv4;
		for (unk_arg21 = unk_argv4 + 1; unk_arg21 < size; unk_arg21++)
		{
			if (array[unk_arg21] < array[unk_arg])
				unk_arg = unk_arg21;
		}

		if (unk_arg != unk_argv4)
		{
			var_al = array[unk_argv4];
			array[unk_argv4] = array[unk_arg];
			array[unk_arg] = var_al;
			print_array(array, size);
		}
	}
}
