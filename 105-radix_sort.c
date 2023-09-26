#include <stdlib.h>
#include "sort.h"
/**
 * dl_custom_alg_ - Initialised custom function.
 * @al_sequence: Argument of custom function.
 * @hg: Argument of custom function.
 * @al_len_int: Argument of custom function.
 * @integer_var_: Argument of custom function.
 * Return: The function returns nothing.
 */
void dl_custom_alg_(int *al_sequence, int **hg,
			int al_len_int, int integer_var_)
{
	int _func, al_var_, int_d1 = 10, snc_vv;
	int al_int_element[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int fh__[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (_func = 0; _func < al_len_int; _func++)
	{
		snc_vv = al_sequence[_func];
		for (al_var_ = 0; al_var_ < integer_var_; al_var_++)
			if (al_var_ > 0)
				snc_vv = snc_vv / 10;
		snc_vv = snc_vv % 10;
		hg[snc_vv][al_int_element[snc_vv]] = al_sequence[_func];
		al_int_element[snc_vv] += 1;
	}

	for (_func = 0, al_var_ = 0; _func < int_d1; _func++)
	{
		while (al_int_element[_func] > 0)
		{
			al_sequence[al_var_] = hg[_func][fh__[_func]];
			fh__[_func] += 1, al_int_element[_func] -= 1;
			al_var_++;
		}
	}

	print_array(al_sequence, al_len_int);
}
/**
 * dl_void_alg_ - Initialised custom function.
 * @al_sequence: Argument of custom function.
 * @al_len_int: Argument of custom function.
 * @integer_var_: Argument of custom function.
 * Return: The function returns nothing.
 */
void dl_void_alg_(int *al_sequence, int al_len_int, int integer_var_)
{
	int al_int_element[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int _func, al_var_, snc_vv, int_d1 = 10, **hg;

	for (_func = 0; _func < al_len_int; _func++)
	{
		snc_vv = al_sequence[_func];
		for (al_var_ = 0; al_var_ < integer_var_; al_var_++)
			if (al_var_ > 0)
				snc_vv = snc_vv / 10;
		snc_vv = snc_vv % 10;
		al_int_element[snc_vv] += 1;
	}

	if (al_int_element[0] == al_len_int)
		return;

	hg = malloc(sizeof(int *) * 10);
	if (!hg)
		return;

	for (_func = 0; _func < int_d1; _func++)
		if (al_int_element[_func] != 0)
			hg[_func] = malloc(sizeof(int) * al_int_element[_func]);


	dl_custom_alg_(al_sequence, hg, al_len_int, integer_var_);

	dl_void_alg_(al_sequence, al_len_int, integer_var_ + 1);

	for (_func = 0; _func < int_d1; _func++)
		if (al_int_element[_func] > 0)
			free(hg[_func]);
	free(hg);
}
/**
 * radix_sort - Initialised custom function.
 * @array: Argument of custom function.
 * @size: Argument of custom function.
 * Return: The function returns nothing.
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	dl_void_alg_(array, size, 1);
}
