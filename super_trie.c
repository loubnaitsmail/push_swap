
#include "push_swap.h"


int SCORE_FINAL;
int SCORE_ATTENDU;

void	print_list(int *tab, int nb_elem)
{
	int i = -1;
	while (++i < nb_elem)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}

int		*sort_list(int *tab, int nb_elem)
{
	int i;
	int j;
	int smaller;
	int pos_smaller;
	int tmp;

	i = 0;
	while (i < nb_elem)
	{
		j = i;
		smaller = tab[j];
		pos_smaller = j;
		while (j < nb_elem)
		{
			if (tab[j] < smaller)
			{
				smaller = tab[j];
				pos_smaller = j;
			}
			j++;
		}
		tmp = tab[i];
		tab[i] = tab[pos_smaller];
		tab[pos_smaller] = tmp;
		i++;
	}
	return tab;
}

int is_extrem(long int value, t_stack *p)
{
	long int min;
	long int max;
	int size;
	t_elem *elem;

	size = 0;
	elem = p->first;
	min = elem->value;
	max = elem->value;
	while (size < p->size)
	{
		if (elem->value > max)
			max = elem->value;
		else if (elem->value < min)
			min = elem->value;
		elem = elem->next;
		size ++;
	}
	printf("size min max %d %ld %ld\n", p->size, min, max);
	if (value < min)
		return (-1);
	else if (value > max)
		return (1);
	else
		return (0);

}


/*
 * FAUT ABSOLUMENT QUE la pile B SOIT TRIEE
 */
int find_closest(long int value, t_stack *p)
{
	t_elem	*by_next;
	t_elem	*by_previous;
	int		score;
	int extrem;



	score = 0;
	by_next = p->first;
	by_previous = p->first;
	extrem = is_extrem(value, p);
	if (extrem == 0)
	{
		while ((value < by_next->value || value > by_next->prev->value) &&
			(value < by_previous->value || value > by_previous->prev->value))
		{
//printf("val(%ld) , <%ld, %ld>\n",value, by_next->prev->value , by_next->value);
//printf("val(%ld) , <%ld, %ld>\n",value, by_previous->prev->value , by_previous->value);
			by_next = by_next->next;
			by_previous = by_previous->prev;
			score++;
		}
		if (value > by_next->value && value < by_next->prev->value)
			return (score);
		else
			return (-1 * score);
	}
	else
	{
		while (!( by_next->prev->value < by_next->value
			|| by_previous->prev->value < by_previous->value))
		{
			by_next = by_next->next;
			by_previous = by_previous->prev;
			score++;
		}
		if (by_next->prev->value < by_next->value)
			return (score);
		else
			return (-1 * score);
	}
}

void	push_b_sorted(t_stack *a, t_stack *b)
{
	int value;
	int sens_rotation;
	int extrem;

	value = a->first->value;
	if (b->size < 2)
	{
		SCORE_ATTENDU ++;
		ft_pb(a, b);
		return;
	}
	sens_rotation = find_closest(value, b);
	SCORE_ATTENDU += 1 + ft_abs(sens_rotation);
	extrem = is_extrem(value, b);
	if (extrem == 0)
	{
		while (! (value > b->first->value && value < b->last->value))
		{
			if (sens_rotation > 0)
				ft_rb(b);
			else
				ft_rrb(b);
		}
	}
	else
	{
		while (b->last->value > b->first->value)
		{
			if (sens_rotation > 0)
				ft_rb(b);
			else
				ft_rrb(b);
		}
	}
	ft_pb(a, b);
}

static int count_rrotate(t_stack *a, t_stack *b)
{
	int min_score;
	int best_count;
	int current_count;
	int tmp_count;
	t_elem *elem;

	elem = a->first;
	if (b->size < 2)
		return (0);
	min_score = ft_abs(find_closest(elem->value, b));
	best_count = 0;
	current_count = 0;
		printf("current, min %d %d\n", current_count, min_score);
	while (current_count < min_score && current_count < a->size)
	{
		tmp_count = ft_abs(find_closest(elem->value, b));
		if (tmp_count+ current_count < min_score)
		{
			min_score = tmp_count + current_count;
			best_count = current_count;
		}
		current_count ++;
		elem = elem->prev;
	}
	return (best_count);
}

int count_rotate(t_stack *a, t_stack *b)
{
	int min_score;
	int best_count;
	int current_count;
	int tmp_count;
	int r_best_count;

	t_elem *elem;
	elem = a->first;
	if (b->size < 2)
		return (0);
	printf("je vais crahs %ld\n", elem->value);
	min_score = ft_abs(find_closest(elem->value, b));
	printf("je vais crahs\n");
	best_count = 0;
	current_count = 0;
		printf("current, min %d %d\n", current_count, min_score);
	while (current_count < min_score && current_count < a->size)
	{
		tmp_count = ft_abs(find_closest(elem->value, b));
		if (tmp_count+ current_count < min_score)
		{
			min_score = tmp_count + current_count;
			best_count = current_count;
		}
		current_count ++;
		printf("current, min %d %d\n", current_count, min_score);
		elem = elem->next;
	}
	r_best_count = count_rrotate(a, b);
	if (r_best_count < best_count)
		return (-1 * r_best_count);
	return (best_count);
}

void naive_version(t_stack *a, t_stack *b)
{
	int count_r;
	while (a->size > 0)
	{
		count_r =  count_rotate(a, b);
		while (ft_abs(count_r) > 0)
		{
			if (count_r > 0)
			{
				ft_ra(a);
				count_r --;
			}
			else
			{
				ft_rra(a);
				count_r++;
			}
		}
		print_stacks(a, b);
		push_b_sorted(a, b);
	}
	//printf("reultat attendu eu %d\n", SCORE_FINAL);
	//printf("pile B sorted");
//	print_stacks(a, b);
	while (b->size > 0)
	{
		ft_pa(a, b);
	}
	print_stacks(a, b);
	int sens_rotation = find_closest(INT_MAX, a);
	while (a->last->value < a->first->value)
	{
		if (sens_rotation == 1)
			ft_ra(a);
		else
			ft_rra(a);
	}
	printf("finish A sorted");
	print_stacks(a, b);
}


// pas de int min dans la liste 
int recherche_dico(int *tab, int start, int end, int tofind)
{
	int middle;

	middle = (end + start) / 2;
	//printf("try to foind %d  %dstart mid end [%d %d %d]\n", 
	//tofind, tab[middle], start, middle, end);
	if (tab[middle] == tofind)
		return middle;
	if (start >= end)
		return INT_MIN;
	if (tab[middle] < tofind)
		return (recherche_dico(tab, middle + 1, end, tofind));
	else
		return (recherche_dico(tab, start, middle, tofind));
}

void super_trie(t_stack *a, t_stack *b, int *tab, int nb_elem)
{
	SCORE_FINAL = 0;
	SCORE_ATTENDU = 0;
	print_list(tab, nb_elem);
	tab = sort_list(tab, nb_elem);
	print_list(tab, nb_elem);

	for(int i = 0; i < nb_elem;i++)
		printf("%d ", recherche_dico(tab, 0, nb_elem, tab[i]));
	printf("\n");


	naive_version(a, b);
	printf("finiish resultat %d \n", SCORE_FINAL);
	printf("finiish attendu %d \n", SCORE_ATTENDU);

}

















