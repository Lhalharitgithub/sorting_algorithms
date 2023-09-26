#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - A custom functA custom function that sorts given array in
 * ascending order.
 * @array: Argument of custom function containing given array.
 * @size: Second argument of custom function representing the size of
 * an array.
 * Return: The protoytpe returns nothing.
 */

void bubble_sort(int *array, size_t size)
{
	size_t st_var;
	int al_int_var1;
	int al_int_var2;

	if (!array || size == 0)
		return;

	do {
		al_int_var2 = 1;
		for (st_var = 0; st_var < size - 1; st_var++)
		{
			if (array[st_var] > array[st_var + 1])
			{
				al_int_var2 = 0;
				al_int_var1 = array[st_var];
				array[st_var] = array[st_var + 1];
				array[st_var + 1] = al_int_var1;
				print_array(array, size);
			}
		}

	} while (al_int_var2 == 0);
}
