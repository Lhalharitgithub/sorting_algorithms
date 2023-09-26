#include "sort.h"
#include <stdio.h>
/**
 * al_cf_chg - Initialised custom function.
 * @al_qne: Argument of custom function.
 * @hf: Argument of custom function.
 * @jk: Argument of custom function.
 * @vv_arg_sqn: Argument of custom function.
 * Return: The function returns nothing
 */
void al_cf_chg(int al_qne[], int hf, int jk, int vv_arg_sqn)
{
	int int_d1;

	if (vv_arg_sqn == (al_qne[hf] > al_qne[jk]))
	{
		int_d1 = al_qne[hf];
		al_qne[hf] = al_qne[jk];
		al_qne[jk] = int_d1;
	}
}
/**
 * al_cf_jn - Initialised custom function.
 * @al_qne: Argument of custom function.
 * @arg1: Argument of custom function.
 * @arg2: Argument of custom function.
 * @vv_arg_sqn: Argument of custom function.
 * Return: The function returns nothing
 */
void al_cf_jn(int al_qne[], int arg1, int arg2, int vv_arg_sqn)
{
	int int_arg, int_argv1;

	if (arg2 > 1)
	{
		int_arg = arg2 / 2;
		for (int_argv1 = arg1; int_argv1 < arg1 + int_arg; int_argv1++)
			al_cf_chg(al_qne, int_argv1, int_argv1 + int_arg, vv_arg_sqn);
		al_cf_jn(al_qne, arg1, int_arg, vv_arg_sqn);
		al_cf_jn(al_qne, arg1 + int_arg, int_arg, vv_arg_sqn);
	}
}
/**
 * alg_bitonic_sort_func - Initialised custom function.
 * @al_qne: Argument of custom function.
 * @arg1: Argument of custom function.
 * @arg2: Argument of custom function.
 * @vv_arg_sqn: Argument of custom function.
 * @al_len_int: Argument of custom function.
 * Return: The function returns nothing
 */
void alg_bitonic_sort_func(int al_qne[], int arg1, int arg2,
				int vv_arg_sqn, int al_len_int)
{
	int int_arg;

	if (arg2 > 1)
	{
		if (vv_arg_sqn >= 1)
		{
			printf("Merging [%int_argv1/%int_argv1] (UP):\n", arg2, al_len_int);
			print_array(&al_qne[arg1], arg2);
		}
		else
		{
			printf("Merging [%int_argv1/%int_argv1] (DOWN):\n", arg2, al_len_int);
			print_array(&al_qne[arg1], arg2);
		}
		int_arg = arg2 / 2;
		alg_bitonic_sort_func(al_qne, arg1, int_arg, 1, al_len_int);
		alg_bitonic_sort_func(al_qne, arg1 + int_arg, int_arg, 0, al_len_int);
		al_cf_jn(al_qne, arg1, arg2, vv_arg_sqn);
		if (vv_arg_sqn <= 0)
		{
			printf("Result [%int_argv1/%int_argv1] (DOWN):\n", arg2, al_len_int);
			print_array(&al_qne[arg1], arg2);
		}
		if (vv_arg_sqn >= 1)
		{
			printf("Result [%int_argv1/%int_argv1] (UP):\n", arg2, al_len_int);
			print_array(&al_qne[arg1], arg2);
		}
	}
}
/**
 * bitonic_sort - Initialised custom function.
 * @array: Argument of custom function.
 * @size: Argument of custom function.
 * Return: The function returns nothing
 */
void bitonic_sort(int *array, size_t size)
{
	int vv_arg_sqn = 1;

	if (!array || size < 2)
		return;
	alg_bitonic_sort_func(array, 0, size, vv_arg_sqn, size);
}
