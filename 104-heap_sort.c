#include "sort.h"
/**
 * sxy_st - Initialised custom function
 * @ry: Argument of custom function
 * @ad_: Argument of custom fucntion
 * @al_ze_len: Argument of custom function
 * @_func: Argument of custom function
 * Return: The function returns nothing
**/
void sxy_st(int *ry, size_t ad_, size_t al_ze_len, size_t _func)
{

	int argvv, snc, snc_vv;
	size_t s_int_1v, s_int1;

	s_int_1v = _func * 2 + 1;
	s_int1 = s_int_1v + 1;
	snc = ry[s_int_1v];
	snc_vv = ry[s_int1];
	if (((s_int_1v < al_ze_len) && (s_int1 < al_ze_len) &&
		(snc >= snc_vv && snc > ry[_func]))
		|| ((s_int_1v == al_ze_len - 1) && snc > ry[_func]))
	{
		argvv = ry[_func];
		ry[_func] = snc;
		ry[s_int_1v] = argvv;
		print_array(ry, ad_);
	}
	else if ((s_int_1v < al_ze_len) && (s_int1 < al_ze_len) &&
		(snc_vv > snc && snc_vv > ry[_func]))
	{
		argvv = ry[_func];
		ry[_func] = snc_vv;
		ry[s_int1] = argvv;
		print_array(ry, ad_);
	}
	if (s_int_1v < al_ze_len - 1)
		sxy_st(ry, ad_, al_ze_len, s_int_1v);
	if (s_int1 < al_ze_len - 1)
		sxy_st(ry, ad_, al_ze_len, s_int1);
}
/**
 * heap_sort - Initialised custom function
 * @array: Argument of custom function
 * @size: Argument of custom function
 * Return: The function returns nothing
**/
void heap_sort(int *array, size_t size)
{
	size_t _func, ad_ = size;
	int argvv;

	if (!array)
		return;
	for (_func = 0; _func < size / 2 ; _func++)
	{
		sxy_st(array, ad_, size, size / 2 - 1 - _func);
	}
	for (_func = 0; _func < ad_ - 1; _func++)
	{
		argvv = array[0];
		array[0] = array[size - 1 - _func];
		array[size - 1 - _func] = argvv;
		print_array(array, ad_);
		sxy_st(array, ad_, size - _func - 1, 0);
	}

}
