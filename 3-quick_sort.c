#include "sort.h"

/**
 * al_change_position_func - Custom function that changes
 * element of array.
 * @argvk: Argument of array to change position.
 * @arg2: Argument of index of left element to change
 * position.
 * @arg3: Argument of index of right element to change
 * position.
 */
void al_change_position_func(int *argvk, size_t arg2, size_t arg3)
{
	int alvar2;

	if (argvk != NULL)
	{
		alvar2 = argvk[arg2];
		argvk[arg2] = argvk[arg3];
		argvk[arg3] = alvar2;
	}
}

/**
 * al_custom_lomuto - Initialised custom function.
 * @argvk: Argument of custom function.
 * @low: Second argument of custom function.
 * @high: Third argument of custom function.
 * @nn_arg_len: Argument of given length
 */
void al_custom_lomuto(int *argvk, size_t low, size_t high, size_t nn_arg_len)
{
	size_t alvar1;
	size_t alvar3;
	int al;

	if ((low >= high) || (argvk == NULL))
		return;
	al = argvk[high];
	alvar1 = low;
	for (alvar3 = low; alvar3 < high; alvar3++)
	{
		if (argvk[alvar3] <= al)
		{
			if (alvar1 != alvar3)
			{
				al_change_position_func(argvk, alvar1, alvar3);
				print_array(argvk, nn_arg_len);
			}
			alvar1++;
		}
	}
	if (alvar1 != high)
	{
		al_change_position_func(argvk, alvar1, high);
		print_array(argvk, nn_arg_len);
	}
	if (alvar1 - low > 1)
		al_custom_lomuto(argvk, low, alvar1 - 1, nn_arg_len);
	if (high - alvar1 > 1)
		al_custom_lomuto(argvk, alvar1 + 1, high, nn_arg_len);
}

/**
 * quick_sort - Custom function that sorts an array with
 * algorithm of quick sort for the given array.
 * @array: Argument of the given array to sort with the
 * custom function.
 * @size: Argument of containing the size or lenght of
 * the given array
 * Return: The function returns nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		al_custom_lomuto(array, 0, size - 1, size);
	}
}
