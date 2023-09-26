#include "sort.h"
#include <stdio.h>
/**
 * al_change_squence - Custom function to change
 * index of element in given sequence.
 * @y: Argument of the array that needs to be
 * changed.
 * @unk_arg21: Argument of the custom function.
 * @arg11: Argument of the custom function.
 * Return: The function returns nothing.
 */
void al_change_squence(int *y, int unk_arg21, int arg11)
{
	int al_int_var1;

	if (y[unk_arg21] != y[arg11])
	{
		al_int_var1 = y[unk_arg21];
		y[unk_arg21] = y[arg11];
		y[arg11] = al_int_var1;
	}
}

/**
 * shell_sort - sort the list and print the changes
 * @array: The array to sort.
 * @size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t nukvar = 0,  unk_arg21, arg11;

	if (size < 2)
		return;

	while (nukvar <= size / 3)
		nukvar = nukvar * 3 + 1;

	while (nukvar >= 1)
	{
		for (unk_arg21 = nukvar; unk_arg21 < size; unk_arg21++)
			for (arg11 = unk_arg21; arg11 >= nukvar &&
					array[arg11] < array[arg11 - nukvar]; arg11 -= nukvar)
				al_change_squence(array, arg11, arg11 - nukvar);
		nukvar /= 3;
		print_array(array, size);
	}
}
