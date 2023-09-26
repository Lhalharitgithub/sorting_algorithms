#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * al_duplicate_func - Initialised custom function
 * @_vn: Argument of custom function
 * @kn_val: Argument of custom function
 * @iz: Argument of custom function
 * Return: The function returns nothing
 */
void al_duplicate_func(int *_vn, int *kn_val, int iz)
{
	int unk_;

	for (unk_ = 0; unk_ < iz; unk_++)
		kn_val[unk_] = _vn[unk_];
}
/**
 * al_join_func - Initialised custom function
 * @ra: Argument of custom function
 * @hg: Argument of custom function
 * @int_d2: Argument of custom function
 * @int_d3: Argument of custom function
 * @int_d4: Argument of custom function
 * @int_d5: Argument of custom function
 * Return: The function returns nothing
 */
void al_join_func(int *ra, int *hg, int int_d2,
				int int_d3, int int_d4, int int_d5)
{
	int unk_ = int_d2, al_var_ = int_d4, __pnr = int_d2;

	while (unk_ <= int_d3 || al_var_ <= int_d5)

		if (unk_ <= int_d3 && al_var_ <= int_d5)
			if (hg[unk_] <= hg[al_var_])
				ra[__pnr] = hg[unk_], __pnr++, unk_++;
			else
				ra[__pnr] = hg[al_var_], __pnr++, al_var_++;

		else if (unk_ > int_d3 && al_var_ <= int_d5)
			ra[__pnr] = hg[al_var_], __pnr++, al_var_++;
		else
			ra[__pnr] = hg[unk_], __pnr++, unk_++;
}
/**
 * al_custom_display_func - Initialised custom function
 * @ra: Argument of custom function
 * @_d5: Argument of custom function
 * @_dd: Argument of custom function
 * Return: The function returns nothing
 */
void al_custom_display_func(int *ra, int _d5, int _dd)
{
	int unk_;

	for (unk_ = _d5; unk_ <= _dd; unk_++)
	{
		if (unk_ > _d5)
			printf(", ");
		printf("%d", ra[unk_]);
	}
	printf("\n");
}
/**
 * al_custom_sp_func - Initialised custom function
 * @yn: Argument of custom function
 * @hg: Argument of custom function
 * @int_var: Argument of custom function
 * @int_var2: Argument of custom function
 * @al_len: Argument of custom function
 * Return: The function returns nothing
 */
void al_custom_sp_func(int *yn, int *hg, int int_var, int int_var2, int al_len)
{
	int int_d, int_d1, int_d2;
	int int_d3, int_d4, int_d5;

	if ((int_var2 - int_var) <= 0)
		return;

	int_d = (int_var2 + int_var + 1) / 2;
	int_d1 = int_var2;
	int_var2 = int_d - 1;

	int_d2 = int_var;
	int_d3 = int_var2;

	al_custom_sp_func(yn, hg, int_var, int_var2, al_len);

	int_var = int_d;
	int_var2 = int_d1;

	int_d4 = int_var;
	int_d5 = int_var2;

	al_custom_sp_func(yn, hg, int_var, int_var2, al_len);

	printf("Merging...\n");
	printf("[left]: ");

	al_custom_display_func(yn, int_d2, int_d3);

	printf("[right]: ");

	al_custom_display_func(yn, int_d4, int_d5);
	al_join_func(yn, hg, int_d2, int_d3, int_d4, int_d5);
	al_duplicate_func(yn, hg, al_len);

	printf("[Done]: ");
	al_custom_display_func(yn, int_d2, int_d5);
}
/**
 * merge_sort - Initialised custom function
 * @array: Argument of custom function
 * @size: Argument of custom function
 * Return: The function returns nothing
 */
void merge_sort(int *array, size_t size)
{
	int *hg;

	if (size < 2)
		return;

	hg = malloc(sizeof(int) * size);
	if (hg == NULL)
		return;

	al_duplicate_func(array, hg, size);

	al_custom_sp_func(array, hg, 0, size - 1, size);

	free(hg);
}
