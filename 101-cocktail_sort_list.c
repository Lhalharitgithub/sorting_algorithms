#include "sort.h"

/**
 * al_chnSquence - Custom function to change element
 * in given sequence.
 * @sm_al: Argument of the custom function.
 * @st: Argument of the custom function.
 * Return: The function returns nothing.
 */
void al_chnSquence(listint_t **sm_al, listint_t **st)
{
	listint_t *_al;
	listint_t *var_al = *sm_al;
	listint_t *unkvar_al;


	if (!(*sm_al)->prev)
		*st = (*sm_al)->next;

	var_al = _al = *sm_al;
	unkvar_al = var_al->next;

	var_al->next = unkvar_al->next;
	_al = var_al->prev;
	var_al->prev = unkvar_al;
	unkvar_al->next = var_al;
	unkvar_al->prev = _al;

	if (unkvar_al->prev)
		unkvar_al->prev->next = unkvar_al;


	if (var_al->next)
		var_al->next->prev = var_al;

	*sm_al = unkvar_al;

}
/**
 * cocktail_sort_list - Custom function that sort given
 * DLL
 * @list: Argument of the custom function to sort given
 * doubly linked list.
 * Return: The function returns nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tt_;
	listint_t *_vn;
	int kn_val = -1;
	int n = -1;
	int arg = 0;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;
	tt_ = *list;
	while (kn_val >= n)
	{
		n++;
		while (tt_->next && arg != kn_val)
		{
			if (tt_->n > tt_->next->n)
			{
				_vn = tt_;
			       al_chnSquence(&_vn, list);
			       print_list(*list);
			       tt_ = _vn;
			}
			arg++;
			tt_ = tt_->next;
		}
		if (n == 0)
			kn_val = arg;
		kn_val--;
		while (tt_->prev && arg >= n)
		{
			if (tt_->n < tt_->prev->n)
			{
				_vn = tt_->prev;
				al_chnSquence(&_vn, list);
				print_list(*list);
				tt_ = _vn->next;
			}
			arg--;
			tt_ = tt_->prev;
		}
	}
}
