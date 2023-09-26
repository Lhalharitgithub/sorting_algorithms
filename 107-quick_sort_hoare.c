#include "sort.h"
/**
*al_cf_chg - Initialised a custom function.
*@al_sequence: Argument of custom function.
*@hf: Argument of custom function.
*@jk: Argument of custom function.
*Return: The function returns nothing.
*/
void al_cf_chg(int *al_sequence, ssize_t hf, ssize_t jk)
{
	int __int_d1;

	__int_d1 = al_sequence[hf];
	al_sequence[hf] = al_sequence[jk];
	al_sequence[jk] = __int_d1;
}
/**
 *func_alg_ - Initialised a custom function.
 *@al_sequence: Argument of custom function.
 *@arg_ele1: Argument of custom function.
 *@arg_ele2: Argument of custom function.
 *@_len_int_al: Argument of custom function.
 *Return: The function returns nothing.
 */
int func_alg_(int *al_sequence, int arg_ele1, int arg_ele2, int _len_int_al)
{
	int sqn_var = arg_ele1 - 1, arg_sqn_var = arg_ele2 + 1;
	int arg1_sqn_var = al_sequence[arg_ele2];

	while (1)
	{

		do {
			sqn_var++;
		} while (al_sequence[sqn_var] < arg1_sqn_var);
		do {
			arg_sqn_var--;
		} while (al_sequence[arg_sqn_var] > arg1_sqn_var);
		if (sqn_var >= arg_sqn_var)
			return (sqn_var);
		al_cf_chg(al_sequence, sqn_var, arg_sqn_var);
		print_array(al_sequence, _len_int_al);
	}
}
/**
 *infunc - Initialised a custom function.
 *@al_sequence: Argument of custom function.
 *@arg_ele1: Argument of custom function.
 *@arg_ele2: Argument of custom function.
 *@_len_int_al: Argument of custom function.
 *Return: The function returns nothing.
 */
void infunc(int *al_sequence, ssize_t arg_ele1,
		ssize_t arg_ele2, int _len_int_al)
{
	ssize_t _r_index = 0;

	if (arg_ele1 < arg_ele2)
	{
		_r_index = func_alg_(al_sequence, arg_ele1, arg_ele2, _len_int_al);
		infunc(al_sequence, arg_ele1, _r_index - 1, _len_int_al);
		infunc(al_sequence, _r_index, arg_ele2, _len_int_al);
	}
}
/**
 *quick_sort_hoare - Initialised a custom function.
 *@array: Argument of custom function.
 *@size: Argument of custom function.
 *Return: The function returns nothing.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	infunc(array, 0, size - 1, size);
}
