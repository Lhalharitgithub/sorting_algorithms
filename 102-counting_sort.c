#include "sort.h"
/**
 * counting_sort - Custom function for counting sort
 * algorithm implementation.
 * @array: Argement of the sequence
 * @size: Argument of the lenght of theh given sequence.
 * Return: The function returns nothing.
 **/
void counting_sort(int *array, size_t size)
{
	int argvv;
	int arg1;
	int *_val;
	int *_vn;
	size_t unk_;

	if (!array || size < 2)
		return;
	argvv = array[0];
	for (unk_ = 0; unk_ < size; unk_++)
	{
		if (array[unk_] > argvv)
			argvv = array[unk_];
	}
	_val = calloc((argvv + 1), sizeof(int));
	for (unk_ = 0; unk_ < size; unk_++)
	{
		_val[array[unk_]]++;
	}
	for (arg1 = 1; arg1 < argvv; arg1++)
	{
		_val[arg1 + 1] += _val[arg1];
	}
	print_array(_val, argvv + 1);
	_vn = malloc(sizeof(int) * size);
	for (unk_ = 0; unk_ < size; unk_++)
	{
		_val[array[unk_]]--;
		_vn[_val[array[unk_]]] = array[unk_];
	}
	for (unk_ = 0; unk_ < size; unk_++)
	{
		array[unk_] = _vn[unk_];
	}
	free(_vn);
	free(_val);
}
