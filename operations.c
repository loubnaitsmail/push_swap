#include "push_swap.h"
extern int SCORE_FINAL;

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

//sa : swap a - swap the first 2 elements at the top of stack a
void	ft_sa(t_stack *a)
{
	t_elem	*tmp;

	if (a->size > 1)
	{
		tmp = a->first->next;
		a->first->next = a->first->next->next;
		tmp->next = a->first;
		a->first = tmp;
		ft_putstr("sa\n");
		SCORE_FINAL++;
	}
}

//sb : swap b - swap the first 2 elements at the top of stack b.
void	ft_sb(t_stack *b)
{
	t_elem	*tmp;

	if (b->size > 1)
	{
		tmp = b->first->next;
		b->first->next = b->first->next->next;
		tmp->next = b->first;
		b->first = tmp;
		ft_putstr("sb\n");
		SCORE_FINAL++;
	}
}

//ss : sa and sb at the same time
void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a);
	ft_sb(b);
	ft_putstr("ss\n");
		SCORE_FINAL++;
}

//pa : push a - take the first element at the top of b  and put it at the top of a
void	ft_pa(t_stack *a, t_stack *b)
{
	long	value;

	if (b != NULL && b->size > 0)
	{
		value = remove_from_top(b);
		add_to_top(a, value);
	ft_putstr("pa\n");
		SCORE_FINAL++;
	}
}

//pb : push b - take the first element at the top of a and put it at the top of b.
void	ft_pb(t_stack *a, t_stack *b)
{
	long	value;

	if (a != NULL && a->size > 0)
	{
		value = remove_from_top(a);
		add_to_top(b, value);
	ft_putstr("pb\n");
		SCORE_FINAL++;
	}
}

//ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
void		ft_ra(t_stack *a)
{
	t_elem	*tmp;
	t_elem *head;

	if (a->size > 1)
	{
		tmp = a->first;
		a->first = a->first->next;
		a->last = tmp;
		/*ahead = a->first;
		tmp->next = NULL;
		while (a->first->next)
		{
			a->first = a->first->next;
		}
		a->first->next = tmp;
		a->first = head;
		*/
	ft_putstr("ra\n");
		SCORE_FINAL++;
	}
}

//rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
//
void		ft_rb(t_stack *b)
{
	t_elem	*tmp;
	t_elem *head;

	if (b->first && b->first->next)
	{
		tmp = b->first;
		b->first = b->first->next;
		b->last = tmp;
		/*
		head = b->first;
		tmp->next = NULL;
		while (b->first->next)
		{
			b->first = b->first->next;
		}
		b->first->next = tmp;
		b->first = head;
	*/
	ft_putstr("rb\n");
		SCORE_FINAL++;
	}
}

//rr : ra and rb at the same time.

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
	ft_putstr("rr\n");
		SCORE_FINAL++;
}

//rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
void		ft_rra(t_stack *a)
{
	t_elem	*head;
	t_elem	*tmp;

	if (a->first && a->first->next)
	{
		tmp = a ->last;
		a->last = a->last->prev;
		a->first = tmp;

		/*
		head = a->first;
		while (a->first->next->next)
		{
			a->first = a->first->next;
		}
		tmp = a->first->next;
		a->first->next = NULL;
		a->first = head;
		tmp->next = a->first;
		a->first = tmp;
	*/
		ft_putstr("rra\n");
		SCORE_FINAL++;
	}
}

//rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
void		ft_rrb(t_stack *b)
{
	t_elem	*tmp;

	if (b->first && b->first->next)
	{
		tmp = b ->last;
		b->last = b->last->prev;;
		b->first = tmp;
		ft_putstr("rrb\n");
		SCORE_FINAL++;
	}
}

//rrr : rra and rrb at the same time.
void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a);
	ft_rrb(b);
	ft_putstr("rrr\n");
		SCORE_FINAL++;
}

//Reverse
void	reverse(t_stack *a)
{
	t_elem	*prev = NULL;
	t_elem *next = NULL;
	t_elem	*current;

	current = a->first;
	while (current != NULL)
	{
		next  = current->next;

		current->next = prev;
		
		prev = current;
		current = next;
	}
	a->first = prev;
	ft_putstr("Reverse\n");
}

